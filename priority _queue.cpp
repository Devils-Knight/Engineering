#include<iostream>
#include <queue>
using namespace std;

int main() {

  
  priority_queue<int> numbers;

  numbers.push(1);
  numbers.push(20);
  numbers.push(7);

  cout << "Priority Queue: ";

  while(!numbers.empty()) {
    cout << numbers.top() << ", ";   
    numbers.pop();
  }

  cout << endl;

  return 0;
}
