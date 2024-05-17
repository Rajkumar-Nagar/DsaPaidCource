#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *Prev;
    Node *Next;

    Node(int data)
    {
        this->data = data;
        this->Prev = NULL;
        this->Next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->Next != NULL)
        {
            cout << "this is also working bro";
            delete Next;
            this->Next == NULL;
        }
        cout << "memory is free for node with data" << value << endl;
    }
};

void Print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->Next;
    }
    cout << endl;
}

int Length(Node *&head)
{

    int lenth = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->Next;
        lenth++;
    }

    return lenth;
}

void InsertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->Next = head;
    head->Prev = temp;
    head = temp;
}

void InsertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->Next = temp;
    temp->Prev = tail;
    tail = temp;
}

void InsertAtPosition(Node *&head, Node *&tail, int position, int data)
{

    if (position == 1)
    {
        InsertAtHead(head, data);
        return;
    }
    Node *temp = head;
    int count = 1;

    while (count != position - 1 && !(temp->Next == NULL))
    {
        temp = temp->Next;
        count++;
    }

    if (temp->Next == NULL)
    {
        InsertAtTail(tail, data);
        return;
    }
    Node *insertNode = new Node(data);

    insertNode->Next = temp->Next;
    temp->Next->Prev = insertNode;
    temp->Next = insertNode;
    insertNode->Prev = temp;
}

void deleteNode(int position, Node *&head,Node *&tail)
{

    // deleting firsht Or start node

    if (position == 1)
    {
        Node *temp = head;
        temp->Next->Prev = NULL;
        head = temp->Next;
        temp->Next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;

        while (cnt < position)
        {
            prev = curr;
            curr = curr->Next;
            cnt++;
        }

        if(curr->Next==NULL){
            cout<<"what this is calling or not";
            prev->Next=NULL;
            tail=prev;
            curr->Prev=NULL;
            delete curr;
            return;
        }

        prev->Next = curr->Next;
        curr->Next->Prev = prev;
        curr->Next = NULL;
        curr->Prev = NULL;

        delete curr;
    }
}

int main()
{

    Node *node = new Node(10);

    Node *head = node;
    Node *tail = node;

    InsertAtHead(head, 20);
    Print(head);
    InsertAtHead(head, 30);
    Print(head);
    InsertAtTail(tail, 50);
    Print(head);
    InsertAtPosition(head, tail, 2, 400);
    Print(head);
    InsertAtPosition(head, tail, 1, 400);
    Print(head);
    InsertAtPosition(head, tail, 7, 400);
    Print(head);

    deleteNode(7, head,tail);
    Print(head);

    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    // cout << "length of linkelist is " << Length(head);

    return 0;
}
