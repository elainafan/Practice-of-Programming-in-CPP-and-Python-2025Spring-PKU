#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
int n,m;
map<string,int>ma;
map<string,int>fa;
int ans=0;
string x,y,z;
int a,b;
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>a>>b;
        ma[x]=a;
        fa[x]=b;
    }
    for(int i=1;i<=n;i++){
        cin>>x>>y>>z;
        if(fa[x]>0){
            fa[x]--;
            ans+=ma[x];
        }
        if(fa[y]>0){
            fa[y]--;
            ans+=ma[y];
        }
        if(fa[z]>0){
            fa[z]--;
            ans+=ma[z];
        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}