#include<iostream>
using namespace std;
int main(){
    float usd, rup, pound;
    int choice;
    char ans;
    do{

    statement1:
    cout<< "*****************ENTER YOUR CHOICE************************\n";
    cout<< "1 for USD to Indian rupees\n2 for Indian rupees to USD\n3 for USD to British Pound\n4 for British pound to USD\n5 for  Indian rupees to British Pound\n6 for British Pound to Indian rupees\n";
    cin>> choice;
    switch(choice){
	case 1:{
	    cout<< "Enter value in USD\n";
	    cin>> usd;
	    rup= 74.67 * usd;
	    cout<<"Equivalent value of Indian rupees is "<< rup<<endl;
	    break;
    }
    case 2: {
	    cout<< "Enter value in Indian rupees\n";
	    cin>> rup;
	    usd=  rup/ 74.67;
	    cout<<"Equivalent value of USD is "<< usd<<endl;
	    break;
    }
    case 3: {
	    cout<< "Enter value in USD\n";
	    cin>> usd;
	    pound= 0.79*usd;
	    cout<<"Equivalent value of British pound is "<< pound<<endl;
	    break;
    }
    case 4: {
	    cout<< "Enter value in British pound\n";
	    cin>> pound;
	    usd=  pound/0.79;
	    cout<<"Equivalent value of USD is "<< usd<<endl;
	    break;
    }
    case 5: {
	    cout<< "Enter the value in Indian rupees \n";
	    cin>> rup;
	    pound=rup/95.07;
	    cout<<"Equivalent value of  British pound is "<< pound<<endl;
	    break;
    }
    case 6: {
	    cout<<  "Enter value in b_pound \n";
	    rup=  pound*95.07;
	    cout<<"Equivalent value of Indian rupees is "<< rup<<endl;
	    break;
    }
    default: {
	    cout<< " Wrong choice \n";
	    goto statement1;
    }
    }
    cout<< "Do you want to continue (Y/N)";
    cin>> ans;
    }while(ans=='y'|| ans=='Y');
}

