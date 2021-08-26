#include <bits/stdc++.h>
using namespace std;

map<string, int> population;

void insertData() {
    cout << "Enter the number of states ";
    int no_of_states;
    cin >> no_of_states;
    for (int i = 0; i < no_of_states; i++) {
        string name;
        int pop;
        cout << "Enter the name of state: ";
        cin >> name;
        cout << "Enter the population: ";
        cin >> pop;
        cout << endl;
        population.insert({name, pop});
    }
}

void getData() {
    string name;
    cout << "Enter the name of state: ";
    cin >> name;
    map<string, int>::iterator it;
    it = population.find(name);
    if (it != population.end()) {
        cout <<"Population of " << name << " is " << population[name] << endl;
    }
    else {
        cout << "The state does not exist." << endl;
    }
}

void delData() {
    string name;
    cout << "Enter the name of state :";
    cin >> name;
    population.erase(name);
}

void showData() {
    for (auto it = population.begin(); it != population.end(); it++) {
        cout << "State : " << it->first <<" " << "Population : " << it->second << endl;
    }
}

int main() {

    while (true)
    {
        cout << endl << "Enter your choice :" << endl;
        cout << "1. Enter the state and population " << endl;
        cout << "2. Find the population of state" << endl;
        cout << "3. Erase the data of state" << endl;
        cout << "4. Show the complete data" << endl;
        cout << "5. exit" << endl;

        int choice;
        cin >> choice;
        if (choice == 1) {
            insertData();
        }
        else if (choice == 2) {
            getData();
        }
        else if (choice == 3) {
            delData();   
        }
        else if (choice == 4) {
            showData();
        }
        else if (choice ==5) {
            return 0;
        }
        else {
            cout << "Try agian" << endl;
        }
    }
    
    return 0;
}