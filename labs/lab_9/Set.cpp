#include "Set.h"

Set::Set(int s)
{
    size = s;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = i + 1;
}

Set::Set(const Set& s)
{
    size = s.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = s.data[i];
}

Set::~Set()
{
    delete[] data;
    data = 0;
}

Set& Set::operator=(const Set& v)
{
    if (this == &v)
        return *this;
    if (size != 0)
        delete[] data;
    size = v.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = v.data[i];
    return *this;
}

void Set::reset()
{
    int ok, k = 0;
    int* arr = new int[size];
    // идем по элементами
    for (int i = 0; i < size; i++) {
        ok = 0;
        // идем по доп. массиву
        for (int j = 0; j < k; j++)
            // если он там есть
            if (data[i] == arr[j]) {
                ok = 1;  // отмечаем, что копировать не надо
                break;
            }
        // если его там нет
        if (ok == 0) {
            arr[k] = data[i];
            k++;
        }
    }
    // копируем
    if (size != 0)
        delete[] data;
    size = k;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = arr[i];
    delete[] arr;
}

int& Set::operator[](int index)
{
    if (index < 0 || index >= size)
        throw 1;
    return data[index];
}

int Set::operator()()
{
    return size;
}

Set Set::operator*(const Set& s)
{
    int count, k = 0;
    if (size >= s.size)
        count = size;
    else
        count = s.size;
    int* arr = new int[count];
    // идем по элементами
    for (int i = 0; i < size; i++)
        // идем по элементами другого множества
        for (int j = 0; j < s.size; j++)
            // если они равны
            if (data[i] == s.data[j]) {
                arr[k] = data[i]; // копируем
                k++;
                break;
            }
    // копируем
    Set temp(k);
    for (int i = 0; i < k; i++)
        temp.data[i] = arr[i];
    delete[] arr;
    return temp;
}


// »—ѕќЋ№«ќ¬јЌ»≈ 2-го варианта реализации оисключений

// префикс
Set& Set::operator--()
{
    if (size == 0)
        throw error("пустое множество");
    int* arr = new int[size - 1];
    for (int i = 0; i < size - 1; i++)
        arr[i] = data[i];
    delete[] data;
    data = arr;
    size--;
    return *this;
}

// постфикс
Set Set::operator--(int)
{
    if (size == 0)
        throw error("пустое множество");
    Set temp(*this);
    int* arr = new int[size - 1];
    for (int i = 0; i < size - 1; i++)
        arr[i] = data[i];
    delete[] data;
    data = arr;
    size--;
    return temp;
}

ostream& operator<<(ostream& out, const Set& v)
{
    if (v.size == 0)
        throw error("пустое множество");
    for (int i = 0; i < v.size; i++)
        out << v.data[i] << "  ";
    return out;
}

istream& operator>>(istream& in, Set& v)
{
    cout << "¬ведите " << v.size << " элементов через пробел: ";
    for (int i = 0; i < v.size; i++) {
        in >> v.data[i];
    }
    v.reset();
    return in;
}
