#include<bits/stdc++.h>

using namespace std;

class linked
{
private:
    struct node
    {
        string process;
        int time;
        node *next;
        node *prev;
    }*head;
public:
    linked();
    void create();
    void display();
    void process(int);
    ~linked();
};

linked::linked()
{
    head = NULL;
}

void linked::create()
{
    char ch;
    int num = 1;
    node *New , *temp;
    do
    {
        New = new node;
        New->next = NULL;
        New->prev = NULL;
        cout<<"\nEnter the Name of Process :";
        cin>>New->process;
        cout<<"\nEnter Time for Process :";
        cin>>New->time;

        if(num==1)
        {
            head = New;
            New->next = head;
            New->prev = head;
            num = 0;
        }
        else
        {
            temp = head;
            while(temp->next != head)
                temp = temp->next;
            temp->next = New;
            New->prev = temp;
            New->next = head;
            head->prev = New;
        }
        cout<<"\nDo you want to Enter more processes ? (Y/y)";
        cin>>ch;
    }while(ch == 'y'||ch == 'Y');
}
void linked::display()
{
    node *temp;
    temp = head;
    if(temp==NULL)
        cout<<"\nEmpty";
    else
    {
        do
        {
            cout<<" \n"<<temp->process<<"( "<<temp->time<<" )";
            temp=temp->next;
        }while(temp!=head);
    }
}

linked::~linked()
{
    node *temp,*t1;
    temp = head->next;
    delete head;
    while(temp!=NULL)
    {
        t1 = temp->next;
        delete temp;
        temp = t1;
    }
}

void linked::process(int x)
{
    node *temp,*t1;
    int time=0;
    temp = head;
    cout<<"\n--------------------------------\n--------------------------------\n";
    cout<<"      Process     Waiting Time\n";
    while(temp!=NULL)
    {
        if(temp->time <= x)
        {
            //cout<<"\nProcess "<<temp->process<<" Ended ";
            cout<<"\t"<<temp->process<<"\t\t"<<time+temp->time<<"\n";
            time+=temp->time;
            if(temp->next == temp)
                break;
            t1=temp->prev;
            t1->next = temp->next;
            temp->next->prev = t1;
            delete temp;
            temp = t1->next;
        }
        else
        {
            //cout<<"\nProcess "<<temp->process<<" remaining :"<<temp->time - x;
            temp->time -= x;
            time+=x;
            temp=temp->next;
        }
    }
    cout<<"\n--------------------------------\n--------------------------------\n";
}

int main()
{
    int n;
    linked jobs;
    jobs.create();
    jobs.display();
    cout<<"\nEnter the Time Slice :";
    cin>>n;
    jobs.process(n);
    return 0;
}
