#include <iostream>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    private:
        Node* head;
    public:
        // Constructor: initialize an empty list
        LinkedList() : head(nullptr) {}
        
        // Destructor: Clean up memory when list is destroyed
        ~LinkedList() {
            Node* current = head;
            while (current != nullptr) {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            }
            head = nullptr;
        }
        
        // Add a node to the front
        void insertAtFront(int value) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = head;
            head = newNode;
        }
        
        // Print the entire list
        void display() {
            Node* temp = head;
            while (temp != nullptr) {
                std::cout << temp->data << " -> ";
                temp = temp->next;
            }
            std::cout << "NULL" << std::endl;
        }
};

int main() {
    // Create the list object on the stack
    LinkedList myList;

    // Add some data
    myList.insertAtFront(30);
    myList.insertAtFront(20);
    myList.insertAtFront(10);

    std::cout << "Linked List Contents: ";
    myList.display();

    // When main() ends, myList goes out of scope.
    // The Destructor (~LinkedList) is called automatically!
    return 0;
}