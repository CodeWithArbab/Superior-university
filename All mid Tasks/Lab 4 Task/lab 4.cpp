#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtPosition(int value, int position) {
        if (position < 0) {
          cout << "Invalid position. Position should be greater than or equal to 0." <<endl;
            return;
        }

        Node* newNode = new Node(value);

        if (head == nullptr || position == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            int currentPosition = 0;

            while (temp->next != nullptr && currentPosition < position - 1) {
                temp = temp->next;
                currentPosition++;
            }

            if (currentPosition != position - 1) {
               cout << "Invalid position." << endl;
                return;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
       cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtPosition(10, 0);
    list.insertAtPosition(20, 1);
    list.insertAtPosition(30, 2);
    list.insertAtPosition(5, 0);

   cout << "Linked List: ";
    list.displayList();

   return 0;
}
