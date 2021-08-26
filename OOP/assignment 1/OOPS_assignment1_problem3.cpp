#include <cstdio>
#include <iostream>

using namespace std;
string color1, color2;
void color_mixer(){
cout<<"--------COLOR MIXER----------"<<endl;
cout<<"please type the first color"<<endl;
cin>>color1;
cout<<"please type the second color"<<endl;
cin>>color2;

if ((color1=="RED" and color2=="BLUE") || (color2=="RED" and color1=="BLUE")){
    cout<<"the resultant color is PURPLE"<<endl;
}


if ((color1=="RED" and color2=="YELLOW") || (color2=="RED" and color1=="YELLOW")){
    cout<<"the resultant color is ORANGE"<<endl;
}


if ((color1=="YELLOW" and color2=="BLUE") || (color2=="YELLOW" and color1=="BLUE")){
    cout<<"the resultant color is GREEN"<<endl;
}




}
int main()
{
color_mixer();
cout<<"Do you want to run the program again if yes type YES and ohterwise type NO"<<endl;
string y;
cin>>y;
if (y=="YES" or y=="yes"){
    goto again1;
}
else{
    return 0;
}
again1:
    main();
return 0;
}










