// File: mystring.cpp 
// ==================
// Implementation file for user-defined String class that stores
// characters internally in a dynamically-allocated array.

#include "mystring.h"

using namespace std;

String::String()
{
	// Initialize an empty string.
	contents = new char[1];  // Allocate array for 1 char. 
	contents[0] = '\0';
	len = 0;


	// finish it by setting the data for contents and len
	//.....	
}

String::String(const char* s)  // or String::String(const char s[]) 
{
	len = strlen(s);
	contents = new char[strlen(s)];
	//...	
	strcpy(contents, s);
}

// The "big three" implementation including their names and parameter lists 
// (1) copy constructor 
String::String(const String& str)
{
	len = str.len;
	contents = new char[len];
	strcpy(contents, str.contents);
}


// (2) destructor 
String::~String()
{

}


// (3) overloading =  
String& String::operator =(const String& str)
{
	len = str.len;
	contents = new char[len];
	strcpy(contents, str.contents);

	return *this;
}

//A method that appends the contents of the passed String onto the end of the String the method is called on. 
//You can use C string function to implement it.
//Be careful about memory leakage
void String::append(const String& str)
{
	char* new_contents = new char[len + str.len + 1];	
	
	for (int i = 0; i < len; i++)
	{
		new_contents[i] = contents[i];
	}

	for (int i = 0; i < str.len; i++)
	{
		new_contents[i+len] = str.contents[i];
	}

	len = len + str.len;

	for (int i = 0; i < len + str.len + 1; i++)
	{
		contents[i] = new_contents[i];
	}
	contents[len + str.len + 1] = '\0';

	delete[] new_contents;
	// complete it ....

}


bool String::operator ==(const String& str) const
{
	return strcmp(contents, str.contents) == 0;
}

bool String::operator !=(const String& str) const
{
	return strcmp(contents, str.contents) != 0;
}

bool String::operator >(const String& str) const
{
	return len > str.len;
}

bool String::operator <(const String& str) const
{
	return len < str.len;
}

bool String::operator >=(const String& str) const
{
	return len >= str.len;
}

bool String::operator <=(const String& str) const
{
	return len <= str.len;
}


String String::operator +=(const String& str)
{
	append(str);
	return *this;
}

void String::print(ostream& out) const
{
	cout << contents;
	// output the string to any ostream out
}


int String::length() const
{
	return len;
}

char String::operator [](int i) const
{
	if (i < 0 || i >= len) {
		cerr << "can't access location " << i
			<< " of string \"" << contents << "\"" << endl;
		return '\0';
	}

	return contents[i];
}

ostream& operator<<(ostream& out, const String& s) // overload ostream operator "<<" - External!
{
	s.print(out);
	return out;
}
