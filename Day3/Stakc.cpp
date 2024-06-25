#include <iostream>
using namespace std;

class stack
{

public:
    int size;
    int *arr;
    int top;

    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
        cout<<"constructor in callled"<<endl;
    }

    void push(int element)
    {
        if ((size - top) > 0)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "segmentation fault";
        }
    }

    void pop()
    {
        if (top > 0)
        {
            --top;
        }
        else
        {
            cout << "segmentation fault";
        }
    }

    void peak()
    {
        if (top > 0)
        {
            arr[top];
        }
        else
        {
            cout <<"stack is empty";
        }
    }

    bool empty()
    {
        if (top > 0)
        {
            return false;
        }
        return true;
    }

    void Print()
    {

        if (top > 0)
        {
            int count = 0;
            while (count <= top)
            {
                cout<<arr[count]<<" ";
                count++;
            }
            cout<<endl;
        }
        else{
            cout<<"this is empty stack";
        }
    }
};

int main()
{

   stack st(5);
   st.push(10);
   st.push(13);
   st.push(17);

   st.Print();
   st.pop();
   st.Print();


    
    return 0;
}
