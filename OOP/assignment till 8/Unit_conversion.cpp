#include<iostream>
using namespace std;
int main(){
    float meter, Centimeter, KiloGram, Gram, Litres, meter_cube;
    int choice;
    char ans;
    do{

    statement1:
    cout<< "*****************ENTER YOUR CHOICE************************\n";
    cout<< "1 for Meter to Centimeter\n2 for Centimeter to meter\n3 for Gram to KiloGram\n4 for KiloGram to Gram\n5 for  Litres to meter cube\n6 for meter cube to Litres\n";
    cin>> choice;
    switch(choice){
	case 1:{
	    cout<< "Enter value in Meter(s)\n";
	    cin>> meter;
	    Centimeter= 100 * meter;
	    cout<<"Equivalent value of Centimeter is "<< Centimeter<<endl;
	    break;
    }
    case 2: {
	    cout<< "Enter value in Centimeter(s)\n";
	    cin>> Centimeter;
	    meter= Centimeter/100;
	    cout<<"Equivalent value of Meter is "<< meter<<endl;
	    break;
    }
    case 3: {
	    cout<< "Enter value in Gram(s)\n";
	    cin>> Gram;
	    KiloGram= Gram/1000;
	    cout<<"Equivalent value of KiloGram is "<< KiloGram<<endl;
	    break;
    }
    case 4: {
	    cout<< "Enter value in KiloGram(s)\n";
	    cin>> KiloGram;
	    Gram= KiloGram*1000;
	    cout<<"Equivalent value of Gram is "<< Gram<<endl;
	    break;
    }
    case 5: {
	    cout<< "Enter value in Litres(s)\n";
	    cin>> Litres;
	    meter_cube= Litres/1000;
	    cout<<"Equivalent value of meter_cube is "<< meter_cube<<endl;
	    break;
    }
    case 6: {
	    cout<<  "Enter value in meter cube \n";
	    Litres=  meter_cube*1000;
	    cout<<"Equivalent value of Litres is "<< Litres<<endl;
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


