#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include "string.h"


String::String() {
	pstring = nullptr;
	length = 0;
}


String::String(const char* c_string) {
	length = strlen(c_string);
	pstring = new char[length + 1];
	for (int i = 0; i <= length; i++) {
		pstring[i] = c_string[i];
	}
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


char* String::get_string() {
	return pstring;
}


void String::clear() {
	if (pstring) {
		delete[] pstring;
		length = 0;
	}
}


String::~String() {
	if (pstring) {
		delete[] pstring;
		length = 0;
		pstring = NULL;
	}
}


String String::operator=(const String& string) {
	length = string.length;
	pstring = new char[length + 1];
	for (int i = 0; i < length; i++) {
		pstring[i] = string.pstring[i];
	}
	pstring[length] = '\0';
	return *this;
}


std::istream& operator>>(std::istream& in, String& s) {
	char str[255];
	in >> std::setw(255) >> str;
	s = str;
	return in;
}


std::ostream& operator<<(std::ostream& out, const String& s) {
	for (int i = 0; i < s.length; ++i) {
		out << s.pstring[i];
	}
	out << "\n";
	return out;
}
