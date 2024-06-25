#include <iostream>
using namespace std;

class heap
{

public:
    int arr[100];
    int size;

    heap()
    {
        size = 0;
        //  arr[0]=-1;
    }

    void insert(int value)
    {
        size = size + 1;
        int index = size;

        arr[index] = value;

        while (index > 1)
        {
            int parent = index / 2;
            // min heap
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deletFromNode()
    {

        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }

        swap(arr[1], arr[size]);
        size--;

        int i = 1;

        while (i < size)
        {
            int leftNode = 2 * i;
            int rightNode = 2 * i + 1;

            if (leftNode < size && arr[leftNode] > arr[i])
            {
                swap(arr[leftNode], arr[i]);
                i = leftNode;
            }
            else if (rightNode < size && arr[rightNode] > arr[i])
            {
                swap(arr[rightNode], arr[i]);
                i = rightNode;
            }

            else
            {
                return;
            }
        }
    }
};

void heapSort(int arr[],int n){

int size=n;

while(size>1){
    // step 1

    swap(arr[1],arr[size]);
    // step 2
    size--;
    // step 3
    heapify(arr,1,n);
}

}
void heapify(int arr[], int i, int n)
{

    int largest = i;

    int leftNode = 2 * i;
    int rightNode = 2 * i + 1;

   
    if (leftNode <= n && arr[leftNode] < arr[largest])
    {
        largest = leftNode;
    }
    if (rightNode <= n && arr[rightNode] < arr[largest])
    {
        largest = rightNode;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}

int main()
{

    heap h;
    h.insert(5);
    h.insert(10);
    h.insert(54);
    h.insert(52);
    h.insert(30);
    h.insert(20);
    h.print();

    int arr[9] = {-1, 15, 35, 40, 12, 5, 37, 9, 11};
    int n = 8;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, i, n);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

        // h.deletFromNode();
        // h.print();
        return 0;
}
