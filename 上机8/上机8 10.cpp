#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
template<class T,class Pred=void>
struct Comparator;
template<>
struct Comparator<int>{
    bool operator()(const int &a,const int &b)const{
        return a<b;
    }
};
template<>
struct Comparator<string>{
    bool operator()(const string &a,const string &b)const{
        return a<b;
    }
};
template<class len>
struct Comparator<string,len>{
    bool operator()(const string &a,const string &b)const{
        if(a.length()!=b.length()) return a.length()<b.length();
        return a<b;
    }
};
// 在此处补充你的代码
struct len {
	int operator() (string s){
		return s.length();
	}
};
int main() 
{
	int a[8] {4,2,1,3,5,6,8,7};
	sort(a,a+8,Comparator<int>());
	for( int x : a)
		cout << x << " ";
	cout << endl;
	int n;
	vector<string> v;
	cin >> n;
	for(int i=0;i< n; ++i) {
		string s;
		cin >> s;
		v.push_back(s);
	}			
	sort(v.begin(),v.end(),Comparator<string>());
	for( string x : v)
		cout << x << " ";
	cout << endl;
	
	sort(v.begin(),v.end(),Comparator<string,len>());
	for( string x : v)
		cout << x << " ";
	system("pause");
	return 0;
}