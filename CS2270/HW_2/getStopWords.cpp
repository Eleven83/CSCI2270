#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//Read in the ignore words and store in array of size 50
void getStopWords(char *ignoreWordFileName, string ignoreWords[])
{
    ifstream inFile;
    inFile.open(ignoreWordFileName);
    if(inFile.is_open())
    {
        for(int i=0; i<50; i++)
        {
            inFile>>ignoreWords[i];
        }
        inFile.close();
    }else
        cout<<"File not Open!"<<endl;
}

int main(int argc, char *argv[])
{
    if(argc!=4)
    {
        return -1;
    }
    int topN=atoi(argv[1]);
    string inFile=argv[2];
    string ignoreWordFileName=argv[3];

    return 0;
}
