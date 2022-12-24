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
    String_ID();  // Конструктор без параметров

    String_ID(char* c_string);  // Конструктор, принимающий в качестве параметра C-строку
    String_ID(char symbol); // Конструктор, принимающий в качестве параметра символ
    String_ID(String& string);

    void upper();  // Перевод всех символов строки в верхний регистр
    void lower();  // Перевод всех символов строки в нижний регистр
    int find(char symbol);  // Поиск первого вхождения символа в строку

    String_ID operator=(const String_ID& string); // Присваивание

    String_ID operator+(const String_ID& string);  // Конкатенация строк
    String_ID operator-(String_ID& string);  // Вычитание строк

    bool operator>(String_ID& string);  // Проверка на больше
    bool operator<(String_ID& string);  // Проверка на меньше

    bool check_string_id(char* string);

    operator char* ();

    bool is_string_id(const char* c_string);  // Проверка, действительно ли это строка идентификатор

};
