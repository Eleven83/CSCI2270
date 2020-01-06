#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool isStopWord(string word, string ignoreWords[])
{
    int maxIgnore=50;
    for(int i=0; i<maxIgnore; i++)
    {
        if(word==ignoreWords[i])
            return true;
    }
    return false;
}
int main()
{

    return 0;
}
