#include <iostream>
#include <vector>
using namespace std;
template <class T1, class Pred = void>
struct getWanted;
template <>
class getWanted<vector<int>::iterator> {
public:
    int val;
    getWanted(vector<int>::iterator x, vector<int>::iterator y) {
        int temp = *x;
        for (auto it = x + 1; it != y; it++) {
            if (*it < temp) temp = *it;
        }
        val = temp;
    }
    template <class Pd>
    getWanted(vector<int>::iterator x, vector<int>::iterator y, Pd f) {
        int temp = *x;
        for (auto it = x + 1; it != y; it++) {
            if (f(temp, *it)) temp = *it;
        }
        val = temp;
    }
    friend ostream &operator<<(ostream &os, const getWanted<vector<int>::iterator> &other) {
        os << other.val;
        return os;
    }
};
template <class Pred>
struct getWanted<vector<int>::iterator, Pred> {
    int val;
    Pred f;
    getWanted(vector<int>::iterator x, vector<int>::iterator y) {
        int temp = *x;
        for (auto it = x + 1; it != y; it++) {
            if (f(temp, *it)) temp = *it;
        }
        val = temp;
    }
    friend ostream &operator<<(ostream &os, const getWanted<vector<int>::iterator, less<int>> &other) {
        os << other.val;
        return os;
    }
};
struct myComp {
    bool operator()(int a, int b) { return a % 10 < b % 10; }
};
int main() {
    int n;
    cin >> n;
    vector<int> a, b, c;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int cmd;
    while (cin >> cmd) {
        switch (cmd) {
            case 0:
                cout << getWanted<vector<int>::iterator, less<int>>(a.begin(), a.end()) << endl;
                break;
            case 1:
                cout << getWanted<vector<int>::iterator>(a.begin(), a.end(), less<int>()) << endl;
                break;
            case 2:
                cout << getWanted<vector<int>::iterator>(a.begin(), a.end(), myComp()) << endl;
                break;
            case 3:
                cout << getWanted<vector<int>::iterator>(a.begin(), a.end()) << endl;
                break;
        }
    }
    return 0;
}