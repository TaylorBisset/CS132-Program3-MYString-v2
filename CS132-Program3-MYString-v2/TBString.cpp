// TBString.cpp
#include "TBString.h"

TBString::TBString()
{
	cap = 100;
	end = 0;
	str = new char[cap + 1];
	str[0] = '\0';
}

TBString::TBString(const TBString& mstr) // Copy Constructor
{
	cap = mstr.cap;
	end = mstr.end;
	str = new char[cap + 1];

	for (int i = 0; i < end; ++i) 
	{
		str[i] = mstr.str[i];
	}
	str[end] = '\0';
}

TBString::TBString(const char* cstr)
{
	for (end = 0; cstr[end] != '\0'; ++end);
	//empty loop

	cap = 100;						//TODO: needs to potentially grow for prog3
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

char& TBString::operator[](int index) 
{
	return str[index];
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

istream& operator>>(istream& inputStrm, TBString& tbStr)		// replaces `bool TBString::read(istream& inputStrm)`
{
	char inputWord[100];
	if (inputStrm >> inputWord)
	{
		if (tbStr.str == inputWord)
		{
			return inputStrm;
		}

		delete tbStr.str;
		tbStr.str = new char[strlen(inputWord) + 1];

		strcpy_s(tbStr.str, strlen(inputWord) + 1, inputWord);
		tbStr.end = strlen(inputWord);
	}
	return inputStrm;
}

ostream& operator<<(ostream& outputStrm, const TBString& tbStr)	// replaces `void TBString::write(ostream& outputStrm)`
{
	outputStrm << tbStr.str;
	return outputStrm;
}

TBString operator+(const TBString& lvalue, const TBString& rvalue)
{
	int lvalueLength = 0;
	while (lvalue.str[lvalueLength] != '\0') 
	{
		lvalueLength++;
	}

	int rvalueLength = 0;
	while (rvalue.str[rvalueLength] != '\0') 
	{
		rvalueLength++;
	}

	int newLength = lvalueLength + rvalueLength;
	char* result = new char[newLength + 1];

	int resultIndex = 0;

	for (int i = 0; i < lvalueLength; i++)
	{
		result[resultIndex] = lvalue.str[i];
		resultIndex++;
	}

	for (int i = 0; i < rvalueLength; i++)
	{
		result[resultIndex] = rvalue.str[i];
		resultIndex++;
	}

	result[newLength] = '\0';

	TBString concatenated(result);
	delete[] result;

	return concatenated;
}

bool TBString::operator<(const TBString& argStr) const			// replaces `bool TBString::lessThan(const TBString& argStr)`
{
	return compareTo(this->str, argStr.str) < 0;
}

bool TBString::operator>(const TBString& argStr) const			// replaces `bool TBString::greaterThan(const TBString& argStr)`
{
	return compareTo(this->str, argStr.str) > 0;
}

bool TBString::operator==(const TBString& argStr) const			// replaces `bool TBString::equals(const TBString& argStr)`
{
	return compareTo(this->str, argStr.str) > 0;
}

TBString& TBString::operator=(const TBString& argStr)			// replaces `void TBString::setEqualTo(const TBString& argStr)`
{
	if (this == &argStr)
	{
		return *this;
	}

	delete[] this->str;

	this->str = new char[strlen(argStr.str) + 1];
	strcpy_s(this->str,  strlen(argStr.str) + 1, argStr.str);

	this->end = argStr.end;

	return *this;
}

const char* TBString::c_str()
{
	return str;
}

/*
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
*/

/*
void TBString::write(ostream& outputStrm)
{
	outputStrm << str;
}
*/

/*
bool TBString::lessThan(const TBString& argStr)
{
	int result = compareTo(this->str, argStr.str);
	if (result == -1)t
	{
		return true;
	}
	else
	{
		return false;
	}
}
*/

/*
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
*/

/*
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
*/

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
