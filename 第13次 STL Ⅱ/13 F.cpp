#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int n,id,p;
map<int,int>ma;
int main(){
    scanf("%d",&n);
    ma[1000000000]=1;
    for(int i=1;i<=n;i++){
        cin>>id>>p;
        cout<<id<<' ';
        auto it=ma.find(p);
        if(it!=ma.end()) {
            cout<<ma[p]<<endl;
            ma[p]=min(id,ma[p]);
            continue;
        }
        else ma[p]=id;
        it=ma.find(p);
        if(it!=ma.begin()&&it!=--ma.end()){
            auto it_1=it;
            auto it_2=it;
            it_1--;
            it_2++;
            if(abs(it_1->first-p)<abs(it_2->first-p)){
                cout<<it_1->second<<endl;
            }
            else if(abs(it_1->first-p)==abs(it_2->first-p)){
                cout<<min(it_1->second,it_2->second)<<endl;
            }
            else cout<<it_2->second<<endl;
        }
        else if(it==ma.begin()){
            cout<<(++it)->second<<endl;
        }
        else if(it==--ma.end()){
            cout<<(--it)->second<<endl;
        }
    }
    system("pause");
    return 0;
}