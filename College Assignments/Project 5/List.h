#pragma once
#include <iostream>
const int CAPACITY = 1024;
using namespace std;
typedef int ElementType; // Now ElementType is int
//can change int to double,char,...
class List {
public:
    List();  //constructor
    unsigned size() const;
    bool empty() const; //check if empty
    void insert(ElementType item, int pos); //insertion
    void erase(int pos); //deletion
    void display(ostream& out) const; //display every item
    ElementType get(unsigned pos) const;
    void operator+=(List list);
    void operator-=(List list);
private:
    int mySize;       // current # of items in list     
    int myArray[CAPACITY];
};
