#include<bits/stdc++.h>
using namespace std;


template <typename T>
class myStack
{

	T a[30]; int tope;

public:
	myStack()
	{
		tope = -1;
	}

	void push(T x)
	{

		tope++;
		a[tope] = x;

	}
	void pop();
	T top();
	bool isEmpty();


};


template <typename T>
void myStack<T> :: pop() {

	tope--;

}

template <typename T>
T myStack<T> :: top() {
	return a[tope];
}

template <typename T>
bool myStack<T> :: isEmpty() {

	if (tope == -1) return true;

	else return false;

}


void reverseString() {

	cout << "\n\nEnter string to be reversed : ";

	string s; cin >> s;

	myStack<char> st;

	for (int i = 0; i < s.length(); i++) {

		st.push(s[i]);

	}

	cout << "\n\nReversed string : ";

	for (int i = 0; i < s.length(); i++) {

		s[i] = st.top();
		st.pop();
		cout << s[i] << " ";

	}

}

void dec_to_bin() {

	cout << "\n\nEnter decimal number : ";

	int n; cin >> n;

	myStack<int> st;

	while (n) {

		st.push(n % 2);
		n /= 2;

	}

	cout << "Binary form : ";

	while (!st.isEmpty()) {

		cout << st.top();
		st.pop();

	}

}


signed main() {


	int flag = 1, ch;

	while (flag) {

		cout << "\n\n//-----------------------------------";
		cout << "\n1.Enter 1 to reverse a string.\n2.Enter 2 to convert a number from decimal to binary.\n3.Enter 0 to exit.\n\nEnter choice : ";
		cin >> ch;

		if (ch == 1) {

			reverseString();

		}

		else if (ch == 2) {

			dec_to_bin();

		}

		else flag = 0;

	}


	return 0;
}
