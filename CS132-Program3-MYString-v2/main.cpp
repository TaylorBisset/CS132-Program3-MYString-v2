/*
 Name:            Taylor Bisset
 Section:         A
 Program Name:    TBString Tester 

 Description:     Sort strings in alphabetical order. 
*/

/*
main.cpp
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "TBString.h"

using namespace std;

int main()
{
    vector<TBString> words(100);        // calls default constructor 100 times
    ifstream fin("infile3.txt");

    // READ

    if (fin.fail())
    {
        cout << "Couldn't open infile3.txt" << endl;
        system("pause");
        exit(1);
    }

    vector<TBString> combinedStrings;
    TBString jumboString;

    int wordCnt = 0;
    for (; fin >> words[wordCnt]; ++wordCnt)
    {       // empty loop
            cout << words[wordCnt].c_str() << '\t';      // for verifying input
    }
    cout << endl << endl;

    words.resize(wordCnt);            //shrink vector to size used

    for (int i = 0; i < wordCnt; i++) 
    {
        jumboString = jumboString + words[i];       // Concatenate the current word

        if ((i + 1) % 5 == 0)                       // Check if we've combined 5 words
        {
            combinedStrings.push_back(jumboString); // Add the concatenated string to the vector
            jumboString = TBString();               // Reset jumboString
        }
    }
    
    // SORT

    bool notDone = true;
    while (notDone == true)
    {
        notDone = false;
        for (int i = 0; i < wordCnt - 1; i++)
        {
            if (words[i] > (words[i + 1]))
            {
                TBString tempStr = words[i];
                words[i] = words[i + 1];
                words[i + 1] = tempStr;
                notDone = true;
            }
        }
    }

    // OUTPUT

    for (int i = 0; i < wordCnt; i++)           // Put every word in its own line
    {
        cout << words[i].c_str() << endl;
    }

    /*
    for (int i = 0; i < wordCnt; i++)           // Puts 5 words on every line
    {
        cout << left << setw(13) << words[i].c_str();
        if ((i + 1) % 6 == 0)
        {
            cout << endl;
        }
    }
    */

    ofstream fout("outfile.txt");
    if (fout.fail())
    {
        cout << "Couldn't open outfile.txt" << endl;
        system("pause");
        exit(1);
    }

    for (int i = 0; i < wordCnt; i++)           // Put every word in its own line
    {
        cout << words[i].c_str() << endl;
    }

    /*
    for (int i = 0; i < wordCnt; i++)           // Puts 5 words on every line
    {
        fout << left << setw(13) << words[i].c_str();
        if ((i + 1) % 6 == 0)
        {
            fout << endl;
        }
    }
    */

    fin.close();
    fout.close();

    // OS independent program termination sequence. 
#ifdef _WIN32
    cout << endl;
    system("pause");
#else
    cout << endl;
    cout << "Press any key to continue . . . ";
    cin.get();
#endif
    return 0;
}


/*

Output to console:

I            I            I            Martian      Or           Such
They         ThisIsMyAmazinglyLongStringToMakeYourExtractionOperatorWorkCorrectly.Were         a            a            a
a            amazingly    an           an           and          animal.
as           ask          ask          be.          began        began
body?        brain        busy.        compare      could        did
directing,   each,        engine       felt         first        for
his          how          human        impossible.  in           in
intelligent  intelligent  ironclad     life         lower        machines,
man's        mechanisms?  much         my           myself       myself
or           rules        ruling,      seem         seemed       sit
sits         steam        the          the          they         they
thing        things       time         to           to           to
to           to           using,       was          what         within
would

Press any key to continue . . .

*/


/*

Assignment Details


Program Note: For this assignment the normal C++ string and cstring functions can’t be used (except >> and << with cstrings).
You may not #include them. You must write all the functions that will be used.


Gang of Four and other friends
Program Description: This assignment is continuing to make your MYString class so that it is more complete and usable.
The data within your MYString class will be the same as before, but now we are adding the Gang of Four functions and some operators.
I have highlighted the new/modified functions in red below.

Your Gang of four and overloaded operator functions should have “normal behavior”.
As you write each function, you should make a little test to verify that the function is working correctly.

- - - - - - - - - - - - - - - - - - - -

The MYString class will need to have the following member functions:

Programming Note: Write and test one or two functions at a time.
Remember to mark member functions that do not change member data with const, I will be looking for this in the grading

- - - - - - - - - - - - - - - - - - - -

Member Functions : return type
    Description

MYString( )
    Default Constructor: creates an empty string

MYString(const MYString & mstr)
    Copy Constructor:  creates a string that is a duplicate of the argument

MYString (const char* cstr)
    creates a string that contains the information from the argument
    example: MYString greeting( "hello there wise one");

~MYString()
    Destructor:  release the dynamic memory

= operator : lvalue&
        Replaces
        setEqualTo(const MYString& argStr): void
    Assignment Operator: this does the assignment operation objStr.setEqualTo( argStr )
    would change objStr so that it would contain the same information as argStr

Non-const [ ] operator : char
        Like:
        at( int index) : char
    returns the character at a certain location.  No Error checking.  Fast but dangerous

>> operator: istream&
        Replaces
        read( istream& istrm) : istr
    read a string from the istream argument (could be from cin or an ifstream variable) 
    {when reading in, you can assume that you will not read in a string longer than 99 characters}
    This function will now return the istream which is the normal behavior.

<< operator : ostream&
        Replaces
        write( ostream& ostrm) : ostr
    write the string out to the ostream argument, but do not add any end of line (could be cout or an ofstream variable)
    This function will now return the ostream which is the normal behavior.

< operator > operator == operator : all return a bool
        Replaces/uses
        compareTo
            or
        lessThan
        greaterThan
        equalTo
    The operator overloaded versions of functions will replace your previous versions.

+ operator : MYString
    this function creates and returns a new MYString variable that is the combination of both the rvalue and the lvalue.
    For example if you had the following values inside two of your strings and added them “bat” + “man”,
    then you would return a MYString that contains “batman”

length( ) : int
    the length of the string ( "cat" would return 3)

capacity() : int
    The amount of spaces that is currently reserved for possible use before growing

c_str( ) : const char *
    return a pointer to a constant cstring version of the MYString object

- - - - - - - - - - - - - - - - - - - -

Static things

These are the static variables and functions that you will need to implement in your program.

Static Variables	What information it holds	                                                        Static Function for access

currentCount	    this is the count of how many MYString instances are currently "alive"	            int getCurrentCount( )

createdCount	    this is the count of how many MYString instance have been created in the program
                    ( don't decrease in destructor)	                                                    int getCreatedCount( )

- - - - - - - - - - - - - - - - - - - -

Main Program Requirements:

Read the words from the input file into MYString variables
(Note: The input file is out in Files/Program Resource/P3 MYString v2 and is called infile3.txt).
As the words are being read in append them with the + operator to each other
until you have combined 5 words together into one jumbo MYString.
Then take this jumbo MYString and add it into the vector with pushback (so it will be using your copy constructor).
The input file probably won’t have an even multiple of 5,
so you will need to allow the loop to end due to reaching end of file (not due to knowing the word count).

Once you have read, combined, and pushed your MYStrings into the vector,
then once again sort the strings into ascending order based on their ASCII value.
Then output them to the screen with one combination string per line.
When outputting the strings also include the length and capacity of the string on the same line.
Here is an example of one line of output:

```

Theyseemedamazinglybusy.I         25:40    // use setw to make it look good
              // don't worry about making the one crazy long word look nice

```
After outputting all the combo strings, then on a new line each output the count of the current objects,
and the total count of the objects create throughout your program.  These static outputs are required.
You should strive for accuracy, but are more for our curiousity sake.

You must create your own sort routine (can’t call a library, bubble sort is fine) and you can’t use the swap function
(I want you to be using your assignment operator).

- - - - - - - - - - - - - - - - - - - -

Turn In:

For turn in, you will have three files: your main program, the .h file and the .cpp file, followed by the output file.
For all programs which include class definitions,
I want you to place them in that order (main, interface/header (.h), and implementation (.cpp),  output file ).

If you have any program output that goes to the console window, then copy is as a comment below main.

The file format for turning in files is pdf .  If you have a program that can easily convert your program file to pdf,
please talk to me (One way to do that is within the print dialog box instead of selecting a printer you can often select Save as PDF ).

In addition to the program header documentation (above main),
you should also have class documentation
(and author info: name, Sect #) at the top of the .h file...where you explain what the class does.

Ways to lose points:

if your main file does not contain the program header with a program description
and short function description to accompany the function prototypes.
your interface (.h) file should have a class description about what the class does
your code should also be consistently indented as talked about in class, and shown in the book
you can not use global variables unless it is a const
make sure you mark member functions with const if they don't modify the member data
you should use good variable names (descriptive, and start with lower case letter)
proper placement of { and } ( a } should not be placed at the end of a line)
you need to have the three source files (mystring.h, mystring.cpp, and the main) as well as a print out of the output file
if you did not split the MYString class into separate files
you did not make member functions const that did not change the member data

*/
