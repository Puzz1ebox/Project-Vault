// File: mystring.h
// ================
// Interface file for user-defined String class.
// In this case, the characters of a String are held internally
// in a dynamically-allocated array.

#ifndef _MYSTRING_H      
#define _MYSTRING_H
#include<iostream>
#include <cstring>  // for strlen(), etc.
using namespace std;

class String {
public:
	String();                                         //   default constructor  
	String(const char* s);  // a conversion constructor  

	// "big three"
	String(const String& str);  // the copy constructor   
	~String();  // the destructor    
	String& operator =(const String& str);  // assignment operator  
	/////////////////////////////////////////////////////////////////////////////	

	void append(const String& str);

	// Overloading operators    
	bool operator ==(const String& str) const; // comparison has the same behavior as strcmp
	bool operator !=(const String& str) const;
	bool operator >(const String& str) const;
	bool operator <(const String& str) const;
	bool operator >=(const String& str) const;
	bool operator <=(const String& str) const;
	String operator +=(const String& str);
	char operator [](int i) const;  // subscript operator. Return the i-th character of string

	void print(ostream& out) const;
	int length() const;

private:
	// Pointer will be used to point to dynamically-allocated array.
	char* contents;
	int len;    //  doesn't include '\0'
};

ostream& operator<<(ostream& out, const String& r); // overload ostream operator "<<" - External!   

#endif /* not defined _MYSTRING_H */
