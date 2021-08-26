#include <bits/stdc++.h>
using namespace std;
class id {
public:
    int p = 0;
    int v = 0;
    friend ostream &operator<<( ostream &output, id &D ) {
        output << D.v << "x^" << D.p;
        return output;
    }
    friend istream &operator>>( istream &input, id &D ) {
        input >> D.v >> D.p;
        return input;
    }
};
int ma = 1, mb = 1;
void prt(id a[], int n) {
    for (int i = 0; i < n; i++) {
        if (i)
            cout << " + ";
        cout << a[i];

    }
    cout << endl;
}
void ppt(id a[], int n) {

}
void solve(int x, id a[], int n) {
    int ans = 0;
    cout << "-----------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        ans += a[i].v * pow(x, a[i].p);
    }
    cout << "Value of :";
    prt(a, n);
    cout << " if x = " << x << " :";
    cout << ans << endl;
    cout << "------------------------------------------" << endl;
}
void add(id a[], int n, id b[], int m) {
    int i = 0, j = 0;
    bool f = 0;
    cout << "Addition :" << endl;
    while (i < n && j < m) {
        if (f)
            cout << " + ";
        if (a[i].p == b[j].p) {
            f = 1;
            cout << a[i].v + b[j].v << "x^" << a[i].p ;
            i++, j++;
        }
        else if (a[i].p < b[j].p) {
            f = 1;
            cout << a[i] ;
            i++;
        }
        else {
            f = 1;
            cout << b[j] ;
            j++;
        }
    }
    while (i < n) {
        if (f)
            cout << " + ";
        f = 1;
        cout << a[i] ;
        i++;
    }
    while (j < m) {
        if (f)
            cout << " + ";
        f = 1;
        cout << b[j] ;
        j++;
    }
    cout << endl;
    cout << "------------------------------------------" << endl;
}
void subtract(id a[], int n, id b[], int m) {
    cout << "Subtrction :" << endl;
    int ck[ma + mb + 10] = {0};
    for (int i = 0; i < n; i++) {
        ck[a[i].p] += a[i].v;
    }
    for (int i = 0; i < m; i++) {
        ck[b[i].p] -= b[i].v;
    }
    bool f = 0;

    for (int i = 0; i < ma + mb + 10; i++) {
        int value = ck[i];
        if (value) {
            if (f)
                cout << " + ";
            f = 1;
            cout << value << "x^" << i;
        }
    }
    cout << endl;
    cout << "------------------------------------------" << endl;
}
void multi(id a[], int n, id b[], int m) {
    cout << "Multiplication : ";
    int ck[ma * mb + 10] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ck[a[i].p + b[j].p] += a[i].v * b[j].v;
        }
    }
    bool f = 0;
    for (int i = 0; i < ma * mb + 10; i++) {
        int value = ck[i];
        if (value) {
            if (f)
                cout << " + ";
            f = 1;
            cout << value << "x^" << i;
        }
    }
    cout << endl;
    cout << "-----------------------XX-------------------" << endl;
}
int  main() {

    int n, m;
    cout << "Enter the number of terms in 1st polynomial :";
    cin >> n;
    cout << "Enter the terms in sorted order of powers:" << endl;
    id a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ma = max(ma, a[i].p);
    }
    cout << "Enter the number of terms in 2nd polynomial :";
    cin >> m;
    cout << "Enter the terms in sorted order of powers:" << endl;
    id b[m];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        mb = max(mb, b[i].p);
    }
    cout << "First polynomial is :";
    prt(a, n);
    cout << "Second polynomial is :";
    prt(b, m);
    cout << "---------------------Menu ---------------------" << endl;
    cout << "1. Find value of a polynomial ." << endl;
    cout << "2.Add" << endl;
    cout << "3.Subtract " << endl;
    cout << "4.Mutiply " << endl;
    cout << "5.Exit " << endl;
    do{
    int c;
    cout << "Enter your choice :";
    cin >> c;
    if (c == 1) {
        int u;
        cout << "1. First polynomial" << endl;
        cout << "2. Second polynomial" << endl;
        cout << "Enter your choice :" ;
        cin >> u;
        cout << "Enter value of x :";
        int x;
        cin >> x;
        if (u == 1)
            solve(x, a, n);
        else
            solve(x, b, m);
    }
    else if (c == 2)
        add(a, n, b, m);
    else if (c == 3)
        subtract(a, n, b, m);
    else if (c == 4)
        multi(a, n, b, m);
    else if (c==5)
        break;

    }while(true);


    /**/
    return 0;
}
