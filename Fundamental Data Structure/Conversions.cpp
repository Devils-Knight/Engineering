#include <bits/stdc++.h>

using namespace std;

template<class T>

class stacks
{
    T st[100];
    int top;

    public:

    stacks(int length = 100)
    {
        top = -1;
    }

    T returnTop()
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
        if(top == 99)
            return true;
        else
            return false;
    }

    void push(T data)
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

    T returnPop()
    {
        return st[top--];
    }

    void display()
    {
        cout<<"\n\tStack elements : ";
        for(int i = top; i >= 0; i--)
        {
            cout<<st[i]<<" ";
        }
        cout<<endl;
    }

    ~stacks()
    {
        delete st;
    }
};

bool isOperand(char c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    else
        return false;
}

bool isOperator(char c)
{
    if(c == '+' || c == '-' || c == '/' || c == '*')
        return true;
    else
        return false;
}


bool isBalanced(stacks<char> stk, string s)
{
    char ch;
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

int precedence(char ch)
{
    if(ch == '+' || ch == '-')
    {
        return 1;
    }
    else if(ch == '*' || ch == '/')
    {
        return 2;
    }
}

bool isVariableRepeated(char c, map<char, int> a)
{
    map<char, int>::iterator itr;
    for(itr = a.begin(); itr != a.end(); ++itr)
    {
        if(c == itr->first)
            return true;
    }
    return false;
}

void evaluationOfPostfix(string s)
{
    stacks<int> stk;
    map<char, int> a;
    int size = s.size();

    for(int i = 0; i < size; i++)
    {
        if(isOperand(s[i]) && !isVariableRepeated(s[i],a))
        {
            int z;
            cout<<"\n\tEnter value of "<<s[i]<<" : ";
            cin>>z;
            a.insert(pair<char, int>(s[i], z));
            stk.push(z);
        }
        else if(isOperand(s[i]) && isVariableRepeated(s[i],a))
        {
            stk.push(a[s[i]]);
        }
        else if(isOperator(s[i]))
        {
            int Operand1,Operand2;

            Operand1 = stk.returnPop();
            Operand2 = stk.returnPop();

            if(s[i] == '+')
                stk.push(Operand2+Operand1);
            else if(s[i] == '-')
                stk.push(Operand2-Operand1);
            else if(s[i] == '*')
                stk.push(Operand2*Operand1);
            else if(s[i] == '/')
                stk.push(Operand2/Operand1);
        }
    }

    cout<<"\n\tValue : "<<stk.returnPop();
}

string toPostfix(stacks<char> stk, string s)
{
    char postFix[100];
    int j = 0;
    int size = s.size();

    for(int i = 0; i < size; i++)
    {
        if(s[i] == '(')
        {
            stk.push(s[i]);
        }
        else if(isOperand(s[i]))
        {
            postFix[j++] = s[i];
        }
        else if(isOperator(s[i]))
        {
            while(stk.returnTop() == '+' || stk.returnTop() == '-' || stk.returnTop() == '/' || stk.returnTop() == '*')
            {
                if(precedence(stk.returnTop()) >= precedence(s[i]))
                {
                    postFix[j++] = stk.returnPop();
                }
                else
                    break;
            }
            stk.push(s[i]);
        }
        else if(s[i] == ')')
        {
            while(stk.returnTop() != '(')
            {
                postFix[j++] = stk.returnPop();
            }
            stk.pop();
        }
    }
    while(!stk.isEmpty())
    {
        postFix[j++] = stk.returnPop();
    }
    postFix[j] = '\0';

    return postFix;
}

void InfixtoPostfix(stacks<char> stk, string s)
{
    if(!isBalanced(stk, s))
    {
        cout<<"\n\tExpression is not Balanced!!!";
        return;
    }

    string postFix = toPostfix(stk, s);

    cout<<"\n\tPostfix Expression : "<<postFix;

    char ch;
    cout<<"\n\n\tDo you want to evaluate this postfix expression (Y/N) : ";
    cin>>ch;
    if(ch == 'Y' || ch == 'y')
    {
        evaluationOfPostfix(postFix);
    }
}

void PostfixtoInfix(string s)
{
    stacks<string> stk;

    int size = s.size();

    for(int i = 0; i < size; i++)
    {
        if(isOperand(s[i]))
        {
            string op(1, s[i]);
            stk.push(op);
        }
        else if(isOperator(s[i]))
        {
            string operand1, operand2;
            operand1 = stk.returnPop();
            operand2 = stk.returnPop();
            stk.push("("+operand2+s[i]+operand1+")");
        }
    }

    cout<<"\n\tInfix Expression : "<<stk.returnPop();
}

void PostfixtoPrefix(string s)
{
    stacks<string> stk;

    int size = s.size();

    for(int i = 0; i < size; i++)
    {
        if(isOperand(s[i]))
        {
            string operand(1, s[i]);
            stk.push(operand);
        }
        else if(isOperator(s[i]))
        {
            string operand1, operand2;
            operand1 = stk.returnPop();
            operand2 = stk.returnPop();
            stk.push(s[i]+operand2+operand1);
        }
    }

    cout<<"\n\tPrefix Expression : "<<stk.returnPop();
}

string rev(string s)
{
    int size = s.size();

    for(int i = 0; i < size; i++)
    {
        if(s[i] == '(')
            s[i] = ')';
        else if(s[i] == ')')
            s[i] = '(';
    }

    reverse(s.begin(), s.end());

    return s;
}

void infixtoPrefix(string s)
{
    stacks<char> stk;
    if(!isBalanced(stk, s))
    {
        cout<<"\n\tExpression is not Balanced!!!";
        return;
    }
    s = rev(s);
    s = toPostfix(stk, s);
    s = rev(s);
    cout<<"\n\tPrefix Expression : "<<s;
}

int main()
{
    char ch = 'y';
    int choice;
    string s;
    do
    {
        stacks<char> stk;
        cout<<"\n\t\t\t\tCHOICE MENU";
        cout<<"\n\n\t1) Infix to Postfix";
        cout<<"\n\t2) Postfix to Infix";
        cout<<"\n\t3) Postfix to Prefix";
        cout<<"\n\t4) Infix to Prefix";
        cout<<"\n\n\tEnter your Choice (1-4) : ";
        cin>>choice;
        switch(choice)
        {
            case 1 : cout<<"\n\tEnter Infix Expression : ";
                     cin>>s;
                     InfixtoPostfix(stk, s);
                     break;
            case 2 : cout<<"\n\tEnter Postfix Expression : ";
                     cin>>s;
                     PostfixtoInfix(s);
                     break;
            case 3 : cout<<"\n\tEnter Postfix Expression : ";
                     cin>>s;
                     PostfixtoPrefix(s);
                     break;
            case 4 : cout<<"\n\tEnter Infix Expression : ";
                     cin>>s;
                     infixtoPrefix(s);
                     break;
            default: cout<<"\n\tWrong Choice!!!";
        }
        stk.~stacks();
        cout<<"\n\n\tDo you want to continue (Y/N) : ";
        cin>>ch;
    }while(ch == 'Y' || ch == 'y');
}
