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

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtFirst(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtLast(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void insertAtNth(int value, int n) {
        Node* newNode = new Node(value);

        if (n == 1) {
            insertAtFirst(value);
        } else {
            Node* temp = head;
            int count = 1;

            while (temp->next != head && count < n - 1) {
                temp = temp->next;
                count++;
            }

            if (temp->next == head) {
                insertAtLast(value);
            } else {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    void insertAtCenter(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* slow = head;
            Node* fast = head;

            while (fast->next != head && fast->next->next != head) {
                slow = slow->next;
                fast = fast->next->next;
            }

            newNode->next = slow->next;
            slow->next = newNode;
        }
    }

    void displayInOrder() {
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void displayInReverseOrder() {
        Node* temp = head;
        do {
            temp = temp->next;
        } while (temp->next != head);

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;

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
