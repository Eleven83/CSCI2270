#include <iostream>
#include <fstream> //both reading and writing classes
#include <string>
using namespace std;

int main()
{


    //iostream
    //fstream
    //stringstream
    //Standard Stream Objects for Console I/O: (cout, cin, cerr, clog, etc.)
    /*
    C++ has this great feature called streams, where information can be read
    in and out from different sources, either the keyboard, or file, and is
    treated as a stream of data. This is nice because it allows the data
    to be interpreted however the programmer wants it to be interpreted.

    We've used the iostream to read in and out from the console.
    Uses the iostream header, provides an interface for reading in from the
    console and writing out to the console.
    */
    /*we've seen cout.This directs the character stream out to the display.
    The standard output stream is cout. The syntax << puts whatever is after
    the << into the stream that proceeds it.*/

    cout<<"Enter an integer: ";
    int intInput;
    /*You can also read a value in from the stream and store in a variable.
    This can be dangerous because this can appear to accept unexpected
    input, even though it doesn't work. Type in a letter or sequence of
    letters instead of an integer. Typing a float will convert the input
    to an integer.*/
    cin>>intInput;
    cin.ignore();
    /*Notice that we're not messing with data types. You're just writing to
    the stream. The integer typed in is stored in the int variable.*/
    cout<<"You typed a "<<intInput<<endl;

    /*
    There is another way to read in data from the stream and store it as
    a string, called getline. This takes up to three arguments, the
    stream to read from, the string to write to, and a terminating character.
    */
    string strName;
    cout<<"Type your name:"<<endl;
//    cin>>strName;
//    cout<<"you typed "<<strName<<endl;

    getline(cin, strName, '\n'); //use newline as terminating
    cout<<"you typed "<<strName<<endl;

    /*
    There is also a file stream object that provides similar functionality,
    but for transmitting data to and from files.
    The data being read from the file is treated as a stream of characters,
    and takes on the type it is assigned in a program.
    For example, reading in a stream of numbers from a file is still a
    bunch of 0 and 1 that are interpreted as integers if the user is reading
    it into an integer.

    /*There are three types of file stream objects.
    The ifstream for reading in from a file and the ofstream that
    writes data out to a file.
    These are objects, just like the objects we talked about in lecture.
    Instead of being an elevator or an automobile, they're ifstream and ofstream
    and have properties and methods to support reading and writing to files.
    */
    //input stream, read data in from a file
    ifstream inFile;

    //use open method
    inFile.open("test2.txt");

    //if successful, points to beginning of file
    //good practice to check that file opened successfully
    //use another method in object, the fail method
    if(inFile.fail()){
        cout<<"The file was not successfully opened"<<endl;
    }else{
        cout<<"File opened successfully"<<endl;
    }
    /*this opens the file in read mode, aka input mode
    this is different than what we saw in python where you opened a file and set a w,r,a flag
    in the open. Here, it's a different stream type.
    */
    /*There are other methods for reading in data. In python, we did a for line in lines
    that would read each line. We have the same option here using the getline
    to read until we've reached the last line in the file.

    Of course there's a built in way to do this, because everyone does it
    */
    string descript;
    int num;

    /*read the entire line as a string, even though it's two numbers
    and we want to treat those numbers as numbers.*/
    while(getline(inFile, descript)){
        cout<<descript<<endl;
    }

    /*Go back to the beginning of the file and read it again. The
    inFile variable is a reference to the beginning of the file and as
    we read, we update inFile to point to a different location in
    computer memory. We can change the variable to point back to the
    beginning of the file.*/

    inFile.clear();
    inFile.seekg(0, ios::beg);

    /*Or, we can close the file and reopen it. That will
    also point to the beginning of the file.*/

    inFile.close();
    inFile.open("test2.txt");

    /*This time, read in the file using getline, but treat
    each space like it's a line break. Each call to getline
    will read up to the next space, and the variable read is
    still stored as a string, but it's a  string with a single
    number, which is easy to convert to an actual number. There's
    a function called stoi that will cast a string as an integer.
    You need to change your build settings to use C++11 to use it.*/

    while(getline(inFile, descript, ' ')){
        cout<<descript<<endl;
    }
    /*
    Remember to close the file. This uses the ifstream close method
    */
    inFile.close();

/*
The ofstream can be used to write data out to a file, first open the open connection.
This functionality is included in fstream.
*/


    ofstream outFile;
    outFile.open("test3.txt");

    /*this will overwrite existing data in file. There aren't any flags
    that I'm aware of to change this behavior for ofstream. You can use
    fstream instead, which requires more information than just the
    filename and has more flexibility for reading, writing, and appending.
    */

    /*starting with the output stream, to write data to a file,
    you just add it to the stream*/

    outFile<<"Hello World 2"<<endl;

    /*This is just like when we write to the console using ostream, now we're
    writing to a file. Anything we write to outFile while it's open will be
    written to test3.txt.
    */

    //write numbers
    int intX = 5;
    outFile<<intX<<endl;
    //Write out an inventory list
    //Mats 39.95
    //Bulbs 3.22
    //Fuses 1.08
    outFile<<"mats "<<39.95<<endl;
    outFile<<"bulbs "<<3.22<<endl;
    outFile<<"fuses "<<1.08<<endl;
    outFile.close();
    //check the file

    return 0;
}
