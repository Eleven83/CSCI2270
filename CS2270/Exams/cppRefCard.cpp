_______________________________________________________________________________

                        C++ QUICK REFERENCE

_______________________________________________________________________________

_______________________________________________________________________________
PREPROCESSOR
_______________________________________________________________________________
    // Comment to end of line
    /* Multi-line comment */
    #include <stdio.h> // Insert standard header file
    #include "myfile.h" // Insert file in current directory
    #define X some text // Replace X with some text
    #define F(a,b) a+b // Replace F(1,2) with 1+2
    #define X \
    some text // Line continuation
    #undef X // Remove definition
    #if defined(X) // Condional compilation (#ifdef X)
    #else // Optional (#ifndef X or #if !defined(X))
    #endif // Required after #if, #ifdef
_______________________________________________________________________________
LITERALS
_______________________________________________________________________________
255, 0377, 0xff // Integers (decimal, octal, hex)
2147483647L, 0x7fffffffl // Long (32-bit) integers
123.0, 1.23e2 // double (real) numbers
'a', '\141', '\x61' // Character (literal, octal, hex)
'\n', '\\', '\'', '\"' // Newline, backslash, single quote, double
quote
"string\n" // Array of characters ending with newline and
\0
"hello" "world" // Concatenated strings
true, false // bool constants 1 and 0
_______________________________________________________________________________
DECLARATIONS
_______________________________________________________________________________
int x; // Declare x to be an integer (value undefined)
int x=255; // Declare and initialize x to 255
short s; long l; // Usually 16 or 32 bit integer (int may be
either)
char c='a'; // Usually 8 bit character
unsigned char u=255; signed char s=-1; // char might be either
unsigned long x=0xffffffffL; // short, int, long are signed
float f; double d; // Single or double precision real (never
unsigned)
bool b=true; // true or false, may also use int (1 or 0)
int a, b, c; // Multiple declarations
int a[10]; // Array of 10 ints (a[0] through a[9])
int a[]={0,1,2}; // Initialized array (or a[3]={0,1,2}; )
int a[2][3]={{1,2,3},{4,5,6}}; // Array of array of ints
char s[]="hello"; // String (6 elements including '\0')
int* p; // p is a pointer to (address of) int
char* s="hello"; // s points to unnamed array containing "hello"
void* p=NULL; // Address of untyped memory (NULL is 0)
int& r=x; // r is a reference to (alias of) int x
enum weekend {SAT,SUN}; // weekend is a type with values SAT and SUN
enum weekend day; // day is a variable of type weekend
enum weekend {SAT=0,SUN=1}; // Explicit representation as int
enum {SAT,SUN} day; // Anonymous enum
typedef String char*; // String s; means char* s;
const int c=3; // Constants must be initialized, cannot assign
to
const int* p=a; // Contents of p (elements of a) are constant
int* const p=a; // p (but not contents) are constant
const int* const p=a; // Both p and its contents are constant
const int& cr=x; // cr cannot be assigned to change x
_______________________________________________________________________________
STORAGE CLASSES
_______________________________________________________________________________
int x; // Auto (memory exists only while in scope)
static int x; // Global lifetime even if local scope
extern int x; // Information only, declared elsewhere
_______________________________________________________________________________
STATEMENTS
_______________________________________________________________________________
x=y; // Every expression is a statement
int x; // Declarations are statements
; // Empty statement
{ // A block is a single statement
int x; // Scope of x is from declaration to end of
block
a; // In C, declarations must precede statements
}
if (x) a; // If x is true (not 0), evaluate a
else if (y) b; // If not x and y (optional, may be repeated)
else c; // If not x and not y (optional)
while (x) a; // Repeat 0 or more times while x is true
for (x; y; z) a; // Equivalent to: x; while(y) {a; z;}
do a; while (x); // Equivalent to: a; while(x) a;
switch (x) { // x must be int
case X1: a; // If x == X1 (must be a const), jump here
case X2: b; // Else if x == X2, jump here
default: c; // Else jump here (optional)
}
break; // Jump out of while, do, or for loop, or switch
continue; // Jump to bottom of while, do, or for loop
return x; // Return x from function to caller
try { a; }
catch (T t) { b; } // If a throws a T, then jump here
catch (...) { c; } // If a throws something else, jump here
_______________________________________________________________________________
FUNCTIONS
_______________________________________________________________________________
int f(int x, int); // f is a function taking 2 ints and returning
int
void f(); // f is a procedure taking no arguments
void f(int a=0); // f() is equivalent to f(0)
f(); // Default return type is int
inline f(); // Optimize for speed
f() { statements; } // Function definition (must be global)
T operator+(T x, T y); // a+b (if type T) calls operator+(a, b)
T operator-(T x); // -a calls function operator-(a)
T operator++(int); // postfix ++ or -- (parameter ignored)
extern "C" {void f();} // f() was compiled in C
struct T { // Equivalent to: class T { public:
virtual void f(); // May be overridden at run time by derived
class
virtual void g()=0; }; // Must be overridden (pure virtual)
class U: public T {}; // Derived class U inherits all members of base
T
class V: private T {}; // Inherited members of T become private
class W: public T, public U {}; // Multiple inheritance
class X: public virtual T {}; // Classes derived from X have base T
directly
All classes have a default copy constructor, assignment operator, and destructor, which perform the
corresponding operations on each data member and each base class as shown above. There is also a default noargument
constructor (required to create arrays) if the class has no constructors. Constructors, assignment, and
destructors do not inherit.
_______________________________________________________________________________
TEMPLATES
_______________________________________________________________________________
template <class T> T f(T t); // Overload f for all types
template <class T> class X { // Class with type parameter T
X(T t); }; // A constructor
template <class T> X<T>::X(T t) {} // Definition of constructor
X<int> x(3); // An object of type "X of int"
template <class T, class U=T, int n=0> // Template with default
parameters
_______________________________________________________________________________
NAMESPACES
_______________________________________________________________________________
namespace N {class T {};} // Hide name T
N::T t; // Use name T in namespace N
using namespace N; // Make T visible without N::
_______________________________________________________________________________
C/C++ STANDARD LIBRARY
_______________________________________________________________________________
Only the most commonly used functions are listed. Header files without .h are in namespace std. File names are
actually lower case.
_______________________________________________________________________________
STDIO.H, CSTDIO (Input/output)
_______________________________________________________________________________
FILE* f=fopen("filename", "r"); // Open for reading, NULL (0) if error
// Mode may also be "w" (write) "a" append, "a+" update, "rb" binary
fclose(f); // Close file f
fprintf(f, "x=%d", 3); // Print "x=3" Other conversions:
"%5d %u %-8ld" // int width 5, unsigned int, long left just.
"%o %x %X %lx" // octal, hex, HEX, long hex
"%f %5.1f" // float or double: 123.000000, 123.0
"%e %g" // 1.23e2, use either f or g
"%c %s" // char, char*
"%%" // %
sprintf(s, "x=%d", 3); // Print to array of char s
printf("x=%d”, 3); // Print to stdout (screen unless redirected)
fprintf(stderr, ... // Print to standard error (not redirected)
getc(f); // Read one char (as an int) or EOF from f
ungetc(c, f); // Put back one c to f
getchar(); // getc(stdin);
putc(c, f) // fprintf(f, "%c", c);
putchar(c); // putc(c, stdout);
fgets(s, n, f); // Read line into char s[n] from f. NULL if EOF
gets(s) // fgets(s, INT_MAX, f); no bounds check
fread(s, n, 1, f); // Read n bytes from f to s, return number read
fwrite(s, n, 1, f); // Write n bytes of s to f, return number
written
fflush(f); // Force buffered writes to f
fseek(f, n, SEEK_SET); // Position binary file f at n
ftell(f); // Position in f, -1L if error
rewind(f); // fseek(f, 0L, SEEK_SET); clearerr(f);
feof(f); // Is f at end of file?
ferror(f); // Error in f?
perror(s); // Print char* s and error message
clearerr(f); // Clear error code for f
remove("filename"); // Delete file, return 0 if OK
rename("old", "new"); // Rename file, return 0 if OK
f = tmpfile(); // Create temporary file in mode "wb+"
tmpnam(s); // Put a unique file name in char s[L_tmpnam]
_______________________________________________________________________________
STDLIB.H, CSTDLIB (Misc. functions)
_______________________________________________________________________________
atof(s); atol(s); atoi(s);// Convert char* s to float, long, int
rand(), srand(seed); // Random int 0 to RAND_MAX, reset rand()
void* p = malloc(n); // Allocate n bytes. Obsolete: use new
free(p); // Free memory. Obsolete: use delete
exit(n); // Kill program, return status n
system(s); // Execute OS command s (system dependent)
getenv("PATH"); // Environment variable or 0 (system dependent)
abs(n); labs(ln); // Absolute value as int, long
_______________________________________________________________________________
STRING.H, CSTRING (Character array handling functions)
_______________________________________________________________________________
Strings are type char[] with a '\0' in the last element used.
strcpy(dst, src); // Copy string. Not bounds checked
strcat(dst, src); // Concatenate to dst. Not bounds checked
strcmp(s1, s2); // Compare, <0 if s1<s2, 0 if s1==s2, >0 if
s1>s2
strncpy(dst, src, n); // Copy up to n chars, also strncat(), strncmp()
strlen(s); // Length of s not counting \0
strchr(s,c); strrchr(s,c);// Address of first/last char c in s or 0
strstr(s, sub); // Address of first substring in s or 0
// mem... functions are for any pointer types (void*), length n bytes
memmove(dst, src, n); // Copy n bytes from src to dst
memcmp(s1, s2, n); // Compare n bytes as in strcmp
memchr(s, c, n); // Find first byte c in s, return address or 0
memset(s, c, n); // Set n bytes of s to c
_______________________________________________________________________________
CTYPE.H, CCTYPE (Character types)
_______________________________________________________________________________
isalnum(c); // Is c a letter or digit?
isalpha(c); isdigit(c); // Is c a letter? Digit?
islower(c); isupper(c); // Is c lower case? Upper case?
tolower(c); toupper(c); // Convert c to lower/upper case
_______________________________________________________________________________
MATH.H, CMATH (Floating point math)
_______________________________________________________________________________
sin(x); cos(x); tan(x); // Trig functions, x (double) is in radians
