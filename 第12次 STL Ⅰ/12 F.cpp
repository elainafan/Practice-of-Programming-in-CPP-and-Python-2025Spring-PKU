#include <iostream>
#include <list>
#include <string>
using namespace std;

template <class T1,class T2>
void Copy(T1 s,T1 e, T2 x)
{
	for(; s != e; ++s,++x)
		*x = *s;
}

 
template<class T>
class myostream_iteraotr
{
private:
    ostream& ost;
    T n;
    string k;
public:
    myostream_iteraotr(ostream& ost,string x):ost(ost),k(x) { }
    myostream_iteraotr& operator++(){
        return *this;
    }
    myostream_iteraotr& operator*(){
        return *this;
    }
    void operator=(const T& other){
        ost<<other<<k;
    }
// 在此处补充你的代码
};


int main()
{	const int SIZE = 5;
	int a[SIZE] = {5,21,14,2,3};
	double b[SIZE] = { 1.4, 5.56,3.2,98.3,3.3};
	list<int> lst(a,a+SIZE);
	myostream_iteraotr<int> output(cout,",");
	Copy( lst.begin(),lst.end(),output); 
	cout << endl;
	myostream_iteraotr<double> output2(cout,"--");
	Copy(b,b+SIZE,output2);
    system("pause");
	return 0;
}