#include <iostream>

using namespace std;

int main()
{

    /*In Python, we used lists to store a collection of data as a sequence.
    With a list, we can access the individual elements in the list using the
    index of the element, such as myList[0] to get the first element, or
    myList[1] to get the second element.

    In C++, we use arrays to accomplish storing a data sequence. Unlike
    lists, where the elements could be any type, arrays are sequences of
    all one type, such as a sequence of integers.

    An array of integers can store more than one
    integer, and each integer in the array has an index.
    */

	/*Create an array of 10 integers*/
	int intArray[10];

	/*I created myArray, but I didn't set the contents of the array to anything
	meaningful. If I print the contents of myArray, it's just garbage. It could
	be stuff left over from a previous variable allocation. C++ doesn't initialize
	local variables, and so you have to be careful before you use them.

    Index through the array using a for loop.
	*/
	for(int x = 0; x < 10; x++){
		cout<<intArray[x]<<endl;
	}
	/*Initializing myArray values, set the value in the array to the for loop index*/
	for(int x = 0; x < 10; x++){
		intArray[x] = x;
		cout<<intArray[x]<<endl;
	}

    //strings are initially empty
    string strArray[10];
    for(int x = 0; x < 10; x++){
        cout<<"string[x]:"<<strArray[x]<<endl;
    }
    /*Arrays can be more than one dimension. For example, when we looked at
    images in python, there was a row and column value for each pixel in the image.
    The row and column are different dimensions, there are 2 dimensions. To create
    an array that is 2 dimensions, we need an allocation for both the rows and the
    columns, and then to inspect the array, we need a loop for each dimension.*/

    //array of ints with 5 rows and 10 columns
    int int2DArray[5][10];
    //if we print everything, it should be garbage
    for(int x = 0; x < 5; x++){
        for(int y = 0; y < 10; y++){
            cout<<int2DArray[x][y]<<" ";
        }
        cout<<endl;
    }

    //initialize the values and then print them
    for(int x = 0; x < 5; x++){
        for(int y = 0; y < 10; y++){
            int2DArray[x][y] = x*y;
            cout<<int2DArray[x][y]<<" ";
        }
        cout<<endl;
    }
    //exercise:
    //write values at int2DArray[1][1], or [2][2], or [3][1]

    /*
    The first time in the x loop, x = 0 and y = 0 through 9. The y variable will
    increment even though x is still 0. Then, after the y loop exits, the code
    execution will go back to the x loop and increment x, which makes x = 1. The
    y loop then restarts from 0, and goes y = 0 through 9 while x = 1. This process
    repeats for x = 0 through 4.
    */

    /*What happens when I print intArray without an index.
    */
    cout<<"array beginning "<<intArray<<endl;


	/*Arrays are stored as contiguous blocks of memory, and when you use the
	name of the array, you're getting the address of the first element of the array,
    in this case intArray[0]. You can use the name of the array and increment it's
    value to navigate through the memory. When you do this, the value at
    intArray[1] is the same as the value at myArray+1. If you do intArray+1,
    you'll get the address at that location.
	 */
	 cout<<intArray<<"\n"; //address of first element in the aray
	 cout<<intArray+1<<"\n"; //address of second element in the array
	 cout<<intArray+2<<"\n"; //address of third element in the array
	/*Even though we're adding 1 each time, the value of the address is going
	  up by 4 each time because intArray contains integers, and an integer takes
	  up 4 bytes in memory. When we increment our index in intArray, we need to
	  jump by 4 bytes.
    */
    //to go through the entire array and see the address increment
    for(int x = 0; x < 10; x++){
        cout<<intArray + x<<endl;
    }

    /*Array operations
    When we worked with python lists, there were standard operations
    that we did on the lists to modify the list contents. We could append
    to the end of the list, insert into the middle, search for list elements,
    and remove list elements.

    With arrays, we also want to be able to insert, search, and delete, but there's
    nothing built-in to C++ to handle these operations. We have to create them
    ourselves. For now, we'll cover the functionality to modify arrays, and
    then when we get to functions in c++, we'll create functions that modify
    an array.
    */

    //search an array
    /*To search an array, we loop through the array contents until the array
    value equals the value we are searching for. Store the index where the
    value is found in the array. Initialize the search index to -1 so that
    if the value isn't found, the search index will be -1 and that's how
    we know the value isn't found.*/
    int intSearch[6] = {4, 34, 23, 56, 67, 43};
    int intSearchVal = 56;
    int intSearchIndex = -1; //index where value is found
    for(int x = 0; x < 6; x++){
        if(intSearch[x] == intSearchVal){
            cout<<"value found at index: "<<x<<endl;
            intSearchIndex = x;
        }
    }
    cout<<"value found at index: "<<intSearchIndex<<endl;

    /*
    To insert an element into an array, there are different scenarios we need to
    consider regarding how much of the array is currently being used. For example,
    even though we may have allocated memory for 10 ints, it's possible that we've
    stored fewer than 10 and therefore, we have space available to store more ints.
    It is also possible that the array is full and any insert operation will result
    in data being lost because it is overwritten by new data.
    */
    //Assume we have the following array state:
    int intArray2[10];
    int intUsed;
    intArray2[0] = 10;
    intArray2[1] = 20;
    intUsed = 2;
    /*intArray2 has memory allocated for 10 integers, but we've only used two locations
    in the array, the rest of the array just holds garbage values that we don't care about.
    We have a variable called intUsed that tells us how many locations have been used.*/

    //insert a new value at the beginning of the array. Shift everything out of the way
    //shift from the end to the beginning
    for(int x = intUsed; x > 0; x--){
        intArray2[x] = intArray2[x-1];
    }
    intArray2[0] = 5; //new value at the beginning
    intUsed++; //the number of used spaces is increased by 1
    for(int x = 0; x < 10; x++){
        cout<<intArray2[x]<<endl;
    }
    /*shift from the x = 1 position
    */

    cout<<"x test"<<endl;
    for(int x = intUsed; x > 1; x--){
        intArray2[x] = intArray2[x-1];
    }
    intUsed++;
    intArray2[1] = 12;
    for(int x = 0; x < 10; x++){
        cout<<intArray2[x]<<endl;
    }

    /*deleting an element from an array
    We don't actually have to delete it, we just need to overwrite the value we no longer
    want. We can do this by shifting all values to the right of the value down by 1 to
    overwrite it.
    */
    //remove first element in the array

    for(int x = 0; x < intUsed-1; x++){
        intArray2[x] = intArray2[x+1];
    }
    intUsed--;
    for(int x = 0; x < 10; x++){
        cout<<intArray2[x]<<endl;
    }

    //remove the second element in the array?

    return 0;
}
