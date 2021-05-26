#include <iostream>
#include <cstdlib>
using namespace std;

//Function that checks the credit card number length.
void creditlength(long long creditnumber)
{
   long long temp;     //Temporary Variable to store the first entery
   int ctr = 0;        //Counter to count the numbers entered
   temp = creditnumber;
   while(temp != 0)
   {
       ctr = ctr + 1;
       temp = temp / 10;
   }
   if(ctr < 14 || ctr > 16)
   {
       cout<<"The Credit Card is not valid, please try again." << endl;
       exit(0);
   }
}

int Summing(long long anynumber)
{
    if(anynumber/10 == 0)
    {
        return anynumber;
    }
    else
    {
        return anynumber%10 + anynumber/10;
    }
}


/*Function that multiply every 2nd place digit by 2 and return it if it's 1 Digit Number or
keep adding till we get 1 Digit. */
int multiplytwo(long long creditnumber)
{
    long long temp; //the same temporary variable to store the main one.
    int total = 0; //a variable to store the sum if it's more than 1 Digit
    int LastTwo, secondplace; //2 variables to get every 2 digits of the number then take the second place from the right.
    int product; //variable to hold the times *2 product
    int summing;

    temp = creditnumber;
    while(temp != 0)
    {
        LastTwo = temp%100;

        secondplace = LastTwo/10;

        product = secondplace*2;

        summing = Summing(product);
        total += summing;

        temp = temp / 100;
    }
    return total;
}


//Function that sums the digits that wasn't multiplied
int RemainingDigits(long long creditnumber)
{
    long long temp;
    int total =0, store;

    temp = creditnumber;

    while(temp != 0)
    {
        store = temp%10;
        total += store;
        temp = temp / 100;
    }
    return total;
}


int main()
{
    long long cardno;
    cout << "Please Enter Your Credit Card Number. " << endl;
    cin >> cardno;

    creditlength(cardno);

    long long sum1, sum2, totalsum;
    sum1 = multiplytwo(cardno);
    sum2 = RemainingDigits(cardno);
    totalsum = sum1 + sum2;



    if(totalsum % 10 == 0)
    {
        cout << "Your Credit Card is Valid to use." << endl;
    }
    else
    {
        cout <<"Your Credit Card is not valid to use." << endl;
    }


    return 0;
}
