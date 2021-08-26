#include <bits/stdc++.h>
using namespace std;
class Heap
{
	int ar[100];
	int len;

public:
	Heap()
	{
		len = 0;
	}
	void heapify(int index)
	{
		int largest = index;
		if (2 * index <= len && ar[2 * index] > ar[largest])
		{
			largest = 2 * index;
		}
		if (2 * index + 1 <= len && ar[2 * index + 1] > ar[largest])
		{
			largest = 2 * index + 1;
		}
		if (largest != index)
		{
			swap(ar[largest], ar[index]);
			heapify(largest);
		}
	}
	int getLatest()
	{
		if (len == 0)
		{
			cout << "Error heap is empty\n";
			return -1;
		}
		int maxi = ar[1];
		swap(ar[1], ar[len]);
		len--;
		if (len != 0)
			heapify(1);
		return maxi;
	}
	void insert(int data)
	{
		len++;
		ar[len] = data;
		int i = len;
		while (i > 1 && ar[i / 2] < ar[i])
		{
			swap(ar[i / 2], ar[i]);
			i = i / 2;
		}
	}
	void display()
	{
		for (int i = 1; i <= len; i++)
		{
			cout << ar[i] << " ";
		}
		cout << " ";
	}
};
int main()
{
	int val;
	char flag = 'y';
	Heap h1;
	while (flag == 'y'||flag=='Y')
	{

		cout << "1. Add to Queue\n";
		cout << "2. Remove from Queue\n";
		cout << "3. Display the Queue\n";
		cout << "Enter your choice : ";
		char ch;
		cin >> ch;
		switch (ch)
		{
		case '1':
			cout << "\nEnter the value you want to add to the Queue : ";
			cin >> val;
			h1.insert(val);
			break;
		case '2':
			cout << "\nThe value remove from Queue is : ";
			cout << h1.getLatest() << "\n";
			break;
		case '3':
			h1.display();
			break;
		default:
			cout << "Invalid choice\n";
		}
		cout << "\n\nDo you wish to continue (y/Y) : ";
		cin >> flag;
	}

	return 0;
}
