#include<iostream>
#include<queue>
#define ll long long
#define ull unsigned long long
using namespace std;
int n,blo;
string name;
priority_queue<pair<int,string>>q;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>blo>>name;
        q.push(make_pair(blo,name));
    }
    while(!q.empty()){
        string a=q.top().second;int x=q.top().first;q.pop();
        if(q.empty()){
            cout<<a<<endl;
            break;
        }
        string b=q.top().second;int y=q.top().first;q.pop();
        if(x==y){
            if(q.empty()){
                cout<<-1<<endl;
                break;
            }
            else{
                continue;
            }
        }
        if(x<y){
            q.push(make_pair(y-x,b));
            continue;
        }
        if(x>y){
            q.push(make_pair(x-y,a));
            continue;
        }
    }
    return 0;
}