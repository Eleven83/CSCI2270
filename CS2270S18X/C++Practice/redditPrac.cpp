#include <iostream>
#include <string>

using namespace std;

const int h0 = 0b01100111010001010010001100000001;
const int h1 = 0b11101111110011011010101110001001;
const int h2 = 0b10011000101110101101110011111110;
const int h3 = 0b00010000001100100101010001110110;
const int h4 = 0b11000011110100101110000111110000;

string reverse(string str) // Reverses a string by the last element of the original string to the front of new string
{
    string result;
    for(int i=str.length()-1; i>=0; i--) //from the end of string to front...
        result += str[i]; // put the end of the original at the front of the result
    return result;
}

string iToB(int num) // intToBinary function
{
    string result;
    for(; num>0; num/=2) // while it's dividing by two and hasn't reached zero. e.g 40, 20, 10, 5, 2, 1, 0
    {
        if(num%2 == 0) // if the number can be evenly divided by two...
            result += "0"; // add "0" to the result
        else
            result += "1"; // add "1" to the result
        result=reverse(result); // then reverse the final result
    }
    return result; // return the binary number as a string
}

string toAscii(string str) // Function to convert a string to it's ascii value (8-bit)
{
    string result;
    string Ascii;
    for(int i=0; i<str.length(); i++) // while I is less than the length of the string..
    {
        Ascii=iToB((int)str[i]); // Convert each char of the string to binary
        while(Ascii.length() != 8) // (to make it 8-bit) If the ascii value isn't already 8-bit
        {
            Ascii=reverse(Ascii); // have to reverse it before you can append "0" to the front
            Ascii+="0"; // add 0s until it is
            Ascii=reverse(Ascii); // reversing it back again
        }
        result+=Ascii; // adding the ascii value to the final result
        Ascii=""; // clearing the variable "Ascii"
    }
    return result; // return the result
}

string input; // user input
int lengthAscii; // length of the string after being converted to 8-bit ascii
int length; // length of the original string before any conversions
string message_length; // Message_Length string that will be converted to binary and then become 64 bit

string sWords[16];
unsigned int words[16];

int main(int argc, char** argv)
{
    //system("clear"); //This is bad...
    cout<<"SHA1 Encryption\n"<<endl;
    cout<<"Text to convert to SHA1: ";
    getline(cin, input); // get the input

    int length=input.length(); // variable to keep track of the original length of the message (dividing post ascii conversion by 8 would probably work though)
    cout<<length<<endl;
    input=toAscii(input); // convert the input to ascii
    input+="1"; // required for part of the message padding process
    lengthAscii=input.length(); // variable to keep track of the length of the ascii converted number
    message_length=iToB(length); // converting to message_length to binary

    for(int i=0; i<448-(lengthAscii-message_length.length()); i++) // add the amount of zeroes required to make the message congruent with 448%512
    input+="0"; // add zeroes
    message_length=reverse(message_length); // reversing the string in preparation of appending zeroes to the front

    for(int i=message_length.length(); i<64; i++) // add zeroes until message_length has 64 bits
        message_length+="0"; // append zeroes

    message_length=reverse(message_length); // reverse again to make it the right way around
    input+=message_length; // append message_length to input
    sWords[0]=input.substr(0,32);
    for(int i=1; i<16; i++)
        sWords[i]=input.substr((i*32)-1, 32);
    for(int i=0; i<16; i++)
        cout<<sWords[i]<<endl;
    return 0;
}
