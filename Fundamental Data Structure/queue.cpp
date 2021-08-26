#include <bits/stdc++.h>

using namespace std;
#define Size 10

class que
{
public:
    int arr[Size];
    int frnt,rear;
    que()
    {
        frnt = -1;
        rear = -1;
    }
    void star()
    {
        for(int i=0;i<Size;i++)
            arr[i] = -1;
    }
    bool isFull();
    bool isEmpty();
    int insrt(int);
    int del();
    void disp();
}Q;

bool que::isFull()
{
    if( Q.rear >= Size-1)
        return true;
    return false;
}

bool que::isEmpty()
{
    if(Q.frnt==-1||Q.frnt>Q.rear)
        return true;
    return false;
}

int que::insrt(int el)
{
    if(Q.isFull())
    {
        cout<<"\nQueue is Full ";
    }
     else
     {
         if(Q.frnt==-1)
            Q.frnt++;
         Q.arr[++rear] = el;
         cout<<"\nInserted the element "<<el;
     }
    return Q.rear;
}

int que::del()
{
    if(Q.isEmpty())
    {
        cout<<"\nQueue is Empty ";
    }
    else
    {
        int deleted;
        deleted = Q.arr[frnt];
        Q.arr[frnt] = -1;
        Q.frnt++;
        cout<<"\nElement deleted is : "<<deleted;
    }
    return Q.frnt;
}

void que::disp()
{
    cout<<"\n";
    for(int i=0;i<Size;i++)
        cout<<Q.arr[i]<<"   ";
}

int main()
{
    int ch,val;
    Q.star();
    start:
    cout<<"\n\n1.Display Queue\n2.Insert an Element\n3.Delete Element\n4.Exit\n";
    cin>>ch;
    switch(ch)
    {
        case 1: Q.disp();
                break;
        case 2: cout<<"Enter the element to insert : ";
                cin>>val;
                Q.insrt(val);
                break;
        case 3: Q.del();
                break;
        case 4: return 0;
        default : goto start;
    }
    goto start;
}


