#include<iostream>

using namespace std;


int main()
{
    int arr[100];
    int i=0, maxm, minm;
    cout<<"\n Enter the series of integers. Enter -99 to indicate the end of the series.\n";
    cout<<"\n --------------------Start entering the integers:-------------------------- \n";
    while(1)
    {   cin>>arr[i];
        if(arr[i] == -99)
            break;
        else
        {
            if(i == 0)
            {
                maxm = arr[0];
                minm = arr[0];
            }
            else
            {
                if(arr[i] > maxm)
                    maxm = arr[i];
                else if(arr[i] < minm)
                    minm = arr[i];
            }
            i++;
        }
    }
    cout<<"\n -------------------------------------------------------------------------- \n";
    cout<<"\n The largest of the integers entered is: "<<maxm<<"\n";
    cout<<"\n The smallest of the integers entered is: "<<minm<<"\n";
    return 0;
}

