#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;
class cat{
public:
    int age;
    int tak;
    string s;
    cat(int x):s("cat"),age(x),tak(0) { }
    cat() { }
};
class drug_cat:public cat{
public:
    drug_cat(int k,int d){
        s="drug_cat";
        age=k;
        tak=d;
    }
};
class Comp{
public:
    bool operator()(cat* x,cat* y)const{
        if(x->age==y->age) return x->tak<y->tak;
        return x->age<y->age;
    }
};
void Print(cat* x){
    if(x->tak==0) cout<<x->s<<' '<<x->age<<endl;
    else cout<<x->s<<' '<<x->age<<' '<<x->tak<<endl;
}
int main()
{
    int t, d;
    cin >> t;
    set<cat*, Comp> ct;
    while (t--) {
        int n;
        cin >> n;
        ct.clear();
        for (int i = 0; i < n; ++i) {
            string c; int k;
            cin >> c >> k;

            if (c == "cat")
                ct.insert(new cat(k));
            else{
                cin >> d;
                ct.insert(new drug_cat(k, d));
                }
        }
        for_each(ct.begin(), ct.end(), Print);
        cout << "---" << endl;
    }
    return 0;
}