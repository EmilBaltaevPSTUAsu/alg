#include "Employee.h"

Employee& Employee::operator=(const Employee& em)
{
    if (this == &em)
        return *this;
    name = em.name;
    age = em.age;
    salary = em.salary;
    post = em.post;
    return *this;
}

void Employee::show()
{
    cout << "Работник: " << name << " " << age << " лет с зарплатой = " << salary << " на должности " << post << endl;
}

void Employee::input()
{
    cout << "Name? "; cin >> name;
    cout << "Age? "; cin >> age;
    cout << "Salary? "; cin >> salary;
    cout << "Post? "; cin >> post;
}
