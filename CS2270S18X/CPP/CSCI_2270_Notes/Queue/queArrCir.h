#ifndef STACK_H
#define STACK_H

#define MAXSIZE 5

class QueArrCir
{
	private:
		int head, tail, queSize;
		string a[MAXSIZE];
	
	public:
		QueArrCir(); 

		bool isEmpty();
		bool isFull();
		void enque( string newItem );
		string deque();
		void disp();
};



#endif