//Practical 1
//Implement a C program to detect tokens in a C program

//importing the libraries
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
// Returns 'true' if the character is a DELIMITER (which is suggesting the end of a statement).
bool isDelimiter(char ch)
{
    //it will compare all the delimiter for  given position character from input substring and return result according the given state
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return (true);
    return (false);
}
 
// Returns 'true' if the character is an OPERATOR (which is suggesting the process being done between operands).
bool isOperator(char ch)
{
    //it will compare all the Operator for  given position character from input substring and return result according the given state
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
        return (true);
    return (false);
}
 
// Returns 'true' if the string is a VALID IDENTIFIER.(which will be suggesting the operands which will be processed)
bool validIdentifier(char* str)
{
    //it will compare all valid identifier for  given position character from input substring and return result according the given state
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' || isDelimiter(str[0]) == true)
        return (false);
    return (true);
}
 
// Returns 'true' if the string is a KEYWORD (which will suggest the keywords of the native C Language).
bool isKeyword(char* str)
{
    //it will compare all the keywords for  given position character from input substring and return result according the given state
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||
         !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return (true);
    return (false);
}
 
// Returns 'true' if the string is an INTEGER (checking the number is the integer using individual location checking).
bool isInteger(char* str)
{
    //it will compare all the digits(numbers)in integer format for  given position character from input substring and return result according the given state
    int i, len = strlen(str);
 
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' || (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}
 
// Returns 'true' if the string is a REAL NUMBER.(checking the float number using individual location checking)
bool isRealNumber(char* str)
{
     //it will compare all the digits(numbers)in float format for  given position character from input substring and return result according the given state
    int i, len = strlen(str);
    bool hasDecimal = false;
 
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' && str[i] != '.' ||
            (str[i] == '-' && i > 0))
            return (false);
        if (str[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
}
 
// Extracts the substring using malloc from the array which will divided into the substrings
char* subString(char* str, int left, int right)
{
    int i;
    //memory allocation according the continue characters found in the string as a single substring
    char* subStr = (char*)malloc(
                  sizeof(char) * (right - left + 2));
 
    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}
 
//Parsing the input STRING taken from the input as array of characters.
//logic about checking tokens with every functionality
 //using the double pointer and running from the both side of the string entered by the user
void parse(char* str)
{
    
    int left = 0, right = 0;
    int len = strlen(str);
 
    while (right <= len && left <= right) {
        if (isDelimiter(str[right]) == false)
            right++;
 
        if (isDelimiter(str[right]) == true && left == right) {
            if (isOperator(str[right]) == true)
                printf("'%c' IS AN OPERATOR\n", str[right]);
 
            right++;
            left = right;
        } else if (isDelimiter(str[right]) == true && left != right
                   || (right == len && left != right)) {
            char* subStr = subString(str, left, right - 1);
 
            if (isKeyword(subStr) == true)
                printf("'%s' IS A KEYWORD\n", subStr);
 
            else if (isInteger(subStr) == true)
                printf("'%s' IS AN INTEGER\n", subStr);
 
            else if (isRealNumber(subStr) == true)
                printf("'%s' IS A REAL NUMBER\n", subStr);
 
            else if (validIdentifier(subStr) == true
                     && isDelimiter(str[right - 1]) == false)
                printf("'%s' IS A VALID IDENTIFIER\n", subStr);
 
            else if (validIdentifier(subStr) == false
                     && isDelimiter(str[right - 1]) == false)
                printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);
            left = right;
        }
    }
    return;
}
 
// Main Function
int main()
{
     // maximum length of string is 100 here
    char str[100];

    //taking the input from the user
    printf("Please Enter the input:");
    
    scanf("%[^\n]s",str);
 
    parse(str); // calling the parse function
 
    return (0);
}