#include <iostream>

using namespace std;


// Declation of Node class template
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    void insert(Node<T>* first, int position, T data);
};

// Insert. Fill in your code here...
template <typename T>
void insert(Node<T>*& first, int position, T data)
{
    if (position == 0)
    {
        Node<T>* temp = first;
        first = new Node<T>();
        first->data = data;
        first->next = temp;
    }
    else
    {
        Node<T>* addressing = first;
        for (int i = 0; i < position - 1; i++)
        {
            addressing = addressing->next;
        }

        Node<T>* temp = addressing->next;
        addressing->next = new Node<T>();
        addressing->next->data = data;
        addressing->next->next = temp;
    }
}

// Display
template <typename T>
void display(Node<T>* first) {
    Node<T>* cur = first;
    while (cur != NULL) {
        cout << (cur->data) << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    Node<int>* ifirst = NULL; // Empty linked list of integer
    insert<int>(ifirst, 0, 5);
    insert<int>(ifirst, 0, 6);
    insert<int>(ifirst, 0, 7);
    insert<int>(ifirst, 1, 8);
    insert<int>(ifirst, 4, 100);
    cout << "A Linked List of Integers: " << endl;
    display<int>(ifirst);

    Node<double>* dfirst = NULL; // Empty linked list of doubles
    insert<double>(dfirst, 0, 5.4);
    insert<double>(dfirst, 0, 23.4);
    insert<double>(dfirst, 0, 7.253);
    insert<double>(dfirst, 1, 100.45);
    insert<double>(dfirst, 4, 15.84);
    cout << "A Linked List of Doubles: " << endl;
    display<double>(dfirst);
}