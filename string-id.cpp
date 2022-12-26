#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <ctype.h>
#include <algorithm>
#include "string-id.h"


String_ID::String_ID() {
    pstring = nullptr;
    length = 0;
}


String_ID::String_ID(char* c_string) {
    std::cout << "\nc_string=" << c_string << "\n";
    if (check_string_id(c_string)) {
        pstring = new char[strlen(c_string) + 1];
        strcpy(pstring, c_string);
        length = strlen(c_string);
        pstring[length] = '\0';
    }
    else {
        pstring = NULL;
        length = 0;
    }
}


String_ID::String_ID(char symbol) {
    if (isalpha(symbol)) {
        length = 1;
        pstring = new char[length + 1];
        pstring[0] = symbol;
        pstring[1] = '\0';
    }
    else {
        length = 0;
        pstring = 0;
    }
}


String_ID::String_ID(String& string) {
    if (check_string_id(string.get_string())) {
        length = string.get_length();
        pstring = new char[length + 1];
        strcpy(pstring, string.get_string());
        pstring[length] = '\0';
    }
    else {
        delete[] pstring;
        pstring = NULL;
        length = 0;
    }
}


void String_ID::upper() {
    for (size_t index = 0; index < length; index++) {
        pstring[index] = toupper(pstring[index]);
    }
}


void String_ID::lower() {
    for (int index = 0; index < length; index++) {
        pstring[index] = tolower(pstring[index]);
    }
}


int String_ID::find(char symbol) {
    for (int index = 0; index < length; index++)
        if (pstring[index] == symbol) {
            return index;
        }
    return -1;
}


String_ID String_ID::operator=(const String_ID& string) {
    String::operator=(string);
    return string;
}


String_ID String_ID::operator+(const String_ID& string) {
    char* new_pstring = new char[length + string.length + 1];

    for (int i = 0; i < length; i++) {
        new_pstring[i] = pstring[i];
    }

    for (int i = length; i < length + string.length; i++) {
        new_pstring[i] = string.pstring[i - length];
    }
    new_pstring[length + string.length] = '\0';
    return String_ID(new_pstring);
}


String_ID String_ID::operator-(String_ID& string) {
    char* new_pstring = new char[length + 1];

    for (int i = 0; i < length; i++) {
        bool same = false;
        for (int j = 0; j < string.length; j++) {
            if (pstring[i] == string.pstring[j]) {
                same = true;
                break;
            }
        }
        if (same) {
            new_pstring[i] = '_';
        }
        else {
            new_pstring[i] = pstring[i];
        }
    }
    new_pstring[length] = '\0';
    return String_ID(new_pstring);
}


int String_ID ::operator>(String_ID& string) {
    // Returns true, if these string > than input string
    int result = strcmp(string.pstring, pstring);
    if (result == 0) return -1;  // Same strings
    else if (result > 0) return 1;
    else return 0;
}


int String_ID ::operator<(String_ID& string) {
    // Returns true, if these string < than input string
    int result = strcmp(string.pstring, pstring);
    if (result == 0) return -1;  // Same strings
    else if (result < 0) return 1;
    else return 0;
}


bool String_ID::check_string_id(char* string) {
    if (string) {
        if (isalpha(string[0])) {
            for (int i = 1; i < strlen(string); i++) {
                if (!((isdigit(string[i]) || (isalpha(string[i])) || (string[i] == '_')))) {
                    return false;
                }
            }
        }
        else {
            return false;
        }
        return true;
    }
    else {
        return false;
    }
}


String_ID::operator char* () {
    return pstring;
}
