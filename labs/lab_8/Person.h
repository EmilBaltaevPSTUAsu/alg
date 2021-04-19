#pragma once
#include "Object.h"
class Person :
    public Object
{
protected:
    string name;
    int age;

public:
    Person() { name = "NoName"; age = 0; }
    Person(string n, int a) { name = n; age = a; }
    Person(const Person& p) { name = p.name; age = p.age; }
    ~Person() {}

    string get_name() { return name; }
    int get_age() { return age; }

    void set_name(string n) { name = n; }
    void set_age(int a) { age = a; }

    Person& operator= (const Person& p);

    void show();
    void input();

    void HandleEvent(const TEvent& e);
};

