#include <bits/stdc++.h>
using namespace std;


template <class T>
void selectionSort(T arr[], int n)
{
    int min_idx;
    for (int i = 0; i < n; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[min_idx], arr[i]);
        } 
    }
}

int main()
{

    int int_arr[5];
    double float_arr[5];

    cout <<"Enter the values of integer array to be sorted: " << endl;
    for (int i  = 0; i < 5; i++) {
        cin >> int_arr[i];
    }

    selectionSort(int_arr, 5);

    cout << "Soreted array is: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << int_arr[i] << " ";
    }
    cout << endl;

    cout << "Enter the elements of float array to be sorted: " << endl;
    for (int i = 0; i < 5; i++) {
        cin >> float_arr[i];
    }

    selectionSort(float_arr, 5);
    cout << "Sorted float array is: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << float_arr[i] << " ";
    }
    cout << endl;

    return 0;
}
