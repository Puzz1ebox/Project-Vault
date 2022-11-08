#include <iostream>
#include <cstdlib>
#include "list.h"
#include <array>

using namespace std;
void List::insert(ElementType item, int pos)
{
    if (mySize == CAPACITY)  exit(1);
    if (pos < 0 || pos > mySize)  return;
    // shift array elements right to make room for item
    for (int i = mySize; i > pos; i--)
        myArray[i] = myArray[i - 1];
    // insert item at pos and increase list size  
    myArray[pos] = item;
    mySize++;  // dont forget this!
}
List::List() {
    mySize = 0;
}
List::List(ElementType arr[], int capacity)
{
    mySize = 0;

    for (int i = 0; i < capacity; i++)
    {
        myArray[i] = arr[i];
    }

    mySize = capacity;
}


bool List::empty() const {
    return (mySize == 0);
}
unsigned List::size() const {
    return mySize;
}
ElementType List::get(unsigned pos) const {
    if (pos >= mySize) {
        cerr << "Invalid Index." << endl;
        exit(1);
    }
    return myArray[pos];
}
void List::display(ostream& out) const {
    for (int i = 0; i < mySize; i++) {
        out << myArray[i] << " ";
    }
}
void List::removeAll(int Val)
{
    for (int i = 0; i < mySize; i++)
    {
        if (myArray[i] == Val)
        {
            for (int j = 0; j < mySize - i; j++)
            {
                myArray[j+i] = myArray[j + i  + 1];
            }

            mySize--;
        }
    }
}