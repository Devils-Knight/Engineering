#include<iostream>
using namespace std;
class Complex
{
	float real,img;
	public:
		Complex()
		{
			real=0.0f;
			img=0.0f;
		}
		Complex(float a,float b)
		{
			real=a;
			img=b;
		}

		Complex &operator+(Complex c1)
		{
			Complex temp;
			temp.real=real+c1.real;
			temp.img=img+c1.img;
			return temp;
		}

		Complex operator-(Complex c1)
		{
			Complex temp;
			temp.real=real-c1.real;
			temp.img=img-c1.img;
			return temp;
		}

		Complex operator*(Complex c1)
		{
			Complex temp;
			temp.real=(real*c1.real)-(img*c1.img);
			temp.img=(img*c1.real)+(real*c1.img);
			return temp;
		}

		Complex operator/(Complex c1)
		{
			Complex temp,c2;
			c2.img=-c1.img;
			float x;
			temp.real=(real*c1.real)-(img*(c2.img));
			temp.img=(real*c2.img)+(img*(c1.real));
			x=(c1.real)*(c1.real)-(c1.img)*(c2.img);
			temp.real=temp.real/x;
			temp.img=temp.img/x;
			return temp;
		}

		friend ostream &operator<<(ostream &out, Complex &c)
		{
			out << c.real<<" + "<< c.img<<" i";;
			return out;
		}

		friend istream &operator>>(istream &in, Complex &c)
		{
			in>> c.real>>c.img;
			return in;
		}
};
int main()
{
	Complex c1,c2,c3;
	int choice;
	char ans;
	do
	{
		cout<<"\n**************************MENU *********************************\n";
		cout<<"\n\t1.Addition\n\t2.Subtraction\n\t3.Multiplication\n\t4.Division";
		cout<<"\n\n\tEnter your choice: ";
		cin>>choice;
		cout<< "\tEnter real and img part of first complex number\n\t";
		cin>>c1;
		cout<< "\tEnter real and img part of second complex number\n\t";
		cin>>c2;
		switch(choice)
		{
			case 1:	c3=c1+c2;
					cout<<"\n\tAddition is: ";
					cout<<c3;
					break;
			case 2:	c3=c1-c2;
					cout<<"\n\tSubtraction is: ";
					cout<<c3;
					break;
			case 3:	c3=c1*c2;
					cout<<"\n\tMultiplication is: ";
					cout<<c3;
					break;
			case 4:	c3=c1/c2;
					cout<<"\n\tDivision is: ";
					cout<<c3;
					break;
			default:cout<<"\n\tWrong choice";
		}
		cout<<"\n\tDo you want to continue?(y/n): ";
		cin>>ans;
	}while(ans=='y' || ans=='Y');
	return 0;
}
