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

    void deleteFirstNode() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "First node deleted." << endl;
        }
    }

    void deleteLastNode() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
        } else if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Last node deleted." << endl;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
            cout << "Last node deleted." << endl;
        }
    }

    void deleteNthNode(int n) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
        } else if (n == 1) {
            deleteFirstNode();
        } else {
            Node* temp = head;
            int count = 1;

            while (temp != nullptr && count < n - 1) {
                temp = temp->next;
                count++;
            }

            if (temp == nullptr || temp->next == nullptr) {
                cout << "N is greater than the number of nodes in the list." << endl;
            } else {
                Node* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
                cout << "Nth node deleted." << endl;
            }
        }
    }

    void deleteCenterNode() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
        } else {
            Node* slow = head;
            Node* fast = head;

            while (fast->next != nullptr && fast->next->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }

            Node* temp = head;
            while (temp->next != slow) {
                temp = temp->next;
            }

            temp->next = slow->next;
            delete slow;
            cout << "Center node deleted." << endl;
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

    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    cout << "Original List: ";
    list.displayList();

    list.deleteFirstNode();
    cout << "List after deleting first node: ";
    list.displayList();

    list.deleteLastNode();
    cout << "List after deleting last node: ";
    list.displayList();

    list.deleteNthNode(2);
    cout << "List after deleting 2nd node: ";
    list.displayList();

    list.deleteCenterNode();
    cout << "List after deleting center node: ";
    list.displayList();

   return 0;
}
