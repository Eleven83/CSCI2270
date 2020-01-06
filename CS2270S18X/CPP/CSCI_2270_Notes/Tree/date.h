#ifndef DATE_H
#define DATE_H

class Date
{
	private:
		string month;
		int day;


	public:
		Date( string monthVal , int dayVal ); //Overloading constructor
		Date();

		void foo( int a );
		void foo( float a);

		string getMonth();
		int getDay();

};

#endif
