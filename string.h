#pragma once
// #include <conio.h>
// #include <string.h>
#include <iostream>
#include <cstring>
#include <cctype>


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

    friend std::istream& operator>>(std::istream& in, String& s);
    friend std::ostream& operator<<(std::ostream& out, const String& s);
};
