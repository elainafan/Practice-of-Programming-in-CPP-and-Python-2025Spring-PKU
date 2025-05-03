#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;
template<class T>
class Print{
    int x;
public:
    Print(int a):x(a) { }
    Print<T>& operator+(T d){
        x--;
        cout<<d;
        if(x==0) cout<<endl;
        return *this;
    } 
};
// 在此处补充你的代码
int main(){
	string s[20];
	int num[20];
	int m,n;
	
	while(cin >> m >> n){
		for(int i=0; i<m; i++){
			cin >> s[i];
		}
		accumulate(s, s+m, Print<string>(m));
		for(int i=0; i<n; i++){
			cin >> num[i];
		}
		accumulate(num, num+n, Print<int>(n));
	}
    system("pause");
    return 0;
}