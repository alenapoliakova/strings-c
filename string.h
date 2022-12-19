#pragma once
// #include <conio.h>
// #include <string.h>
#include <iostream>
// #include <Windows.h>
// #include <sstream>
// #include <typeinfo>
#include <cstring>
#include <cctype>
// #include <iomanip>
// #include <string>


class String {
protected:
    char* pstring;
    int length;
public:
    String();  // Конструктор без параметров

    String(const char* c_string);  // Конструктор, принимающий в качестве параметра C-строку

    String(char symbol);  // Конструктор, принимающий в качестве параметра символ

    String(const String& string);  // Конструктор копирования

    int get_length();  // Получение длины строки

    void clear();  // Очистка строки

    ~String();  // Деструктор
};
