#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void printTopN(wordItem wordItemList[], int topN)
{
    for(int i=0; i<topN; i++)
    {
        cout<<wordItemList[i].count<<" - "<<wordItemList[i].word<<endl;
    }
}
int main()
{

    return 0;
}
