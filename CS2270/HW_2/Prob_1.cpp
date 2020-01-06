/*
CSCI 2270-100
Author: Ryan Hoffman
Assignment 2
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

//Uses array of structs to store the words and their counts
struct wordItem
{
    string word;
    int count;
};

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
//Function to check whether a word in the ignoreWords array
bool isStopWord(string word, string ignoreWords[])
{
    int maxSize=50;
    for(int i=0; i<maxSize; i++)
    {
        if(word==ignoreWords[i])
            return true;
    }
    return false;
}
//Function to count the number of words not including stop words
int getTotalNumberNonStopWords(wordItem list[], int length)
{
    int totalWords=0;
    for(int i=0; i<length; i++)
    {
        totalWords+=list[i].count;
    }
    return totalWords;
}

//Function to sort the list array by word frequency
void arraySort(wordItem list[], int length)
{
    for(int j=0; j<length; j++)
    {
        for(int i=0; i<length-1; i++)
        {
            //Swap
            if(list[i].count<list[i+1].count)
            {
                wordItem temp=list[i];
                list[i]=list[i+1];
                list[i+1]=temp;
            }
        }
    }
}
void printTopN(wordItem wordItemList[], int topN)
{
    for(int i=0; i<topN; i++)
    {
        cout<<wordItemList[i].count<<" - "<<wordItemList[i].word<<endl;
    }
}
//resizing the array -- this is what a vector does
void resizeArray(wordItem wordItemList[], int length)
{
    //Double the length
    int newLength=length*2;
    //Dynamically allocate a new array of doubled size
    wordItem *newArray=new wordItem[newLength];
    for(int i=0; i<length; i++)
    {
        newArray[i]=wordItemList[i];
    }
    delete [] wordItemList;
    wordItemList=newArray;
}

int main(int argc, char* argv[])
{
    //The number of command line arguments should be 4
    if(argc!=4)
    {
        return -1;
    }
    int topNwords=atoi(argv[1]);
    char* originalFile=argv[2];
    char* ignoreWordsFile=argv[3];

    string ignoreWords[50];
    //Call to getStopWords function to store in an array
    getStopWords(ignoreWordsFile, ignoreWords);
    // for(int i=0; i<50; i++)
    // {
    //     cout<<ignoreWords[i]<<endl;
    // }

    int newCapacity=100;
    int numOfDoublings=0;
    int numOfUniqueWords=0;
    wordItem wordItemList[newCapacity];
    int sizeOfArray=0;

    fstream inFile;
    inFile.open(originalFile);
    if(inFile.is_open())
    {
        string line;
        while(getline(inFile, line))
        {
            stringstream ss;
            ss<<line;
            string word;
            while(getline(ss, word))
            {
                
            }
        }
    }else
        cout<<"ERROR!"<<endl;

    cout<<"#"<<endl;
    cout<<"Array doubled: "<<numOfDoublings<<endl;
    cout<<"#"<<endl;
    cout<<"Unique non-common words: "<<numOfUniqueWords<<endl;
    cout<<"#"<<endl;
    cout<<"Total non-common words: "<<getTotalNumberNonStopWords(wordItemList, sizeOfArray)<<endl;

    return 0;
}
