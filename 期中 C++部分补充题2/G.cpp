#include <iostream>
using namespace std;

class Singleton
{ 
private:
    int val;
    int cnt;
	Singleton() : val(0), cnt(0) {};
    static Singleton* instance;
	
public:
    void Add(int delta) {
        val += delta;
        cnt += 1;
    }
    void Print() {
        cout << cnt << " " << val << endl;
    }
    static Singleton* getInstance(){
      if(instance==NULL){
        instance=new Singleton();
      }
      return instance;
    }
// 在此处补充你的代码
};

Singleton* Singleton::instance = NULL;

int main()
{
    int m;
    while (cin>>m) {
        Singleton* p = Singleton::getInstance();
        p->Add(m);
        p->Print();
    }
    system("pause");
    return 0;
}