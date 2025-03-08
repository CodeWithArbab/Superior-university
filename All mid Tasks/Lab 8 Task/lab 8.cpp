#include <iostream>
using namespace std;

//class Node {
//public:
//    int data;
//    Node* next;
//
//    Node(int value) {
//        data = value;
//        next = nullptr;
//    }
//};
//
//class SinglyLinkedList {
//private:
//    Node* head;
//
//public:
//    SinglyLinkedList() {
//        head = nullptr;
//    }
//
//    void append(int value) {
//        Node* newNode = new Node(value);
//
//        if (head == nullptr) {
//            head = newNode;
//        } else {
//            Node* temp = head;
//            while (temp->next != nullptr) {
//                temp = temp->next;
//            }
//            temp->next = newNode;
//        }
//    }
//
//    void displayList() {
//        Node* temp = head;
//        while (temp != nullptr) {
//            cout << temp->data << " ";
//            temp = temp->next;
//        }
//        cout << endl;
//    }
//
//    Node* getHead() {
//        return head;
//    }
//
//    void setHead(Node* newHead) {
//        head = newHead;
//    }
//};
//
//void mergeSinglyLinkedLists(SinglyLinkedList& list1, SinglyLinkedList& list2) {
//    if (list1.getHead() == nullptr) {
//        list1.setHead(list2.getHead());
//    } else if (list2.getHead() == nullptr) {
//        // do nothing
//    } else {
//        Node* temp = list1.getHead();
//        while (temp->next != nullptr) {
//            temp = temp->next;
//        }
//        temp->next = list2.getHead();
//    }
//}
//
//int main() {
//    SinglyLinkedList list1;
//    list1.append(10);
//    list1.append(20);
//    list1.append(30);
//
//    SinglyLinkedList list2;
//    list2.append(40);
//    list2.append(50);
//    list2.append(60);
//
//    cout << "List 1: ";
//    list1.displayList();
//
//    cout << "List 2: ";
//    list2.displayList();
//
//    mergeSinglyLinkedLists(list1, list2);
//
//    cout << "Merged List: ";
//    list1.displayList();
//
//    return 0;
//}


//Doubly Linked List

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

    void append(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
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

    Node* getHead() {
        return head;
    }

    void setHead(Node* newHead) {
        head = newHead;
    }

    Node* getTail() {
        return tail;
    }

    void setTail(Node* newTail) {
        tail = newTail;
    }
};

void mergeDoublyLinkedLists(DoublyLinkedList& list1, DoublyLinkedList& list2) {
    if (list1.getHead() == nullptr) {
        list1.setHead(list2.getHead());
        list1.setTail(list2.getTail());
    } else if (list2.getHead() == nullptr) {
        // do nothing
    } else {
        list1.getTail()->next = list2.getHead();
        list2.getHead()->prev = list1.getTail();
        list1.setTail(list2.getTail());
    }
}

int main() {
    DoublyLinkedList list1;
    list1.append(10);
    list1.append(20);
    list1.append(30);

    DoublyLinkedList list2;
    list2.append(40);
    list2.append(50);
    list2.append(60);

    cout << "List 1: ";
    list1.displayList();

    cout << "List 2: ";
    list2.displayList();

    mergeDoublyLinkedLists(list1, list2);

    cout << "Merged List: ";
    list1.displayList();

   return 0;
}
