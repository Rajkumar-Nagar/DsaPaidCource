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

Node *insetToBst(Node *root, int data)
{

    if (root == NULL)
    {
        root = new Node(data);

        return root;
    }

    if (data < root->data)
    {
        root->left = insetToBst(root->left, data);
    }

    else
    {
        root->right = insetToBst(root->right, data);
    }
    return root;
}

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

Node *max_value(Node *root)
{

    Node *temp = root;

    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    return temp;
}

Node *min_value(Node *root)
{

    Node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp;
}

Node *deleteFromBst(Node *root, int value)
{

    // base case

    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == value)
    {
        // leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // one child

        // left child

        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // right child

        if (root->right != NULL && root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // two child

        if (root->left != NULL && root->right != NULL)
        {
            int max = max_value(root)->data;
            root->data = max;
            root->left = deleteFromBst(root->left, max);
            return root;
        }
    }
    
     else if (root->data > value)
        {
            root->left = deleteFromBst(root->left, value);
            return root;
        }
        else 
        {
            root->right = deleteFromBst(root->right, value);
            return root;
        }
}

void inputDataForBst(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insetToBst(root, data);
        cout << "enter the number" << endl;
        cin >> data;
    }
}

int main()
{
    Node *root = NULL;

    cout << "inter the data of bst" << endl;

    inputDataForBst(root);
    LevelTraversing(root);

    cout << "delete from bst" << endl;
    int value;
    cin >> value;
    root = deleteFromBst(root, value);

    LevelTraversing(root);

    return 0;
}
