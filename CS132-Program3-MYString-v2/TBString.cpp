// TBString.cpp
#include "TBString.h"

TBString::TBString()
{
	cap = 20;
	end = 0;
	str = new char[cap];
	str[end] = '\0';
}

TBString::TBString(const TBString& other) // Copy Constructor
{
	cap = other.cap;
	end = other.end;
	str = new char[cap];

	for (int i = 0; i <= end; ++i) 
	{
		str[i] = other.str[i];
	}
}

TBString::TBString(const char* cstr)
{
	for (end = 0; cstr[end] != '\0'; ++end);
	//empty loop

	cap = 20;						//TODO: needs to potentially grow for prog3
	str = new char[cap];

	for (int i = 0; i <= end; ++i)
	{
		str[i] = cstr[i];
	}
}

TBString::~TBString() // Destructor 
{
	delete[] str;
}

int TBString::length()
{
	return end;
}

int TBString::capacity()
{
	return cap;
}

char TBString::at(int index)
{
	if (index >= 0 && index < end)
	{
		return str[index];
	}
	else
	{
		return '\0';
	}
}

bool TBString::read(istream& inputStrm)
{
	char inputWord[100];
	if (inputStrm >> inputWord)
	{
		for (end = 0; inputWord[end] != '\0'; ++end);  			//empty loop

		// cap = ??;						//TODO: needs to potentially grow for prog3

		for (int i = 0; i <= end; ++i)
		{
			str[i] = inputWord[i];
		}
		return true;
	}
	else
	{
		return false;
	}
}

void TBString::write(ostream& outputStrm)
{
	outputStrm << str;
}

bool TBString::lessThan(const TBString& argStr)
{
	int result = compareTo(this->str, argStr.str);
	if (result == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TBString::greaterThan(const TBString& argStr)
{
	int result = compareTo(this->str, argStr.str);
	if (result == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TBString::equals(const TBString& argStr)
{
	int result = compareTo(this->str, argStr.str);
	if (result == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

TBString& TBString::operator=(const TBString& argStr)	// replaces `void TBString::setEqualTo(const TBString& argStr)`
{

}

/*
void TBString::setEqualTo(const TBString& argStr)
{
	end = argStr.end;

	// cap = ??;						//TODO: needs to potentially grow for prog3

	for (int i = 0; i <= end; ++i)
	{
		str[i] = argStr.str[i];
	}
}
*/

const char* TBString::c_str()
{
	return str;
}
