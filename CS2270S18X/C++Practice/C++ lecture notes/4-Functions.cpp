/*Today, we're going to talk about function in C++ and how to write them
compared to how you wrote functions in python. The concept of a function
is the same, it's a block of code with inputs and outputs that performs
a task. Functions should be designed to handle one task and are particularly
useful for tasks that need to be done multiple times.

*/

#include <iostream>

using namespace std;

/*Just like in python, you have to define the function and specify what the code
does, what it's input arguments are and what it returns. In C++ the arguments are
in the (), but you also have to explicitly give those arguments a type. In this
example of mySum, both arguments are integers. The function also returns an integer,
and we know this because the type precedes the name of the function.
*/

int mySum(int intA, int intB){
    return intA + intB;
}
/*
We could have a function return a double by using
*/
double myDivider(double dblA, double dblB){
    return dblA/dblB;
}


/*The previous example also uses doubles as arguments to the function,
but the arguments could be any type. There isn't a requirement on argument
and return types.
*/

/*There are also cases where we don't want our function to return a value,
but C++ still requires that every function has a type. A function that
doesn't return a value is a void. In this example, notice that there's
no return statement at the end of the function.
 */
void printMsg(string msg){
    cout<<msg<<endl;
}

//no return, one argument that is int array
void arrayTest(int intA[]){
    for(int i = 0; i < 10; i++)
        intA[i] = i;
}
void printHelp(){
    cout<<"CSCI1300 Assignment 7 help"<<endl;
    cout<<"There is no help."<<endl;
}

/*
void function that takes one argument, an array of doubles.
*/
void myArrayFunction(double dblA[])
{
	//here, we are just initializing the array
	//the array should still be initialized when we
	//print it in main
	for(int x = 0; x < 10; x++)
		dblA[x] = 0;
}

int main()
{
    /*Functions are similar to what we saw in python, where we define the function
    and then call the function. When you call the function, the code in the
    function definition runs. Functions have arguments and return values.

    For example, call mySum function. mySum returns an integer and takes two
    integers as arguments.
    */


    int intSum = mySum(40, 50); //90
    cout<<"sum = "<<intSum<<endl;

    double dblResult = myDivider(40,50);
    cout<<"divide = "<<dblResult<<endl;
    /*
    printMsg takes one string argument and doesn't return anything.
    */

    printMsg("this is a test string");

    /*Recall that when we refer to the name of an array variable, we
    get the address of the first element in the array. When we pass
    an array as an argument to a function, we're effectively passing
    that address. If we change a value at an address in memory, those
    changes persist outside of the function where the changes were made.
    We can see that by passing an array to a function and printing the
    address being modified inside and outside the function. We'll see
    that they're the same.*/
    int intArray[10];
    arrayTest(intArray);

    for(int x = 0; x < 10; x++){
        cout<<intArray[x]<<endl;
    }

    /*Exercises:
    Write a function that inserts a value into an array. The function
    should take the array, the value, and the position for the value
    as arguments. The function doesn't need to return a value since it's
    an array being modified.

    Write a function to delete a value from an array. The function
    should take the array and the value to delete as arguments. The first
    instance of value found in the array should be deleted.

    Write a function to search for a value in an array. The function
    should take the array and the value to search for and return the first
    index of the value in the array.
    */

    return 0;
}
