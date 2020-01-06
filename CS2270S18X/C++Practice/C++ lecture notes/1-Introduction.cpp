/*Create a CodeBlocks project and copy and paste the text from this file
into your main.cpp. Erase what is already in main.cpp.
*/


/*
 * C++ is a useful language to learn because it forces you to pay
 * attention to variable types and memory and some of the stuff going
 * on behind the scenes that python hides.
 * The functionality for the language is included with libraries and
 * namespaces. To use the functionality associated with the iostream,
 * we need to include the iostream library. These files are also
 * called header files, or .h files.
 *
*/
/* All of the standard C++ functionality is included in a namespace
 * called std. To use this functionality, we need to let the program
 * know that we want it included, so you say "using namespace std".
 * There are other namespaces, but we're not going to get into that.
*/

#include <iostream>
#include<math.h>

using namespace std;

int main()
{
    //declare an integer
	int intX = 12;
    /*What's different than python. You need a type. We can no longer
    say x=12, we need to say int x to let the signify how much space to
    reserve in memory for x.

    The line also ends in a semicolon. Forgetting the ; will generate an error

    I'm going to start using a stricter naming convention on variables because
    typing matters in C++ much more than in python. Variables will have a 3-letter
    signifier of the type of variable as part of the name. For example, all
    integer variables will have names that start with int, double variables will
    have names starting with dbl, float is flt, char is chr, string is str.
    */

    //floating point number
    double dblA = 5.67886;

    cout << "Hello world!"<< endl;
    int intA = 5;
    int intB = 6;
    //And, there are operations on variables, such as *,+,-,/
    int intResult = intA * intB;
    cout<<intResult;
    intResult = intA - intB;
    cout<<"\n";
    cout<<intResult<<endl;

    intResult = intA + intB;
    cout<<"\n";
    cout<<intResult<<endl;

    /*there is also a float data type that is floating point, but uses less
    memory than double. In data structures, discrete structures, and numerical
    analysis you will learn more about the nuances of floating point arithmetic
    and how unexpected things can happen.*/
    float fltA = 5.678;
    cout<<fltA<<endl;

    //exponents are handled in math.h. Not built in like they were in python.
    //need to #include <math.h> at the top of your source file, and then use
    //pow, which wants the base and the power.
    float area = 3.14 * pow(10,2);
    cout<<area<<endl;

    /*There is also a double data type, which is essentially a big float. A
    float is 4 bytes and a double is 8 bytes. This difference matters when you
    need your floating point numbers to be precise. There can be greater accuracy
    in representing a number with 8 bytes than with 4 bytes.
    */
    float dblArea = 3.14 * pow(10,2);
    cout<<area<<endl;

    /*
    how would you calculate the circumference of a circle in C++?

    or the windchill using the formula:

    windchill = 35.74 + 0.6215*temperature + (0.4275*temperature - 35.75)*wind^0.16
    */

    double wc = 35.74 + 0.6215 * 40 + (0.4275 * 40 - 35.75) * pow(20, .16);
    cout<<wc<<endl;

    /*
    C++ handles strings using methods available in a string class. When you create a
    string variable, you are creating an instance of the string, and just like in
    python, there are several built-in things you can do to manipulate strings.
    */
    string strA;
    /*
    Why we use CodeBlocks. Type strA. and watch what happens. You should get a big
    huge dropdown list of all of the properties and methods in the string class. This
    is called intellisense, where typing . brings up all possible options for what can
    go after the .

    For example, there is a length method that returns the number of characters in the
    string.
    */
    int intLength = strA.length();
    cout<<intLength<<endl;

    /*strings are character sequences, and in the C language, the predessessor to C++,
    the only way to handle character strings was to create an array of characters. Arrays
    are part of C++ and used frequently.

    By convention, the end of strings represented in character sequences is signaled by a
    special character: the null character, whose literal value can be written as '\0'.
    */

    char chrFoo [20];

    // initialization, these do the same thing
    char chrWord[] = { 'H', 'e', 'l', 'l', 'o', '\0' };

    char chrWord2[] = "Hello";
    cout<<chrWord2<<endl;

    // assigning value to char sequences later (after initialization)
    chrWord[0] = 'B';
    chrWord[1] = 'y';
    chrWord[2] = 'e';
    chrWord[3] = '\0';

    cout<<chrWord<<endl;

    // string console input and output
    char chrQuestion[] = "What is your name? ";
    char chrAnswer[50];
    cout << chrQuestion;
    cin >> chrAnswer;
    cout << "Hello, " << chrAnswer << "\n";

    /*
    The cout and cin commands handle the iostream, which writes out to the
    console and reads in from the console. A nice feature is that you can
    assign the type at the time of reading. If you set cin to read into an
    integer, and the input is valid, then the input can be stored as an
    integer without special treatment.
    */
    cout<<"Type a number:"<<endl;
    cin>>intA;
    cout<<intA+5<<endl;

    /*
    Input handled as a string can also be treated as a string.
    */
    cout<<"Type a letter:"<<endl;
    cin>>strA;
    cout<<strA + "hello"<<endl;

    return 0;
}
/*Once the code is typed, you will need to build and run it.
 *
 Building is the yellow gear icon in CodeBlocks. To build and run, click
 the icon with the yellow gears and green arrow.

*/

