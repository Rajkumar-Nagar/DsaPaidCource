#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            cout << "this is also working bro";
            delete next;
            this->next == NULL;
        }
        cout << "memory is free for node with data" << value << endl;
    }
};

void insetNode(Node *&tail, int element, int d)
{
    // empty list

    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }

    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *&tail)
{

    Node *temp = tail;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (tail != temp);
    cout << endl;
}

void deleteNode(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "list is empty" << endl;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {

            prev = curr;
            curr = curr->next;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

int main()
{

    Node *tail = NULL;

    insetNode(tail, 5, 3);
    print(tail);
    insetNode(tail, 3, 4);
    print(tail);
    insetNode(tail, 4, 5);
    print(tail);
    return 0;
}
