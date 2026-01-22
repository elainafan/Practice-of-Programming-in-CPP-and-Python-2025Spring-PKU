import asyncio
from playwright.async_api import async_playwright
import os
import requests
import re


async def fetch_data(word):
    url = f"https://cn.bing.com/dict/search?q={word}"
    synonyms = []
    image_url = None

    async with async_playwright() as p:
        browser = await p.chromium.launch(headless=True)
        page = await browser.new_page()
        await page.goto(url)
        await page.wait_for_timeout(1000)

        img_tag = await page.query_selector("img.rms_img")
        if img_tag:
            image_url = await img_tag.get_attribute("src")

        syn_section = await page.query_selector("div#synoid")
        if syn_section:
            a_tags = await syn_section.query_selector_all("a")
            for a in a_tags:
                text = (await a.inner_text()).strip()
                if re.fullmatch(r"[a-zA-Z]+", text):
                    synonyms.append(text)

        await browser.close()

    return list(set(synonyms)), image_url


async def main():
    input_file = "words.txt"
    output_file = "result.txt"

    if not os.path.exists(input_file):
        print("未找到 words.txt 文件")
        return

    with open(input_file, "r", encoding="utf-8") as f:
        words = [line.strip() for line in f if line.strip()]

    with open(output_file, "w", encoding="utf-8") as out_f:
        for word in words:
            print(f"正在处理：{word}")
            synonyms, image_url = await fetch_data(word)

            if synonyms:
                out_f.write(f"${word}\n")
                for syn in synonyms:
                    out_f.write(f"{syn}\n")
                print(f"写入同义词：{', '.join(synonyms)}")
            else:
                print(f"没有找到同义词：{word}")

            if image_url:
                try:
                    img_data = requests.get(image_url).content
                    with open(f"{word}.png", "wb") as img_file:
                        img_file.write(img_data)
                    print(f"已保存图片：{word}.png")
                except Exception as e:
                    print(f"图片下载失败：{word} - {e}")


if __name__ == "__main__":
    asyncio.run(main())
