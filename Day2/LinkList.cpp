#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
   
}

void revershList(Node *&head){
    
    Node *prev=NULL;
    Node *curr=head;

    while (curr!=NULL)
    {
        Node *Forword= curr->next;
        curr->next=prev;
        prev=curr;
        curr=Forword;
    }
    
    head=prev;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    // Creted new node
    Node *node1 = new Node(10);

    Node *head = node1;


    print(head);

    insertAtHead(head, 12);
    print(head);

    insertAtHead(head, 13);
    print(head);

    insertAtHead(head, 14);
    print(head);

    revershList(head);
    print(head);

    return 0;
}
