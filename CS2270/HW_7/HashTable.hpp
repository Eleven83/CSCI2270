#ifndef HW_7_HASH_TABLE
#define HW_7_HASH_TABLE

#include <string>
#include <iostream>
#include <vector>

struct wordItem
{
    std::string word;
    int count;
    wordItem* next;

};

const int STOPWORD_LIST_SIZE = 50;

class HashTable{
public:
	HashTable(int hashTableSize);
	~HashTable();
	void getStopWords(char *ignoreWordFileName);
	bool isStopWord(std::string word);
	bool isInTable(std::string word);
	void incrementCount(std::string word);
	void addWord(std::string word);
	int getTotalNumberNonStopWords();
	void printTopN(int n);
	int getNumUniqueWords();
	int getNumCollisions();

private:
	int getHash(std::string word);
	wordItem* searchTable(std::string word);

	int numUniqueWords;
	int numCollisions;
	int hashTableSize;
	wordItem** hashTable;
	std::vector<std::string> vecIgnoreWords = std::vector<std::string>(STOPWORD_LIST_SIZE);
};

#endif
