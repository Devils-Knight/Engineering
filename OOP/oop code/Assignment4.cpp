#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
    ofstream fobj;
    fobj.open("student.txt");
    char name[30], dob[30], address[30];
    cout << "Enter name of student :";
    cin.getline(name,30);
    fobj << name << endl;
    
    cout << "Enter student's date of birth :";
    cin.getline(dob,30);
    fobj << dob << endl;

    cout << "Enter the address of student :";
    cin.getline(address,30);
    fobj << address << endl;
    fobj.close();

    ifstream file;
    cout << endl << "Details of student  :" << endl;
    file.open("student.txt");
    char c;
    while (!file.eof())
    {
        file.get(c);
        cout << c;
    }
    file.close();
    return 0;
}
