#include <iostream>
using namespace std;

class Producer
{

public:
    string Name;
    int Age;

public:
    void operator+(Producer &h1)
    {

        cout << this->Age - h1.Age;
    }

    void operator()()
    {
        cout << "Hello World this is bracket";
    }

    int getAge()
    {
        return Age;
    }
};

class Actor : protected Producer
{

public:
    string Movie;
    int year = 6;
};

int main()
{

    Producer Raj, Kumar;
    Raj.Age = 5;
    Kumar.Age = 3;

    Raj + Kumar;
    Raj();
}
