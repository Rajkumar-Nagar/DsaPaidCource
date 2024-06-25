#include <iostream>
using namespace std;
#include <map>

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

    // ~Node()
    // {
    //     int value = this->data;
    //     if (this->next != NULL)
    //     {
    //         cout << "this is also working bro";
    //         delete next;
    //         this->next == NULL;
    //     }
    //     cout << "memory is free for node with data" << value << endl;
    // }
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

Node *removeDuplicates(Node *head) {
    Node *curr = head;

    while (curr != NULL) {
        Node *curr_next = curr->next;
        Node *prev = curr;
        
        while (curr_next != NULL) {
            if (curr_next->data == curr->data) {
                Node *forward = curr_next->next;
                prev->next = forward;
                delete curr_next;  
                curr_next = forward;
            } else {
                prev = curr_next;
                curr_next = curr_next->next;
            }
        }
        
        curr = curr->next;
    }

    return head;
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
bool hasCycle(Node *head) {
    if (head == NULL) {
        return false;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

Node *foloadys(Node *head){

if(head==NULL){
    return NULL;
}

Node *temp=head;
Node *slow=head;
Node* fast =head;

while (slow!=NULL&&fast!=NULL)
{
   fast=fast->next;
   if(fast!=NULL){
    fast=fast->next;
   }
   slow=slow->next;
   if(fast==slow){
    return slow;
   }
}

return NULL;

}

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
    InsertTail(tail, 20);
    Print(head);
    InsertTail(tail, 30);
    Print(head);
    InsertTail(tail, 60);
    Print(head);
    InsertTail(tail, 30);
    Print(head);
    InsertTail(tail, 50);

    Node *dublicateremove=removeDuplicates(head);

    Print(dublicateremove);

    //  tail->next = head->next;

    // if (foloadys(head)!=NULL) {
    //     cout << "There is a cycle in the linked list." << endl;
    // } else {
    //     cout << "There is no cycle in the linked list." << endl;
    // }


    // InsertAtmid(head, tail, 1, 500);
    // Print(head);
    // InsertAtmid(head, tail, 2, 400);
    // Print(head);

    // InsertAtmid(head, tail, 7, 440);
    // Print(head);

    // deleteNode(2, head);
    // Print(head);

    // InsterHead(head, 30);
    // Print(head);
    // InsterHead(head, 40);
    // Print(head);

    return 0;
}
