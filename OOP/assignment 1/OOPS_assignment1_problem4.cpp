#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main()
{
    int num, flag =1, guess, guess_num = 0;
    cout<<"\n This is a number guessing game. You win if you guess the number correctly :)";
    cout<<"\n ----------------- The number should be between 0 and 20 -------------------\n";
    srand(time(0));
    num = rand()%21;
    while(flag == 1)
    {   guess_num++;
        cout<<"\n Guess the number: ";
        cin>>guess;
        if(guess == num)
            {cout<<"\n Yes!! You guessed the number correctly in "<<guess_num<<" guesses.\n";
             flag = 0;
            }
        else if(guess > num)
            cout<<"\n Your guess is higher than the number. Try Again!!\n";
        else
            cout<<"\n Your guess is smaller than the number. Try Again!!\n";
    }

    return 0;
}
