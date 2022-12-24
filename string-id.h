#pragma once
#include <iostream>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include <sstream>
#include <typeinfo>	
#include <cstring>
#include <iomanip>
#include <string>
#include <cctype>
#include <ctype.h>

#include "string.h"


class String_ID : public String {
public:
    String_ID();  // ����������� ��� ����������

    String_ID(char* c_string);  // �����������, ����������� � �������� ��������� C-������
    String_ID(char symbol); // �����������, ����������� � �������� ��������� ������
    String_ID(String& string);

    void upper();  // ������� ���� �������� ������ � ������� �������
    void lower();  // ������� ���� �������� ������ � ������ �������
    int find(char symbol);  // ����� ������� ��������� ������� � ������

    String_ID operator=(const String_ID& string); // ������������

    String_ID operator+(const String_ID& string);  // ������������ �����
    String_ID operator-(String_ID& string);  // ��������� �����

    bool operator>(String_ID& string);  // �������� �� ������
    bool operator<(String_ID& string);  // �������� �� ������

    bool check_string_id(char* string);

    operator char* ();

    bool is_string_id(const char* c_string);  // ��������, ������������� �� ��� ������ �������������

};
