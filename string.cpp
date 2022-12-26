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
	char* copy_pstring = new char[length + 1];
	strcpy(copy_pstring, pstring);
	return copy_pstring;
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
	delete[] pstring;
	pstring = new char[length + 1];
	for (int i = 0; i < length; i++) {
		pstring[i] = string.pstring[i];
	}
	pstring[length] = '\0';
	return *this;
}
