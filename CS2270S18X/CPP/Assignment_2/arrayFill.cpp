#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

// struct to store word+count combinations
struct wordItem
{
    string word;
    int count;
    wordItem()
    {
    }
};

// prototype the functions used in this program
void getStopWords(char *ignoreWordFileName, string ignoreWords[]);
bool isStopWord(string word, string ignoreWords[]);
int getTotalNumberNonStopWords(wordItem list[], int length);
void arraySort(wordItem list[], int length);
void printTopN(wordItem wordItemList[], int topN);

// main expects 2 arguments, filename and number of top words
int main(int argc, char* argv[])
{
    ifstream inStream;      // stream for reading in file

    wordItem *arr;          // array for storing words
    wordItem *arr2;         // used for dynamically doubling array size
    string ignoreWords[50]; // array for storing common words, can assume to be 50 words total

    int timesDoubled = 0;   // stores the times we double the array
    int arrLoc = 0;         // stores the location of the last element in the arr
    int arrCapacity = 100;   // stores the capacity of th e array
    int totalWords = 0;      // stores the total number of unique words in the document
    int numCommon = atoi(argv[1]);

    // verify we have the correct number of parameters, else throw error msg & return
    if (argc != 4)
    {
        cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
        return 0;
    }

    // open the file
    inStream.open(argv[2]);

    // throw an error if we couldn't open the file
    if (!inStream)
    {
        cout << "Error: Could not open file for reading" << endl;
        return 0;
    }
    arr = new wordItem[arrCapacity]; // declare our initial array
    string word;                     // stores each word we read in
    wordItem tmp;                    // stores our word item temporarily
    bool wordFound;                  // flag for whether we have found the word

    // init the ignoreWords array with the argument passed to the main function
    getStopWords(argv[3], ignoreWords);

    // loop until the end of the file
    while (!inStream.eof())
    {
        wordFound = false;

        // read in a word
        inStream >> word;

        // find and add non-common words
        if(!isStopWord(word, ignoreWords))
        {
            // check if the word has already in the list
            for (int i = 0; i < arrLoc; i++)
            {
                if (word==arr[i].word)
                {
                    wordFound=true;
                    arr[i].count++;
                    i = arrLoc;
                }
            }
            // if the word is not in the list, add it to the array
            if (wordFound == false)
            {
                // if there is space for our element
                if (arrLoc < arrCapacity)
                {
                    arr[arrLoc].word = word;
                    arr[arrLoc].count = 1;
                    arrLoc++;
                }
                // if there is not enough space, double the size of the array
                else
                {
                    // allocate new array
                    arr2 = new wordItem[arrCapacity*2];

                    // copy the original array in
                    for (int i = 0; i < arrCapacity; i++)
                        arr2[i] = arr[i];

                    // add the new unique word
                    arr2[arrCapacity].word = word;
                    arr2[arrCapacity].count = 1;
                    arrLoc++;
                    // free the memory associated with arr
                    delete[] arr;

                    // make arr point to the new memory just allocated
                    arr = arr2;

                    // double the capacity
                    arrCapacity *= 2;

                    // increment double counter
                    timesDoubled++;
                }
            }
        }

    }
    // close the file
    inStream.close();

    // sort the array using bubble sort
    arraySort(arr, arrLoc);

    // print out the top N most common words in the document
    printTopN(arr, numCommon);

    // print how many time the array doubled
    cout << "#" << endl;
    cout << "Array doubled: " << timesDoubled << endl;

    // print the unique non-common words
    cout << "#" << endl;
    cout << "Unique non-common words: "<< arrLoc <<endl;
    // print out the total number of non-common words
    cout << "#" << endl;
    totalWords = getTotalNumberNonStopWords(arr, arrLoc);
    cout << "Total non-common words: " << totalWords << endl;

    // free the final array
    delete[] arr;

    return 0;
}

/*
* Function name: printTopN
* Purpose: to print the top N high frequency words
* @param wordItemList - a pointer that points to a *sorted* array of wordItems
* @param topN - the number of top frequency words to print
* @return none
*/
void printTopN(wordItem wordItemList[], int topN)
{
    // print out the most frequent words
    for (int i = 0; i < topN; i++)
        cout << wordItemList[i].count << " - " << wordItemList[i].word << endl;
}
/*
* Function name: getTotalNumberNonStopWords
* Purpose: compute the total number of words saved in the words array (including repeated words)
* @param list - an array of wordItems containing non-stopwords
* @param length - the length of the words array
* @return - the total number of words in the words array (including repeated words multiple times)
*/
int getTotalNumberNonStopWords(wordItem list[], int length)
{
    // print out the sum of all the words in the wordItem list
    int totalWords = 0;
    for (int i = 0; i < length; i++)
        totalWords += list[i].count;
    return totalWords;
}

/*
* Function name: isStopWord
* Purpose: to see if a word is a stop word
* @param word - a word (which you want to check if it is a stop word)
* @param ignoreWords - the array of strings storing ignore/stop words
* @return - true (if word is a stop word), or false (otherwise)
*/
bool isStopWord(string word, string ignoreWords[])
{
    // go through the array and return whether or not the word is a stop word
    for (int i = 0; i < 50; i++)
        if (word == ignoreWords[i])
            return true;
    return false;
}
/*
* Function name: getStopWords
* Purpose: read stop word list from file and store into an array
* @param ignoreWordFile - filename (the file storing ignore words)
* @param ignoreWords - store ignore words from the file (pass by reference)
* @return - none
* Note: The number of words is fixed to 50
*/
void getStopWords(char *ignoreWordFileName, string ignoreWords[])
{
    // open the file
    ifstream in_stream;
    in_stream.open(ignoreWordFileName);

    // go through the words in the text file and store them in the ignoreWords array
    int count = 0;
    string line;
    while (!in_stream.eof())
    {
        getline(in_stream, line);
        ignoreWords[count++] = line;
    }
    in_stream.close();
}

/*
* Function name: arraySort
* Purpose: sort an array of wordItems, increasing, by their count fields
* @param list - an array of wordItems to be sorted
* @param length - the length of the words array
*/
void arraySort(wordItem list[], int length)
{
    int i, j;
    wordItem temp;
    for(i = 0; i < length; i++)
    {
        for (j = i+1; j < length; j++)
        {
            if (list[i].count < list[j].count)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}
