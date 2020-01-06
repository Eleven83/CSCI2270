/*
Practice
*/
#include <iostream>

using namespace std;

int main()
{
    int dollars, cents;
    double price;
    char dollarSign = 36; //Implicit conversion

    cout<<"Enter price in dollars and cents: "<<endl;
    cin>>price;
    dollars = price;
    cents = price * 100 - dollars * 100;
    cout<<"Total dollars: "<<dollarSign<<dollars<<" cents: "<<cents<<endl;

    return 0;
}
