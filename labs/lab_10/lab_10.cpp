#include <iostream>
#include "stream.h"

int main()
{
    system("chcp 1251");

    int x;
    while (true) {
        try {
            cout << "\n1. Сформировать файл";
            cout << "\n2. Прочитать файл";
            cout << "\n3. Удалить все записи не равные заданному значению";
            cout << "\n4. Уменьшить все записи с заданным значением в два раза";
            cout << "\n5. Добавить К записей в начало файла";
            cout << "\n6. Очистить";
            cout << "\n7. Выход";
            cout << "\n>";
            cin >> x;
            switch (x) {
            case 1: 
                save();
                break;
            case 2:
                read();
                break;
            case 3:
                del();
                break;
            case 4:
                update();
                break;
            case 5:
                insert();
                break;
            case 6:
                system("cls");
                break;
            case 7:
                return 0;
                break;
            }
        }
        catch (exception& ex) {
            cout << "Ошибка: " << ex.what() << endl;
        }
    }
}
