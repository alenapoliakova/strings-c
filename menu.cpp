#include "string.h"
#include "string-id.h"

using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");

    String_ID str1, str2, str3;
    char s = 0;
    int act = 0;
    cout << endl << "���� �� ���� ��������� ������, �� ��������� �-���������������," << endl
        << "�� �������� �� �������� �� ����������� ��� ��������� ������ ������." << endl;
    do {
        cout << endl << "����: " << endl;
        cout << "������������ ����� - 1" << endl;
        cout << "��������� ����� - 2" << endl;
        cout << "��������� ����� - 3" << endl;
        cout << "������ ����� ������ - 4" << endl;
        cout << "������� ������ - 5" << endl;
        cout << "������� �������� � ������� ������� - 6" << endl;
        cout << "������� �������� � ������ ������� - 7" << endl;
        cout << "����� ������� ��������� ������� � ������ - 8" << endl;
        cout << "����� �� ���� - 9" << endl;
        cout << "�������� ����� ����: ";
        cin >> act;
        if ((act > 9) || (act < 1)) {
            cout << endl << "������ ������ ���� �� ����������. �������� ��� ���: ";
            cin >> act;
        }
        switch (act) {
        case 1: {
            cout << endl << "������������ �����:" << endl << endl;
            cout << "������� ������ �1: ";
            cin >> str1;
            cout << "������� ������ �2: ";
            cin >> str2;
            //str3 = str2;
            str1 = str1 + str2;
            cout << "������������ ����� ���������: " << str1 << endl;
            str1.clear();
            str2.clear();
            break;
        }
        case 2: {
            cout << endl << "��������� �����:" << endl << endl;
            cout << "������� ������ �1: ";
            cin >> str1;
            cout << "������� ������ �2: ";
            cin >> str2;
            cout << "��������� ����� ���������: " << str1 - str2 << endl;
            break;
            str1.clear();
            str2.clear();
        }
        case 3: {
            cout << endl << "��������� �����:" << endl;
            cout << "������� ������ �1: ";
            cin >> str1;
            cout << "������� ������ �2: ";
            cin >> str2;
            if (((str1 < str2) || (str2 < str1) || (str1 > str2) || (str2 > str1) || (str1 == str2) || (str2 == str1)) == NULL)
                break;
            else if (str1 < str2)
                cout << "������ �1 ������ ������ �2" << endl;
            else if (str1 == str2)
                cout << "������ �����" << endl;
            else if (str1 > str2)
                cout << "������ �1 ������ ������ �2" << endl;
            str1.clear();
            str2.clear();
            break;
        }
        case 4: {
            cout << endl << "������ ����� ������:" << endl << endl;
            cout << "������� ������: ";
            cin >> str1;
            cout << endl;
            cout << "����� ������ = " << str1.get_length() << endl;
            str1.clear();
            break;
        }
        case 5: {
            cout << endl << "������� ������:" << endl << endl;
            cout << "������� ������: ";
            cin >> str1;
            cout << "���������� ������� ������." << endl;
            str1.clear();
            cout << "������ ����� �������: " << str1 << endl;
            break;
        }
        case 6: {
            cout << endl << "������� �������� � ������� �������:" << endl << endl;
            cout << "������� ������: ";
            cin >> str1;
            str1.upper();
            cout << "���������� ������: " << str1 << endl;
            str1.clear();
            break;
        }
        case 7: {
            cout << endl << "������� �������� � ������ �������:" << endl << endl;
            cout << "������� ������: ";
            cin >> str2;
            str2.lower();
            cout << "���������� ������: " << str2 << endl;
            str2.clear();
            break;
        }
        case 8: {
            cout << endl << "����� ������� ��������� ������� � ������:" << endl << endl;
            cout << "������� ������: ";
            cin >> str1;
            cout << "������� ������: ";
            cin >> s;
            int position = str1.find(s);
            if (position > 0)
                cout << "������ ������ � ������ ������ ��� � ������� " << position << endl;
            else
                cout << "������ �� �������� �������-��������������� ��� ������ ������� � ������ ���!" << endl;
            break;
            str1.clear();
        }

        }
    } while (act != 9);
}
