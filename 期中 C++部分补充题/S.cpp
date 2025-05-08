#include <set>
#include <iostream>
#include <string>
using namespace std;
struct myComp{
    bool operator()(const pair<int,int>&x,const pair<int,int>&y)const{
        if(x.first>0&&y.first>0&&x.second>0&&y.second>0) return x.first>y.first;
        if(x.first<0||y.first<0) return x.second<y.second;
        if(x.second<0||y.second<0) return x.first>y.first;
    }
};
// 在此处补充你的代码
int main() {
	string cmd;
	set<pair<int, int>, myComp> S;
	while (cin >> cmd) {
		if (cmd == "A") {
			int x, y;
			cin >> x >> y;
			S.insert(make_pair(x, y));
		} else if (cmd == "Qx") {
			int x;
			cin >> x;
			cout << S.lower_bound(make_pair(x, -1))->second << endl;
		} else if (cmd == "Qy") {
			int y;
			cin >> y;
			cout << S.lower_bound(make_pair(-1, y))->first << endl;
		} else {
			int x, y;
			cin >> x >> y;
			S.erase(make_pair(x, y));
		}
	}
    system("pause");
	return 0;
}