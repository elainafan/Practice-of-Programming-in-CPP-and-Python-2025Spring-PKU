#include <iostream>
#include <set>

using namespace std;
template <class T>
class MySet : public set<T> {
public:
    set<T> ma;
    void insert(T x) {
        if (ma.find(x) != ma.end())
            cout << "Error insert " << x << endl;
        else
            ma.insert(x);
        return;
    }
    void erase(T x) {
        if (ma.find(x) == ma.end())
            cout << "Error erase " << x << endl;
        else
            ma.erase(x);
        return;
    }
    // 在此处补充你的代码
};
int main() {
    int n;
    scanf("%d", &n);
    MySet<int> S;
    for (int i = 1; i <= n; i++) {
        cout << "Operation #" << i << ":" << endl;
        string type;
        int w;
        cin >> type >> w;
        if (type == "insert")
            S.insert(w);
        else if (type == "erase")
            S.erase(w);
    }
    cout << endl;
    MySet<string> S2;
    for (int i = 1; i <= n; i++) {
        cout << "Operation #" << i << ":" << endl;
        string type;
        string w;
        cin >> type >> w;
        if (type == "insert")
            S2.insert(w);
        else if (type == "erase")
            S2.erase(w);
    }
    system("pause");
    return 0;
}