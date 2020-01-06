// Write a function called isPrime that takes an integer argument and identifies
// whether the argument is prime or not. The function does not have a return value.
// It should print "Yes" if the number is prime, "No" otherwise.
// Use the following function definition:
// void isPrime(int number);
#include <iostream>

using namespace std;

void isPrime(int number)
{
    bool prime=true;
    for(int i=2; i<=number/2; i++)
    {
        if(number%i==0)
        {
            prime=false;
            break;
        }
    }
    if(prime)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
}
// Test    Expected    Got
// isPrime(23) Yes     Yes
// isPrime(8)  No      No
// isPrime(41) Yes     Yes
// isPrime(35) No      No

int main ()
{
    isPrime(23);
    isPrime(8);
    isPrime(41);
    isPrime(35);
}
