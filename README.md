# String & String ID C++ (inheritance)
Project with base class `String` and his successor `String_ID`, using to work with strings.  
Running `menu.cpp` programm will create array with type of based class (`String`) to store `String_ID` objects. 
Menu has 15 actions to work with strings.

## Example of using some actions from menu
- Add string `hello` to array. Program will create this string with id=1:
```text
-----
Menu:
-----
1. Create an empty string.
2. Create copy of string by ID.
3. Create string from input string.
4. Create string from input symbol.
5. (=) Equate strings by ID
6. (+) Add string n1 + string n2.
7. (-) Subtract string n1 from string n2.
8. (>) String n1 > than string n2.
9. (<) String n1 < than string n2.
10. Convert string to lowercase.
11. Convert string to uppercase.
12. Find first entry of element X to string.
13. Delete element by ID.
14. Get all strings.
15. Exit.

        Select your choice: 3

Write string: hello

Strings:

N(1)=hello
```
- Create copy from used string:
```text
        Select your choice: 2

Write a ID of string for copy:
ID=1

Strings:

N(1)=hello
N(2)=hello
```
- Add string with id=1 to string with id=2 (it will create new string with id=3):
```text
        Select your choice: 6

Add string1 to string2
ID=1

ID=2

Strings:

N(1)=hello
N(2)=hello
N(3)=hellohello
```
