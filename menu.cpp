#define NOMINMAX
#include <iostream>
#include <vector>
#include "string.h"
#include "string-id.h"

using namespace std;

void print_strings(std::vector<String>& strings);
int get_id_from_console(std::vector<String>& strings);


int main() {
    std::vector <String> strings;

    const int CREATE_EMPTY_STRING = 1;
    const int CREATE_COPY_OF_STRING_BY_ID = 2;
    const int CREATE_STRING_FROM_INPUT_STRING = 3;
    const int CREATE_STRING_FROM_INPUT_SYMBOL = 4;

    const int EQUATE_STRINGS = 5;
    const int ADD = 6;
    const int SUBSTRACT = 7;
    const int MORE = 8;
    const int LESS = 9;
    const int STRING_TO_LOWERCASE = 10;
    const int STRING_TO_UPPERCASE = 11;
    const int FIND_INDEX_OF_ENTRY = 12;
    const int DELETE_STRING = 13;

    const int GET_ALL_STRINGS = 14;
    const int EXIT = 15;

    while (true) {
        print_strings(strings);
        std::cout << "\n-----\n" << "Menu:\n" << "-----\n";
        std::cout << "1. Create an empty string.\n2. Create copy of string by ID.\n3. Create string from input string.\n4. Create string from input symbol.\n";
        std::cout << "5. (=) Equate strings by ID\n6. (+) Add string n1 + string n2.\n7. (-) Subtract string n1 from string n2.\n";
        std::cout << "8. (>) String n1 > than string n2.\n9. (<) String n1 < than string n2.\n10. Convert string to lowercase.\n11. Convert string to uppercase.\n";
        std::cout << "12. Find first entry of element X to string.\n13. Delete element by ID.\n";
        std::cout << "14. Get all strings.\n15. Exit.\n\n";
        std::cout << "\tSelect your choice: ";

        int choice;
        if (std::cin >> choice) {
            switch (choice) {
            case CREATE_EMPTY_STRING: {
                strings.push_back(String_ID());
                break;
            }
            case CREATE_COPY_OF_STRING_BY_ID: {
                std::cout << "\nWrite a ID of string for copy: ";
                int id = get_id_from_console(strings);
                strings.push_back((String_ID)strings[id - 1]);
                break;
            }
            case CREATE_STRING_FROM_INPUT_STRING: {
                std::cout << "\nWrite string: ";
                std::cin.ignore();
                std::string line;
                std::getline(std::cin, line);

                char* string = new char[line.size() + 1];
                for (int i = 0; i < line.size() + 1; i++) {
                    string[i] = line[i];
                }
                strings.push_back(String_ID(string));
                break;
            }
            case CREATE_STRING_FROM_INPUT_SYMBOL: {
                std::cout << "\nWrite one symbol: ";
                char symbol;
                std::cin >> symbol;
                strings.push_back(String_ID(symbol));
                break;
            }
            case EQUATE_STRINGS: {
                int string_id = get_id_from_console(strings);
                String_ID copy_string = strings[string_id - 1];
                std::cout << "\nCreate new string: " << copy_string.get_string();
                strings.push_back(copy_string);
                break;
            }
            case ADD: {
                std::cout << "\nAdd string1 to string2";
                int first_id = get_id_from_console(strings);
                int second_id = get_id_from_console(strings);
                String_ID a = String_ID(strings[first_id - 1]);
                String_ID b = String_ID(strings[second_id - 1]);
                strings.push_back(a + b);
                break;
            }
            case SUBSTRACT: {
                std::cout << "\nSubstract strings";
                int first_id = get_id_from_console(strings);
                int second_id = get_id_from_console(strings);
                String_ID a = String_ID(strings[first_id - 1]);
                String_ID b = String_ID(strings[second_id - 1]);
                strings.push_back(a - b);
                break;
            }
            case MORE: {
                int first_id = get_id_from_console(strings);
                int second_id = get_id_from_console(strings);

                String_ID a = String_ID(strings[first_id - 1]);
                String_ID b = String_ID(strings[second_id - 1]);

                bool result = a > b;
                if (result) {
                    std::cout << "\nYes, " << a.get_string() << " bigger than " << b.get_string();
                }
                else {
                    std::cout << "\nNo, " << a.get_string() << " not bigger than " << b.get_string();
                }
                break;
            }
            case LESS: {
                int first_id = get_id_from_console(strings);
                int second_id = get_id_from_console(strings);

                String_ID a = String_ID(strings[first_id - 1]);
                String_ID b = String_ID(strings[second_id - 1]);

                bool result = a < b;
                if (result) {
                    std::cout << "\nYes, " << a.get_string() << " less than " << b.get_string();
                }
                else {
                    std::cout << "\nNo, " << a.get_string() << " not less than " << b.get_string();
                }
                break;
            }
            case STRING_TO_LOWERCASE: {
                int string_id = get_id_from_console(strings);
                String_ID string = String_ID(strings[string_id - 1]);
                string.lower();
                strings[string_id - 1] = string;
                break;
            }
            case STRING_TO_UPPERCASE: {
                int string_id = get_id_from_console(strings);
                String_ID string = String_ID(strings[string_id - 1]);
                string.upper();
                strings[string_id - 1] = string;
                break;
            }
            case FIND_INDEX_OF_ENTRY: {
                int string_id = get_id_from_console(strings);
                String_ID string = String_ID(strings[string_id - 1]);

                std::cout << "\nWrite string to find it in " << string.get_string() << " :";
                char str;
                std::cin >> str;

                std::cout << "\nIndex=" << string.find(str);
                break;
            }
            case DELETE_STRING: {
                int string_id = get_id_from_console(strings);
                strings.erase(strings.cbegin() + string_id - 1);
                break;
            }
            case GET_ALL_STRINGS: {
                print_strings(strings);
                break;
            }
            case EXIT:
                return 0;
            default:
                std::cout << "\nPlease enter a choice from Menu\n";
                break;
            }
        }
        else {
            std::cout << "\nPlease enter a valid number\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void print_strings(std::vector<String>& strings) {
    std::cout << "\nStrings:\n";
    for (int i = 0; i < strings.size(); i++) {
        std::cout << "\nN(" << i + 1 << ")=" << strings[i].get_string();
    }
    std::cout << "\n";
}


int get_id_from_console(std::vector<String>& strings) {
    while (true) {
        std::cout << "\nID=";
        int id;
        if (std::cin >> id) {
            if (id >= 1 && id <= strings.size()) {
                return id;
            }
            else {
                std::cout << "\nPlease enter ID from list of all strings\n";
            }
        }
        else {
            std::cout << "\nPlease enter a valid ID\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
