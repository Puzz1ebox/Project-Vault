/**
*
*Assignment 3
*
*Academic Integrity Statement: I certify that, while others may have assisted me in
brainstorming, debugging and validating this program, the program itself is my own
work. I understand that submitting code which is the work of other individuals is a
violation of the course Academic Integrity Policy and may result in a zero credit for
the assignment, or course failure and a report to the Academic Dishonesty Board. I
also understand that if I knowingly give my original work to another individual that
it could also result in a zero credit for the assignment, or course failure and a
report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines
at:
https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-inte
grity-procedural-guidelines
*
*Student Name: Raymond A Bailey
*
*PSU user ID: XXX6548
*
*PSU email: Rab6548@psu.edu
*
*CMPSC122 Fall 2022
*
*Due Time: 11:59PM, 16SEP22, Friday
*
*Time of Last Modification: 6:08PM, 16SEP22, Friday
*Description: Detects instances of various cstrings and modifies cstrings
*
*/


#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <string.h>

using namespace std;

int myFind(const char* s, const char* b)
{
    int sLength = strlen(s);
    int bLength = strlen(b);
    int count = 0;

    for (int i = 0; i < bLength - sLength + 1; i++)
    {
        if (s[0] == b[i])
        {
            int subcount = 0;

            for (int j = 0; j < sLength; j++)
            {
                if (s[j] == b[i + j])
                {
                    subcount++;
                }
            }

            if (subcount == sLength)
            {
                count++;
            }
        }
    }
    // count will be 0 if there is nothing in which to count
    return count;
}


int myReplace(char* str, const char* find, const char* replace)
{
    int sLength = strlen(find);
    int bLength = strlen(str);

    for (int i = 0; i < bLength - sLength + 1; i++)
    {
        if (find[0] == str[i])
        {
            int subcount = 0;

            for (int j = 0; j < sLength; j++)
            {
                if (find[j] == str[i + j])
                {
                    subcount++;
                }
            }

            if (subcount == sLength)
            {

                char n[20];

                for (int j = i + sLength; j < bLength; j++)
                {
                    n[j-i-sLength] = str[j];
                }

                strcpy(str + i, replace);
                strcat(str, n);
                return i;

            }
        }
    }

    return -1;
}

// functions to test your program, DO NOT modify
void testFind(const char* s, const char* b)
{
    int res = myFind(s, b);
    if (res <= 0) {
        cout << "String " << "\"" << s << "\"" << " does not appear in string "
             << "\"" << b << "\"" << endl;
    }
    else {
        cout << "String " << "\"" << s << "\"" << " found in string "
             << "\"" << b << "\"" << " at " << res << "locations" << endl;
    }
}
// functions to test your program, DO NOT modify
void testReplace(char* str, const char* find, const char* replace)
{
    cout << "The string before replacing: " << str << endl;
    int res = myReplace(str, find, replace);
    cout << "The string before replacing: " << str << endl;
    cout << "The replace happens at location " << res << endl;
}
int main()
{
    testFind("abc", "abbbfd");
    testFind("in", "Begining");
    testFind("put", "MyComputer");
    testFind("load", "Download");
    testFind("friend", "friendship");
    char test1[15] = "Begining";
    testReplace(test1, "gin", "e");
    char test2[15] = "Computer";
    testReplace(test2, "put", "mand");
    char test3[15] = "Download";
    testReplace(test3, "load", "ing");
}
/* Output
C:\Users\Puzz1ebox\CLionProjects\Proj3\cmake-build-debug\Proj3.exe
String "abc" does not appear in string "abbbfd"
String "in" found in string "Begining" at 2locations
String "put" found in string "MyComputer" at 1locations
String "load" found in string "Download" at 1locations
String "friend" found in string "friendship" at 1locations
The string before replacing: Begining
The string before replacing: Beeing
The replace happens at location 2
The string before replacing: Computer
The string before replacing: Commander
The replace happens at location 3
The string before replacing: Download
The string before replacing: Downing
The replace happens at location 4

Process finished with exit code 0

 */




