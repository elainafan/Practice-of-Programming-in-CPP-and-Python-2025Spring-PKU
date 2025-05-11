#include <iostream>
using namespace std;
class Sample {
public:
	int my_value;
static int sum;
    Sample(int x):my_value(x){
        sum+=x;
    }
    Sample(const Sample &x){
        sum+=x.my_value;
    }
    ~Sample(){
        sum-=my_value;
    }
    Sample() { }
};
int Sample::sum=0;
int main()
{
	Sample a(5);
	cout<<Sample::sum<<endl;
	Sample b = a;
	cout << Sample::sum << endl;
	Sample c;
	cout << Sample::sum << endl;
	Sample * d = new Sample(20);
	cout << Sample::sum<<endl;
	delete d;
	cout << Sample::sum<<endl;
	return 0;
}