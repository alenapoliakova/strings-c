#define _CRT_SECURE_NO_WARNINGS
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
#include "string-id.h"


String_ID::String_ID() {
    pstring = nullptr;
    length = 0;
}


String_ID::String_ID(char* c_string) {
    std::cout << "\nc_string=" << c_string << "\n";
    if (check_string_id(c_string)) {
        pstring = c_string;
        length = strlen(c_string);
        pstring[length] = '\0';
    }
    else {
        delete[] c_string;
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
    if (is_string_id(string.get_string())) {
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
    return NULL;
}


String_ID String_ID::operator=(const String_ID& string) {
    String::operator=(string);
    return string;
}


String_ID String_ID::operator+(const String_ID& string) {
    String_ID new_string(*this);

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
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < string.length; j++) {
            if (pstring[i] == string.pstring[j])
                pstring[i] = '_';
        }
    }
    String_ID new_string(pstring);

    return new_string;
}


bool String_ID ::operator>(String_ID& string) {
    // Returns true, if string >
    String_ID str(string);

    if (str) {
        int max_length = 0;

        int length1 = strlen(str.pstring);
        int length2 = strlen(this->pstring);

        if (length1 > length2) {
            max_length = length2;
        } else {
            max_length = length1;
        }

        bool bigger = NULL;

        for (int i = 0; i < max_length; i++) {
            if (int(this->pstring[i]) > int(str.pstring[i])) {
                bigger = false;
            }
            else if (int(this->pstring[i]) < int(str.pstring[i])) {
                bigger = true;
            }
        }

        if ((bigger == NULL && (length2 > length1)) || !bigger) {
            return true;
        }
        return false;
    }
    return NULL;
}


bool String_ID ::operator<(String_ID& string) {
    // Returns true, if string <
    String_ID str(string);

    if (str) {
        int max_length = 0;

        int length1 = strlen(str.pstring);
        int length2 = strlen(this->pstring);
        if (length1 > length2) {
            max_length = length2;
        }
        else {
            max_length = length1;
        }
        bool less = NULL;

        for (int i = 0; i < max_length; i++) {
            if (int(this->pstring[i]) > int(str.pstring[i])) {
                less = false;
            } else if (int(this->pstring[i]) < int(str.pstring[i])) {
                less = true;
            }
        }

        if ((less == NULL && (length2 < length1)) || less) {
            return true;
        }
        return false;
    }
    else return NULL;
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
    }
    else {
        return false;
    }
}


String_ID::operator char* () {
    return pstring;
}


bool String_ID::is_string_id(const char* c_string) {
    if (c_string) {
        for (int i = 0; i < strlen(c_string); i++) {
            if (!((c_string[i] >= 'a' && c_string[i] <= 'z') || (c_string[i] >= 'A' && c_string[i] <= 'Z') || (c_string[i] >= '0' && c_string[i] <= '9') || c_string[i] == '_')) {
                return false;
            }
        }
    }
    else {
        return false;
    }
}
