#include<iostream>
using namespace std;
class calculator{
int num1,num2;
float result;
public:
void getData();
void putData();
void add();
void sub();
void mul();
void div();
void mod();
};
void calculator::getData(){
cout<<"Enter two numbers";
cin>>num1>>num2;
}
void calculator::putData(){
cout<<"Num1 = "<<num1<<"\tNum2 = "<<num2<<"\tResult = "<<result;
}
void calculator::add(){
result=num1+num2;
}
void calculator::sub(){
result=num1-num2;
}
void calculator::mul(){
result=num1*num2;
}
void calculator::mod(){
result=num1%num2;
}
void calculator::div(){
result=num1/float(num2);
}
int main(){
calculator c;
char choice, ans;
do
{
cout<<"\n**********MENU*************\n";
cout<<"1. +\n2. - \n3. * \n4. / \n5. %\n Enter your operator\n";
cin>>choice;
c.getData();

switch(choice)
{
case '+': c.add();
break;
case '-': c.sub();
break;
case '*': c.mul();
break;
case '/': c.div();
break;
case '%': c.mod();
break;
}
c.putData();
cout<<"\nDo you want to continue(Y/N)";
cin>>ans;
}while(ans=='Y' || ans=='y');
return 0;
}
