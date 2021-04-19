#pragma once
#include "Person.h"
class Employee :
    public Person
{
protected:
    int salary;
    string post;

public:
    Employee() : Person() {}
    Employee(string n, int a, int s, string p) : Person(n, a) { salary = s; post = p; }
    Employee(const Employee& em) : Person(em) { salary = em.salary; post = em.post; }
    ~Employee() {}

    Employee& operator= (const Employee& em);

    void show();
    void input();
};

