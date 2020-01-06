#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void arraySort(wordItem list[], int length)
{
    for(int j=0; j<length; j++)
    {
        for(int i=0; i<length-1; i++)
        {
            if(list[i].count<list[i+1].count)
            {
                wordItem temp=list[i];
                list[i]=list[i+1];
                list[i+1]=temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int mostFrequent=stoi(argv[1]);
    string fileName=argv[2];
    string ignoreWordsFile=argv[3];

    return 0;
}
