/*Assignment 7
CSCI 2270 - Fall 2018
Professor: Shayon Gupta
Author: Ryan Hoffman
*/
#include "HashTable.hpp"
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/*
Parameterized Constructor:
Initializes a hash table of size hashTableSize and private class members
*/
HashTable::HashTable(int hashTableSize)
{
	vecIgnoreWords.clear();
	numUniqueWords=0;
	numCollisions=0;
	this->hashTableSize=hashTableSize;
	hashTable=new wordItem*[hashTableSize];
	for(int i=0; i<hashTableSize; i++)
    {
		hashTable[i]=NULL;
	}
}
/*
Destructor: Free all the dynamic memory allocated by the table.
*/
HashTable::~HashTable()
{
	for(int i=0; i<hashTableSize; i++)
    {
		if(hashTable[i]!=NULL)
			delete hashTable[i];
		delete [] hashTable;
	}
}
//DJB2 Hash Algorithm
int HashTable::getHash(string word)
{
	unsigned int hash=5381;
	unsigned int wordLength = word.length();
	for(int i=0; i<wordLength; i++)
    {
		hash = hash*33 + word[i];
	}
	hash = hash%hashTableSize;
	if(hash<0)
    {
		hash += hashTableSize;
	}
	return hash;
}

void HashTable::getStopWords(char *ignoreWordFileName)
{
    string word;
    ifstream inFile(ignoreWordFileName);
    while(inFile>>word)
    {
        vecIgnoreWords.push_back(word);
	}
	inFile.close();
}

bool HashTable::isStopWord(std::string word)
{
    for(int i=0;i<50;i++)
    {
        if(word==vecIgnoreWords[i])
        {
            return true;
        }
    }
    return false;
}

bool HashTable::isInTable(string word)
{
    int index=getHash(word);
    wordItem *input = hashTable[index];
    if(input!=NULL)
    {
        if(word== input->word)
        {
            return true;
        }
        while(input->next!=NULL)
        {
            input=input->next;
            if(word== input->word)
            {
                return true;
            }
        }
    }
    return false;
}

void HashTable::incrementCount(string word)
{
    int hash=getHash(word);
    wordItem *input = hashTable[hash];
    if(input!=NULL)
    {
        if(word== input->word)
        {
            input->count++;
        }
        while(input->next!=NULL)
        {
            input=input->next;
            if(word== input->word)
            {
                input->count++;
            }
        }
    }
}

void HashTable::addWord(string word)
{
	if(isStopWord(word)==false)
    {
		if(isInTable(word)==true)
        {
			incrementCount(word);
		}else{
			numUniqueWords++;
			int hash = getHash(word);
			wordItem *input = hashTable[hash];
			if(input==NULL)
            {
				wordItem* newWord= new wordItem;
				newWord->word=word;
				newWord->count=1;
				newWord->next=NULL;
				hashTable[hash]=newWord;
			}else{
				while(input->next!=NULL)
                {
					input=input->next;
				}
				wordItem* newWord= new wordItem;
				newWord->word=word;
				newWord->count=1;
				newWord->next=NULL;
				input->next=newWord;
				numCollisions++;
			}
		}
	}
}

int HashTable::getTotalNumberNonStopWords()
{
	int numberWords=0;
	for(int i=0; i<hashTableSize; i++)
    {
		wordItem *input=hashTable[i];
		if(input!=NULL)
        {
			numberWords+=input->count;
			while(input->next!=NULL)
            {
				input=input->next;
				numberWords+=input->count;
			}
		}
	}
	return numberWords;
}

void HashTable::printTopN(int n)
{
	//Create an array to hold the topNWords
	wordItem topNWords[n];
	//Initialize the array values
	for(int i=0; i<n; i++)
	{
		wordItem topNWord = {"", 0, NULL};
		topNWords[i] = topNWord;
	}
	//Loop through the hash table
	for(int i=0; i<hashTableSize; i++)
	{
		for(wordItem*c=hashTable[i]; c; c=c->next)
		{
			if(c->count > topNWords[0].count && c->word != "" && c->word != " ")
			{
				topNWords[0].word=c->word, topNWords[0].count=c->count;
				for(int j=0; j<n; j++) for(int k = 0; k<n-j-1; k++)
				{
					if(topNWords[k].count > topNWords[k+1].count)
					{
						string tempWord = c->word;
						int tempCount = c->count;
						topNWords[k].word = topNWords[k+1].word;
						topNWords[k].count = topNWords[k+1].count;
						topNWords[k+1].word = tempWord;
						topNWords[k+1].count = tempCount;
					}
				}
			}
		}
	}
	//Displays all the keys of the hash table.
	for(int i=n-1; i>=0; i--)
	{
		cout<<topNWords[i].count<<" - "<<topNWords[i].word<<endl;
	}
}

int HashTable::getNumUniqueWords()
{
	return numUniqueWords;
}
int HashTable::getNumCollisions()
{
	return numCollisions;
}

int main(int argc, char *argv[])
{
    HashTable H = (atoi(argv[4]));
    H.getStopWords(argv[3]);
    string word;
    ifstream ifs (argv[2]);

    while(ifs>>word)
    {
        H.addWord(word);
    }
    ifs.close();
    H.printTopN(atoi(argv[1]));

    cout<<"#"<<endl;
    cout<<"Number of collisions: "<<H.getNumCollisions()<<endl;
    cout<<"#"<<endl;
    cout<<"Unique non-stop words: "<<H.getNumUniqueWords()<<endl;
    cout<<"#"<<endl;
    cout<<"Total non-stop words: "<<H.getTotalNumberNonStopWords()<<endl;
}
