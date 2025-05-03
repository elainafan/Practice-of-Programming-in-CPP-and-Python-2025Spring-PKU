#include <iostream>
#include <string>
#include <vector>
using namespace std;
template<class T1,class T2,class T3>
T1 FindFirstLess(T1 x,T1 y,T2 t,T3 f){
    bool flag=false;
    T1 k;
    for(T1 it=x;it!=y;it++){
        if(*it<t){
            flag=1;
            k=it;
            break;
        }
    }
    if(flag) return k;
    else return y;
}
// 在此处补充你的代码
int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n ;
		string type; 
		cin >> n >> type;
		vector<int> vi;
		vector<string> vs;
		if( type == "N") {
			int a,m;
			for(int i = 0;i < n  - 1; ++i) {
				
				cin >> a;
				vi.push_back(a);
			}
			cin >> m;
			vector<int>::iterator p = FindFirstLess(vi.begin(),vi.end(),m,less<int>());
			if( p!= vi.end())
				cout << * p << endl;
			else
				cout << "Not Found" << endl; 
				
		}
		else {
			string a,m;
			for(int i = 0;i < n - 1; ++i) {
				cin >> a;
				vs.push_back(a);
			}
			cin >> m;
			vector<string>::iterator p = FindFirstLess(vs.begin(),vs.end(),m,less<string>());
			if( p!= vs.end())
				cout << * p << endl;
			else
				cout << "Not Found" << endl; 
		
		}
	}
    system("pause");
    return 0;
}