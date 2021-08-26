#include <iostream>

using namespace std;

class node
{
    int bit;

    public:

    node* next;
    node* prev;

    node()
    {
        next = NULL;
        prev = NULL;
    }

    int returnBit()
    {
        return bit;
    }

    void setData(int b)
    {
        bit = b;
    }
};

class DLOperations
{
    public:

    node* head;

    int Count;

    DLOperations()
    {
        head = NULL;
        Count = 0;
    }

    void InsertatBeg(int bit)
    {
        node* temp = new node();
        temp->setData(bit);

        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        Count++;
    }

    void InsertatEnd(int bit)
    {
        node* temp = new node();
        temp->setData(bit);
        temp->next = NULL;

        if(head == NULL)
        {
            head = temp;
            Count++;
            return;
        }

        node* temp1 = head;

        while(temp1->next != NULL)
            temp1 = temp1->next;

        temp1->next = temp;
        temp->prev = temp1;
        Count++;


    }

    void InsertatPos(int x, int bit)
    {
        node* temp = new node();
        temp->setData(bit);

        if(head == NULL && x == 1)
        {
            head = temp;
            Count++;
            return;
        }

        if(x > Count)
        {
            cout<<"\n\tPosition entered is out of range";
            return;
        }

        if(Count == 1 && x == 1)
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
            return;
        }

        node* temp1 = head;

        for(int i = 0; i < x-1; i++)
            temp1 = temp1->next;

        temp->next = temp1;
        temp->prev = temp1->prev;
        temp1->prev->next = temp;
        temp1->prev = temp;
        Count++;
    }

    void DeleteBeg()
    {
        if(head == NULL)
        {
            cout<<"\n\tEmpty!!!..Nothing to delete";
            return;
        }
        node* temp = head;
        head = temp->next;
        head->prev = NULL;
        delete temp;
        Count--;
    }

    void DeleteEnd()
    {
        if(head == NULL)
        {
            cout<<"\n\tEmpty!!!..Nothing to delete";
            return;
        }

        node* temp = head;

        for(int i = 0; i < Count-1; i++)
            temp = temp->next;

        temp->prev->next = NULL;
        delete temp;
        Count--;
    }

    void DeletebyPos(int x)
    {
        if(x > Count)
        {
            cout<<"\n\tPosition entered does not exist";
            return;
        }

        node* temp = head;

        for(int i = 0; i < Count-1; i++)
            temp = temp->next;

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        Count--;
    }

    void display()
    {
        node* temp = head;
        cout<<"\n\tBinary Number : ";

        while(temp != NULL)
        {
            cout<<(temp->returnBit());
            temp = temp->next;
        }
    }

    ~DLOperations()
    {
        while(head != NULL)
        {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class BinaryNumber: public DLOperations
{
    public:

    int c, n, p;

    BinaryNumber()
    {
        n = 1;
        p = 0;
    }

    void setBinaryNumber(int d)
    {
        if(d == 0)
        {
            InsertatBeg(0);
            return;
        }
        while(d != 0)
        {
            InsertatBeg(d%2);
            d /= 2;
        }
    }

    void onesComplement(node* h)
    {
        int bit;
        node* temp = h;
        while(temp != NULL)
        {
            bit = temp->returnBit();
            InsertatEnd((bit+1)%2);
            temp = temp->next;
        }
    }

    void twosComplement(node* h)
    {
        int bit;
        node* temp1 = h;
        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        while(temp1 != NULL)
        {
            bit = temp1->returnBit();

            c = (bit+n)%2;
            n = (bit+n)/2;

            InsertatBeg(c);

            temp1 = temp1->prev;
        }
        if(n != 0)
            InsertatBeg(n);
    }

    void binaryAddition(node* h1, node* h2)
    {
        int bit1, bit2;

        node* temp1 = h1;
        node* temp2 = h2;

        while(temp1->next != NULL)
            temp1 = temp1->next;

        while(temp2->next != NULL)
            temp2 = temp2->next;

        while(temp1 != NULL && temp2 != NULL)
        {
            bit1 = temp1->returnBit();
            bit2 = temp2->returnBit();

            c = (bit1+bit2+p)%2;
            p = (bit1+bit2+p)/2;

            InsertatBeg(c);

            temp1 = temp1->prev;
            temp2 = temp2->prev;
        }

        while(temp1 != NULL)
        {
            bit1 = temp1->returnBit();

            c = (bit1 + p) % 2;
            p = (bit1 + p) / 2;

            InsertatBeg(c);

            temp1 = temp1->prev;
        }

        while(temp2 != NULL)
        {
            bit2 = temp2->returnBit();

            c = (bit2 + p) % 2;
            p = (bit2 + p) / 2;

            InsertatBeg(c);

            temp2 = temp2->prev;
        }

        if(p != 0)
            InsertatBeg(p);
    }

    void display()
    {
        DLOperations::display();
    }

    ~BinaryNumber()
    {
        while(head != NULL)
        {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    BinaryNumber b, b1, b2;
    int decimal, decimal1;
    char ch = 'Y';
    int choice;
    do
    {
        cout<<"\n\n\t\t\tSELECT THE CHOICE";
        cout<<"\n\n\t1) Display Binary equivalent of decimal number";
        cout<<"\n\t2) Find 1's Complement";
        cout<<"\n\t3) Find 2's Complement";
        cout<<"\n\t4) Addition of two Binary number";
        cout<<"\n\n\tEnter your Choice (1-4) : ";
        cin>>choice;
        switch(choice)
        {
            case 1 : cout<<"\n\tEnter Decimal Number : ";
                     cin>>decimal;
                     b.setBinaryNumber(decimal);
                     b.display();
                     b.~BinaryNumber();
                     break;

            case 2 : cout<<"\n\tEnter Decimal Number : ";
                     cin>>decimal;
                     b.setBinaryNumber(decimal);
                     b1.onesComplement(b.head);
                     cout<<"\n\n\t\tBinary Equivalent of entered decimal number"<<endl;
                     b.display();
                     cout<<"\n\n\t\t\t1's Complement"<<endl;
                     b1.display();
                     b.~BinaryNumber();
                     b1.~BinaryNumber();
                     break;

            case 3 : cout<<"\n\tEnter Decimal Number : ";
                     cin>>decimal;
                     b.setBinaryNumber(decimal);
                     b1.onesComplement(b.head);
                     b2.twosComplement(b1.head);
                     cout<<"\n\n\t\tBinary Equivalent of entered decimal number"<<endl;
                     b.display();
                     cout<<"\n\n\t\t\t1's Complement"<<endl;
                     b1.display();
                     cout<<"\n\n\t\t\t2's Complement"<<endl;
                     b2.display();
                     b.~BinaryNumber();
                     b1.~BinaryNumber();
                     b2.~BinaryNumber();
                     break;

            case 4 : cout<<"\n\n\tEnter 1st decimal number : ";
                     cin>>decimal;
                     b.setBinaryNumber(decimal);
                     cout<<"\n\n\tEnter 2nd decimal number : ";
                     cin>>decimal1;
                     b1.setBinaryNumber(decimal1);
                     cout<<"\n\tI)";
                     b.display();
                     cout<<"\n\n\tII)";
                     b1.display();
                     b2.binaryAddition(b.head, b1.head);
                     cout<<"\n\n\t\t\tSUM"<<endl;
                     b2.display();
                     b.~BinaryNumber();
                     b1.~BinaryNumber();
                     b2.~BinaryNumber();
                     break;

            default: cout<<"\n\n\tWrong Choice!!!";
        }
        cout<<"\n\n\tDo you want to continue (Y/N) : ";
        cin>>ch;
    }while(ch == 'Y' || ch == 'y');
    return 0;
}
