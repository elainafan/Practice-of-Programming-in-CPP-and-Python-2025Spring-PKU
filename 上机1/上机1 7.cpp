#include <iostream>
using namespace std;
class Complex{
private:
    int real,imag;
public:
    Complex(){
        real=0,imag=0;
    }
    Complex(char *p){
        real=p[0]-'0';
        imag=p[2]-'0';
    }
    Complex(const Complex &b){
        real=b.real;
        imag=b.imag;
    }
    Complex(int x){
        real=x;imag=0;
    }
    Complex operator+(const Complex &b){
        Complex temp;
        temp.real=real+b.real;
        temp.imag=imag+b.imag;
        return temp;
    }
    Complex operator-(const Complex &b){
        Complex temp;
        temp.real=real-b.real;
        temp.imag=imag-b.imag;
        return temp;
    }
    Complex operator*(const Complex &b){
        Complex temp;
        temp.real=real*b.real-imag*b.imag;
        temp.imag=real*b.imag+imag*b.real;
        return temp;
    }
    Complex &operator+=(const Complex &b){
        real+=b.real;
        imag+=b.imag;
        return *this;
    }
    Complex &operator-=(int x){
        real-=x;
        return *this;
    }
    Complex &operator*=(const Complex &b){
        Complex temp;
        temp.real=real*b.real-imag*b.imag;
        temp.imag=real*b.imag+imag*b.real;
        real=temp.real,imag=temp.imag;
        return *this;
    }
    friend ostream &operator<<(ostream &o,const Complex &b){
        if(b.real==0&&b.imag!=0){
            o<<b.imag<<'i';
            return o;
        }
        if(b.imag==0){
            o<<b.real;
            return o;
        }
        else{
            o<<b.real<<'+'<<b.imag<<'i';
            return o;
        }
    }
};
int main() {
	Complex c1;
	Complex c2("3+2i"); // 用字符串初始化时，只需考虑"a+bi"的形式，其中a和b都是1位数字
	Complex c3(c2);
	Complex c4(-15);
	cout << c2 << endl;
	cout << c3 << endl;
	cout << c4 << endl;
	cout << c2 + c4 << endl;
	cout << c2 - c3 << endl;
	cout << c2 * c3 << endl;
	c2 += c4;
	cout << c2 << endl;
	c2 -= -12;
	cout << c2 << endl;
	c3 *= c3;
	cout << c3 << endl;
	return 0;
}