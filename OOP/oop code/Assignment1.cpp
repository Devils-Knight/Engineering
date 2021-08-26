/* Problem Statement:
    Implement a class Complex which represents the Complex Number data type. Implement the following 
        1. Constructor (including a default constructor which creates the complex number 0+0i). 
        2. Overload operator+ to add two complex numbers. 
        3. Overload operator* to multiply two complex numbers. 
        4. Overload operators << and >> to print and read Complex Numbers.
*/


#include <bits/stdc++.h>
using namespace std;

class Complex{
    double re_, im_;
    public:
        Complex(double re = 0.0, double im = 0.0): re_(re), im_(im){   // default parameterised constructor

        }

        Complex(const Complex& c): re_(c.re_), im_(c.im_){             // copy constructor

        }

        ~Complex(){                                                    // destructor

        }

        Complex& operator=(const Complex& c){                          // copy constructor
            re_ = c.re_;
            im_ = c.im_;
            return *this;
        }

        void operator- (){                                             // negation of complex number
            re_ = -re_;
            im_ = -im_;
        }

        Complex operator+ (Complex const &obj1){                       // addition of complex numbers
            Complex obj2;
            obj2.re_ = re_ + obj1.re_;
            obj2.im_ = im_ + obj1.im_;
            return obj2;
        }

        Complex operator* (Complex const &obj3){                       // multiplication of complex numbers
            Complex multi;
            multi.re_ = re_*obj3.re_ - im_*obj3.im_;
            multi.im_ = re_*obj3.im_ + obj3.re_*im_;
            return multi;
        }

        friend ostream& operator<< (ostream& os, const Complex &a){    // input of complex numbers through cin >>
            os << a.re_ <<" + i" << a.im_ << endl;
            return os;
        }

        friend istream& operator>> (istream& is, Complex &a){          // output of complex number using cout << 
            is >> a.re_ >> a.im_;
            return is;
        }

        void print(){
            if(im_ >= 0){
                cout << re_ << " + i" << im_ << endl;
            }
            else{
                cout << re_ << " + i(" << im_ <<")" << endl;
            }
        }

        

};

int main(){
    Complex comp1(3, 2), comp2(1, 7);
    comp1.print();
    comp2.print();
    cout << "Sum of the above complex number is: ";
    Complex sum = comp2 + comp1;
    sum.print();
    cout << "Multiplication of the above complex numer is: ";
    Complex multi = comp1*comp2;
    multi.print();
    cout << "Enter the real and imaginary part of Complex number: "<< endl;
    Complex comp3;
    cin >> comp3;
    cout << comp3;
    cout << "Negation of the Complex number: ";
    -comp3;
    comp3.print();
    cout << endl;
}