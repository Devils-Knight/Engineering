#include <iostream>

using namespace std;

class stacks
{
    char *st;
    int top;
    int size;

    public:

    stacks(int length = 100)
    {
        size = length;
        st = new char[length];
        top = -1;
    }

    char returnTop()
    {
        return st[top];
    }

    bool isEmpty()
    {
        if(top == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if(top == size-1)
            return true;
        else
            return false;
    }

    void push(char data)
    {
        if(isFull())
        {
            cout<<"\n\tStack is Full!!!";
            return;
        }
        st[++top] = data;
    }

    void pop()
    {
        st[top--];
    }

    void display()
    {
        cout<<"\n\tStack elements : ";
        for(int i = 0; i <= top; i++)
        {
            cout<<st[i]<<" ";
        }
        cout<<endl;
    }

    ~stacks()
    {
        delete []st;
    }
}stk;

bool isBalanced(string s)
{
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '{' || s[i] == '(' || s[i] == '[')
            stk.push(s[i]);
        else if(s[i] == '}' || s[i] == ')' || s[i] == ']')
        {
            if(s[i] == '}' && stk.returnTop() == '{')
                stk.pop();
            else if(s[i] == ']' && stk.returnTop() == '[')
                stk.pop();
            else if(s[i] == ')' && stk.returnTop() == '(')
                stk.pop();
            else
                return false;
        }
    }

    if(stk.isEmpty())
        return true;
    else
        return false;
}

int main()
{
    char ch = 'y';
    string s;

    do
    {
        cout<<"\n\tEnter array : ";
        cin>>s;
        if(isBalanced(s))
        {
            cout<<"\n\tEquation is Balanced";
        }
        else
        {
            cout<<"\n\tEquation is not balanced";
        }
        cout<<"\n\tDo you want to continue (Y/N) : ";
        cin>>ch;
    }while(ch == 'Y' || ch == 'y');
}
