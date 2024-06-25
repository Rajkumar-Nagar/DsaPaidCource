#include <iostream>
using namespace std;
#include <queue>

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


void LevelTraversing(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {

            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

Node *buildBinary(Node *root)
{

    cout << "enter the data :" << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildBinary(root->left);

    cout << "Enter data for inserting in right of" << data << endl;
    root->right = buildBinary(root->right);

    return root;
}

void inorderTravese(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTravese(root->left);
    cout << root->data << " ";
    inorderTravese(root->right);
}

void preOrderTraverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

void postOrderTravese(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderTravese(root->left);
    postOrderTravese(root->right);
    cout << root->data << " ";
}

void BuidFromlevelOrder(Node *&root){

queue<Node*>q;
cout<<"enter the root data"<<endl;
int rootdata;
cin >>rootdata;
root=new Node(rootdata);
q.push(root);

while(!q.empty()){
    Node *temp=q.front();
    q.pop();

    cout<<"enter the left node of "<<temp->data<<endl;
    int  leftdata;
    cin>>leftdata;

    if(leftdata!=-1){
       temp->left=new Node (leftdata);
        q.push(temp->left);
    }

    cout<<"enter the right node of "<<temp->data<<endl;
    int  rightdata;
    cin>>rightdata;

    if(rightdata!=-1){
    temp->right=new Node (rightdata);
        q.push(temp->right);
    }

}

}

int main()
{
    Node *root = NULL;
    BuidFromlevelOrder(root);
    // root = buildBinary(root);
    // LevelTraversing(root);

    // inorderTravese(root);
    // cout<<endl;
    // preOrderTraverse(root);
    // cout<<endl;
    // postOrderTravese(root);
    // cout<<endl;

    return 0;
}
