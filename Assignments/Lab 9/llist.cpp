#include <iostream>

using namespace std;

typedef int Type;

class Node {
public:
    Type data;
    Node* next;
};

int GetLength(Node* first) {
    
    Node* addressing = new Node();
    addressing = first;
    int count = 0;
    while (addressing != NULL)
    {
        count++;
        addressing = addressing->next;
    }

    return count;
}

Type GetElement(Node* first, int position) {
    
    Node* addressing = new Node();
    addressing = first;

    for (int i = 0; i < position - 1; i++)
    {
        addressing = addressing->next;
    }

    return addressing->data;
}





void insert(Node*& first, unsigned position, Type data) {
    if (position == 0) {
        Node* temp = first;
        first = new Node;
        first->data = data;
        first->next = temp;
    }
    else {
        Node* prev = first;
        int currentIndex = 1;
        while (currentIndex < position) {
            prev = prev->next;
            currentIndex++;
        }
        Node* temp = prev->next;
        prev->next = new Node;
        prev->next->data = data;
        prev->next->next = temp;
    }
}

void display(Node* first) {
    Node* cur = first;
    while (cur != NULL) {
        cout << (cur->data) << " ";
        cur = cur->next;
    }
    cout << endl;
}

void remove(Node*& first, unsigned position) {
    if (position == 0) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }
    else {
        Node* prev = first;
        int currentIndex = 1;
        while (currentIndex < position) {
            prev = prev->next;
            currentIndex++;
        }
        Node* temp = prev->next;
        prev->next = prev->next->next;
        delete temp;
    }
}

Node* NewLinkedList(Type* arr, unsigned size) {
    Node* first = NULL;
    for (int i = size - 1; i >= 0; i--) {
        insert(first, 0, arr[i]);
    }

    return first;
}

int main() {
    {
        cout << "Given linked list: ";
        Type arr[] = { 10,4,2,6,42,50 };
        Node* first = NewLinkedList(arr, 6);
        display(first);
        cout << "The length is " << GetLength(first) << endl;
        cout << "Element at position " << 3 << " is " << GetElement(first, 3) << endl;
        cout << endl;
    }

    {
        cout << "Given linked list: ";
        Type arr[] = { 5,2,6,4,6 };
        Node* first = NewLinkedList(arr, 5);
        display(first);
        cout << "The length is " << GetLength(first) << endl;
        cout << "Element at position " << 0 << " is " << GetElement(first, 0) << endl;
        cout << endl;
    }

    {
        cout << "Given linked list: ";
        Type arr[] = { 1,3,5,7,9,11,53,70 };
        Node* first = NewLinkedList(arr, 8);
        display(first);
        cout << "The length is " << GetLength(first) << endl;
        cout << "Element at position " << 7 << " is " << GetElement(first, 7) << endl;
        cout << endl;
    }
}
