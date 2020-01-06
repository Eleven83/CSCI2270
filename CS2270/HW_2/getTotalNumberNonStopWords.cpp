#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int getTotalNumberNonStopWords(wordItem list[], int length)
{
    int total=0;
    for(int i=0; i<length; i++)
    {
        total+=list[i].count;
    }
    return total;
}
int main()
{

    return 0;
}
