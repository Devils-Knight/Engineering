#include <bits/stdc++.h>

using namespace std;

#define Max 100
class Stack
{
    int top;
public:
    char a[Max];
    Stack()
    {
        top = -1;
    }

    bool push(char x);
    char pop();
    char peek();
    bool isEmpty();
    char next();
    char prev();

};

bool Stack::push(char x)
{
    if (top >= (Max-1))
    {
        cout<<"\nStack Overflow ";
        return false;
    }
    else
    {
        a[++top] = x;
        //cout<<"\nPushed element "<<a[top]<<"into stack ";
        return true;
    }
}
char Stack::pop()
{
    if(top<0)
    {
        cout<<"\nStack Underflow";
        return 0;
    }
    else
    {
        //cout<<"\nElement "<<a[top]<<"popped out";
        char x= a[top--];
        return x;
    }
}


char Stack::peek()
{
    return (a[top]);
}


bool Stack::isEmpty()
{
    return (top < 0);

}

char Stack::next()
{
    if (top<Max)
    {
      return (a[top+1]);
    }
}

char Stack::prev()
{
    if (top<Max)
    {
      return (a[top-1]);
    }
}

void checkBalancing(Stack s , char st[])
{
    Stack c;
    char ch;

    if (s.isEmpty())
    {
        cout<<"The given Equation is balanced\n\n\n";
    }
     else
     {
        char p,n;
        int i=0;
        while (true)
        {
            if(s.isEmpty())
                break;
            c.push(s.pop());
            if(i>0)
            {
                int k = abs(int(c.peek()) - int(c.prev()));
                if (k != 0 && k <= 2)
                {
                    c.pop();
                    c.pop();
                }
            }
            i++;
        }
        if(c.isEmpty())
        {
            cout<<"The given Equation is Balanced\n\n\n";
        }
        else
        {
            cout<<"The given Equation is Not balanced\n\n\n";
        }
     }
}


int main()
{
    char st[100];
    Stack s;
    char choice;
    int ch =0;
    cout<<"\nEnter any expression you want to check : ";
    cin>>st;
    while(st[ch] != '\0')
    {
        if (st[ch] == '(' || st[ch] == ')' ||st[ch] == '{' ||st[ch] == '}' ||st[ch] == '[' ||st[ch] == ']')
            {
                s.push(st[ch]);
            }
        ch++;
    }

    checkBalancing(s,st);
    cout<<"\nTHANKYOU";
    return 0;
}
