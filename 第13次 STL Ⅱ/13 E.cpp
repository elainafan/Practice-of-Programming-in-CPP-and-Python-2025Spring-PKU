#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int n;
int id,p;
multimap<int,int>lst;
int main(){
    scanf("%d",&n);
    lst.insert(make_pair(1000000000,1));
    for(int i=1;i<=n;i++){
        cin>>id>>p;
        auto it=lst.insert(make_pair(p,id));
        cout<<id<<' ';
        if(it!=lst.begin()&&it!=--lst.end()){
            auto it_1=it;
            auto it_2=it;
            it_1--;
            it_2++;
            if(abs(it_1->first-p)<=abs(it_2->first-p)){
                cout<<it_1->second<<endl;
            }
            else cout<<it_2->second<<endl;
        }   
        else if(it==lst.begin()){
            cout<<(++it)->second<<endl;
        }
        else if(it==--lst.end()){
            cout<<(--it)->second<<endl;
        }
    }
    system("pause");
    return 0;
}