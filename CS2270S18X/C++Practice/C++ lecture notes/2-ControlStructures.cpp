/*Create a CodeBlocks project and add this file to the project
*/


#include <iostream>
#include <string>

using namespace std;

int main()
{

	 /* Control structures: if statements and for and while loops
	  * These look very similar to what you saw in python. The differences
	  are just in syntax. The conditional expression has to be in (), and there
	  are {} around the code that executes when the conditional is true. The
	  {} replace the indentation in python as the mechanism for establishing
	  the code block to execute when the condition is true.

        The elif in python is replaced by else if in c++. The logic is the same
        in both languages. First, the if is evaluated and if it is false, then
        the else if is evaluated. If the else if is false, then the else is evaluated.
	  */
	  int intA = 5;
	  if (intA < 5){
		  cout<<"a < 5"<<endl;
	  }else if (intA > 5){
		  cout<<"a > 5"<<endl;
	  }else{
		  cout<<"a = 5"<<endl;
	  }


    // while (expression) statement
    /* C++ has a while loop, just like Python, that will
    execute as long as the looping criteria is true. Here, we define
    a variable called counter and initialize it to 0. As long as the
    value of counter is less than or equal to 5, the while loop code
    between the {} will execute. The variable called counter is incremented by
    1 each time through
    the while loop, which is what keeps the while loop from executing forever.

    New syntax is introduced here with intCounter++. This is the same as
    intCounter = intCounter + 1.
    */

    int intCounter = 0;
    while (intCounter <= 5){
        cout<<"intCounter = "<< intCounter <<endl;
        intCounter++; //this is the same as intCounter = intCounter + 1
    }

    //another example using the while loop and doing something in the loop
    double dblHalf=10;
    intCounter = 0; //reset intCounter to start the loop again
    while(intCounter <= 5)
    {
        //output a mix of string literals and variables
        cout << "intCounter = " << intCounter << " and half = " << dblHalf << "\n";
        dblHalf = dblHalf/2;
        intCounter++;
    }

    //Exercise: as the user to enter a letter that isn't an "e" and continue asking
    //until they do it correctly.

    /*
    Next: Definite iteration-loop for a fixed number of times.

    Python has a loop, called a for loop, that is used to loop through a collection
    of elements or loop for a fixed number of times. C++ has the same loop, but it
    looks different than the python for loop. In C++, the for loop is generally
    used for looping through arrays, which are similar to python lists in that
    they hold a collection of data.

    We still use the keyword "for", and then between the () is the code that
    establishes how long the for loop goes. There are three terms for the for
    loop.

    The first term is the initialization of the for loop iterator.

    The iterator is an integer that has an initial value. Ex: int i = 0,
    creates a variable i with an initial value of 0.

    The second term states the condition for exiting the loop. Ex: i < 10,
    means continue looping as long as i < 10. Once i = 10, the loop will exit

    The third term states how to increment the iterator variable on each
    iteration of the loop. Ex: i++ adds one to i each time the loop executes.


    */
    //loop 0 through 9, incrementing by 1
    for(int i = 0; i < 10; i++)
        cout<<"i = "<<i<<endl;

    //loop 0 through 19, incrementing by 2
    for(int i = 0; i < 20; i+=2)
        cout<<"i = "<<i<<endl;

    //loop 0 through 20, incrementing by 2
    for(int i = 0; i <= 20; i+=2)
        cout<<"i = "<<i<<endl;

    //loop 1 through 10, incrementing by 2
    //this prints the odd numbers only
    for(int i = 1; i <= 10; i+=2)
        cout<<"i = "<<i<<endl;

    return 0;
}
