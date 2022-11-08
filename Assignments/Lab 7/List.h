#pragma once
#include <iostream>

using namespace std;


const int CAPACITY = 1024;

typedef int ElementType; // Now “ElementType” is “int”
//can change int to double,char,...
class List {
public:
    List();  //constructor
    List(ElementType arr[], int capacity);
    void removeAll(int val);
    unsigned size() const;
    bool empty() const; //check if empty
    void insert(ElementType item, int pos); //insertion
    void erase(int pos);	//deletion
    void display(ostream& out) const; //display every item
    ElementType get(unsigned pos) const;
private:
    int mySize;       // current # of items in list     
    int myArray[CAPACITY];
};




