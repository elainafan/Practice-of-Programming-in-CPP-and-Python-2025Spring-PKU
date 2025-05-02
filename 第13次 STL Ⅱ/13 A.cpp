#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxn 200005
using namespace std;
int n;
list<int>ma[maxn];
string s;
int id,num;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s[0]=='n'){
            cin>>id;
        }
        else if(s[0]=='a'){
            cin>>id>>num;
            ma[id].push_back(num);
        }
        else if(s[0]=='m'){
            cin>>id>>num;
            if(id==num) continue;
            else{
                ma[id].merge(ma[num]);
            }
        }
        else if(s[0]=='u'){
            cin>>id;
            ma[id].sort();
            ma[id].unique();
        }
        else if(s[0]=='o'){
            cin>>id;
            if(ma[id].empty()) cout<<endl;
            else{
                ma[id].sort();
                for(auto i=ma[id].begin();i!=ma[id].end();i++){
                    cout<<*i<<' ';
                }
                cout<<endl;
            }
        }
    }
    system("pause");
    return 0;
}