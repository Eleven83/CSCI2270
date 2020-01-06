/*
CSCI 2270 - 300
Author: Ryan Hoffman
TA: Abhidip Bhattacharyya
Assignment 2
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct wordItem
{
	string word;
	int count;
};

//REQUIRED FUNCTION: read stop word list from file and store in array
void getStopWords(char *ignoreWordFileName, string ignoreWords[])
{
    ifstream inFile;
    inFile.open(ignoreWordFileName);
    int size1=50;
    ignoreWords[size1];
    if(inFile.is_open())
    {
        for(int i=0; i<size1; i++)
        {
            inFile>>ignoreWords[i];
        }
        inFile.close();
    }else
        cout<<"FILE OPEN FAIL"<<endl;
}
//REQUIRED FUNCTION: Return true if it's a stop word, false otherwise
bool isStopWord(string word, string ignoreWords[])
{
    int sizeOf=50;
    for(int i=0; i<sizeOf; i++)
    {
        if(word==ignoreWords[i])
            return true;
    }
    return false;
}
//REQUIRED FUNCTION: Compute the total number of words stored in the words array
int getTotalNumberNonStopWords(wordItem list[], int numberOfUniqueWords)
{
    int total=0;
    for(int i=0; i<numberOfUniqueWords; i++)
    {
        total+=list[i].count;
    }
    return total;
}
//REQUIRED FUNCTION: Sort the array in increasing order by their count
void arraySort(wordItem wordItemList[], int numberOfUniqueWords)
{
    for(int i=0; i<numberOfUniqueWords; i++)
    {
        for(int j=0; j<numberOfUniqueWords-1; j++)
        {
            if(wordItemList[j].count<wordItemList[j+1].count)
            {
                wordItem temp=wordItemList[j];
                wordItemList[j]=wordItemList[j+1];
                wordItemList[j+1]=temp;
            }
        }
    }
}
//REQUIRED FUNCTION: Print the top N most frequent words
void printTopN(wordItem wordItemList[], int topN)
{
    for(int i=0; i<topN; i++)
    {
        cout<<wordItemList[i].count<<" - "<<wordItemList[i].word<<endl;
    }
}

int main(int argc, char *argv[]) {

    int MAX_SIZE=50;
    string ignoreWordsArr[MAX_SIZE];
    getStopWords(argv[1], ignoreWordsArr);
    // for(int i=0; i<MAX_SIZE; i++)
    // {
    //     cout<<ignoreWordsArr[i]<<endl;
    // }
    isStopWord(string word, string ignoreWords[]);
    getTotalNumberNonStopWords(wordItem list[], int numberOfUniqueWords);
    arraySort(wordItem list[], int length);
    printTopN(wordItem wordItemList[], int topN);
    //cout<<numCount<<" - "<<word<<endl;
    cout<<"#"<<endl;
    cout<<"Array doubled: "<<numDoublings<<endl;
    cout<<"#"<<endl;
    cout<<"Unique non-common words: "<<numUniqueWords<<endl;

    return 0;
}
