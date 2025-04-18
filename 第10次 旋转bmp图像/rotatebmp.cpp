#include<bits/stdc++.h>
#pragma pack(1)
using namespace std;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
struct Header{
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
};
struct Info{
    DWORD biSize;
    DWORD biWidth;
    DWORD biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    DWORD biXPlesPerMeter;
    DWORD biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biCIrImportant;
};
struct DATA{
    BYTE red;
    BYTE blue;
    BYTE green;
};
WORD bfType;
Header srcHead;
Info srcInfo;
int h,w,siz;
int getDiff(Info &info){
    int DataSizePerline=(info.biWidth*info.biBitCount+31)/8;
    DataSizePerline-=DataSizePerline%4;
    return DataSizePerline-info.biWidth*info.biBitCount/8;
}
void rotation(const DATA* src){
    int newH=w;
    int newW=h;
    int newSize=newH*newW;
    FILE *p;
    p=fopen("dest.bmp","wb");
    Header newHead=srcHead;
    Info newInfo=srcInfo;
    newHead.bfSize=(DWORD)(newHead.bfSize);
    newInfo.biHeight=(DWORD)(newH);
    newInfo.biWidth=(DWORD)(newW);
    int newdiff=getDiff(newInfo);
    newInfo.biSizeImage=(DWORD)((newInfo.biWidth*3+newdiff)*newInfo.biHeight);
    fwrite(&bfType,1,sizeof(WORD),p);
    fwrite(&newHead,1,sizeof(Header),p);
    fwrite(&newInfo,1,sizeof(Info),p);
    DATA* target=new DATA[newSize];
    for(int i=0;i<=newH-1;i++){
        for(int j=0;j<=newW-1;j++){
            *(target+i*newW+j)=*(src+j*w+newH-i-1);
        }
    }
    for(int i=0;i<=newH-1;i++){
        fwrite((char*)target+i*newW*3,3,newW,p);
        fseek(p,newdiff,SEEK_CUR);
    }
    fclose(p);
    delete []target;
}
int main(){
    FILE* p;
    p=fopen("4.bmp","rb");
    if(p!=NULL){
        fread(&bfType,1,sizeof(WORD),p);
        fread(&srcHead,1,sizeof(Header),p);
        fread(&srcInfo,1,sizeof(Info),p);
        h=srcInfo.biHeight;
        w=srcInfo.biWidth;
        siz=w*h;
        DATA *imgdata=new DATA[siz];
        int diff=getDiff(srcInfo);
        for(int i=0;i<=h-1;i++){
            fread((char*)imgdata+i*w*3,3,w,p);
            fseek(p,diff,SEEK_CUR);
        }
        fclose(p);
        rotation(imgdata);
        delete []imgdata;
    }
    system("pause");
    return 0;
}