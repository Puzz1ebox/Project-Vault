#include <iostream>

using namespace std;
typedef int Type;
class Node {
public:
    Type data;
    Node* next;
};
void insert(Node*& first, int position, Type data) {
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
void remove(Node*& first, int position) {
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

Node* CreateCopy(Node* origFirst)
{

    Node* first = new Node();

    Node* addressing = origFirst;
    Node* addressingNew = first;
    while (addressing != NULL)
    {
        addressingNew->data = addressing->data;
        addressing = addressing->next;

        if (addressing != NULL)
        {
            addressingNew->next = new Node();
        }

        addressingNew = addressingNew->next;
    }

    return first;
}



int main() {
    Node* first = NULL; // Empty linked list
    insert(first, 0, 5);
    insert(first, 0, 6);
    insert(first, 0, 7);
    insert(first, 1, 8);
    insert(first, 4, 100);
    Node* second = CreateCopy(first);
    insert(second, 2, 1000);
    insert(first, 2, 999);
    display(first);
    display(second);

    Node* firstAgain = NULL; // Empty linked list
    insert(firstAgain, 0, 88);
    insert(firstAgain, 1, 99);
    insert(firstAgain, 2, 111);
    insert(firstAgain, 3, 222);
    insert(firstAgain, 4, 333);
    Node* secondAgain = CreateCopy(firstAgain);
    insert(secondAgain, 5, 444);
    insert(firstAgain, 5, 555);
    display(firstAgain);
    display(secondAgain);
}