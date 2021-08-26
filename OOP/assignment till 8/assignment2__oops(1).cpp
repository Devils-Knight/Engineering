#include<bits/stdc++.h>
using namespace std;
int n;
union prize{
	int cash;
	char memonto[25];
};
struct  extra_ciricular_activites{
	int roll_no,prize_no;
	string name;
	int year;
	string activity_name;
	union prize prize_given;
};
struct extra_ciricular_activites eca[25];


void insert(){
	cout<<"\nNumber of students doing extra curricular activities ";
	cin>>n;
	cout<<"\nEnter the details"<<endl;
	for(int i=0;i<n;i++){
		cout<<"\nEnter Roll Number:.";
		cin>>eca[i].roll_no;
		cout<<"Enter Name:.";
		cin>>eca[i].name;
		cout<<"\nEnter Activity name:.";
		cin>>eca[i].activity_name;
		cout<<"Activity year:.";
		cin>>eca[i].year;
	    cout<<"Enter Prize type:.";
	    cout<<"\t\t Prize Type (1.By Cash 2.By Memento):";
		cin>>eca[i].prize_no;
		    if(eca[i].prize_no==1){
                cout<<"\t\t\t\tPrize amount:";
                cin>>eca[i].prize_given.cash;
            }
            else if(eca[i].prize_no==2){
                cout<<"\t\t\t\tMemento Name:";
                cin>>eca[i].prize_given.memonto;
            }
        cout << endl;
	}
}
int main(){
	insert();
	cout<<"\n\tEnter the details"<<"\n";

	cout<<"\n\t Roll No\tName\tActivity\tYear\tPrizetype\tPrize \n";
	for(int i=0;i<n;i++){
			cout<<"\n\t"<<eca[i].roll_no<<"\t"<<eca[i].name<<"\t"<<eca[i].activity_name<<"\t"<<eca[i].year;
		if(eca[i].prize_no==1)
			cout<<"\tBy Cash       \t"<<eca[i].prize_given.cash;
		else
			cout<<"\tBy Memento        \t"<<eca[i].prize_given.memonto;
	}
	}



