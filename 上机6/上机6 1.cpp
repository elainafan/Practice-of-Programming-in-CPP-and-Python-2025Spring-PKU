#include <iostream>
using namespace std;
template<class T>
int sum(T* a,int n,int f(int x)){
    int temp=0;
    for(T* i=a;i<=a+n-1;i++){
        temp+=f(*i);
    }
    return temp;
}
int sqr(int n) {
    return n * n;
}
int main() {
    int t, n, a[0x100];
    cin >> t;
    for (int c = 0; c < t; ++c) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << sum(a, n, sqr) << endl;
    }
    return 0;
}