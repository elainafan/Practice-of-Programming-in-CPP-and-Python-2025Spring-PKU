#include <bits/stdc++.h>
#define ll long long
using namespace std;
int m, n, k, t, z;
int rm, bm;
struct node {
    int bloo, atta;
    string s;
};
node q[6];
int tim, proces;
int rcnt, bcnt;  // 转换器
int rwin, bwin;
int r_warrior_num, b_warrior_num;  // 两个阵营的士兵数
int rnum[6], bnum[6];              // 各个种族产生的人数
int r[6] = {0, 3, 4, 5, 2, 1}, b[6] = {0, 4, 1, 2, 3, 5};
int step[8] = {0, 5, 5, 25, 5, 10, 5, 5};
int rflag = 0, bflag = 0;
int city[25][2];  // 表示该城市是否有红/蓝阵营,第二维的数字表示红蓝士兵编号
struct warrior {
    int cnt_sword, cnt_bomb, cnt_arrow;        // 剑、炸弹、箭的数量
    int cnt_used_arrow, cnt_never_used_arrow;  // 使用过的箭的数量
    int cnt_total_weapon;                      // 总武器的数量
    int bloo, atta;                            // 士兵的生命值和攻击力
    int catagory;                              // 这个士兵是哪个种类的
    int walk_city;                             // 到达哪个城市
    int loyalty;                               // 忠诚度
    int pd_if_live;                            // 死了没
    int id;                                    // 这是该种的第几只
    int weapon[11];
};
warrior red_warrior[105], blue_warrior[105];
void trans(int k) {
    if (k >= 0 && k <= 9)
        cout << "00" << k;
    else if (k >= 10 && k <= 99)
        cout << '0' << k;
    else
        cout << k;
    return;
}
void output(int x) {
    if (x >= 0 && x <= 9)
        cout << "000:0" << x << ' ';
    else if (x >= 10 && x <= 59)
        cout << "000:" << x << ' ';
    else {
        int k = x / 60, j = x % 60;
        trans(k);
        if (j >= 0 && j <= 9)
            cout << ":0" << j << ' ';
        else
            cout << ':' << j << ' ';
    }
    return;
}
void r_making_weapon_dragon(int number) {
    if (number % 3 == 0) {
        red_warrior[r_warrior_num].cnt_total_weapon++;
        red_warrior[r_warrior_num].cnt_sword++;
    } else if (number % 3 == 1) {
        red_warrior[r_warrior_num].cnt_total_weapon++;
        red_warrior[r_warrior_num].cnt_bomb++;
    } else if (number % 3 == 2) {
        red_warrior[r_warrior_num].cnt_total_weapon++;
        red_warrior[r_warrior_num].cnt_arrow++;
        red_warrior[r_warrior_num].cnt_never_used_arrow++;
    }
}
void b_making_weapon_dragon(int number) {
    if (number % 3 == 0) {
        blue_warrior[b_warrior_num].cnt_total_weapon++;
        blue_warrior[b_warrior_num].cnt_sword++;
    } else if (number % 3 == 1) {
        blue_warrior[b_warrior_num].cnt_total_weapon++;
        blue_warrior[b_warrior_num].cnt_bomb++;
    } else if (number % 3 == 2) {
        blue_warrior[b_warrior_num].cnt_total_weapon++;
        blue_warrior[b_warrior_num].cnt_arrow++;
        blue_warrior[b_warrior_num].cnt_never_used_arrow++;
    }
}
void r_making_weapon_ninja(int number) {
    if (number % 3 == 0) {
        red_warrior[r_warrior_num].cnt_total_weapon++;
        red_warrior[r_warrior_num].cnt_sword++;
        red_warrior[r_warrior_num].cnt_bomb++;
        red_warrior[r_warrior_num].cnt_total_weapon++;
    } else if (number % 3 == 1) {
        red_warrior[r_warrior_num].cnt_total_weapon++;
        red_warrior[r_warrior_num].cnt_arrow++;
        red_warrior[r_warrior_num].cnt_bomb++;
        red_warrior[r_warrior_num].cnt_total_weapon++;
        red_warrior[r_warrior_num].cnt_never_used_arrow++;
    } else if (number % 3 == 2) {
        red_warrior[r_warrior_num].cnt_total_weapon++;
        red_warrior[r_warrior_num].cnt_sword++;
        red_warrior[r_warrior_num].cnt_arrow++;
        red_warrior[r_warrior_num].cnt_total_weapon++;
        red_warrior[r_warrior_num].cnt_never_used_arrow++;
    }
}
void b_making_weapon_ninja(int number) {
    if (number % 3 == 0) {
        blue_warrior[b_warrior_num].cnt_total_weapon++;
        blue_warrior[b_warrior_num].cnt_sword++;
        blue_warrior[b_warrior_num].cnt_bomb++;
        blue_warrior[b_warrior_num].cnt_total_weapon++;
    } else if (number % 3 == 1) {
        blue_warrior[b_warrior_num].cnt_total_weapon++;
        blue_warrior[b_warrior_num].cnt_arrow++;
        blue_warrior[b_warrior_num].cnt_bomb++;
        blue_warrior[b_warrior_num].cnt_total_weapon++;
        blue_warrior[b_warrior_num].cnt_never_used_arrow++;
    } else if (number % 3 == 2) {
        blue_warrior[b_warrior_num].cnt_total_weapon++;
        blue_warrior[b_warrior_num].cnt_sword++;
        blue_warrior[b_warrior_num].cnt_arrow++;
        blue_warrior[b_warrior_num].cnt_total_weapon++;
        blue_warrior[b_warrior_num].cnt_never_used_arrow++;
    }
}
void r_making_weapon_iceman(int number) {
    if (number % 3 == 0) {
        red_warrior[r_warrior_num].cnt_total_weapon++;
        red_warrior[r_warrior_num].cnt_sword++;
    } else if (number % 3 == 1) {
        red_warrior[r_warrior_num].cnt_total_weapon++;
        red_warrior[r_warrior_num].cnt_bomb++;
    } else if (number % 3 == 2) {
        red_warrior[r_warrior_num].cnt_total_weapon++;
        red_warrior[r_warrior_num].cnt_arrow++;
        red_warrior[r_warrior_num].cnt_never_used_arrow++;
    }
}
void b_making_weapon_iceman(int number) {
    if (number % 3 == 0) {
        blue_warrior[b_warrior_num].cnt_total_weapon++;
        blue_warrior[b_warrior_num].cnt_sword++;
    } else if (number % 3 == 1) {
        blue_warrior[b_warrior_num].cnt_total_weapon++;
        blue_warrior[b_warrior_num].cnt_bomb++;
    } else if (number % 3 == 2) {
        blue_warrior[b_warrior_num].cnt_total_weapon++;
        blue_warrior[b_warrior_num].cnt_arrow++;
        blue_warrior[b_warrior_num].cnt_never_used_arrow++;
    }
}
void r_making_weapon_lion(int number) {
    if (number % 3 == 0) {
        red_warrior[r_warrior_num].cnt_total_weapon++;
        red_warrior[r_warrior_num].cnt_sword++;
    } else if (number % 3 == 1) {
        red_warrior[r_warrior_num].cnt_total_weapon++;
        red_warrior[r_warrior_num].cnt_bomb++;
    } else if (number % 3 == 2) {
        red_warrior[r_warrior_num].cnt_total_weapon++;
        red_warrior[r_warrior_num].cnt_arrow++;
        red_warrior[r_warrior_num].cnt_never_used_arrow++;
    }
    red_warrior[r_warrior_num].loyalty = rm;
}
void b_making_weapon_lion(int number) {
    if (number % 3 == 0) {
        blue_warrior[b_warrior_num].cnt_total_weapon++;
        blue_warrior[b_warrior_num].cnt_sword++;
    } else if (number % 3 == 1) {
        blue_warrior[b_warrior_num].cnt_total_weapon++;
        blue_warrior[b_warrior_num].cnt_bomb++;
    } else if (number % 3 == 2) {
        blue_warrior[b_warrior_num].cnt_total_weapon++;
        blue_warrior[b_warrior_num].cnt_arrow++;
        blue_warrior[b_warrior_num].cnt_never_used_arrow++;
    }
    blue_warrior[b_warrior_num].loyalty = bm;
}
void r_birth() {
    if (rm >= q[r[rcnt]].bloo) {
        rm -= q[r[rcnt]].bloo;
        rnum[r[rcnt]]++;
        r_warrior_num++;
        red_warrior[r_warrior_num].bloo = q[r[rcnt]].bloo;
        red_warrior[r_warrior_num].catagory = r[rcnt];
        red_warrior[r_warrior_num].pd_if_live = 1;
        red_warrior[r_warrior_num].atta = q[r[rcnt]].atta;
        red_warrior[r_warrior_num].cnt_used_arrow = 0;
        red_warrior[r_warrior_num].walk_city = 0;
        red_warrior[r_warrior_num].id = r_warrior_num;
        city[0][0] = 1;
        if (r[rcnt] == 1)
            r_making_weapon_dragon(r_warrior_num);
        else if (r[rcnt] == 2)
            r_making_weapon_ninja(r_warrior_num);
        else if (r[rcnt] == 3)
            r_making_weapon_iceman(r_warrior_num);
        else if (r[rcnt] == 4)
            r_making_weapon_lion(r_warrior_num);
        output(tim);
        cout << "red " << q[r[rcnt]].s << ' ' << red_warrior[r_warrior_num].id << " born" << endl;
        if (r[rcnt] == 4) {
            cout << "Its loyalty is " << red_warrior[r_warrior_num].loyalty << endl;
        }
        return;
    } else if (rm < q[r[rcnt]].bloo) {
        rflag = 1;
        return;
    }
}
void b_birth() {
    if (bm >= q[b[bcnt]].bloo) {
        bm -= q[b[bcnt]].bloo;
        bnum[b[bcnt]]++;
        b_warrior_num++;
        blue_warrior[b_warrior_num].id = b_warrior_num;
        blue_warrior[b_warrior_num].bloo = q[b[bcnt]].bloo;
        blue_warrior[b_warrior_num].catagory = b[bcnt];
        blue_warrior[b_warrior_num].pd_if_live = 1;
        blue_warrior[b_warrior_num].atta = q[b[bcnt]].atta;
        blue_warrior[b_warrior_num].cnt_used_arrow = 0;
        blue_warrior[b_warrior_num].walk_city = n + 1;
        city[n + 1][1] = 1;
        if (b[bcnt] == 1)
            b_making_weapon_dragon(b_warrior_num);
        else if (b[bcnt] == 2)
            b_making_weapon_ninja(b_warrior_num);
        else if (b[bcnt] == 3)
            b_making_weapon_iceman(b_warrior_num);
        else if (b[bcnt] == 4)
            b_making_weapon_lion(b_warrior_num);
        output(tim);
        cout << "blue " << q[b[bcnt]].s << ' ' << blue_warrior[b_warrior_num].id << " born" << endl;
        if (b[bcnt] == 4) {
            cout << "Its loyalty is " << blue_warrior[b_warrior_num].loyalty << endl;
        }
        return;
    } else if (bm < q[b[bcnt]].bloo) {
        bflag = 1;
        return;
    }
}
void r_check_lion(int t) {
    for (int i = 1; i <= r_warrior_num; i++) {
        if (red_warrior[i].catagory == 4 && red_warrior[i].loyalty <= 0 && red_warrior[i].pd_if_live == 1) {
            red_warrior[i].pd_if_live = 0;
            city[red_warrior[i].walk_city][0] = 0;
            output(t);
            cout << "red lion " << red_warrior[i].id << " ran away" << endl;
        }
    }
}
void b_check_lion(int t) {
    for (int i = 1; i <= b_warrior_num; i++) {
        if (blue_warrior[i].catagory == 4 && blue_warrior[i].loyalty <= 0 && blue_warrior[i].pd_if_live == 1) {
            blue_warrior[i].pd_if_live = 0;
            city[blue_warrior[i].walk_city][1] = 0;
            output(t);
            cout << "blue lion " << blue_warrior[i].id << " ran away" << endl;
        }
    }
}
void r_move(int t) {
    for (int i = 1; i <= r_warrior_num; i++) {
        if (!red_warrior[i].pd_if_live) continue;
        if (red_warrior[i].catagory == 3) {
            int temp = red_warrior[i].bloo / 10;
            red_warrior[i].bloo -= temp;
            if (red_warrior[i].bloo <= 0) {
                red_warrior[i].pd_if_live = 0;
                city[red_warrior[i].walk_city][0] = 0;
                continue;
            }
        }
        city[red_warrior[i].walk_city][0] = 0;
        red_warrior[i].walk_city++;
        city[red_warrior[i].walk_city][0] = i;
        if (red_warrior[i].catagory == 4) {
            red_warrior[i].loyalty -= k;
        }
    }
}
void b_move(int t) {
    for (int i = 1; i <= b_warrior_num; i++) {
        if (!blue_warrior[i].pd_if_live) continue;
        if (blue_warrior[i].catagory == 3) {
            int temp = blue_warrior[i].bloo / 10;
            blue_warrior[i].bloo -= temp;
            if (blue_warrior[i].bloo <= 0) {
                blue_warrior[i].pd_if_live = 0;
                city[blue_warrior[i].walk_city][1] = 0;
                continue;
            }
        }
        city[blue_warrior[i].walk_city][1] = 0;
        blue_warrior[i].walk_city--;
        city[blue_warrior[i].walk_city][1] = i;
        if (blue_warrior[i].catagory == 4) {
            blue_warrior[i].loyalty -= k;
        }
    }
}
void move_output(int t) {
    if (city[0][1]) {
        output(t);
        int k = city[0][1];
        cout << "blue " << q[blue_warrior[k].catagory].s << ' ' << blue_warrior[k].id;
        cout << " reached red headquarter with " << blue_warrior[k].bloo;
        cout << " elements and force " << blue_warrior[k].atta << endl;
        output(t);
        cout << "red headquarter was taken" << endl;
        bwin = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (city[i][0]) {
            int k = city[i][0];
            if (red_warrior[k].pd_if_live) {
                output(t);
                cout << "red " << q[red_warrior[k].catagory].s << ' ' << red_warrior[k].id;
                cout << " marched to city " << i << ' ' << "with " << red_warrior[k].bloo;
                cout << " elements and force " << red_warrior[k].atta << endl;
            }
        }
        if (city[i][1]) {
            int k = city[i][1];
            if (blue_warrior[k].pd_if_live) {
                output(t);
                cout << "blue " << q[blue_warrior[k].catagory].s << ' ' << blue_warrior[k].id;
                cout << " marched to city " << i << ' ' << "with " << blue_warrior[k].bloo;
                cout << " elements and force " << blue_warrior[k].atta << endl;
            }
        }
    }
    if (city[n + 1][0]) {
        output(t);
        int k = city[n + 1][0];
        cout << "red " << q[red_warrior[k].catagory].s << ' ' << red_warrior[k].id;
        cout << " reached blue headquarter with " << red_warrior[k].bloo;
        cout << " elements and force " << red_warrior[k].atta << endl;
        output(t);
        cout << "blue headquarter was taken" << endl;
        rwin = 1;
    }
    return;
}
void r_steal(int x, int y, int city, int t) {
    int res = 10 - red_warrior[x].cnt_total_weapon;
    int steal = 0;
    if (blue_warrior[y].cnt_sword != 0) {
        if (res >= blue_warrior[y].cnt_sword) {
            steal = blue_warrior[y].cnt_sword;
            red_warrior[x].cnt_sword += blue_warrior[y].cnt_sword;
            red_warrior[x].cnt_total_weapon += blue_warrior[y].cnt_sword;
            blue_warrior[y].cnt_total_weapon -= blue_warrior[y].cnt_sword;
            blue_warrior[y].cnt_sword = 0;
        } else {
            red_warrior[x].cnt_sword += res;
            red_warrior[x].cnt_total_weapon += res;
            blue_warrior[y].cnt_sword -= res;
            blue_warrior[y].cnt_total_weapon -= res;
            steal = res;
        }
        output(t);
        cout << "red wolf " << red_warrior[x].id << " took " << steal << " sword from blue ";
        cout << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id << " in city " << city << endl;
        return;
    } else if (blue_warrior[y].cnt_bomb != 0) {
        if (res >= blue_warrior[y].cnt_bomb) {
            steal = blue_warrior[y].cnt_bomb;
            red_warrior[x].cnt_bomb += blue_warrior[y].cnt_bomb;
            red_warrior[x].cnt_total_weapon += blue_warrior[y].cnt_bomb;
            blue_warrior[y].cnt_total_weapon -= blue_warrior[y].cnt_bomb;
            blue_warrior[y].cnt_bomb = 0;
        } else {
            red_warrior[x].cnt_bomb += res;
            red_warrior[x].cnt_total_weapon += res;
            blue_warrior[y].cnt_bomb -= res;
            blue_warrior[y].cnt_total_weapon -= res;
            steal = res;
        }
        output(t);
        cout << "red wolf " << red_warrior[x].id << " took " << steal << " bomb from blue ";
        cout << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id << " in city " << city << endl;
        return;
    } else if (blue_warrior[y].cnt_arrow != 0) {
        if (res <= blue_warrior[y].cnt_never_used_arrow) {
            red_warrior[x].cnt_never_used_arrow += res;
            red_warrior[x].cnt_arrow += res;
            red_warrior[x].cnt_total_weapon += res;
            blue_warrior[y].cnt_never_used_arrow -= res;
            blue_warrior[y].cnt_arrow -= res;
            blue_warrior[y].cnt_total_weapon -= res;
            steal = res;
        } else if (res > blue_warrior[y].cnt_never_used_arrow && res <= blue_warrior[y].cnt_arrow) {
            red_warrior[x].cnt_never_used_arrow += blue_warrior[y].cnt_never_used_arrow;
            red_warrior[x].cnt_used_arrow += res - blue_warrior[y].cnt_never_used_arrow;
            red_warrior[x].cnt_arrow += res;
            red_warrior[x].cnt_total_weapon += res;
            blue_warrior[y].cnt_arrow -= res;
            blue_warrior[y].cnt_used_arrow -= res - blue_warrior[y].cnt_never_used_arrow;
            blue_warrior[y].cnt_never_used_arrow = 0;
            blue_warrior[y].cnt_total_weapon -= res;
            steal = res;
        } else if (res > blue_warrior[y].cnt_arrow) {
            steal = blue_warrior[y].cnt_arrow;
            red_warrior[x].cnt_arrow += blue_warrior[y].cnt_arrow;
            red_warrior[x].cnt_never_used_arrow += blue_warrior[y].cnt_never_used_arrow;
            red_warrior[x].cnt_used_arrow += blue_warrior[y].cnt_used_arrow;
            red_warrior[x].cnt_total_weapon += blue_warrior[y].cnt_arrow;
            blue_warrior[y].cnt_never_used_arrow = 0;
            blue_warrior[y].cnt_used_arrow = 0;
            blue_warrior[y].cnt_total_weapon -= blue_warrior[y].cnt_arrow;
            blue_warrior[y].cnt_arrow = 0;
        }
        output(t);
        cout << "red wolf " << red_warrior[x].id << " took " << steal << " arrow from blue ";
        cout << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id << " in city " << city << endl;
        return;
    }
}
void b_steal(int x, int y, int city, int t) {
    int res = 10 - blue_warrior[x].cnt_total_weapon;
    int steal = 0;
    if (red_warrior[y].cnt_sword != 0) {
        if (res >= red_warrior[y].cnt_sword) {
            steal = red_warrior[y].cnt_sword;
            blue_warrior[x].cnt_sword += red_warrior[y].cnt_sword;
            blue_warrior[x].cnt_total_weapon += red_warrior[y].cnt_sword;
            red_warrior[y].cnt_total_weapon -= red_warrior[y].cnt_sword;
            red_warrior[y].cnt_sword = 0;
        } else {
            blue_warrior[x].cnt_sword += res;
            blue_warrior[x].cnt_total_weapon += res;
            red_warrior[y].cnt_sword -= res;
            red_warrior[y].cnt_total_weapon -= res;
            steal = res;
        }
        output(t);
        cout << "blue wolf " << blue_warrior[x].id << " took " << steal << " sword from red ";
        cout << q[red_warrior[y].catagory].s << ' ' << red_warrior[y].id << " in city " << city << endl;
        return;
    } else if (red_warrior[y].cnt_bomb != 0) {
        if (res >= red_warrior[y].cnt_bomb) {
            steal = red_warrior[y].cnt_bomb;
            blue_warrior[x].cnt_bomb += red_warrior[y].cnt_bomb;
            blue_warrior[x].cnt_total_weapon += red_warrior[y].cnt_bomb;
            red_warrior[y].cnt_total_weapon -= red_warrior[y].cnt_bomb;
            red_warrior[y].cnt_bomb = 0;
        } else {
            blue_warrior[x].cnt_bomb += res;
            blue_warrior[x].cnt_total_weapon += res;
            red_warrior[y].cnt_bomb -= res;
            red_warrior[y].cnt_total_weapon -= res;
            steal = res;
        }
        output(t);
        cout << "blue wolf " << blue_warrior[x].id << " took " << steal << " bomb from red ";
        cout << q[red_warrior[y].catagory].s << ' ' << red_warrior[y].id << " in city " << city << endl;
        return;
    } else if (blue_warrior[y].cnt_arrow != 0) {
        if (res <= red_warrior[y].cnt_never_used_arrow) {
            blue_warrior[x].cnt_never_used_arrow += res;
            blue_warrior[x].cnt_arrow += res;
            blue_warrior[x].cnt_total_weapon += res;
            red_warrior[y].cnt_never_used_arrow -= res;
            red_warrior[y].cnt_arrow -= res;
            red_warrior[y].cnt_total_weapon -= res;
            steal = res;
        } else if (res > red_warrior[y].cnt_never_used_arrow && res <= red_warrior[y].cnt_arrow) {
            blue_warrior[x].cnt_never_used_arrow += red_warrior[y].cnt_never_used_arrow;
            blue_warrior[x].cnt_used_arrow += res - red_warrior[y].cnt_never_used_arrow;
            blue_warrior[x].cnt_arrow += res;
            blue_warrior[x].cnt_total_weapon += res;
            red_warrior[y].cnt_arrow -= res;
            red_warrior[y].cnt_used_arrow -= res - red_warrior[y].cnt_never_used_arrow;
            red_warrior[y].cnt_never_used_arrow = 0;
            red_warrior[y].cnt_total_weapon -= res;
            steal = res;
        } else if (res > red_warrior[y].cnt_arrow) {
            steal = red_warrior[y].cnt_arrow;
            blue_warrior[x].cnt_arrow += red_warrior[y].cnt_arrow;
            blue_warrior[x].cnt_never_used_arrow += red_warrior[y].cnt_never_used_arrow;
            blue_warrior[x].cnt_used_arrow += red_warrior[y].cnt_used_arrow;
            blue_warrior[x].cnt_total_weapon += red_warrior[y].cnt_arrow;
            red_warrior[y].cnt_never_used_arrow = 0;
            red_warrior[y].cnt_used_arrow = 0;
            red_warrior[y].cnt_total_weapon -= red_warrior[y].cnt_arrow;
            red_warrior[y].cnt_arrow = 0;
        }
        output(t);
        cout << "blue wolf " << blue_warrior[x].id << " took " << steal << " arrow from red ";
        cout << q[red_warrior[y].catagory].s << ' ' << red_warrior[y].id << " in city " << city << endl;
        return;
    }
}
void wolf_try_to_steal(int t) {
    for (int i = 1; i <= n; i++) {
        if (!(city[i][0] && city[i][1])) continue;
        int x = city[i][0], y = city[i][1];
        if (red_warrior[x].catagory == 5 && blue_warrior[y].catagory == 5) continue;
        if (red_warrior[x].catagory == 5) {
            r_steal(x, y, i, t);
        } else if (blue_warrior[y].catagory == 5) {
            b_steal(y, x, i, t);
        }
    }
}
void r_announce_blood(int t) {
    output(t);
    cout << rm << " elements in red headquarter" << endl;
}
void b_announce_blood(int t) {
    output(t);
    cout << bm << " elements in blue headquarter" << endl;
}
void output_warrior(int t) {
    for (int i = 1; i <= n; i++) {
        if (city[i][0]) {
            int k = city[i][0];
            if (red_warrior[k].pd_if_live) {
                output(t);
                cout << "red " << q[red_warrior[k].catagory].s << ' ' << red_warrior[k].id << " has ";
                cout << red_warrior[k].cnt_sword << " sword ";
                cout << red_warrior[k].cnt_bomb << " bomb ";
                cout << red_warrior[k].cnt_arrow << " arrow and ";
                cout << red_warrior[k].bloo << " elements" << endl;
            }
        }
        if (city[i][1]) {
            int k = city[i][1];
            if (blue_warrior[k].pd_if_live) {
                output(t);
                cout << "blue " << q[blue_warrior[k].catagory].s << ' ' << blue_warrior[k].id << " has ";
                cout << blue_warrior[k].cnt_sword << " sword ";
                cout << blue_warrior[k].cnt_bomb << " bomb ";
                cout << blue_warrior[k].cnt_arrow << " arrow and ";
                cout << blue_warrior[k].bloo << " elements" << endl;
            }
        }
    }
}
void red_sword_attack(int x, int y, int number) {
    int temp = red_warrior[x].atta * 2 / 10;
    blue_warrior[y].bloo -= temp;
}
void red_bomb_attack(int x, int y, int number) {
    int temp = red_warrior[x].atta * 4 / 10;
    blue_warrior[y].bloo -= temp;
    if (red_warrior[x].catagory == 2) {
        return;
    } else {
        int tem = temp / 2;
        red_warrior[x].bloo -= tem;
        return;
    }
}
void red_used_arrow_attack(int x, int y, int number) {
    int temp = red_warrior[x].atta * 3 / 10;
    blue_warrior[y].bloo -= temp;
    return;
}
void red_not_used_arrow_attack(int x, int y, int number) {
    int temp = red_warrior[x].atta * 3 / 10;
    blue_warrior[y].bloo -= temp;
    return;
}
void blue_sword_attack(int x, int y, int number) {
    int temp = blue_warrior[x].atta * 2 / 10;
    red_warrior[y].bloo -= temp;
}
void blue_bomb_attack(int x, int y, int number) {
    int temp = blue_warrior[x].atta * 4 / 10;
    red_warrior[y].bloo -= temp;
    if (blue_warrior[x].catagory == 2) {
        return;
    } else {
        int tem = temp / 2;
        blue_warrior[x].bloo -= tem;
        return;
    }
}
void blue_used_arrow_attack(int x, int y, int number) {
    int temp = blue_warrior[x].atta * 3 / 10;
    red_warrior[y].bloo -= temp;
    return;
}
void blue_not_used_arrow_attack(int x, int y, int number) {
    int temp = blue_warrior[x].atta * 3 / 10;
    red_warrior[y].bloo -= temp;
    return;
}
void r_trans(int x, int number) {
    int temp = red_warrior[x].weapon[number];
    if (temp == 1)
        return;
    else if (temp == 2)
        red_warrior[x].weapon[number] = 0;
    else if (temp == 3)
        red_warrior[x].weapon[number] = 0;
    else if (temp == 4)
        red_warrior[x].weapon[number] = 3;
}
void b_trans(int x, int number) {
    int temp = blue_warrior[x].weapon[number];
    if (temp == 1)
        return;
    else if (temp == 2)
        blue_warrior[x].weapon[number] = 0;
    else if (temp == 3)
        blue_warrior[x].weapon[number] = 0;
    else if (temp == 4)
        blue_warrior[x].weapon[number] = 3;
}
void update(int x, int pd) {
    if (pd == 0) {
        int temp = 0;
        red_warrior[x].cnt_sword = 0;
        red_warrior[x].cnt_bomb = 0;
        red_warrior[x].cnt_never_used_arrow = 0;
        red_warrior[x].cnt_used_arrow = 0;
        red_warrior[x].cnt_arrow = 0;
        for (int i = 1; i <= red_warrior[x].cnt_total_weapon; i++) {
            if (!red_warrior[x].weapon[i])
                continue;
            else if (red_warrior[x].weapon[i] == 1) {
                temp++;
                red_warrior[x].cnt_sword++;
            } else if (red_warrior[x].weapon[i] == 2) {
                temp++;
                red_warrior[x].cnt_bomb++;
            } else if (red_warrior[x].weapon[i] == 3) {
                temp++;
                red_warrior[x].cnt_used_arrow++;
                red_warrior[x].cnt_arrow++;
            } else if (red_warrior[x].weapon[i] == 4) {
                temp++;
                red_warrior[x].cnt_never_used_arrow++;
                red_warrior[x].cnt_arrow++;
            }
        }
        red_warrior[x].cnt_total_weapon = temp;
        return;
    } else if (pd == 1) {
        int temp = 0;
        blue_warrior[x].cnt_sword = 0;
        blue_warrior[x].cnt_bomb = 0;
        blue_warrior[x].cnt_never_used_arrow = 0;
        blue_warrior[x].cnt_used_arrow = 0;
        blue_warrior[x].cnt_arrow = 0;
        for (int i = 1; i <= blue_warrior[x].cnt_total_weapon; i++) {
            if (!blue_warrior[x].weapon[i])
                continue;
            else if (blue_warrior[x].weapon[i] == 1) {
                temp++;
                blue_warrior[x].cnt_sword++;
            } else if (blue_warrior[x].weapon[i] == 2) {
                temp++;
                blue_warrior[x].cnt_bomb++;
            } else if (blue_warrior[x].weapon[i] == 3) {
                temp++;
                blue_warrior[x].cnt_used_arrow++;
                blue_warrior[x].cnt_arrow++;
            } else if (blue_warrior[x].weapon[i] == 4) {
                temp++;
                blue_warrior[x].cnt_never_used_arrow++;
                blue_warrior[x].cnt_arrow++;
            }
        }
        blue_warrior[x].cnt_total_weapon = temp;
        return;
    }
}
void get(int x, int y, int pd) {
    if (pd == 1) {
        int res = 10 - blue_warrior[x].cnt_total_weapon;
        if (res <= red_warrior[y].cnt_sword) {
            blue_warrior[x].cnt_total_weapon += res;
            blue_warrior[x].cnt_sword += res;
            return;
        } else if (res > red_warrior[y].cnt_sword && res <= red_warrior[y].cnt_sword + red_warrior[y].cnt_bomb) {
            blue_warrior[x].cnt_total_weapon += res;
            blue_warrior[x].cnt_sword += red_warrior[y].cnt_sword;
            blue_warrior[x].cnt_bomb += res - red_warrior[y].cnt_sword;
            return;
        } else if (res > red_warrior[y].cnt_sword + red_warrior[y].cnt_bomb &&
                   res <= red_warrior[y].cnt_sword + red_warrior[y].cnt_bomb + red_warrior[y].cnt_never_used_arrow) {
            blue_warrior[x].cnt_sword += red_warrior[y].cnt_sword;
            blue_warrior[x].cnt_bomb += red_warrior[y].cnt_bomb;
            blue_warrior[x].cnt_never_used_arrow += res - red_warrior[y].cnt_sword - red_warrior[y].cnt_bomb;
            blue_warrior[x].cnt_arrow += res - red_warrior[y].cnt_sword - red_warrior[y].cnt_bomb;
            blue_warrior[x].cnt_total_weapon += res;
            return;
        } else if (res > red_warrior[y].cnt_sword + red_warrior[y].cnt_bomb + red_warrior[y].cnt_never_used_arrow &&
                   res <= red_warrior[y].cnt_total_weapon) {
            blue_warrior[x].cnt_total_weapon += res;
            blue_warrior[x].cnt_sword += red_warrior[y].cnt_sword;
            blue_warrior[x].cnt_bomb += red_warrior[y].cnt_bomb;
            blue_warrior[x].cnt_never_used_arrow += red_warrior[y].cnt_never_used_arrow;
            blue_warrior[x].cnt_used_arrow +=
                res - red_warrior[y].cnt_sword - red_warrior[y].cnt_bomb - red_warrior[y].cnt_never_used_arrow;
            blue_warrior[x].cnt_arrow += res - red_warrior[y].cnt_sword - red_warrior[y].cnt_bomb;
            return;
        } else if (res > red_warrior[y].cnt_total_weapon) {
            blue_warrior[x].cnt_total_weapon += red_warrior[y].cnt_total_weapon;
            blue_warrior[x].cnt_sword += red_warrior[y].cnt_sword;
            blue_warrior[x].cnt_bomb += red_warrior[y].cnt_bomb;
            blue_warrior[x].cnt_never_used_arrow += red_warrior[y].cnt_never_used_arrow;
            blue_warrior[x].cnt_used_arrow += red_warrior[y].cnt_used_arrow;
            blue_warrior[x].cnt_arrow += red_warrior[y].cnt_arrow;
            return;
        }
    } else if (pd == 0) {
        int res = 10 - red_warrior[x].cnt_total_weapon;
        if (res <= blue_warrior[y].cnt_sword) {
            red_warrior[x].cnt_total_weapon += res;
            red_warrior[x].cnt_sword += res;
            return;
        } else if (res > blue_warrior[y].cnt_sword && res <= blue_warrior[y].cnt_sword + blue_warrior[y].cnt_bomb) {
            red_warrior[x].cnt_total_weapon += res;
            red_warrior[x].cnt_sword += blue_warrior[y].cnt_sword;
            red_warrior[x].cnt_bomb += res - blue_warrior[y].cnt_sword;
            return;
        } else if (res > blue_warrior[y].cnt_sword + blue_warrior[y].cnt_bomb &&
                   res <= blue_warrior[y].cnt_sword + blue_warrior[y].cnt_bomb + blue_warrior[y].cnt_never_used_arrow) {
            red_warrior[x].cnt_sword += blue_warrior[y].cnt_sword;
            red_warrior[x].cnt_bomb += blue_warrior[y].cnt_bomb;
            red_warrior[x].cnt_never_used_arrow += res - blue_warrior[y].cnt_sword - blue_warrior[y].cnt_bomb;
            red_warrior[x].cnt_arrow += res - blue_warrior[y].cnt_sword - blue_warrior[y].cnt_bomb;
            red_warrior[x].cnt_total_weapon += res;
            return;
        } else if (res > blue_warrior[y].cnt_sword + blue_warrior[y].cnt_bomb + blue_warrior[y].cnt_never_used_arrow &&
                   res <= blue_warrior[y].cnt_total_weapon) {
            red_warrior[x].cnt_total_weapon += res;
            red_warrior[x].cnt_sword += blue_warrior[y].cnt_sword;
            red_warrior[x].cnt_bomb += blue_warrior[y].cnt_bomb;
            red_warrior[x].cnt_never_used_arrow += blue_warrior[y].cnt_never_used_arrow;
            red_warrior[x].cnt_used_arrow +=
                res - blue_warrior[y].cnt_sword - blue_warrior[y].cnt_bomb - blue_warrior[y].cnt_never_used_arrow;
            red_warrior[x].cnt_arrow += res - blue_warrior[y].cnt_sword - blue_warrior[y].cnt_bomb;
            return;
        } else if (res > blue_warrior[y].cnt_total_weapon) {
            red_warrior[x].cnt_total_weapon += blue_warrior[y].cnt_total_weapon;
            red_warrior[x].cnt_sword += blue_warrior[y].cnt_sword;
            red_warrior[x].cnt_bomb += blue_warrior[y].cnt_bomb;
            red_warrior[x].cnt_never_used_arrow += blue_warrior[y].cnt_never_used_arrow;
            red_warrior[x].cnt_used_arrow += blue_warrior[y].cnt_used_arrow;
            red_warrior[x].cnt_arrow += blue_warrior[y].cnt_arrow;
            return;
        }
    }
}
bool r_check_attack(int x) {
    bool f = true;
    for (int i = 1; i <= red_warrior[x].cnt_total_weapon; i++) {
        int temp = 0;
        if (red_warrior[x].weapon[i] == 1)
            temp = red_warrior[x].atta * 2 / 10;
        else if (red_warrior[x].weapon[i] == 2)
            temp = red_warrior[x].atta * 4 / 10;
        else if (red_warrior[x].weapon[i] == 3 || red_warrior[x].weapon[i] == 4)
            temp = red_warrior[x].atta * 3 / 10;
        if (temp > 0) {
            f = false;
            break;
        }
    }
    return f;
}
bool b_check_attack(int x) {
    bool f = true;
    for (int i = 1; i <= blue_warrior[x].cnt_total_weapon; i++) {
        int temp = 0;
        if (blue_warrior[x].weapon[i] == 1)
            temp = blue_warrior[x].atta * 2 / 10;
        else if (blue_warrior[x].weapon[i] == 2)
            temp = blue_warrior[x].atta * 4 / 10;
        else if (blue_warrior[x].weapon[i] == 3 || blue_warrior[x].weapon[i] == 4)
            temp = blue_warrior[x].atta * 3 / 10;
        if (temp > 0) {
            f = false;
            break;
        }
    }
    return f;
}
bool r_check_if_only_sword(int x) {
    bool f = true;
    int k = 0;
    for (int i = 1; i <= red_warrior[x].cnt_total_weapon; i++) {
        if (red_warrior[x].weapon[i] == 1)
            k++;
        else if (red_warrior[x].weapon[i] == 2 || red_warrior[x].weapon[i] == 3 || red_warrior[x].weapon[i] == 4) {
            f = false;
            break;
        }
    }
    return f;
}
bool b_check_if_only_sword(int x) {
    bool f = true;
    int k = 0;
    for (int i = 1; i <= blue_warrior[x].cnt_total_weapon; i++) {
        if (blue_warrior[x].weapon[i] == 1)
            k++;
        else if (blue_warrior[x].weapon[i] == 2 || blue_warrior[x].weapon[i] == 3 || blue_warrior[x].weapon[i] == 4) {
            f = false;
            break;
        }
    }
    return f;
}  // 这两个函数的意义是防止有哑弹/哑箭就跳出 因此要检验这两种情况 1.无哑弹哑箭 2.只有剑？
void actual_fight(int x, int y, int c, int t, int pd) {
    int flag;
    if (pd == 1)
        flag = 1;
    else
        flag = 0;
    int red_weapon = 1, blue_weapon = 1;  // 红蓝方目前使用的武器
    int rfight = 1, bfight = 1;           // 表示是否有战斗能力
    int rpd = 0, bpd = 0;
    memset(red_warrior[x].weapon, 0, sizeof(red_warrior[x].weapon));
    memset(blue_warrior[y].weapon, 0, sizeof(blue_warrior[y].weapon));
    for (int i = 1; i <= red_warrior[x].cnt_total_weapon; i++) {
        if (i >= 1 && i <= red_warrior[x].cnt_sword)
            red_warrior[x].weapon[i] = 1;
        else if (i > red_warrior[x].cnt_sword && i <= red_warrior[x].cnt_sword + red_warrior[x].cnt_bomb) {
            red_warrior[x].weapon[i] = 2;
        } else if (i > red_warrior[x].cnt_sword + red_warrior[x].cnt_bomb &&
                   i <= red_warrior[x].cnt_total_weapon - red_warrior[x].cnt_never_used_arrow) {
            red_warrior[x].weapon[i] = 3;
        } else {
            red_warrior[x].weapon[i] = 4;
        }
    }
    for (int i = 1; i <= blue_warrior[y].cnt_total_weapon; i++) {
        if (i >= 1 && i <= blue_warrior[y].cnt_sword)
            blue_warrior[y].weapon[i] = 1;
        else if (i > blue_warrior[y].cnt_sword && i <= blue_warrior[y].cnt_sword + blue_warrior[y].cnt_bomb) {
            blue_warrior[y].weapon[i] = 2;
        } else if (i > blue_warrior[y].cnt_sword + blue_warrior[y].cnt_bomb &&
                   i <= blue_warrior[y].cnt_total_weapon - blue_warrior[y].cnt_never_used_arrow) {
            blue_warrior[y].weapon[i] = 3;
        } else {
            blue_warrior[y].weapon[i] = 4;
        }
    }
    while (1) {
        if (r_check_attack(x) && rfight == 1 && r_check_if_only_sword(x)) rfight = 0;
        if (b_check_attack(y) && bfight == 1 && b_check_if_only_sword(y)) bfight = 0;
        if (rfight == 0 && bfight == 0) break;
        if (flag == 1) {
            if (rfight) {
                for (int i = 0; i <= red_warrior[x].cnt_total_weapon - 1; i++) {
                    if (rpd == 0 && i == 0) {
                        rpd = 1;
                        int temp = red_weapon + i;
                        temp = (temp - 1) % red_warrior[x].cnt_total_weapon + 1;
                        if (red_warrior[x].weapon[temp]) {
                            red_weapon = temp;
                            break;
                        }
                    }
                    if (rpd == 1 && i == 0) continue;
                    int temp = red_weapon + i;
                    temp = (temp - 1) % red_warrior[x].cnt_total_weapon + 1;
                    if (red_warrior[x].weapon[temp]) {
                        red_weapon = temp;
                        break;
                    }
                }
                if (red_warrior[x].weapon[red_weapon] == 1)
                    red_sword_attack(x, y, red_weapon);
                else if (red_warrior[x].weapon[red_weapon] == 2)
                    red_bomb_attack(x, y, red_weapon);
                else if (red_warrior[x].weapon[red_weapon] == 3)
                    red_used_arrow_attack(x, y, red_weapon);
                else if (red_warrior[x].weapon[red_weapon] == 4)
                    red_not_used_arrow_attack(x, y, red_weapon);
                r_trans(x, red_weapon);
            }
        } else if (flag == 0) {
            if (bfight) {
                for (int i = 0; i <= blue_warrior[y].cnt_total_weapon - 1; i++) {
                    if (bpd == 0 && i == 0) {
                        bpd = 1;
                        int temp = blue_weapon + i;
                        temp = (temp - 1) % blue_warrior[y].cnt_total_weapon + 1;
                        if (blue_warrior[y].weapon[temp]) {
                            blue_weapon = temp;
                            break;
                        }
                    }
                    if (bpd == 1 && i == 0) continue;
                    int temp = blue_weapon + i;
                    temp = (temp - 1) % blue_warrior[y].cnt_total_weapon + 1;
                    if (blue_warrior[y].weapon[temp]) {
                        blue_weapon = temp;
                        break;
                    }
                }
                if (blue_warrior[y].weapon[blue_weapon] == 1)
                    blue_sword_attack(y, x, blue_weapon);
                else if (blue_warrior[y].weapon[blue_weapon] == 2)
                    blue_bomb_attack(y, x, blue_weapon);
                else if (blue_warrior[y].weapon[blue_weapon] == 3)
                    blue_used_arrow_attack(y, x, blue_weapon);
                else if (blue_warrior[y].weapon[blue_weapon] == 4)
                    blue_not_used_arrow_attack(y, x, blue_weapon);
                b_trans(y, blue_weapon);
            }
        }
        if (flag == 1)
            flag = 0;
        else if (flag == 0)
            flag = 1;
        if (red_warrior[x].bloo <= 0 || blue_warrior[y].bloo <= 0) break;
    }
    if (red_warrior[x].bloo <= 0 && blue_warrior[y].bloo <= 0) {
        red_warrior[x].pd_if_live = 0;
        blue_warrior[y].pd_if_live = 0;
        city[c][0] = 0;
        city[c][1] = 0;
        output(t);
        cout << "both red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id << ' ';
        cout << "and blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id;
        cout << " died in city " << c << endl;
        return;
    } else if (red_warrior[x].bloo <= 0) {
        red_warrior[x].pd_if_live = 0;
        city[c][0] = 0;
        update(x, 0);
        update(y, 1);
        get(y, x, 1);
        output(t);
        cout << "blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id;
        cout << " killed red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id;
        cout << " in city " << c << " remaining " << blue_warrior[y].bloo << " elements" << endl;
    } else if (blue_warrior[y].bloo <= 0) {
        blue_warrior[y].pd_if_live = 0;
        city[c][1] = 0;
        update(x, 0);
        update(y, 1);
        get(x, y, 0);
        output(t);
        cout << "red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id;
        cout << " killed blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id;
        cout << " in city " << c << " remaining " << red_warrior[x].bloo << " elements" << endl;
        return;
    } else if (red_warrior[x].bloo > 0 && blue_warrior[y].bloo > 0) {
        output(t);
        update(x, 0);
        update(y, 1);
        cout << "both red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id;
        cout << " and blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id;
        cout << " were alive in city " << c << endl;
        return;
    }
}
void red_yell(int x, int city, int t) {
    output(t);
    cout << "red dragon " << red_warrior[x].id << " yelled in city " << city << endl;
}
void blue_yell(int x, int city, int t) {
    output(t);
    cout << "blue dragon " << blue_warrior[x].id << " yelled in city " << city << endl;
}
void fight(int t) {
    for (int i = 1; i <= n; i++) {
        if (!(city[i][1] && city[i][0])) continue;
        int x = city[i][0], y = city[i][1];
        if (i % 2 == 1) {
            actual_fight(x, y, i, t, 1);
        }
        if (i % 2 == 0) {
            actual_fight(x, y, i, t, 0);
        }
        if (red_warrior[x].catagory == 1 && red_warrior[x].pd_if_live == 1) {
            red_yell(x, i, t);
        }
        if (blue_warrior[y].catagory == 1 && blue_warrior[y].pd_if_live == 1) {
            blue_yell(y, i, t);
        }
    }
}
int main() {
    scanf("%d", &z);
    for (int v = 1; v <= z; v++) {
        scanf("%d%d%d%d", &m, &n, &k, &t);
        rm = m, bm = m;
        tim = 0;
        rflag = 0, bflag = 0;
        rcnt = 0, bcnt = 0;
        rwin = 0, bwin = 0;
        memset(rnum, 0, sizeof(rnum));
        memset(bnum, 0, sizeof(bnum));
        memset(red_warrior, 0, sizeof(red_warrior));
        memset(blue_warrior, 0, sizeof(blue_warrior));
        memset(city, 0, sizeof(city));
        r_warrior_num = 0, b_warrior_num = 0;
        city[0][0] = 1;
        city[n + 1][1] = 1;
        proces = 0;
        for (int i = 1; i <= 5; i++) {
            scanf("%d", &q[i].bloo);
        }
        for (int i = 1; i <= 5; i++) {
            scanf("%d", &q[i].atta);
        }
        printf("Case %d:\n", v);
        q[1].s = "dragon", q[2].s = "ninja", q[3].s = "iceman", q[4].s = "lion", q[5].s = "wolf";
        for (int i = 0; i <= 10005; i++) {
            if (tim > t) break;
            if (tim % 60 == 0) {
                rcnt++;
                bcnt++;
                rcnt = (rcnt - 1) % 5 + 1;
                bcnt = (bcnt - 1) % 5 + 1;
                if (rflag == 0) r_birth();
                if (bflag == 0) b_birth();
            }
            if (tim % 60 == 5) {
                r_check_lion(tim);
                b_check_lion(tim);
            }
            if (tim % 60 == 10) {
                r_move(tim);
                b_move(tim);
                move_output(tim);
                if (rwin || bwin) break;
            }
            if (tim % 60 == 35) {
                wolf_try_to_steal(tim);
            }
            if (tim % 60 == 40) {
                fight(tim);
            }
            if (tim % 60 == 50) {
                r_announce_blood(tim);
                b_announce_blood(tim);
            }
            if (tim % 60 == 55) {
                output_warrior(tim);
            }
            proces++;
            proces = (proces - 1) % 7 + 1;
            tim += step[proces];
        }
    }
    system("pause");
    return 0;
}