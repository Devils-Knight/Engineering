#include <iostream>
using namespace std;
int dd,mm,yy;
int magic_date(int dd,int mm,int yy){
    if (dd*mm==yy){
        cout<<"it is a magic date"<<endl;
    }
    else{
        cout<<"the date is not magic"<<endl;
    }}
int main(){
    int day,month,year;
    cout<<"----------PROGRAM TO FIND MAGIC DATES-------------"<<endl;
    cout<<"enter the day: "<<endl;
    cin>>day;
    cout<<"enter the month: "<<endl;
    cin>>month;
    cout<<"enter the year: "<<endl;
    cin>>year;
    magic_date(day,month,year);
    cout<<"Do you want to run the program again if yes type YES and ohterwise type NO"<<endl;
string y;
cin>>y;
if (y=="YES" or y=="yes"){
    goto again;
}
else{
    return 0;
}
again:
    main();
}
