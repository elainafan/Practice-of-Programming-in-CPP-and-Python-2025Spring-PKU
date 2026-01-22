#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t, m;
int rm, bm;
struct node {
    int w;
    string s;
};
node q[6];
int r[6] = {0, 3, 4, 5, 2, 1}, b[6] = {0, 4, 1, 2, 3, 5};
int rcnt = 0, bcnt = 0, rflag = 0, bflag = 0;
int rnum[6], bnum[6];
void output(int x) {
    if (x >= 0 && x <= 9)
        cout << "00" << x << ' ';
    else if (x >= 10 && x <= 99)
        cout << '0' << x << ' ';
    else
        cout << x << ' ';
}
void rbirth(int j) {
    if (rflag == 0 && rm >= q[r[rcnt]].w) {
        rm -= q[r[rcnt]].w;
        rnum[r[rcnt]]++;
        output(j);
        cout << "red " << q[r[rcnt]].s << ' ' << j + 1 << ' ' << "born with strength " << q[r[rcnt]].w;
        cout << ',' << rnum[r[rcnt]] << ' ' << q[r[rcnt]].s << ' ' << "in red headquarter" << endl;
        return;
    } else if (rflag == 0 && rm < q[r[rcnt]].w) {
        int tem = 0, temp = rcnt;
        for (int i = 1; i <= 5; i++) {
            temp++;
            temp = (temp - 1) % 5 + 1;
            if (rm >= q[r[temp]].w) {
                rm -= q[r[temp]].w;
                rnum[r[temp]]++;
                output(j);
                cout << "red " << q[r[temp]].s << ' ' << j + 1 << ' ' << "born with strength " << q[r[temp]].w;
                cout << ',' << rnum[r[temp]] << ' ' << q[r[temp]].s << ' ' << "in red headquarter" << endl;
                rcnt = temp;
                return;
            }
        }
        if (tem == 0) {
            rflag = 1;
            output(j);
            cout << "red headquarter stops making warriors" << endl;
            return;
        }
    }
}
void bbirth(int j) {
    if (bflag == 0 && bm >= q[b[bcnt]].w) {
        bm -= q[b[bcnt]].w;
        bnum[b[bcnt]]++;
        output(j);
        cout << "blue " << q[b[bcnt]].s << ' ' << j + 1 << ' ' << "born with strength " << q[b[bcnt]].w;
        cout << ',' << bnum[b[bcnt]] << ' ' << q[b[bcnt]].s << ' ' << "in blue headquarter" << endl;
        return;
    } else if (bflag == 0 && bm < q[b[bcnt]].w) {
        int tem = 0, temp = bcnt;
        for (int i = 1; i <= 5; i++) {
            temp++;
            temp = (temp - 1) % 5 + 1;
            if (bm >= q[b[temp]].w) {
                bm -= q[b[temp]].w;
                bnum[b[temp]]++;
                output(j);
                cout << "blue " << q[b[temp]].s << ' ' << j + 1 << ' ' << "born with strength " << q[b[temp]].w;
                cout << ',' << bnum[b[temp]] << ' ' << q[b[temp]].s << ' ' << "in blue headquarter" << endl;
                bcnt = temp;
                return;
            }
        }
        if (tem == 0) {
            bflag = 1;
            output(j);
            cout << "blue headquarter stops making warriors" << endl;
            return;
        }
    }
}
int main() {
    scanf("%d", &t);
    for (int v = 1; v <= t; v++) {
        scanf("%d", &m);
        rm = m, bm = m;
        rflag = 0, bflag = 0;
        rcnt = 0, bcnt = 0;
        memset(rnum, 0, sizeof(rnum));
        memset(bnum, 0, sizeof(bnum));
        q[1].s = "dragon", q[2].s = "ninja", q[3].s = "iceman", q[4].s = "lion", q[5].s = "wolf";
        for (int i = 1; i <= 5; i++) {
            scanf("%d", &q[i].w);
        }
        printf("Case:%d\n", v);
        for (int j = 0; j <= 999; j++) {
            rcnt++;
            bcnt++;
            rcnt = (rcnt - 1) % 5 + 1;
            bcnt = (bcnt - 1) % 5 + 1;
            if (rflag == 0) rbirth(j);
            if (bflag == 0) bbirth(j);
            if (rflag == 1 && bflag == 1) break;
        }
    }
    system("pause");
    return 0;
}