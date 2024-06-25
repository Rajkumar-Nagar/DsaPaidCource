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

void revershList(Node *&head)
{

    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *Forword = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Forword;
    }

    head = prev;
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

// void reverseByRecurrsion(Node *&head, Node *curr, Node *prev)
// {

//     if (curr != NULL)
//     {
//         head = prev;
//         return;
//     }
//     Node *forword = curr->next;
//     reverseByRecurrsion(head, forword, curr);
//     curr->next = prev;
// }

int getlength(Node *head)
{
    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

Node *MiddleOfNode(Node *head)
{

    int Length = getlength(head);

    int mid = Length / 2;
    cout << "length is " << mid << endl;
    Node *temp = head;

    int cnt = 1;
    while (cnt <= mid)
    {
        temp = temp->next;
        cnt++;
    }

    return temp;
}

Node *midOptimiseApproach(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    if (head->next->next == NULL)
    {
        return head->next;
    }

    Node *slow = head;
    Node *Fast = head->next;

    while (Fast != NULL)
    {
        Fast = Fast->next;
        if (Fast != NULL)
        {
            Fast = Fast->next;
        }
        slow = slow->next;
    }

    return slow;
}

bool ReverseOrNot(Node *head, int k)
{
    Node *temp = head;
    int count = 1;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count >= k;
}

Node *kReverse(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *curr = head;
    Node *forward = NULL;
    Node *prev = NULL;

    int count = 0;

    // Reverse first k nodes of the linked list
    while (curr != NULL && count < k)
    {
        forward = curr->next; // Keep track of the next node
        curr->next = prev;    // Reverse the current node's pointer
        prev = curr;          // Move prev one step forward
        curr = forward;       // Move curr one step forward
        count++;
    }

    // Now head points to the k-th node. Connect it with the result of the next k-group reversal
    if (forward != NULL)
    {
        head->next = ReverseOrNot(head, k) ? kReverse(forward, k) : forward;
    }
    // prev is the new head of the reversed list
    return prev;
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
    insertAtHead(head, 15);
    print(head);
    insertAtHead(head, 16);
    print(head);

  
    // insertAtHead(head, 16);
    // print(head);

    // Node *curr = head;
    // Node *prev = NULL;

    // reverseByRecurrsion(head, curr, prev);
    // print(head);.

    // Node *kReversehead = kReverse(head, 2);
    // print(kReversehead);
    // Node *Mid = MiddleOfNode(head);
    // cout << "mid node is " << Mid->data << endl;

    // Node *Mid1 = midOptimiseApproach(head);
    // cout << "mid node is " << Mid1->data << endl;

    return 0;
}
