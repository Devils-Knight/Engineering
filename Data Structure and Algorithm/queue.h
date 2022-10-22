#include <iostream>
using namespace std;

//Improving our code with templates and complexity to O(1)
template<typename t>

class node{
    t data;
    node<t>* next;
    node(t data){
        this->data=data;
        next=NULL;
    }
    template<typename s>
    friend class queue;
};

template<typename s>

class queue{
    node<s> *head=NULL , *tail=NULL;
    int curr_size=0;
    public:
    void enqueue(s data){
        if(head==NULL){
            head=new node<s>(data);
            tail=head;
            curr_size++;
            return;
        }
        tail->next=new node<s>(data);
        tail=tail->next;
        curr_size++;
    }

    void dequeue(){
        if(head==NULL){
            cout<<"Queue is empty"<<endl;
            return;
        }
        node<s>* newnode=head;
        head=newnode->next;
        // cout<<"Popped element is: "<<newnode->data<<endl;
        delete newnode;
        curr_size--;
    }


    s front(){
        try {
        if(head!=NULL)
            return head->data;
        else
            throw 505;
        }
        catch(int error){
            cout<<"Queue is Empty"<<endl;
        }
    }

    int size(){
        return curr_size;
    }

    bool isempty(){
        if(head==NULL)
            return true;
        else
            return false;        
    }
};
/**
int main(){
    queue<float> q;
    cout<<"-----------------Empty queue test result----------------------"<<endl;
    cout<<"Is queue empty: ";q.isempty()?cout<<"yes"<<endl:cout<<"no"<<endl;
    cout<<"Front element of queue: "<<q.front()<<endl;
    cout<<"Size of queue: "<<q.size()<<endl;
    q.dequeue();
    cout<<"-----------------Filled queue test result----------------------"<<endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout<<"Is queue empty: ";q.isempty()?cout<<"yes"<<endl:cout<<"no"<<endl;
    cout<<"Front element of queue: "<<q.front()<<endl;
    cout<<"Size of queue: "<<q.size()<<endl;
    cout<<"-----------------Popped queue test result----------------------"<<endl;
    q.dequeue();
    cout<<"Front element of queue: "<<q.front()<<endl;
    cout<<"Size of queue: "<<q.size()<<endl;
    q.dequeue();
    cout<<"Front element of queue: "<<q.front()<<endl;
    cout<<"Size of queue: "<<q.size()<<endl;
    q.dequeue();
    cout<<"Front element of queue: "<<q.front()<<endl;
    cout<<"Size of queue: "<<q.size()<<endl;
    q.dequeue();
    return 0;
}
**/
