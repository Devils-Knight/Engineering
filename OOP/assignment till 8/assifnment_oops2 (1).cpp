#include<bits/stdc++.h>
using namespace std;
int n;

struct Information_of_items{
	int Item_number;
	string Item_name,Item_category;
	double price,Available_stock;
	string manufacturing_date;
};
struct Information_of_items ii[25];
void insert(){
	cout<<"Number of Items:.";
	cin>>n;
	cout<<"\nEnter the list of Items"<<endl;
	for(int i=0;i<n;i++){

	cout<<"\nItem Number:.";
	cin>>ii[i].Item_number;
	cout<<"Item Name:.";
	cin>>ii[i].Item_name;
	cout<<"Item Category:.";
	cin>>ii[i].Item_category;
	cout<<"Price of Item:.";
	cin>>ii[i].price;
	cout<<"Manufacturing date:.";
	cin>>ii[i].manufacturing_date;
	cout<<"Available Stock:.";
	cin>>ii[i].Available_stock;
}

}



int main(){
	insert();
	cout<<"\nITEM DETAILS";
	cout<<setw(20)<<"\nItem number"<<setw(20)<<"\tItem name"<<setw(20)<<"\tItem Category"<<setw(20)<<"\tItem Price"<<setw(20)<<"\tAvailable stock"<<setw(20)<<"\tManufacturing date"<<"\n";
	for(int i=0;i<n;i++){
		cout<<setw(10)<<ii[i].Item_number<<setw(20)<<ii[i].Item_name<<setw(20)<<ii[i].Item_category<<setw(20)<<ii[i].price<<setw(20)<<ii[i].Available_stock<<setw(20)<<ii[i].manufacturing_date<<"\n";
	}
	return 0;
}
