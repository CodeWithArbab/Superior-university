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

    void append(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayFirstNode() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
        } else {
           cout << "First node: " << head->data << endl;
        }
    }

    void displayLastNode() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
           cout << "Last node: " << temp->data <<endl;
        }
    }

    void displayNthNode(int n) {
        if (head == nullptr) {
         cout << "List is empty." << endl;
        } else {
            Node* temp = head;
            int count = 1;

            while (temp != nullptr && count < n) {
                temp = temp->next;
                count++;
            }

            if (temp == nullptr) {
                cout << "N is greater than the number of nodes in the list." << endl;
            } else {
               cout << "Nth node: " << temp->data << endl;
            }
        }
    }

    void displayCenterNode() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
        } else {
            Node* slow = head;
            Node* fast = head;

            while (fast->next != nullptr && fast->next->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }

            cout << "Center node: " << slow->data << endl;
        }
    }
};

int main() {
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    list.displayFirstNode();
    list.displayLastNode();
    list.displayNthNode(3);
    list.displayCenterNode();

   return 0;
}
