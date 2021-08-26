#include<bits/stdc++.h>
using namespace std;

class Student{

    public:

    string name;
    string DOB;
    long long phone_no;

    Student() {

    }
    
   Student(string naam, string dob, long long telephone){
       name = naam;
       DOB = dob;
       phone_no = telephone;
   }

   Student(const Student &stu){  // copy constructor
       name = stu.name;
       DOB = stu.DOB;
       phone_no = stu.phone_no;
   }
   ~Student(){  // destructor

   }

   void getDetails(){
       cout << endl << "Enter the student details ......." << endl;
       cout << "Name:";
       cin >> name;
       cout  << "Date of Birth: "; 
       cin >> DOB;
       cout  << "Phone number: "; 
       cin >> phone_no;
       cout << endl;
   }

   void showDetails(){
       cout << endl << "The Student details are as follow: " << endl;
       cout << "Name: " << name << endl;
       cout << "Date of Birth: " << DOB << endl;
       cout << "Phone number: "<< phone_no << endl;
   }

};

bool compatator (Student a, Student b) {
    return a.name < b.name;
}

int main()
{
    int number;
    vector<Student>records;
    
    cout << "Enter the number of students :";
    cin >> number;

    for (int i = 0; i < number; i++) {
        Student st;
        st.getDetails();
        records.push_back(st);
    }

    sort(records.begin(), records.end(), compatator);
    
    cout << "Records in sorted order with respect to name: " << endl;
    for (int i = 0; i < records.size(); i++) {
        cout << records[i].name << " ";
    }
    cout << endl;

    string inp;
    cout << "Enter the name of person for corresponding records :";
    cin >> inp;

    bool flag = false;
    for (int i = 0; i < records.size(); i++) {
        if (records[i].name == inp) {
            records[i].showDetails();
            flag = true;
            break;
        }
    }
    if (flag == false) {
        cout << "No data found" << endl;
    }

}