#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
int t,n;
map<string,queue<string>>ma;
map<string,int>cnt;
map<string,set<string>>computer;
char op;
string x,y;
int main(){
    cin>>t;
    while(t--){
        ma.clear();
        cnt.clear();
        computer.clear();
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>op;
            if(op=='C'){
                cin>>x>>y;
                cnt[x]++;
                ma[x].push(y);
                if(cnt[x]>=7){
                    cnt[x]--;
                    string temp=ma[x].front();
                    ma[x].pop();
                    computer[x].insert(temp);
                }
            }
            else{
                cin>>x>>y;
                if(ma.find(x)!=ma.end()&&computer[x].find(y)!=computer[x].end()){
                    cout<<"Success"<<endl;
                    auto it=computer[x].find(y);
                    computer[x].erase(it);
                    ma[x].push(y);
                    cnt[x]++;
                    if(cnt[x]>=7){
                        cnt[x]--;
                        string temp=ma[x].front();
                        ma[x].pop();
                        computer[x].insert(temp);
                    }
                }
                else{
                    cout<<"Failed"<<endl;
                }
            }
        }
    }
    system("pause");
    return 0;
}