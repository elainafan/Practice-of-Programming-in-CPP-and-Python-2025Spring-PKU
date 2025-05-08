#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class CMean {
private:
	int& result;
	int num;
	bool flag;
public:
	CMean(int& t):result(t),num(0),flag(true) { }
	void operator()(const auto &x){
		result+=x;
		num++;
		return ;
	}
	CMean(const CMean &other):result(other.result),num(other.num),flag(false){ }
	~CMean(){
		if(flag){
			result/=num;
			flag=false;
		} 
	}
// 在此处补充你的代码
};

int main(int argc, char* argv[]) {
	int  v;
	int t;
	cin >> t;
	while ( t -- ) {
		cin >> v;
		vector<int> vec;
		while (v) {
			vec.push_back(v);
			cin >> v;
		}
		int myAver = 0;
		for_each(vec.begin(), vec.end(), CMean(myAver));
		cout << myAver << endl;
	}
	system("pause");
	return 0;
}