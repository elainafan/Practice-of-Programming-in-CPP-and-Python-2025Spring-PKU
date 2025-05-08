#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <set>

using namespace std;
class MyQueue
{
private:
    int tot,cnt;
public:
    priority_queue<int>q;
    MyQueue(int x){ 
        tot=x;
        cnt=0;
    }
    friend istream &operator>>(istream &is,MyQueue &t){
        int dd;
        is>>dd;
        if(dd%2) return is;
        else{
            t.q.push(-dd);
            t.cnt++;
            if(t.cnt>t.tot) t.q.pop();
            return is;
        }
    }
    friend ostream &operator<<(ostream &os,MyQueue &t){
        vector<int>a;
        while(!t.q.empty()){
            int x=-t.q.top();
            t.q.pop();
            a.push_back(x);
        }
        for(auto it=a.end()-1;it>=a.begin();it--){
            os<<*it<<' ';
        }
        return os;
    }
// 在此处补充你的代码
};
int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		MyQueue q(k);
		for (int i = 0; i < n; ++i)
			cin >> q;
		cout<<q;
		cout << endl;
	}
    system("pause");
	return 0; 
}