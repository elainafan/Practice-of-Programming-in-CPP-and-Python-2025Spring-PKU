#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
#define maxn 25
using namespace std;
string Copy();
string Add();
bool isnum(string x);
int Find();
int Rfind();
string Insert();
string Reset();
void Print(int x);
void Printall();
int n0;
string str[maxn];
int tot;
string Copy(){
    string N,X,L;
    int n,x,l;
    cin>>N;
    if(N=="find"){
        n=Find();
    }
    else if(N=="rfind"){
        n=Rfind();
    }
    else n=stoi(N);
    cin>>X;
    if(X=="find"){
        x=Find();
    }
    else if(X=="rfind"){
        x=Rfind();
    }
    else x=stoi(X);
    cin>>L;
    if(L=="find"){
        l=Find();
    }
    else if(L=="rfind"){
        l=Rfind();
    }
    else l=stoi(L);
    string temp=str[n].substr(x,l);
    return temp;
}
string Add(){
    string S1,S2,s1,s2;
    cin>>S1;
    if(S1=="copy"){
        s1=Copy();
    }
    else if(S1=="add"){
        s1=Add();
    }
    else s1=S1;
    cin>>S2;
    if(S2=="copy"){
        s2=Copy();
    }
    else if(S2=="add"){
        s2=Add();
    }
    else s2=S2;
    if(isnum(s1)&&isnum(s2)){
        int a=stoi(s1),b=stoi(s2);
        return to_string(a+b);
    }
    else return s1+s2;
}
bool isnum(string x){
    int l=x.length();
    if(l>=5) return false;
    bool flag=true;
    for(int i=0;i<=l-1;i++){
        if(!(x[i]>='0'&&x[i]<='9')){
            flag=false;
            break;
        }
    }
    return flag;
}
int Find(){
    string S,N,s;
    int n;
    cin>>S;
    if(S=="copy"){
        s=Copy();
    }
    else if(S=="add"){
        s=Add();
    }
    else s=S;
    cin>>N;
    if(N=="find"){
        n=Find();
    }
    else if(N=="rfind"){
        n=Rfind();
    }
    else n=stoi(N);
    int temp;
    if(str[n].find(s)!=string::npos){
        temp=str[n].find(s);
    }
    else temp=str[n].size();
    return temp;
}
int Rfind(){
    string S,s,N;
    int n;
    cin>>S;
    if(S=="copy"){
        s=Copy();
    }
    else if(S=="add"){
        s=Add();
    }
    else s=S;
    cin>>N;
    if(N=="find"){
        n=Find();
    }
    else if(N=="rfind"){
        n=Rfind();
    }
    else n=stoi(N);
    int temp;
    if(str[n].rfind(s)!=string::npos){
        temp=str[n].rfind(s);
    }
    else temp=str[n].size();
    return temp;
}
string Insert(){
    string N,X,S,s;
    int n,x;
    cin>>S;
    if(S=="copy"){
        s=Copy();
    }
    else if(S=="add"){
        s=Add();
    }
    else s=S;
    cin>>N;
    if(N=="find"){
        n=Find();
    }
    else if(N=="rfind"){
        n=Rfind();
    }
    else{
        n=stoi(N);
    }
    cin>>X;
    if(X=="find"){
        x=Find();
    }
    else if(X=="rfind"){
        x=Rfind();
    }
    else x=stoi(X);
    string temp=str[n].insert(x,s);
    return temp;
}
string Reset(){
    string S,s,N;
    int n;
    cin>>S;
    if(S=="copy"){
        s=Copy();
    }
    else if(S=="add"){
        s=Add();
    }
    else s=S;
    cin>>N;
    if(N=="find"){
        n=Find();
    }
    else if(N=="rfind"){
        n=Rfind();
    }
    else n=stoi(N);
    swap(str[n],s);
    return str[n];
}
void Print(int x){
    cout<<str[x]<<endl;
    return ;
}
void Printall(){
    for(int i=1;i<=n0;i++){
        cout<<str[i]<<endl;
    }
    return ;
}
int main(){
    cin>>n0;
    for(int i=1;i<=n0;i++){
        cin>>str[i];
    }
    while(1){
        string op;
        cin>>op;
        if(op=="over") break;
        else if(op=="copy"){
            Copy();
        }
        else if(op=="add"){
            Add();
        }
        else if(op=="find"){
            Find();
        }
        else if(op=="rfind"){
            Rfind();
        }
        else if(op=="insert"){
            Insert();
        }
        else if(op=="reset"){
            Reset();
        }
        else if(op=="print"){
            int x;
            cin>>x;
            Print(x);
        }
        else if(op=="printall"){
            Printall();
        }
    }
    system("pause");
    return 0;
}