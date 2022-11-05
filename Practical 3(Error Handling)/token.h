
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isValidDelimiter(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}' ||
        ch == '#' || ch == '<' || ch == '>' || ch == '\0' || ch == '\n')
        return (true);
    return (false);
}
bool isIgnorable(char ch)
{
    if (ch != ' ' && ch != '\0' && ch != '\n' && ch != '\'' && ch != '"')
    {
        return true;
    }
    return false;
}
bool isValidOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || ch == '<' || ch == '=')
        return (true);
    return (false);
}
bool isString(char *str)
{
    if (str[0] == '"')
    {
        return true;
    }
    return false;
}

// Returns 'true' if the string is a VALID IDENTIFIER.
bool isvalidIdentifier(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && str[i] != '_')
        {
            return (false);
        }
        i++;
    }
    return (true);
}

// Return 'true' if the Token is Valid Keyword
bool isValidKeyword(char *str)
{
    if (!strcmp(str, "if") || !strcmp(str, "main") || !strcmp(str, "else") || !strcmp(str, "while") || !strcmp(str, "do") || !strcmp(str, "break") || !strcmp(str, "continue") || !strcmp(str, "int") || !strcmp(str, "double") || !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str, "char") || !strcmp(str, "case") || !strcmp(str, "char") || !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") || !strcmp(str, "typedef") || !strcmp(str, "switch") || !strcmp(str, "unsigned") || !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto") || !strcmp(str, "include"))
    {
        return (true);
    }
    return (false);
}

/* 
    Find all token from Input String 
    str : input String
    tracker : array to store token into 
    size : to track size of tracker array 
 */ 
void getToeken(char *str, char *tracker[], int *size)
{
    char *p = (char *)malloc(sizeof(char) * 20);
    int i;
    int k = 0;
    int start = *size + 1;
    int startFlag = 0;
    (*size)++;
    tracker[*size] = p;

    if (isValidDelimiter(str[0]) && isIgnorable(str[0]))
    {
        *(p + k) = str[0];
        k++;
        *(p + k) = '\0';
        k = 0;
        p = (char *)malloc(sizeof(char) * 20);
        (*size)++;
        tracker[(*size)] = p;
        startFlag = 1;
    }

    for (i = startFlag; i < 20 && str[i] != '\0'; i++)
    {
        if (isValidDelimiter(str[i]))
        {
            *(p + k) = '\0';
            k = 0;
            p = (char *)malloc(sizeof(char) * 20);
            (*size)++;
            tracker[(*size)] = p;

            if (isIgnorable(str[i]))
            {
                *(p + k) = str[i];
                k++;
                *(p + k) = '\0';
                k = 0;
                p = (char *)malloc(sizeof(char) * 20);
                (*size)++;
                tracker[(*size)] = p;
            }
        }
        else
        {
            *(p + k) = str[i];
            k++;
        }
    }
    *(p + k) = '\0';
}
