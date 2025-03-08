#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtFirst(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtLast(int value) {
        Node* newNode = new Node(value);

        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAtNth(int value, int n) {
        Node* newNode = new Node(value);

        if (n == 1) {
            insertAtFirst(value);
        } else {
            Node* temp = head;
            int count = 1;

            while (temp != nullptr && count < n - 1) {
                temp = temp->next;
                count++;
            }

            if (temp == nullptr) {
                insertAtLast(value);
            } else {
                newNode->next = temp->next;
                newNode->prev = temp;
                if (temp->next != nullptr) {
                    temp->next->prev = newNode;
                }
                temp->next = newNode;
            }
        }
    }

    void insertAtCenter(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            Node* slow = head;
            Node* fast = head;

            while (fast->next != nullptr && fast->next->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }

            newNode->next = slow->next;
            newNode->prev = slow;
            if (slow->next != nullptr) {
                slow->next->prev = newNode;
            }
            slow->next = newNode;
        }
    }

    void displayInOrder() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayInReverseOrder() {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtFirst(10);
    list.insertAtFirst(20);
    list.insertAtLast(30);
    list.insertAtLast(40);
    list.insertAtNth(25, 3);
    list.insertAtCenter(35);

    cout << "Display in order: ";
    list.displayInOrder();

    cout << "Display in reverse order: ";
    list.displayInReverseOrder();

 return 0;
}