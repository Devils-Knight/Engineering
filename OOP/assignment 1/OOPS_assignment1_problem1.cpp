#include <iostream>

using namespace std;
int x;
void input(){
    cout<<"enter a number between 1 and 10: "<<endl;
    cin>>x;
    if (x<1 || x>10){
        cout<<"------please enter a valid input-----------"<<endl;
        input();
    }
}
int ming(){
cout<<"---------------PROGRAM TO CONVERT NUMBERS TO THEIR ROMAN FORMS---------------"<<endl;
input();
switch(x){
case 1:
    cout<<"I"<<endl;
    break;
case 2:
    cout<<"II"<<endl;
    break;
case 3:
    cout<<"III"<<endl;
    break;
case 4:
    cout<<"IV"<<endl;
    break;
case 5:
    cout<<"V"<<endl;
    break;
case 6:
    cout<<"VI"<<endl;
    break;
case 7:
    cout<<"VII"<<endl;
    break;
case 8:
    cout<<"VIII"<<endl;
    break;
case 9:
    cout<<"IX"<<endl;
    break;
case 10:
    cout<<"X"<<endl;
    break;
}
cout<<"Do you want to run the program again if yes type YES and ohterwise type NO"<<endl;
string y;
int flag=0;
cin>>y;
if (y=="YES" or y=="yes"){
    goto again;
}
else{
    return 0;
}
again:
    ming();
}
int main()
{

ming();

}







