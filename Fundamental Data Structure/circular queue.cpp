#include <bits/stdc++.h>

using namespace std;
#define Size 4

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
    int insrt(int);
    int del();
    void disp();
}Q;



int que::insrt(int el)
{
    if(Q.frnt==(Q.rear+1)%Size)
        cout<<"Queue is Full ";
    else
    {
        if(Q.frnt==-1)
        {
            Q.frnt = 0;
            Q.rear = 0;
        }
        else
            Q.rear = (Q.rear+1)%Size;
        arr[Q.rear] = el;
    }
}

int que::del()
{
    int deleted ;
    if(Q.frnt==-1)
    {
        cout<<"Queue is Empty ";
        return 0;
    }
    deleted = arr[Q.frnt];
    arr[Q.frnt]=-1;
    cout<<"Element Deleted is :"<<deleted;
    if(Q.frnt!=Q.rear)
    {
        Q.frnt=(Q.frnt+1)%Size;
    }
    return deleted;

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


