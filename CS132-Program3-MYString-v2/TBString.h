#ifndef TBSTRING_H
// TBString.h
#define TBSTRING_H

#include <istream>

using namespace std;

class TBString
{    // You NEED to change the name of the class to reflect your name 
                    //   for example Nancy Programmer would use the name NPString 
public:
    TBString();						// default constructor
    TBString(const TBString& mstr); // copy constructor
    TBString(const char* cstr);     // cstring constructor
    ~TBString();                    // destructor

    int length();
    int capacity();

    char at(int index);
    bool read(istream& inputStrm);
    void write(ostream& outputStrm);

    bool lessThan(const TBString& argStr);
    bool greaterThan(const TBString& argStr);
    bool equals(const TBString& argStr);

    TBString& operator=(const TBString& argStr);  // replaces `void setEqualTo(const TBString& argStr);`
    const char* c_str();

private:
    int length(const char* str)
    {
        int len;
        for (len = 0; str[len] != '\0'; len++) {}
        return len;
    }

    int compareTo(const char* lstr, const char* rstr)
    {
        while (*lstr != '\0' && *rstr != '\0')
        {
            if (*lstr < *rstr)
            {
                return -1;
            }
            else if (*lstr > *rstr)
            {
                return 1;
            }
            lstr++;
            rstr++;
        }
        if (length(lstr) < length(rstr))
        {
            return -1;
        }
        else if (length(lstr) > length(rstr))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    char* str;
    int end;
    int cap;
};

#endif
