#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
private:
    int size;
    Node* head;
    int count;

public:
    Stack(int size) {
        this->size = size;
        this->head = NULL;
        this->count = 0;
    }

    void push(int data) {
        if (count >= size) {
            cout << "Stack overflow. Cannot push " << data << endl;
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        count++;
    }

    void pop() {
        if (head == NULL) {
            cout << "Stack underflow. Cannot pop" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
    }

    void print() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    int peek() {
        if (head == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return head->data;
    }
};

int main() {
    Stack* stack = new Stack(5);

    stack->push(12);
    stack->push(13);
    stack->push(14);
    stack->print();

    stack->pop();
    stack->print();

    cout << "Top element is " << stack->peek() << endl;

    delete stack;
    return 0;
}
