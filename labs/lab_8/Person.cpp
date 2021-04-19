#include "Person.h"

Person& Person::operator=(const Person& p)
{
    if (this == &p)
        return *this;
    name = p.name;
    age = p.age;
    return *this;
}

void Person::show()
{
    cout << "Человек: " << name << " " << age << " лет\n";
}

void Person::input()
{
    cout << "Name? "; cin >> name;
    cout << "Age? "; cin >> age;
}

void Person::HandleEvent(const TEvent& e)
{
    if (e.what == evMessage) {
        switch (e.command)
        {
        case cmGet:
            cout << "Name - " << name << endl;
            break;
        }
    }
}
