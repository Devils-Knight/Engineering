#include<iostream>
#include<cstdio>
#include<iomanip>
#define max 100
using namespace std;
struct BAccount
{
	long long ac_no;
	char ac_na[50];
	double bal;
	int int_bank,ac_type;
	long pin_code;
}BA[max];
int n;
void insert()
{
	int i;
	cout<<"\n\t Enter number of Customers:";
	cin>>n;
	cout<<"\n\t Enter data for "<<n<<" Customers:\n";
	for(i=0;i<n;i++)
	{
		cout<<"\n\t Account Number:";
		cin>>BA[i].ac_no;
		cout<<"\n\t Account Holder Name:";
		fflush(stdin);
		cin.getline(BA[i].ac_na, 50);
		cout<<"\n\t Pincode (InBetween 422001 to 422013):";
		cin>>BA[i].pin_code;
		cout<<"\n\t Account Balance:";
		cin>>BA[i].bal;
		cout<<"\n\t Is Customer use Internet Banking(1.Yes & 2.No):";
		cin>>BA[i].int_bank;
		cout<<"\n\t Type of Account (1.Saving 2.Recurring 3.Deposit):";
		cin>>BA[i].ac_type;
	}
}
void customerType()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
	int i;
	cout<<"\n\n\t Golden Customers:\n";
	cout<<"\t-----------------------------------------------------\n";
	cout<<"\tAccountNo\tName\tPincode\tBalance";
	for(i=0;i<n;i++)
	{
		if(BA[i].bal>1000000)
			cout<<"\n\t"<<BA[i].ac_no<<"\t"<<BA[i].ac_na<<"\t"<<BA[i].pin_code<<"\t"<<BA[i].bal;
	}
	cout<<"\n\n\t Silver Customers:\n";
	cout<<"\t-----------------------------------------------------\n";
	cout<<"\tAccountNo\tName\tPincode\tBalance";
	for(i=0;i<n;i++)
	{
		if(BA[i].bal<=1000000 && BA[i].bal>500000)
			cout<<"\n\t"<<BA[i].ac_no<<"\t"<<BA[i].ac_na<<"\t"<<BA[i].pin_code<<"\t"<<BA[i].bal;
	}
	cout<<"\n\n\t General Customers:\n";
	cout<<"\t-----------------------------------------------------\n";
	cout<<"\tAccountNo\tName\tPincode\tBalance";
	for(i=0;i<n;i++)
	{
		if(BA[i].bal< 500000)
			cout<<"\n\t"<<BA[i].ac_no<<"\t"<<BA[i].ac_na<<"\t"<<BA[i].pin_code<<"\t"<<BA[i].bal;
	}
}
void intFacility()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
	int i;
	cout<<"\n\n\t Customers who Use Internet Facility:\n";
	cout<<"\t-----------------------------------------------------\n";
	cout<<"\tAccountNo\tName\tPincode\tBalance";
	for(i=0;i<n;i++)
	{
		if(BA[i].int_bank==1)
			cout<<"\n\t"<<BA[i].ac_no<<"\t"<<BA[i].ac_na<<"\t"<<BA[i].pin_code<<"\t"<<BA[i].bal;
	}
	cout<<"\n\n\t Customers who Don't Use Internet Facility:\n";
	cout<<"\t-----------------------------------------------------\n";
	cout<<"\tAccountNo\tName\tPincode\tBalance";
	for(i=0;i<n;i++)
	{
		if(BA[i].int_bank==2)
			cout<<"\n\t"<<BA[i].ac_no<<"\t"<<BA[i].ac_na<<"\t"<<BA[i].pin_code<<"\t"<<BA[i].bal;
	}
}
void searchByLocation()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
	long temppin,i;
	cout<<"\n\t Enter Pincode Customers belonging:";
	cin>>temppin;
	cout<<"\n\n\t Customers Belonging to this Location:\n",temppin;
	cout<<"\t-----------------------------------------------------\n";
	cout<<"\tAccountNo\tName\tBalance";
	for(i=0;i<n;i++)
	{
		if(BA[i].pin_code==temppin)
			cout<<"\n\t"<<BA[i].ac_no<<"\t"<<BA[i].ac_na<<"\t"<<BA[i].bal;
	}
}
void viewByAcType()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
	int i;
	cout<<"\n\n\t Saving Account Type Customers:\n";
	cout<<"\t-----------------------------------------------------\n";
	cout<<"\tAccountNo\tName\tPincode\tBalance";
	for(i=0;i<n;i++)
	{
		if(BA[i].ac_type==1)
			cout<<"\n\t"<<BA[i].ac_no<<"\t"<<BA[i].ac_na<<"\t"<<BA[i].pin_code<<"\t"<<BA[i].bal;
	}
	cout<<"\n\n\t Recurring Account Type Customers:\n";
	cout<<"\t-----------------------------------------------------\n";
	cout<<"\tAccountNo\tName\tPincode\tBalance";
	for(i=0;i<n;i++)
	{
		if(BA[i].ac_type==2)
			cout<<"\n\t"<<BA[i].ac_no<<"\t"<<BA[i].ac_na<<"\t"<<BA[i].pin_code<<"\t"<<BA[i].bal;
	}
	cout<<"\n\n\t Deposit Account Type Customers:\n";
	cout<<"\t-----------------------------------------------------\n";
	cout<<"\tAccountNo\tName\tPincode\tBalance";
	for(i=0;i<n;i++)
	{
		if(BA[i].ac_type==3)
			cout<<"\n\t"<<BA[i].ac_no<<"\t"<<BA[i].ac_na<<"\t"<<BA[i].pin_code<<"\t"<<BA[i].bal;
	}
}
int main()
{
	insert();
	customerType();
	intFacility();
	searchByLocation();
	viewByAcType();
	return 0;
}
