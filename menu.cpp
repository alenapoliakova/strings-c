#include "string.h"
#include "string-id.h"

using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");

    String_ID str1, str2, str3;
    char s = 0;
    int act = 0;
    cout << endl << "Если на вход поступает строка, не являющася с-идентификатором," << endl
        << "то действия со строками не выполняются или выводится пустая строка." << endl;
    do {
        cout << endl << "Меню: " << endl;
        cout << "Конкатенация строк - 1" << endl;
        cout << "Вычитание строк - 2" << endl;
        cout << "Сравнение строк - 3" << endl;
        cout << "Узнать длину строки - 4" << endl;
        cout << "Очистка строки - 5" << endl;
        cout << "Перевод символов в верхний регистр - 6" << endl;
        cout << "Перевод символов в нижний регистр - 7" << endl;
        cout << "Поиск первого вхождения символа в строку - 8" << endl;
        cout << "Выход из меню - 9" << endl;
        cout << "Выберите пункт меню: ";
        cin >> act;
        if ((act > 9) || (act < 1)) {
            cout << endl << "Такого пункта меню не существует. Выберите еще раз: ";
            cin >> act;
        }
        switch (act) {
        case 1: {
            cout << endl << "Конкатенация строк:" << endl << endl;
            cout << "Введите строку №1: ";
            cin >> str1;
            cout << "Введите строку №2: ";
            cin >> str2;
            //str3 = str2;
            str1 = str1 + str2;
            cout << "Конкатенация строк выполнена: " << str1 << endl;
            str1.clear();
            str2.clear();
            break;
        }
        case 2: {
            cout << endl << "Вычитание строк:" << endl << endl;
            cout << "Введите строку №1: ";
            cin >> str1;
            cout << "Введите строку №2: ";
            cin >> str2;
            cout << "Вычитание строк выполнено: " << str1 - str2 << endl;
            break;
            str1.clear();
            str2.clear();
        }
        case 3: {
            cout << endl << "Сравнение строк:" << endl;
            cout << "Введите строку №1: ";
            cin >> str1;
            cout << "Введите строку №2: ";
            cin >> str2;
            if (((str1 < str2) || (str2 < str1) || (str1 > str2) || (str2 > str1) || (str1 == str2) || (str2 == str1)) == NULL)
                break;
            else if (str1 < str2)
                cout << "Строка №1 меньше строки №2" << endl;
            else if (str1 == str2)
                cout << "Строки равны" << endl;
            else if (str1 > str2)
                cout << "Строка №1 больше строки №2" << endl;
            str1.clear();
            str2.clear();
            break;
        }
        case 4: {
            cout << endl << "Узнать длину строки:" << endl << endl;
            cout << "Введите строку: ";
            cin >> str1;
            cout << endl;
            cout << "Длина строки = " << str1.get_length() << endl;
            str1.clear();
            break;
        }
        case 5: {
            cout << endl << "Очистка строки:" << endl << endl;
            cout << "Введите строку: ";
            cin >> str1;
            cout << "Выполнение очистки строки." << endl;
            str1.clear();
            cout << "Строка после очистки: " << str1 << endl;
            break;
        }
        case 6: {
            cout << endl << "Перевод символов в верхний регистр:" << endl << endl;
            cout << "Введите строку: ";
            cin >> str1;
            str1.upper();
            cout << "Измененная строка: " << str1 << endl;
            str1.clear();
            break;
        }
        case 7: {
            cout << endl << "Перевод символов в нижний регистр:" << endl << endl;
            cout << "Введите строку: ";
            cin >> str2;
            str2.lower();
            cout << "Измененная строка: " << str2 << endl;
            str2.clear();
            break;
        }
        case 8: {
            cout << endl << "Поиск первого вхождения символа в строку:" << endl << endl;
            cout << "Введите строку: ";
            cin >> str1;
            cout << "Введите символ: ";
            cin >> s;
            int position = str1.find(s);
            if (position > 0)
                cout << "Символ входит в строку первый раз в позиции " << position << endl;
            else
                cout << "Строка не является строкой-идентификатором или такого символа в строке нет!" << endl;
            break;
            str1.clear();
        }

        }
    } while (act != 9);
}
