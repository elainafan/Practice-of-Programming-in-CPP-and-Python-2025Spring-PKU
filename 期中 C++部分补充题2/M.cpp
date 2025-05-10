#include<iostream>
using namespace std;
void print(unsigned int x) {
    for(unsigned int y=0;;y=(y-x)&x){
        cout<<y<<endl;
        if(y==x) break;
    }
    return ;
// 在此处补充你的代码
}
int main() {
	int T; cin >> T;
	while (T--) {
		unsigned x; cin >> x;
		print(x);
	}
    system("pause");
	return 0;
}