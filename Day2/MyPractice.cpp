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

void deleteNode(int position, Node *&head)
{

    // deleting firsht Or start node

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;

        temp->next = NULL;
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
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void InsertTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
};

void InsterHead(Node *&head, int d)
{

    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
};

void InsertAtmid(Node *&head, Node *&tail, int position, int data)
{

    if (position == 1)
    {
        InsterHead(head, data);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count != position - 1 && !(temp->next == NULL))
    {
        // cout << "what this is working " << endl;
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        InsertTail(tail, data);
        return;
    }

    Node *Insetmid = new Node(data);

    Insetmid->next = temp->next;
    temp->next = Insetmid;
}

void Print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
};

int main()
{

    Node *node = new Node(10);
    Node *head = node;
    Node *tail = node;
    Print(head);

    InsertTail(tail, 20);
    Print(head);

    InsertTail(tail, 30);
    Print(head);

    InsertAtmid(head, tail, 1, 500);
    Print(head);
    InsertAtmid(head, tail, 2, 400);
    Print(head);

    InsertAtmid(head, tail, 7, 440);
    Print(head);

    deleteNode(2, head);
    Print(head);

    // InsterHead(head, 30);
    // Print(head);
    // InsterHead(head, 40);
    // Print(head);

    return 0;
}
