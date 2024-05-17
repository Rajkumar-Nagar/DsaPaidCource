#include <iostream>
using namespace std;
#include <cstring>

class Hero
{

private:
    int health = 300;
    int level = 10;

public:
    static int TimetoComplete;
     char *name;
    Hero()
    {
        cout << "simple cunstructor is called ";
        name = new char[100];
    }
    Hero(int health)
    {
        cout << "constructor is called ";
        cout << this;
    }

    Hero(Hero &h2)
    {
        char *Dummy = new char[100];

        strcpy(Dummy, h2.name);
        cout << "passing array address is this " << " " << &(h2.name);
        cout << "this is array" << " " << &Dummy << endl;
        // Dummy = h2.name;
        this->name = Dummy;
        cout << "copy constructor is called";
        this->health = h2.health;
    }

    int Print()
    {
        cout << "Name" << " " << this->name << endl;
        cout << "Health" << " " << this->health << endl;
        cout << "Level" << " " << this->level << endl;
    }

    int setHeath(int h)
    {
        health = h;
        return health;
    }
    int setLevel(int L)
    {
        level = L;
        return level;
    }
    void setName(char name[])
    {
        this->name = name;
    }
};

int Hero :: TimetoComplete = 5;

int main()

{
    Hero hero1;
    hero1.setHeath(12);
    hero1.setLevel(10);
    char name[9] = "Rajkumar";
    hero1.setName(name);
    cout<<Hero :: TimetoComplete;

    cout << "name address is this " << hero1.name;

    Hero hero2(hero1);

    hero1.name[0] = 'b';

    hero1.Print();
    hero2.Print();

    // static declaration
    // Hero h1(50);
    // Hero h3(h1);

    // cout << h3.getHealth() << endl;
    // cout << "the heath of hero is " << h1.getHealth() << endl;

    // dynamic Declaration

    // Hero *h2 = new Hero(39);
    // cout << h2->getHealth()<<endl;
    // cout<<h2<<endl;
}
