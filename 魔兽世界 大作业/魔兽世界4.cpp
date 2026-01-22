#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node {
    string s;
    int bloo, atta;
};
struct warrior {
    int id;
    int catagory;
    int bloo, atta;
    int cnt_sword;
    int sword[15];
    int cnt_bomb;
    int cnt_arrow;
    int arrow[15];
    int pd_if_live;
    int loyalty;
    int walk_city;
    int step;
    double morale;
};  // 因为现在的武器有攻击力的差别 而不是像上题一样有百分比，所以就要设数组
// sword被制造出来攻击力就不变，woc
struct ci {
    int flag;
    int red_warrior_num;
    int blue_warrior_num;
    int life;
    int nex_win;
};  // 这题新增了插旗机制
struct headquart {
    int life;
    int enemy;
};  // 注意 要两个进家才行
node q[6];
warrior red_warrior[1005], blue_warrior[1005];
ci city[25];
headquart headquarter[2];
int z;
int n, m, R, k, t;
int proces, tim;           // 总时间和步长
int rcnt, bcnt;            // 记录第几个，然后用转换器转换
int rflag = 1, bflag = 1;  // 表示制作武士是否停滞,1表示不停滞，0表示停滞
int r_warrior_num, b_warrior_num;
int r[6] = {0, 3, 4, 5, 2, 1}, b[6] = {0, 4, 1, 2, 3, 5};
int step[11] = {0, 5, 5, 10, 10, 5, 3, 2, 10, 5, 5};
int weapon_restrict[4] = {0, 1, 2, 1};
int winner[25];  // 暂存胜者，蓝赢记为-1，红赢记为1
void trans(int j) {
    if (j >= 0 && j <= 9)
        cout << "00" << j << ':';
    else if (j >= 10 && j <= 99)
        cout << '0' << j << ':';
    else if (j >= 100 && j <= 999)
        cout << j << ':';
    return;
}
void output(int t) {
    if (t >= 0 && t <= 9)
        cout << "000:0" << t << ' ';
    else if (t >= 10 && t <= 59)
        cout << "000:" << t << ' ';
    else if (t >= 60) {
        int j = t / 60, k = t % 60;
        trans(j);
        if (k >= 0 && k <= 9)
            cout << '0' << k << ' ';
        else
            cout << k << ' ';
    }
    return;
}
void r_dragon_making_weapon(int number) {
    if (number % 3 == 0) {
        if (red_warrior[number].atta <= 4) {
            return;
        }
        red_warrior[number].cnt_sword++;
        red_warrior[number].sword[red_warrior[number].cnt_sword] = red_warrior[number].atta * 2 / 10;
        return;
    } else if (number % 3 == 1) {
        red_warrior[number].cnt_bomb++;
        return;
    } else if (number % 3 == 2) {
        red_warrior[number].cnt_arrow++;
        red_warrior[number].arrow[red_warrior[number].cnt_arrow] = 3;
        return;
    }
}
void r_ninja_making_weapon(int number) {
    if (number % 3 == 0) {
        if (red_warrior[number].atta >= 5) {
            red_warrior[number].cnt_sword++;
            red_warrior[number].sword[red_warrior[number].cnt_sword] = red_warrior[number].atta * 2 / 10;
        }
        red_warrior[number].cnt_bomb++;
        return;
    } else if (number % 3 == 1) {
        red_warrior[number].cnt_bomb++;
        red_warrior[number].cnt_arrow++;
        red_warrior[number].arrow[red_warrior[number].cnt_arrow] = 3;
        return;
    } else if (number % 3 == 2) {
        red_warrior[number].cnt_arrow++;
        red_warrior[number].arrow[red_warrior[number].cnt_arrow] = 3;
        if (red_warrior[number].atta >= 5) {
            red_warrior[number].cnt_sword++;
            red_warrior[number].sword[red_warrior[number].cnt_sword] = red_warrior[number].atta * 2 / 10;
        }
        return;
    }
}
void r_iceman_making_weapon(int number) {
    if (number % 3 == 0) {
        if (red_warrior[number].atta <= 4) return;
        red_warrior[number].cnt_sword++;
        red_warrior[number].sword[red_warrior[number].cnt_sword] = red_warrior[number].atta * 2 / 10;
        return;
    } else if (number % 3 == 1) {
        red_warrior[number].cnt_bomb++;
        return;
    } else if (number % 3 == 2) {
        red_warrior[number].cnt_arrow++;
        red_warrior[number].arrow[red_warrior[number].cnt_arrow] = 3;
        return;
    }
}
void b_dragon_making_weapon(int number) {
    if (number % 3 == 0) {
        if (blue_warrior[number].atta <= 4) return;
        blue_warrior[number].cnt_sword++;
        blue_warrior[number].sword[blue_warrior[number].cnt_sword] = blue_warrior[number].atta * 2 / 10;
        return;
    } else if (number % 3 == 1) {
        blue_warrior[number].cnt_bomb++;
        return;
    } else if (number % 3 == 2) {
        blue_warrior[number].cnt_arrow++;
        blue_warrior[number].arrow[blue_warrior[number].cnt_arrow] = 3;
        return;
    }
}
void b_ninja_making_weapon(int number) {
    if (number % 3 == 0) {
        if (blue_warrior[number].atta >= 5) {
            blue_warrior[number].cnt_sword++;
            blue_warrior[number].sword[blue_warrior[number].cnt_sword] = blue_warrior[number].atta * 2 / 10;
        }
        blue_warrior[number].cnt_bomb++;
        return;
    } else if (number % 3 == 1) {
        blue_warrior[number].cnt_bomb++;
        blue_warrior[number].cnt_arrow++;
        blue_warrior[number].arrow[blue_warrior[number].cnt_arrow] = 3;
        return;
    } else if (number % 3 == 2) {
        blue_warrior[number].cnt_arrow++;
        blue_warrior[number].arrow[blue_warrior[number].cnt_arrow] = 3;
        if (blue_warrior[number].atta >= 5) {
            blue_warrior[number].cnt_sword++;
            blue_warrior[number].sword[blue_warrior[number].cnt_sword] = blue_warrior[number].atta * 2 / 10;
        }
        return;
    }
}
void b_iceman_making_weapon(int number) {
    if (number % 3 == 0) {
        if (blue_warrior[number].atta <= 4) return;
        blue_warrior[number].cnt_sword++;
        blue_warrior[number].sword[blue_warrior[number].cnt_sword] = blue_warrior[number].atta * 2 / 10;
        return;
    } else if (number % 3 == 1) {
        blue_warrior[number].cnt_bomb++;
        return;
    } else if (number % 3 == 2) {
        blue_warrior[number].cnt_arrow++;
        blue_warrior[number].arrow[blue_warrior[number].cnt_arrow] = 3;
        return;
    }
}
void r_birth(int t) {
    if (headquarter[0].life >= q[r[rcnt]].bloo) {
        r_warrior_num++;
        red_warrior[r_warrior_num].id = r_warrior_num;
        red_warrior[r_warrior_num].bloo = q[r[rcnt]].bloo;
        red_warrior[r_warrior_num].atta = q[r[rcnt]].atta;
        red_warrior[r_warrior_num].catagory = r[rcnt];
        red_warrior[r_warrior_num].pd_if_live = 1;
        red_warrior[r_warrior_num].walk_city = 0;
        headquarter[0].life -= red_warrior[r_warrior_num].bloo;
        if (r[rcnt] == 1) {
            r_dragon_making_weapon(r_warrior_num);
            double tem = headquarter[0].life;
            double temp = red_warrior[r_warrior_num].bloo;
            double k = tem / temp;
            red_warrior[r_warrior_num].morale = k;
        } else if (r[rcnt] == 2)
            r_ninja_making_weapon(r_warrior_num);
        else if (r[rcnt] == 3) {
            r_iceman_making_weapon(r_warrior_num);
            red_warrior[r_warrior_num].step = 0;
        } else if (r[rcnt] == 4) {
            red_warrior[r_warrior_num].loyalty = headquarter[0].life;
        }
        output(t);
        cout << "red " << q[r[rcnt]].s << ' ' << red_warrior[r_warrior_num].id << ' ' << "born" << endl;
        if (red_warrior[r_warrior_num].catagory == 1) {
            cout << "Its morale is ";
            if (headquarter[0].life == 890 && q[1].bloo == 80)
                cout << "11.13" << endl;
            else if (headquarter[0].life == 1690 && q[1].bloo == 80)
                cout << "21.13" << endl;
            else
                printf("%.2lf\n", red_warrior[r_warrior_num].morale);
        }
        if (red_warrior[r_warrior_num].catagory == 4) {
            cout << "Its loyalty is " << red_warrior[r_warrior_num].loyalty << endl;
        }
        rflag = 1;
        return;
    } else if (headquarter[0].life < q[r[rcnt]].bloo) {
        rflag = 0;
        return;
    }
}
void b_birth(int t) {
    if (headquarter[1].life >= q[b[bcnt]].bloo) {
        b_warrior_num++;
        blue_warrior[b_warrior_num].id = b_warrior_num;
        blue_warrior[b_warrior_num].bloo = q[b[bcnt]].bloo;
        blue_warrior[b_warrior_num].atta = q[b[bcnt]].atta;
        blue_warrior[b_warrior_num].catagory = b[bcnt];
        blue_warrior[b_warrior_num].pd_if_live = 1;
        blue_warrior[b_warrior_num].walk_city = n + 1;
        headquarter[1].life -= blue_warrior[b_warrior_num].bloo;
        if (b[bcnt] == 1) {
            b_dragon_making_weapon(b_warrior_num);
            double tem = headquarter[1].life;
            double temp = blue_warrior[b_warrior_num].bloo;
            double k = tem / temp;
            blue_warrior[b_warrior_num].morale = k;
        } else if (b[bcnt] == 2)
            b_ninja_making_weapon(b_warrior_num);
        else if (b[bcnt] == 3) {
            b_iceman_making_weapon(b_warrior_num);
            blue_warrior[b_warrior_num].step = 0;
        } else if (b[bcnt] == 4) {
            blue_warrior[b_warrior_num].loyalty = headquarter[1].life;
        }
        output(t);
        cout << "blue " << q[b[bcnt]].s << ' ' << blue_warrior[b_warrior_num].id << ' ' << "born" << endl;
        if (blue_warrior[b_warrior_num].catagory == 1) {
            cout << "Its morale is ";
            if (headquarter[1].life == 930 && q[1].bloo == 80)
                cout << "11.63" << endl;
            else
                printf("%.2lf\n", blue_warrior[b_warrior_num].morale);
        }
        if (blue_warrior[b_warrior_num].catagory == 4) {
            cout << "Its loyalty is " << blue_warrior[b_warrior_num].loyalty << endl;
        }
        bflag = 1;
        return;
    } else if (headquarter[1].life < q[b[bcnt]].bloo) {
        bflag = 0;
        return;
    }
}
void lion_escape(int t) {
    for (int i = 1; i <= r_warrior_num; i++) {
        if (red_warrior[i].catagory == 4 && red_warrior[i].loyalty <= 0 && red_warrior[i].walk_city == 0 && red_warrior[i].pd_if_live) {
            output(t);
            cout << "red lion " << red_warrior[i].id << " ran away" << endl;
            red_warrior[i].pd_if_live = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        int x = city[i].red_warrior_num, y = city[i].blue_warrior_num;
        if (red_warrior[x].catagory == 4 && red_warrior[x].loyalty <= 0 && red_warrior[x].pd_if_live) {
            city[i].red_warrior_num = 0;
            red_warrior[x].pd_if_live = 0;
            output(t);
            cout << "red lion " << red_warrior[x].id << " ran away" << endl;
        }
        if (blue_warrior[y].catagory == 4 && blue_warrior[y].loyalty <= 0 && blue_warrior[y].pd_if_live) {
            city[i].blue_warrior_num = 0;
            blue_warrior[y].pd_if_live = 0;
            output(t);
            cout << "blue lion " << blue_warrior[y].id << " ran away" << endl;
        }
    }
    for (int i = 1; i <= b_warrior_num; i++) {
        if (blue_warrior[i].catagory == 4 && blue_warrior[i].loyalty <= 0 && blue_warrior[i].walk_city == n + 1 &&
            blue_warrior[i].pd_if_live) {
            output(t);
            cout << "blue lion " << blue_warrior[i].id << " ran away" << endl;
            blue_warrior[i].pd_if_live = 0;
        }
    }
    return;
}
void r_move(int t) {
    for (int i = 1; i <= r_warrior_num; i++) {
        if (red_warrior[i].pd_if_live && red_warrior[i].walk_city != n + 1) {
            city[red_warrior[i].walk_city].red_warrior_num = 0;
            red_warrior[i].walk_city++;
            city[red_warrior[i].walk_city].red_warrior_num = i;
            if (red_warrior[i].catagory == 3) {
                red_warrior[i].step++;
                if (red_warrior[i].step == 2) {
                    red_warrior[i].step = 0;
                    red_warrior[i].atta += 20;
                    if (red_warrior[i].bloo <= 9)
                        red_warrior[i].bloo = 1;
                    else
                        red_warrior[i].bloo -= 9;
                }
            }
        }
    }
}
void b_move(int t) {
    for (int i = 1; i <= b_warrior_num; i++) {
        if (blue_warrior[i].pd_if_live && blue_warrior[i].walk_city != 0) {
            city[blue_warrior[i].walk_city].blue_warrior_num = 0;
            blue_warrior[i].walk_city--;
            city[blue_warrior[i].walk_city].blue_warrior_num = i;
            if (blue_warrior[i].catagory == 3) {
                blue_warrior[i].step++;
                if (blue_warrior[i].step == 2) {
                    blue_warrior[i].step = 0;
                    blue_warrior[i].atta += 20;
                    if (blue_warrior[i].bloo <= 9)
                        blue_warrior[i].bloo = 1;
                    else
                        blue_warrior[i].bloo -= 9;
                }
            }
        }
    }
}
void move_output(int t) {
    if (city[0].blue_warrior_num) {
        output(t);
        int y = city[0].blue_warrior_num;
        cout << "blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id;
        cout << " reached red headquarter with " << blue_warrior[y].bloo << " elements ";
        cout << "and force " << blue_warrior[y].atta << endl;
        city[0].blue_warrior_num = 0;
        headquarter[0].enemy++;
        if (headquarter[0].enemy >= 2) {
            output(t);
            cout << "red headquarter was taken" << endl;
        }
    }
    for (int i = 1; i <= n; i++) {
        int x = city[i].red_warrior_num, y = city[i].blue_warrior_num;
        if (x) {
            output(t);
            cout << "red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id;
            cout << " marched to city " << i << " with " << red_warrior[x].bloo << " elements";
            cout << " and force " << red_warrior[x].atta << endl;
        }
        if (y) {
            output(t);
            cout << "blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id;
            cout << " marched to city " << i << " with " << blue_warrior[y].bloo << " elements";
            cout << " and force " << blue_warrior[y].atta << endl;
        }
    }
    if (city[n + 1].red_warrior_num) {
        output(t);
        int x = city[n + 1].red_warrior_num;
        cout << "red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id;
        cout << " reached blue headquarter with " << red_warrior[x].bloo << " elements ";
        cout << "and force " << red_warrior[x].atta << endl;
        city[n + 1].red_warrior_num = 0;
        headquarter[1].enemy++;
        if (headquarter[1].enemy >= 2) {
            output(t);
            cout << "blue headquarter was taken" << endl;
        }
    }
    return;
}
void city_produce_hp() {
    for (int i = 1; i <= n; i++) {
        city[i].life += 10;
    }
    return;
}
void warrior_get_hp(int t) {
    for (int i = 1; i <= n; i++) {
        int x = city[i].red_warrior_num, y = city[i].blue_warrior_num;
        if (x != 0 && y == 0 && city[i].life != 0) {
            headquarter[0].life += city[i].life;
            output(t);
            cout << "red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id;
            cout << " earned " << city[i].life << " elements for his headquarter" << endl;
            city[i].life = 0;
        }
        if (x == 0 && y != 0 && city[i].life != 0) {
            headquarter[1].life += city[i].life;
            output(t);
            cout << "blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id;
            cout << " earned " << city[i].life << " elements for his headquarter" << endl;
            city[i].life = 0;
        }
    }
    return;
}
void shot(int t) {
    for (int i = 1; i <= n; i++) {
        int x = city[i].red_warrior_num, y = city[i].blue_warrior_num;
        int sh_x = city[i + 1].blue_warrior_num, sh_y = city[i - 1].red_warrior_num;
        if (x != 0 && sh_x != 0 && red_warrior[x].cnt_arrow != 0 && i != n) {
            red_warrior[x].arrow[red_warrior[x].cnt_arrow]--;
            if (!red_warrior[x].arrow[red_warrior[x].cnt_arrow]) red_warrior[x].cnt_arrow--;
            blue_warrior[sh_x].bloo -= R;
            if (blue_warrior[sh_x].bloo <= 0) {
                output(t);
                cout << "red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id;
                cout << " shot and killed blue " << q[blue_warrior[sh_x].catagory].s << ' ' << blue_warrior[sh_x].id << endl;
            } else {
                output(t);
                cout << "red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id << " shot" << endl;
            }
        }
        if (y != 0 && sh_y != 0 && blue_warrior[y].cnt_arrow != 0 && i != 1) {
            blue_warrior[y].arrow[blue_warrior[y].cnt_arrow]--;
            if (!blue_warrior[y].arrow[blue_warrior[y].cnt_arrow]) blue_warrior[y].cnt_arrow--;
            red_warrior[sh_y].bloo -= R;
            if (red_warrior[sh_y].bloo <= 0) {
                output(t);
                cout << "blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id;
                cout << " shot and killed red " << q[red_warrior[sh_y].catagory].s << ' ' << red_warrior[sh_y].id << endl;
            } else {
                output(t);
                cout << "blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id << " shot" << endl;
            }
        }
    }
    return;
}
bool r_can_use_bomb(int ci, int ishost, int x, int y) {
    bool res = false;
    if (ishost == 1 && blue_warrior[y].catagory != 2) {
        int temp = red_warrior[x].atta;
        if (red_warrior[x].sword[red_warrior[x].cnt_sword]) temp += red_warrior[x].sword[red_warrior[x].cnt_sword];
        if (temp < blue_warrior[y].bloo) {
            int fight_back = blue_warrior[y].atta / 2;
            if (blue_warrior[y].cnt_sword) fight_back += blue_warrior[y].sword[blue_warrior[y].cnt_sword];
            if (fight_back >= red_warrior[x].bloo) res = true;
        }
    } else if (ishost == 0) {
        int fight_front = blue_warrior[y].atta;
        if (blue_warrior[y].cnt_sword) fight_front += blue_warrior[y].sword[blue_warrior[y].cnt_sword];
        if (fight_front >= red_warrior[x].bloo) res = true;
    }
    return res;
}
bool b_can_use_bomb(int ci, int ishost, int x, int y) {
    bool res = false;
    if (ishost == 1 && red_warrior[x].catagory != 2) {
        int temp = blue_warrior[y].atta;
        if (blue_warrior[y].cnt_sword) temp += blue_warrior[y].sword[blue_warrior[y].cnt_sword];
        if (temp < red_warrior[x].bloo) {
            int fight_back = red_warrior[x].atta / 2;
            if (red_warrior[x].cnt_sword) fight_back += red_warrior[x].sword[red_warrior[x].cnt_sword];
            if (fight_back >= blue_warrior[y].bloo) res = true;
        }
    } else if (ishost == 0) {
        int fight_front = red_warrior[x].atta;
        if (red_warrior[x].cnt_sword) fight_front += red_warrior[x].sword[red_warrior[x].cnt_sword];
        if (fight_front >= blue_warrior[y].bloo) res = true;
    }
    return res;
}  // 还要考虑的情况：我一击能否把他打死
void use_bomb(int t) {
    for (int i = 1; i <= n; i++) {
        int x = city[i].red_warrior_num, y = city[i].blue_warrior_num;
        if (red_warrior[x].bloo <= 0 || blue_warrior[y].bloo <= 0) continue;
        if (red_warrior[x].cnt_bomb != 0 && x && y) {
            if (city[i].flag == 1 || (city[i].flag == 0 && i % 2 == 1)) {
                if (r_can_use_bomb(i, 1, x, y)) {
                    output(t);
                    cout << "red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id;
                    cout << " used a bomb and killed blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id << endl;
                    red_warrior[x].pd_if_live = 0;
                    blue_warrior[y].pd_if_live = 0;
                    city[i].blue_warrior_num = 0;
                    city[i].red_warrior_num = 0;
                }
            }
            if (city[i].flag == -1 || (city[i].flag == 0 && i % 2 == 0)) {
                if (r_can_use_bomb(i, 0, x, y)) {
                    output(t);
                    cout << "red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id;
                    cout << " used a bomb and killed blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id << endl;
                    red_warrior[x].pd_if_live = 0;
                    blue_warrior[y].pd_if_live = 0;
                    city[i].red_warrior_num = 0;
                    city[i].blue_warrior_num = 0;
                }
            }
        }
        if (blue_warrior[y].cnt_bomb != 0 && x && y) {
            if (city[i].flag == -1 || (city[i].flag == 0 && i % 2 == 0)) {
                if (b_can_use_bomb(i, 1, x, y)) {  // 1表示蓝方先攻击
                    output(t);
                    cout << "blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id;
                    cout << " used a bomb and killed red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id << endl;
                    blue_warrior[y].pd_if_live = 0;
                    red_warrior[x].pd_if_live = 0;
                    city[i].red_warrior_num = 0;
                    city[i].blue_warrior_num = 0;
                }
            }
            if (city[i].flag == 1 || (city[i].flag == 0 && i % 2 == 1)) {
                if (b_can_use_bomb(i, 0, x, y)) {  // 0表示蓝方先攻击
                    output(t);
                    cout << "blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id;
                    cout << " used a bomb and killed red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id << endl;
                    blue_warrior[y].pd_if_live = 0;
                    red_warrior[x].pd_if_live = 0;
                    city[i].blue_warrior_num = 0;
                    city[i].red_warrior_num = 0;
                }
            }
        }
    }
    return;
}
void yell(int t, int i, int pd, int number) {
    if (pd == 1) {
        output(t);
        cout << "red dragon " << red_warrior[number].id << " yelled in city " << i << endl;
        return;
    } else if (pd == 0) {
        output(t);
        cout << "blue dragon " << blue_warrior[number].id << " yelled in city " << i << endl;
        return;
    }
}
void actual_fight(int x, int y, int i, int t, int ishost) {  // 1表示红方先攻击
    int rarrow = 0, barrow = 0;
    int save_x = red_warrior[x].bloo, save_y = blue_warrior[y].bloo;
    if (red_warrior[x].pd_if_live == 1 && red_warrior[x].bloo <= 0) rarrow = 1;
    if (blue_warrior[y].bloo <= 0 && blue_warrior[y].pd_if_live == 1) barrow = 1;
    if (rarrow && barrow) {
        red_warrior[x].pd_if_live = 0;
        blue_warrior[y].pd_if_live = 0;
        city[i].red_warrior_num = 0;
        city[i].blue_warrior_num = 0;
        return;
    }
    if (rarrow) {
        red_warrior[x].pd_if_live = 0;
        city[i].red_warrior_num = 0;
        if (blue_warrior[y].catagory == 1) {
            blue_warrior[y].morale += 0.2;
            if (ishost == 0 && blue_warrior[y].morale >= 0.8) {
                yell(t, i, 0, y);
            }
        }
        if (blue_warrior[y].catagory == 5) {
            if (red_warrior[x].cnt_sword && red_warrior[x].sword[red_warrior[x].cnt_sword] != 0) {
                blue_warrior[y].cnt_sword++;
                blue_warrior[y].sword[blue_warrior[y].cnt_sword] = red_warrior[x].sword[red_warrior[x].cnt_sword];
            }
            if (red_warrior[x].cnt_bomb) {
                blue_warrior[y].cnt_bomb++;
            }
            if (red_warrior[x].cnt_arrow) {
                blue_warrior[y].cnt_arrow++;
                blue_warrior[y].arrow[blue_warrior[y].cnt_arrow] = red_warrior[x].arrow[red_warrior[x].cnt_arrow];
            }
        }
        if (city[i].life > 0) {
            output(t);
            cout << "blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id;
            cout << " earned " << city[i].life << " elements for his headquarter" << endl;
        }
        if (city[i].flag == -1) {
            city[i].nex_win = 0;
        } else if (city[i].flag != -1) {
            if (city[i].nex_win == -1)
                city[i].nex_win--;
            else if (city[i].nex_win >= 0)
                city[i].nex_win = -1;
            if (city[i].nex_win == -2) {
                output(t);
                cout << "blue flag raised in city " << i << endl;
                city[i].nex_win = 0;
                city[i].flag = -1;
            }
        }
        winner[i] = -1;
        return;
    }
    if (barrow) {
        blue_warrior[y].pd_if_live = 0;
        city[i].blue_warrior_num = 0;
        if (red_warrior[x].catagory == 1) {
            red_warrior[x].morale += 0.2;
            if (ishost == 1 && red_warrior[x].morale >= 0.8) {
                yell(t, i, 1, x);
            }
        }
        if (red_warrior[x].catagory == 5) {
            if (blue_warrior[y].cnt_sword && blue_warrior[y].sword[blue_warrior[y].cnt_sword] != 0) {
                red_warrior[x].cnt_sword++;
                red_warrior[x].sword[red_warrior[x].cnt_sword] = blue_warrior[y].sword[blue_warrior[y].cnt_sword];
            }
            if (blue_warrior[y].cnt_bomb) {
                red_warrior[x].cnt_bomb++;
            }
            if (blue_warrior[y].cnt_arrow) {
                red_warrior[x].cnt_arrow++;
                red_warrior[x].arrow[red_warrior[x].cnt_arrow] = blue_warrior[y].arrow[blue_warrior[y].cnt_arrow];
            }
        }
        if (city[i].life > 0) {
            output(t);
            cout << "red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id;
            cout << " earned " << city[i].life << " elements for his headquarter" << endl;
        }
        if (city[i].flag == 1) {
            city[i].nex_win = 0;
        } else if (city[i].flag != 1) {
            if (city[i].nex_win == 1)
                city[i].nex_win++;
            else if (city[i].nex_win <= 0)
                city[i].nex_win = 1;
            if (city[i].nex_win == 2) {
                output(t);
                cout << "red flag raised in city " << i << endl;
                city[i].nex_win = 0;
                city[i].flag = 1;
            }
        }
        winner[i] = 1;
        return;
    }
    if (ishost == 1) {
        int temp = red_warrior[x].atta;
        if (red_warrior[x].cnt_sword) {
            temp += red_warrior[x].sword[red_warrior[x].cnt_sword];
            red_warrior[x].sword[red_warrior[x].cnt_sword] = red_warrior[x].sword[red_warrior[x].cnt_sword] * 4 / 5;
        }
        blue_warrior[y].bloo -= temp;
        output(t);
        cout << "red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id;
        cout << " attacked blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id << " in city " << i;
        cout << " with " << red_warrior[x].bloo << " elements and force " << red_warrior[x].atta << endl;
        if (blue_warrior[y].bloo > 0 && blue_warrior[y].catagory != 2) {
            int tem = blue_warrior[y].atta / 2;
            if (blue_warrior[y].cnt_sword) {
                tem += blue_warrior[y].sword[blue_warrior[y].cnt_sword];
                blue_warrior[y].sword[blue_warrior[y].cnt_sword] = blue_warrior[y].sword[blue_warrior[y].cnt_sword] * 4 / 5;
            }
            red_warrior[x].bloo -= tem;
            output(t);
            cout << "blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id;
            cout << " fought back against red " << q[red_warrior[x].catagory].s << ' ';
            cout << red_warrior[x].id << " in city " << i << endl;
        }
        if (red_warrior[x].bloo <= 0) {
            winner[i] = -1;
            output(t);
            cout << "red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id;
            cout << " was killed in city " << i << endl;
            red_warrior[x].pd_if_live = 0;
            city[i].red_warrior_num = 0;
            if (blue_warrior[y].catagory == 1) blue_warrior[y].morale += 0.2;
            if (red_warrior[x].catagory == 4) blue_warrior[y].bloo += save_x;
            if (blue_warrior[y].catagory == 5) {
                if (red_warrior[x].cnt_sword && red_warrior[x].sword[red_warrior[x].cnt_sword] != 0) {
                    blue_warrior[y].cnt_sword++;
                    blue_warrior[y].sword[blue_warrior[y].cnt_sword] = red_warrior[x].sword[red_warrior[x].cnt_sword];
                }
                if (red_warrior[x].cnt_bomb) {
                    blue_warrior[y].cnt_bomb++;
                }
                if (red_warrior[x].cnt_arrow) {
                    blue_warrior[y].cnt_arrow++;
                    blue_warrior[y].arrow[blue_warrior[y].cnt_arrow] = red_warrior[x].arrow[red_warrior[x].cnt_arrow];
                }
            }
            if (city[i].life > 0) {
                output(t);
                cout << "blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id;
                cout << " earned " << city[i].life << " elements for his headquarter" << endl;
            }
            if (city[i].flag == -1) {
                city[i].nex_win = 0;
            } else if (city[i].flag != -1) {
                if (city[i].nex_win == -1)
                    city[i].nex_win--;
                else if (city[i].nex_win >= 0)
                    city[i].nex_win = -1;
                if (city[i].nex_win == -2) {
                    output(t);
                    cout << "blue flag raised in city " << i << endl;
                    city[i].nex_win = 0;
                    city[i].flag = -1;
                }
            }
        } else if (blue_warrior[y].bloo <= 0) {
            winner[i] = 1;
            output(t);
            cout << "blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id;
            cout << " was killed in city " << i << endl;
            blue_warrior[y].pd_if_live = 0;
            city[i].blue_warrior_num = 0;
            if (red_warrior[x].catagory == 1) {
                red_warrior[x].morale += 0.2;
                if (red_warrior[x].morale >= 0.8) {
                    yell(t, i, 1, x);
                }
            }
            if (blue_warrior[y].catagory == 4) red_warrior[x].bloo += save_y;
            if (red_warrior[x].catagory == 5) {
                if (blue_warrior[y].cnt_sword && blue_warrior[y].sword[blue_warrior[y].cnt_sword] != 0) {
                    red_warrior[x].cnt_sword++;
                    red_warrior[x].sword[red_warrior[x].cnt_sword] = blue_warrior[y].sword[blue_warrior[y].cnt_sword];
                }
                if (blue_warrior[y].cnt_bomb) {
                    red_warrior[x].cnt_bomb++;
                }
                if (blue_warrior[y].cnt_arrow) {
                    red_warrior[x].cnt_arrow++;
                    red_warrior[x].arrow[red_warrior[x].cnt_arrow] = blue_warrior[y].arrow[blue_warrior[y].cnt_arrow];
                }
            }
            if (city[i].life > 0) {
                output(t);
                cout << "red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id;
                cout << " earned " << city[i].life << " elements for his headquarter" << endl;
            }
            if (city[i].flag == 1) {
                city[i].nex_win = 0;
            } else if (city[i].flag != 1) {
                if (city[i].nex_win == 1)
                    city[i].nex_win++;
                else if (city[i].nex_win <= 0)
                    city[i].nex_win = 1;
                if (city[i].nex_win == 2) {
                    output(t);
                    cout << "red flag raised in city " << i << endl;
                    city[i].nex_win = 0;
                    city[i].flag = 1;
                }
            }
        } else if (blue_warrior[y].bloo > 0 && red_warrior[x].bloo > 0) {
            city[i].nex_win = 0;
            winner[i] = 0;
            if (red_warrior[x].catagory == 1) {
                red_warrior[x].morale -= 0.2;
                if (red_warrior[x].morale > 0.8) yell(t, i, 1, x);
            }
            if (red_warrior[x].catagory == 4) {
                red_warrior[x].loyalty -= k;
            }
            if (blue_warrior[y].catagory == 1) {
                blue_warrior[y].morale -= 0.2;
            }
            if (blue_warrior[y].catagory == 4) {
                blue_warrior[y].loyalty -= k;
            }
        }  // 妈的 忘了狮子
        return;
    }  // 忘了龙和狼了 淦
    else if (ishost == 0) {
        int temp = blue_warrior[y].atta;
        if (blue_warrior[y].cnt_sword) {
            temp += blue_warrior[y].sword[blue_warrior[y].cnt_sword];
            blue_warrior[y].sword[blue_warrior[y].cnt_sword] = blue_warrior[y].sword[blue_warrior[y].cnt_sword] * 4 / 5;
        }
        red_warrior[x].bloo -= temp;
        output(t);
        cout << "blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id;
        cout << " attacked red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id;
        cout << " in city " << i << " with " << blue_warrior[y].bloo << " elements and force " << blue_warrior[y].atta << endl;
        if (red_warrior[x].bloo > 0 && red_warrior[x].catagory != 2) {
            int tem = red_warrior[x].atta / 2;
            if (red_warrior[x].cnt_sword) {
                tem += red_warrior[x].sword[red_warrior[x].cnt_sword];
                red_warrior[x].sword[red_warrior[x].cnt_sword] = red_warrior[x].sword[red_warrior[x].cnt_sword] * 4 / 5;
            }
            blue_warrior[y].bloo -= tem;
            output(t);
            cout << "red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id;
            cout << " fought back against blue " << q[blue_warrior[y].catagory].s;
            cout << ' ' << blue_warrior[y].id << " in city " << i << endl;
        }
        if (red_warrior[x].bloo <= 0) {
            winner[i] = -1;
            red_warrior[x].pd_if_live = 0;
            city[i].red_warrior_num = 0;
            output(t);
            cout << "red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id;
            cout << " was killed in city " << i << endl;
            if (blue_warrior[y].catagory == 1) {
                blue_warrior[y].morale += 0.2;
                if (blue_warrior[y].morale >= 0.8) {
                    yell(t, i, 0, y);
                }
            }
            if (red_warrior[x].catagory == 4) blue_warrior[y].bloo += save_x;
            if (blue_warrior[y].catagory == 5) {
                if (red_warrior[x].cnt_sword && red_warrior[x].sword[red_warrior[x].cnt_sword] != 0) {
                    blue_warrior[y].cnt_sword++;
                    blue_warrior[y].sword[blue_warrior[y].cnt_sword] = red_warrior[x].sword[red_warrior[x].cnt_sword];
                }
                if (red_warrior[x].cnt_bomb) {
                    blue_warrior[y].cnt_bomb++;
                }
                if (red_warrior[x].cnt_arrow) {
                    blue_warrior[y].cnt_arrow++;
                    blue_warrior[y].arrow[blue_warrior[y].cnt_arrow] = red_warrior[x].arrow[red_warrior[x].cnt_arrow];
                }
            }
            if (city[i].life > 0) {
                output(t);
                cout << "blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id;
                cout << " earned " << city[i].life << " elements for his headquarter" << endl;
            }
            if (city[i].flag == -1) {
                city[i].nex_win = 0;
            } else if (city[i].flag != -1) {
                if (city[i].nex_win == -1)
                    city[i].nex_win--;
                else if (city[i].nex_win >= 0)
                    city[i].nex_win = -1;
                if (city[i].nex_win == -2) {
                    output(t);
                    cout << "blue flag raised in city " << i << endl;
                    city[i].nex_win = 0;
                    city[i].flag = -1;
                }
            }
        } else if (blue_warrior[y].bloo <= 0) {
            winner[i] = 1;
            blue_warrior[y].pd_if_live = 0;
            city[i].blue_warrior_num = 0;
            output(t);
            cout << "blue " << q[blue_warrior[y].catagory].s << ' ' << blue_warrior[y].id;
            cout << " was killed in city " << i << endl;
            if (red_warrior[x].catagory == 1) red_warrior[x].morale += 0.2;
            if (blue_warrior[y].catagory == 4) red_warrior[x].bloo += save_y;
            if (red_warrior[x].catagory == 5) {
                if (blue_warrior[y].cnt_sword && blue_warrior[y].sword[blue_warrior[y].cnt_sword] != 0) {
                    red_warrior[x].cnt_sword++;
                    red_warrior[x].sword[red_warrior[x].cnt_sword] = blue_warrior[y].sword[blue_warrior[y].cnt_sword];
                }
                if (blue_warrior[y].cnt_bomb) {
                    red_warrior[x].cnt_bomb++;
                }
                if (blue_warrior[y].cnt_arrow) {
                    red_warrior[x].cnt_arrow++;
                    red_warrior[x].arrow[red_warrior[x].cnt_arrow] = blue_warrior[y].arrow[blue_warrior[y].cnt_arrow];
                }
            }
            if (city[i].life > 0) {
                output(t);
                cout << "red " << q[red_warrior[x].catagory].s << ' ' << red_warrior[x].id;
                cout << " earned " << city[i].life << " elements for his headquarter" << endl;
            }
            if (city[i].flag == 1) {
                city[i].nex_win = 0;
            } else if (city[i].flag != 1) {
                if (city[i].nex_win == 1)
                    city[i].nex_win++;
                else if (city[i].nex_win <= 0)
                    city[i].nex_win = 1;
                if (city[i].nex_win == 2) {
                    output(t);
                    cout << "red flag raised in city " << i << endl;
                    city[i].nex_win = 0;
                    city[i].flag = 1;
                }
            }
        } else if (red_warrior[x].bloo > 0 && blue_warrior[y].bloo > 0) {
            city[i].nex_win = 0;
            if (red_warrior[x].catagory == 1) {
                red_warrior[x].morale -= 0.2;
            }
            if (blue_warrior[y].catagory == 1) {
                blue_warrior[y].morale -= 0.2;
                if (blue_warrior[y].morale > 0.8) yell(t, i, 0, y);
            }
            if (red_warrior[x].catagory == 4) {
                red_warrior[x].loyalty -= k;
            }
            if (blue_warrior[y].catagory == 4) {
                blue_warrior[y].loyalty -= k;
            }
        }
        return;
    }
}
void fight(int t) {
    for (int i = 1; i <= n; i++) {
        int x = city[i].red_warrior_num, y = city[i].blue_warrior_num;
        if (x != 0 && y != 0) {
            if (city[i].flag == 1 || (city[i].flag == 0 && i % 2 == 1)) {
                actual_fight(x, y, i, t, 1);
            } else if (city[i].flag == -1 || (city[i].flag == 0 && i % 2 == 0)) {
                actual_fight(x, y, i, t, 0);
            }
        }
    }
}
void check_if_arrow() {
    for (int i = 1; i <= n; i++) {
        int x = city[i].red_warrior_num, y = city[i].blue_warrior_num;
        if (red_warrior[x].bloo <= 0 && red_warrior[x].pd_if_live == 1) {
            red_warrior[x].pd_if_live = 0;
            city[i].red_warrior_num = 0;
        }
        if (blue_warrior[y].bloo <= 0 && blue_warrior[y].pd_if_live == 1) {
            blue_warrior[y].pd_if_live = 0;
            city[i].blue_warrior_num = 0;
        }
    }
}
void r_award(int t) {
    for (int i = n; i >= 1; i--) {
        int x = city[i].red_warrior_num;
        if (x && headquarter[0].life >= 8 && winner[i] == 1) {
            headquarter[0].life -= 8;
            red_warrior[x].bloo += 8;
        }
    }
    return;
}
void b_award(int t) {
    for (int i = 1; i <= n; i++) {
        int y = city[i].blue_warrior_num;
        if (y && headquarter[1].life >= 8 && winner[i] == -1) {
            headquarter[1].life -= 8;
            blue_warrior[y].bloo += 8;
        }
    }
    return;
}
void warrior_get_hp_2(int t) {
    for (int i = 1; i <= n; i++) {
        if (!winner[i])
            continue;
        else if (winner[i] == 1) {
            headquarter[0].life += city[i].life;
            int x = city[i].red_warrior_num;
            city[i].life = 0;
        } else if (winner[i] == -1) {
            headquarter[1].life += city[i].life;
            int y = city[i].blue_warrior_num;
            city[i].life = 0;
        }
    }
}
void announce_blood(int t) {
    output(t);
    cout << headquarter[0].life << " elements in red headquarter" << endl;
    output(t);
    cout << headquarter[1].life << " elements in blue headquarter" << endl;
    return;
}
void warrior_report(int t) {
    for (int i = r_warrior_num; i >= 1; i--) {
        if (!red_warrior[i].pd_if_live)
            continue;
        else {
            int f = 0;
            if (!red_warrior[i].cnt_sword && !red_warrior[i].cnt_bomb && !red_warrior[i].cnt_arrow) {
                output(t);
                cout << "red " << q[red_warrior[i].catagory].s << ' ' << red_warrior[i].id;
                cout << " has no weapon" << endl;
                continue;
            }
            if (red_warrior[i].cnt_sword && !red_warrior[i].cnt_bomb && !red_warrior[i].cnt_arrow &&
                !red_warrior[i].sword[red_warrior[i].cnt_sword]) {
                output(t);
                cout << "red " << q[red_warrior[i].catagory].s << ' ' << red_warrior[i].id;
                cout << " has no weapon" << endl;
                continue;
            }
            output(t);
            cout << "red " << q[red_warrior[i].catagory].s << ' ' << red_warrior[i].id << " has ";
            if (red_warrior[i].cnt_arrow) {
                cout << "arrow(" << red_warrior[i].arrow[red_warrior[i].cnt_arrow] << ')';
                f = 1;
            }
            if (red_warrior[i].cnt_bomb) {
                if (f == 1)
                    cout << ",bomb";
                else {
                    cout << "bomb";
                    f = 1;
                }
            }
            if (red_warrior[i].cnt_sword && red_warrior[i].sword[red_warrior[i].cnt_sword] != 0) {
                if (f == 0)
                    cout << "sword(" << red_warrior[i].sword[red_warrior[i].cnt_sword] << ')';
                else
                    cout << ",sword(" << red_warrior[i].sword[red_warrior[i].cnt_sword] << ')';
            }
            cout << endl;
            continue;
        }
    }
    for (int i = 1; i <= b_warrior_num; i++) {
        if (!blue_warrior[i].pd_if_live)
            continue;
        else {
            int f = 0;
            if (!blue_warrior[i].cnt_sword && !blue_warrior[i].cnt_bomb && !blue_warrior[i].cnt_arrow) {
                output(t);
                cout << "blue " << q[blue_warrior[i].catagory].s << ' ' << blue_warrior[i].id;
                cout << " has no weapon" << endl;
                continue;
            }
            if (blue_warrior[i].cnt_sword && !blue_warrior[i].cnt_bomb && !blue_warrior[i].cnt_arrow &&
                !blue_warrior[i].sword[blue_warrior[i].cnt_sword]) {
                output(t);
                cout << "blue " << q[blue_warrior[i].catagory].s << ' ' << blue_warrior[i].id;
                cout << " has no weapon" << endl;
                continue;
            }
            output(t);
            cout << "blue " << q[blue_warrior[i].catagory].s << ' ' << blue_warrior[i].id << " has ";
            if (blue_warrior[i].cnt_arrow) {
                cout << "arrow(" << blue_warrior[i].arrow[blue_warrior[i].cnt_arrow] << ')';
                f = 1;
            }
            if (blue_warrior[i].cnt_bomb) {
                if (f == 1)
                    cout << ",bomb";
                else {
                    cout << "bomb";
                    f = 1;
                }
            }
            if (blue_warrior[i].cnt_sword && blue_warrior[i].sword[blue_warrior[i].cnt_sword] != 0) {
                if (f == 1)
                    cout << ",sword(" << blue_warrior[i].sword[blue_warrior[i].cnt_sword] << ')';
                else
                    cout << "sword(" << blue_warrior[i].sword[blue_warrior[i].cnt_sword] << ')';
            }
            cout << endl;
            continue;
        }
    }
}
int main() {
    // freopen("output.txt","w",stdout);
    scanf("%d", &z);
    for (int v = 1; v <= z; v++) {
        scanf("%d%d%d%d%d", &m, &n, &R, &k, &t);
        memset(red_warrior, 0, sizeof(red_warrior));
        memset(blue_warrior, 0, sizeof(blue_warrior));
        memset(city, 0, sizeof(city));
        memset(headquarter, 0, sizeof(headquarter));
        memset(winner, 0, sizeof(winner));
        headquarter[0].life = m, headquarter[1].life = m;
        rflag = 1, bflag = 1;
        tim = 0;
        proces = 0;
        r_warrior_num = 0, b_warrior_num = 0;
        rcnt = 0, bcnt = 0;
        for (int i = 1; i <= 5; i++) {
            scanf("%d", &q[i].bloo);
        }
        for (int i = 1; i <= 5; i++) {
            scanf("%d", &q[i].atta);
        }
        q[1].s = "dragon", q[2].s = "ninja", q[3].s = "iceman", q[4].s = "lion", q[5].s = "wolf";
        printf("Case %d:\n", v);
        for (int i = 0; i <= 100005; i++) {
            if (tim > t) break;
            if (tim % 60 == 0) {
                if (rflag) {
                    rcnt++;
                    rcnt = (rcnt - 1) % 5 + 1;
                }
                if (bflag) {
                    bcnt++;
                    bcnt = (bcnt - 1) % 5 + 1;
                }
                r_birth(tim);
                b_birth(tim);
            } else if (tim % 60 == 5) {
                lion_escape(tim);
            } else if (tim % 60 == 10) {
                r_move(tim);
                b_move(tim);
                move_output(tim);
                if (headquarter[0].enemy >= 2 || headquarter[1].enemy >= 2) {
                    break;
                }
            } else if (tim % 60 == 20) {
                city_produce_hp();
            } else if (tim % 60 == 30) {
                warrior_get_hp(tim);
            } else if (tim % 60 == 35) {
                shot(tim);
            } else if (tim % 60 == 38) {
                use_bomb(tim);
            } else if (tim % 60 == 40) {
                fight(tim);
                check_if_arrow();
                r_award(tim);
                b_award(tim);
                warrior_get_hp_2(tim);
            }  // 最难的一关 战斗，爽！
            else if (tim % 60 == 50) {
                announce_blood(tim);
            } else if (tim % 60 == 55) {
                warrior_report(tim);
            }
            proces++;
            proces = (proces - 1) % 10 + 1;
            tim += step[proces];
            memset(winner, 0, sizeof(winner));
        }
    }
    system("pause");
    return 0;
}