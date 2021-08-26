/* Problem Statement:
    Imagine a publishing company which does marketing for book and audio cassette versions. Create a class publication that 
    stores the title (a string) and price (type float) of publications. From this class derive two classes: book which adds 
    a page count (type int) and tape which adds a playing time in minutes (type float). Write a program that instantiates 
    the book and tape class, allows user to enter data and displays the data members. If an exception is caught, replace all
    the data member values with zero values.
*/



#include <bits/stdc++.h>
using namespace std;

class Publication{

    protected:
        string title;
        float price;

    public:
    Publication(string name, float cost)  // parameterized constructor
    {
        title = name;
        price = cost;
    }

    Publication(){  // Default Constructor

    }

    ~Publication(){  // Destructor

    }

    void getDetails(){
        cout << "Enter the title of the publication : " << endl;
        cin >> title;
        cout << "Enter the price of publication : " << endl;
        cin >> price;
    }

    void showDetails(){
        cout << "Title of the publication : " << title << endl;
        cout << "Price of the publication : " << price << endl;
    }



};


class Book : public Publication{
    public:
        int page_cnt;

        Book(string name, float cost, int page) : Publication(name, cost){  // parameterized constructor
            page_cnt = page;
        }

        Book(){  // Default Constructor

        }

        ~Book(){  // Destructor

        }

        void getDetails(){
            Publication::getDetails();
            cout << "Enter the number of pages: " << endl;
            cin >> page_cnt;
        }

        void showDetails(){
            Publication::showDetails();
            cout << "Total pages in the book : " << page_cnt << endl;
        }
};

class Tape : public Publication{
    public:
        float playing_time;

        Tape(string name, float cost, float run_time) : Publication(name, cost){  // parameterized constructor
            playing_time = run_time;
        }

        Tape(){   // Default Constructor

        }

        ~Tape(){  // Destructor

        }

        void getDetails(){
            Publication::getDetails();
            cout << "Enter the playing time of the tape: " << endl;
            cin >> playing_time;
        }


        void showDetails(){
            Publication::showDetails();
            cout << "Total playing time of tape is: " << playing_time << endl;
        }

};

class AudioBook : public virtual Book, public virtual Tape{
    public:
        string service_provider;
        string reader;

        AudioBook(string name, float cost, int page, float run_time, string provider, string voice) : Book(name, cost, page){
            playing_time = run_time;
            service_provider = provider;
            reader = voice;
        }

        AudioBook(){  // Default Constructor

        }

        ~AudioBook(){  // Destructor

        }
            

        void getDetails(){
            Book::getDetails();
            cout << "Total playing time of Audiobook is: " << endl;
            cin >> Tape::playing_time;
            cout << "Enter the name of audiobook service provider: " << endl;
            cin.ignore();
            getline(cin, service_provider);
            cout << "Enter the name of the reader: " << endl;
            cin.ignore();
            getline(cin, reader);
        }

        void showDetails(){
            Book::showDetails();
            cout << "Total playing time of Audiobook is: " << Tape::playing_time << endl;
            cout << "Name of audiobook service provider: " << service_provider << endl;
            cout << "Name of the reader is: " << reader << endl;
        
        }

};

int main(){

    Book b("Song of fire and ice", 100, 125); // or b.getDetails();
    b.showDetails();

    Tape t("Beatels", 125.6, 56); // or t.getDetails();
    t.showDetails();

    AudioBook a("Jungle book", 125.50, 20, 60, "Audible", "Anuranjan");   // or a.getDetails();
    a.showDetails();


    return 0;
}
