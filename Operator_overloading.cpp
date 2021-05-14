#include <iostream>
using namespace std;
class ComplexNumber{
private:
    double re;
    double im;
public:
    //constructor
    ComplexNumber(double re, double im){
        this->re = re;
        this->im = im;
    }
    friend ostream& operator<<(ostream& output, const ComplexNumber& cn){
        output << cn.re << " +" << " ( " <<cn.im <<" i" << " )";
        return output;
    }
    friend istream& operator>>(istream &input, ComplexNumber& cn){
        input >> cn.re >> cn.im;
        return input;
    }
    friend ComplexNumber operator + (const ComplexNumber& x, const ComplexNumber& y){
        return(ComplexNumber(x.re+y.re, x.im + y.im));
    }
    friend ComplexNumber operator - (const ComplexNumber& x, const ComplexNumber& y){
        return(ComplexNumber(x.re-y.re, x.im - y.im));
    }
    friend ComplexNumber operator * (const ComplexNumber& x, const ComplexNumber& y) {
        return (ComplexNumber(x.re * y.re, x.im * y.im));
    }
    friend ComplexNumber operator / (const ComplexNumber& x, const ComplexNumber& y) {
        return (ComplexNumber(((x.re*y.re)+(x.im*y.im))/((y.re*y.re)+(y.im*y.im)), ( (x.im *y.re - x.re*y.im) / ( y.re * y.re + y.im*y.im) )));
    }
    friend bool operator== (ComplexNumber& x, ComplexNumber& y){
        return ((x.re == y.re) && (x.im == y.im));
    }
    friend bool operator!= (ComplexNumber& x, ComplexNumber& y){
        return ((x.re != y.re) && (x.im != y.im));
    }
    ComplexNumber& operator =(const ComplexNumber& cn){
        this->re = cn.re;
        this->im = cn.im;
        return* this;
    }
    ComplexNumber& operator +=(const ComplexNumber& cn){
        this->re +=  cn.re;
        this->im +=  cn.im;
        return* this;
    }
    ComplexNumber& operator -=(const  ComplexNumber& cn){
        this->re -=  cn.re;
        this->im -=  cn.im;
        return* this;
    }
    ComplexNumber& operator *=(const  ComplexNumber& cn){
      this->re = (this->re * cn.re) - (this->im * cn.im);
      this->im = (this->re * cn.im) + (this->im * cn.re);
        return* this;
    }
    ComplexNumber& operator /=(const  ComplexNumber& cn){
        this->re = ((this->re * cn.re) + (this->im * cn.im))/(cn.re * cn.re + cn.im * cn.im);
        this->im = (this->re * cn.im) + (this->im * cn.re)/(cn.re * cn.re + cn.im * cn.im);
        return* this;
    }
    ComplexNumber& operator ~ (){
        this->re = this->re * (-1);
        this->im = this->im * (-1);
        return *this;
    }
    ComplexNumber& operator ! (){
        this->im = this->im * (-1);
        return *this;
    }
    ComplexNumber& operator ++ (int){
        this->im = this->im +1;
        return *this;
    }
    ComplexNumber& operator -- (int){
        this->im = this->im -1;
        return *this;
    }
    ComplexNumber& operator -- (){
        this->re = this->re -1;
        return *this;
    }
    ComplexNumber& operator ++ (){
        this->re = this->re +1;
        return *this;
    }
};
int main() {
    ComplexNumber a =  ComplexNumber(8,3);
    ComplexNumber b = ComplexNumber(4,5);
    cout << "a + b = " << a + b << endl;
    cout << "a - b  = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;
    cout << " a == b ? " << (a == b) << endl;
    cout << " a != b ? " << (a != b) << endl;
  //  cout << " a = b " << (a = b) << endl;
   // cout << " a += b " << (a+=b) << endl;
   // cout << " a -= b " << (a -= b) << endl;
   // cout << " a *= b " << (a *= b) << endl;
 //   cout << " a /= b " << (a /= b) << endl;
   //  cout << " ~a = " << ~a << endl;
   // cout << " !a = " << !a << endl;
   cout << " a ++   " << a++ << endl;
    cout << " a --   " << a-- << endl;
    cout << " ++ a  " << ++a << endl;
    cout << " -- a   " << --a << endl;
    return 0;
}
