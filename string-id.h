#pragma once
#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <ctype.h>
#include "string.h"


class String_ID : public String {
public:
    String_ID();

    String_ID(char* c_string);
    String_ID(char symbol);
    String_ID(String& string);

    void upper();
    void lower();
    int find(char symbol); 

    String_ID operator=(const String_ID& string);
    String_ID operator+(const String_ID& string);
    String_ID operator-(String_ID& string);

    int operator>(String_ID& string);
    int operator<(String_ID& string);

    bool check_string_id(char* string);
    operator char* ();
};
