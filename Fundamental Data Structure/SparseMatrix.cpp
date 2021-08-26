#include <iostream>

using namespace std;

class sparseMatrix
{
    public :

    int** sm;
    int r, c, z; //r-> rows, c-> columns, z->non zero elements

    sparseMatrix(int row, int col, int nonZero)
    {
        r = row;
        c = col;
        z = nonZero;
        sm = new int*[r];

        for(int i = 0; i < z+1; i++)
            sm[i] = new int[3];

        sm[0][0] = {0};
    }

    void inputSparse()
    {
        sm[0][0] = r;
        sm[0][1] = c;
        sm[0][2] = z;

        for(int i = 0; i < z; i++)
        {
            cout<<"Enter row, column and value : ";
            cin>>sm[i+1][0]>>sm[i+1][1]>>sm[i+1][2];
        }
    }

    void display()
    {
        for(int i = 0; i < z+1; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout<<sm[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    ~sparseMatrix()
    {
        delete []sm;
    }
};

class normalMatrix
{
    public :

    int** m;
    int r, c, z;  //z for counting no. of non zero elements

    normalMatrix(int row, int col)
    {
        r = row;
        c = col;
        z = 0;

        m = new int*[r];
        for(int i = 0; i < r; i++)
            m[i] = new int[c];

        m[0][0] = {0};
    }

    void inputNormalMatrix()
    {
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                cout<<"Enter element A["<<i<<"]["<<j<<"] : ";
                cin>>m[i][j];
                if(m[i][j] != 0)
                    z++;
            }
        }
    }

    void displayNormalMatrix()
    {
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    ~normalMatrix()
    {
        delete []m;
    }
};

sparseMatrix toSparse(normalMatrix a)
{
    sparseMatrix s(a.r, a.c, a.z);

    s.sm[0][0] = a.r;
    s.sm[0][1] = a.c;
    s.sm[0][2] = a.z;

    int k = 1;

    for(int i = 0; i < a.r; i++)
    {
        for(int j = 0; j < a.c; j++)
        {
            if(a.m[i][j] != 0)
            {
                s.sm[k][0] = i;
                s.sm[k][1] = j;
                s.sm[k][2] = a.m[i][j];
                k++;
            }
        }
    }

    return s;
}

normalMatrix toNormal(sparseMatrix a)
{
    normalMatrix n(a.r, a.c);

    for(int i = 0; i < a.z; i++)
    {
        n.m[a.sm[i+1][0]][a.sm[i+1][1]] = a.sm[i+1][2];
    }

    return n;
}

sparseMatrix add(sparseMatrix a, sparseMatrix b)
{
    sparseMatrix s(a.r, a.c, a.z+b.z);

    s.sm[0][0] = a.r;
    s.sm[0][1] = a.c;

    int i = 1, j = 1, k = 1;

    while(i < a.z+1 && j < b.z+1)
    {

        if(a.sm[i][0] < b.sm[j][0])
        {
            s.sm[k][0] = a.sm[i][0];
            s.sm[k][1] = a.sm[i][1];
            s.sm[k][2] = a.sm[i][2];
            k++;
            i++;
        }

        else if(a.sm[i][0] > b.sm[j][0])
        {
            s.sm[k][0] = b.sm[j][0];
            s.sm[k][1] = b.sm[j][1];
            s.sm[k][2] = b.sm[j][2];
            k++;
            j++;
        }

        else if(a.sm[i][0] == b.sm[j][0])
        {
            if(a.sm[i][1] < b.sm[j][1])
            {
                s.sm[k][0] = a.sm[i][0];
                s.sm[k][1] = a.sm[i][1];
                s.sm[k][2] = a.sm[i][2];
                k++;
                i++;
            }
            else if(a.sm[i][1] > b.sm[j][1])
            {
                s.sm[k][0] = b.sm[j][0];
                s.sm[k][1] = b.sm[j][1];
                s.sm[k][2] = b.sm[j][2];
                k++;
                j++;
            }
            else if(a.sm[i][1] == b.sm[j][1])
            {
                s.sm[k][0] = a.sm[i][0];
                s.sm[k][1] = a.sm[i][1];
                s.sm[k][2] = a.sm[i][2] + b.sm[j][2];
                i++;
                k++;
                j++;
            }
        }
    }

    while(i < a.z+1)
    {
        s.sm[k][0] = a.sm[i][0];
        s.sm[k][1] = a.sm[i][1];
        s.sm[k][2] = a.sm[i][2];
        k++;
        i++;
    }

    while(j < b.z+1)
    {
        s.sm[k][0] = b.sm[j][0];
        s.sm[k][1] = b.sm[j][1];
        s.sm[k][2] = b.sm[j][2];
        k++;
        j++;
    }

    s.sm[0][2] = k-1;
    s.z = k-1;

    return s;
}

sparseMatrix transpose(sparseMatrix a)
{
    sparseMatrix s(a.c, a.r, a.z);

    s.sm[0][0] = a.c;
    s.sm[0][1] = a.r;
    s.sm[0][2] = a.z;

    int k = 1;

    for(int i = 0; i < a.c; i++)
    {
        for(int j = 1; j <= a.z; j++)
        {
            if(i == a.sm[j][1])
            {
                s.sm[k][0] = a.sm[j][1];
                s.sm[k][1] = a.sm[j][0];
                s.sm[k][2] = a.sm[j][2];
                k++;
            }
        }
    }

    return s;
}

sparseMatrix fastTranspose(sparseMatrix a)
{
    sparseMatrix s(a.r, a.c, a.z);

    s.sm[0][1] = a.r;
    s.sm[0][0] = a.c;
    s.sm[0][2] = a.z;

    int cnt[a.c] = {0}, startRow[a.z] = {0};

    for(int i = 1; i < a.z+1; i++)
    {
        cnt[a.sm[i][1]]++;
    }

    startRow[0] = 1;

    for(int i = 1; i < a.c; i++)
    {
        startRow[i] = startRow[i-1] + cnt[i-1];
    }

    int x, xt;

    for(int i = 1; i < a.z+1; i++)
    {
        x = a.sm[i][1];
        xt = startRow[x];

        s.sm[xt][0] = a.sm[i][1];
        s.sm[xt][1] = a.sm[i][0];
        s.sm[xt][2] = a.sm[i][2];

        startRow[x]++;
    }

    return s;
}

sparseMatrix def()
{
    int n, r, c;

    cout<<"\nEnter no. of rows and columns : ";
    cin>>r>>c;
    cout<<"Enter no. of non zero elements : ";
    cin>>n;

    sparseMatrix s(r, c, n);

    return s;
}

normalMatrix definition()
{
    int r, c;

    cout<<"\nEnter no. of rows and columns : ";
    cin>>r>>c;

    normalMatrix m(r, c);

    return m;
}

int main()
{
    char ch = 'y';
    do
    {
        int choice;
        cout<<"\n\t\t\tChoice Menu\n"<<endl;
        cout<<"1) Conversion from Sparse to Normal Matrix"<<endl;
        cout<<"2) Conversion from Normal to Sparse Matrix"<<endl;
        cout<<"3) Addition of Sparse Matrices"<<endl;
        cout<<"4) Transpose of Sparse Matrix using Simple Transpose method"<<endl;
        cout<<"5) Transpose of Sparse Matrix using Fast Transpose method"<<endl;
        cout<<"\nEnter your choice : ";
        cin>>choice;

        if(choice == 1)
        {
            sparseMatrix s = def();
            s.inputSparse();

            cout<<"\nGiven Spare Matrix : "<<endl;
            s.display();

            normalMatrix t = toNormal(s);

            cout<<"\nNormal Matrix : "<<endl;
            t.displayNormalMatrix();
        }

        else if(choice == 2)
        {
            normalMatrix m = definition();
            m.inputNormalMatrix();

            cout<<"\nGiven Matrix : "<<endl;
            m.displayNormalMatrix();

            sparseMatrix t = toSparse(m);

            cout<<"\nSparse Matrix : "<<endl;
            t.display();
        }

        else if(choice == 3)
        {
            sparseMatrix s1 = def();
            s1.inputSparse();

            sparseMatrix s2 = def();
            s2.inputSparse();

            cout<<"\nSpare Matrix 1 : "<<endl;
            s1.display();

            cout<<"\nSpare Matrix 2 : "<<endl;
            s2.display();

            if(s1.r != s2.r || s1.c != s2.c)
            {
                cout<<"\nAddition not possible!!!"<<endl;
            }
            else
            {
                sparseMatrix s = add(s1, s2);
                cout<<"\nSum : "<<endl;
                s.display();
            }
        }

        else if(choice == 4)
        {
            sparseMatrix s = def();
            s.inputSparse();

            cout<<"\nGiven Spare Matrix : "<<endl;
            s.display();

            sparseMatrix t = transpose(s);
            cout<<"\nTranspose : "<<endl;
            t.display();
        }

        else if(choice == 5)
        {
            sparseMatrix s = def();
            s.inputSparse();

            cout<<"\nGiven Spare Matrix : "<<endl;
            s.display();

            sparseMatrix t = fastTranspose(s);
            cout<<"\nTranspose : "<<endl;
            t.display();
        }
        else
        {
            cout<<"\nWrong Choice!!!"<<endl;
        }

        cout<<"\nDo you want to continue (Y/N) : ";
        cin>>ch;
    }while(ch == 'Y' || ch == 'y');

    return 0;
}
