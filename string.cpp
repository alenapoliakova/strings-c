#pragma once
#include <iostream>
#include "string.h"


String::String() {
	pstring = nullptr;
	length = 0;
}


String::String(const char* c_string) {
	length = strlen(c_string);
	pstring = new char[length + 1];
	strcpy(this->pstring, c_string);
}


String::String(char symbol) {
	length = 1;
	pstring = new char[length + 1];
	pstring[0] = symbol;
	pstring[1] = '\0';
}


String::String(const String& string) {
	length = string.length;
	pstring = new char[length + 1];
	for (int i = 0; i < length; i++) {
		pstring[i] = string.pstring[i];
	}
	pstring[length] = '\0';
}


int String::get_length() {
	return length;
}


void String::clear() {
	if (pstring) {
		delete[] pstring;
		length = 0;
	}
}

String::~String() {
	delete[] pstring;
	length = 0;
	pstring = NULL;
}
