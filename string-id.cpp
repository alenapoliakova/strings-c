#include "string-id.h"


String_ID::String_ID() {
    pstring = nullptr;
    length = 0;
}


String_ID::String_ID(const String_ID& c_string) {
    if (is_string_id(c_string.pstring)) {
        this->length = c_string.length;
        this->pstring = new char[this->length + 1];
        strcpy(this->pstring, c_string.pstring);
        this->pstring[this->length] = '\0';
    }
    else {
        delete[] this->pstring;
        pstring = NULL;
        length = 0;
    }
}


String_ID::String_ID(char* c_string) {
    if (!(is_string_id)) {
        delete[] pstring;
        length = 0;
        pstring = NULL;
    }
    else {
        pstring = c_string;
        length = strlen(c_string);
        pstring[length] = '\0';
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


String_ID::String_ID(const String_ID& string) {
    if (!(is_string_id)) {
        delete[] pstring;
        length = 0;
        pstring = NULL;
    }
    else {
        length = string.length;
        pstring = new char[length + 1];
        strcpy(this->pstring, string.pstring);
        pstring[length] = '\0';
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


String_ID& String_ID::operator+(String_ID& string) {
    String_ID new_string(*this);
    if (new_string && string) {
        char* c_string = new char[strlen(new_string) + strlen(new_string.pstring) + 1]();
        strcat(c_string, new_string);
        strcat(c_string, new_string.pstring);
        String_ID result_string = String_ID(c_string);
        result_string.pstring[strlen(new_string) + strlen(string.pstring)] = '\0';
        return result_string;
    }
    return *this;
}


String_ID String_ID::operator-(String_ID& string) {
    String_ID new_str(*this);
    String_ID str(string);

    if (new_str.pstring && str) {
        for (int index1 = 0; index1 < length; index1++) {
            
            // If symbol 1 == symbol 2 => delete it
            for (int index2 = 0; index2 < strlen(string.pstring); index2++) {
                if (new_str.pstring[index1] == string.pstring[index2]) {
                    for (int cnt = index1; cnt < length - 1; cnt++) {
                        new_str.pstring[cnt] = new_str.pstring[cnt + 1];
                    }
                    new_str.pstring[length - 1] = '\0';
                    index1--;
                    break;
                }
            }
        }
        return String_ID(new_str.pstring);
    }
    return '\0';
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



String_ID::operator char* () {
    return pstring;
}


bool String_ID::is_string_id(const char* c_string) {
    if (c_string) {
        if (isalpha(c_string[0])) {
            for (int index = 1; index < strlen(c_string); index++) {
                if (!(isdigit(c_string[index]) || isalpha(c_string[index]) || c_string[index] == '_')) {
                    return false;
                }
            }
        }
        else {
            return false;
        }
    }
    return false;
}
