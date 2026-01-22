#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
bool isprime(int x) {
    if (x == 1) return false;
    if (x == 2) return true;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int count(int x) {
    int ans = 0;
    for (int i = 1; i < x; i++) {
        if (x % i != 0) continue;
        if (isprime(i)) ans++;
    }
    return ans;
}
struct node {
    int num, rnum;
};
struct cmp {
    bool operator()(const node a, const node b) const {
        if (a.rnum == b.rnum) return a.num < b.num;
        return a.rnum < b.rnum;
    }
};
int main() {
    int n, k;
    cin >> n;
    set<node, cmp> queue;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10; j++) {
            cin >> k;
            node a;
            a.num = k;
            a.rnum = count(k);
            queue.insert(a);
        }
        auto it = queue.end();
        it--;
        cout << (*it).num << ' ';
        auto it_2 = queue.begin();
        cout << (*it_2).num << endl;
        queue.erase(it);
        queue.erase(it_2);
    }
    system("pause");
    return 0;
}