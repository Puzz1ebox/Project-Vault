#include <iostream>
#include <cstdlib>
#include "List.h"
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
    mySize++;  // don't forget this!
}
void List::erase(int pos)
{
    if (pos < 0 || pos >= mySize)  return;
    // shift array elements left
    for (int i = pos; i < mySize - 1; i++)
        myArray[i] = myArray[i + 1];
    mySize--;  // don't forget this!
}
List::List() {
    mySize = 0;
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

void List::operator+=(List list)
{
    for (int i = this->mySize; i < this->mySize + list.mySize; i++)
    {
        this->myArray[i] = list.myArray[i - this->mySize];
    }

    this->mySize += list.mySize;
}

void List::operator-=(List list)
{
    for (int i = 0; i < this->mySize; i++)
    {
        for (int j = 0; j < list.mySize; j++)
        {
            if(this->myArray[i] == list.myArray[j])
            { 
                this->erase(i);
                i--;
            }
        }
    }
}