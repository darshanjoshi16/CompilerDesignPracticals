#include "token.h"

void main()
{
    FILE *input, *output, *output2;
    input = fopen("input.txt", "r");
    output = fopen("compressed_file.txt", "w");
    output2 = fopen("error_file.txt", "w");
    char str[50];
    bool flag = false;
    int lineNumber = 0;
    while (fgets(str, 50, input) != NULL)
    {
        lineNumber++;
        bool flag = false;
        char *tracker[10];
        int size = -1;
        if (strcmp(str, "") == 0)
        {
            printf("Skipping Line \n %s", str);
            continue;
        }
        getToeken(str, tracker, &size);
        for (int i = 0; i < size; i++)
        {
            if (strcmp(tracker[i], "") == 0)
            {
                // printf("Skip Token %d\n", i);
                continue;
            }
            if (!flag)
            {
                // Checking for start of Multiline Comments
                if (strcmp(tracker[i], "/") == 0)
                {
                    printf("Possible Comment %s\n\n", tracker[i + 1]);
                    if (strcmp(tracker[i + 2], "*") == 0)
                    {
                        printf("Multiline Comment Encounter Comment at line %d\n", lineNumber);
                        flag = true;
                        continue;
                    }
                    else if (strcmp(tracker[i + 2], "/") == 0)
                    {
                        printf("Single Line Comment Encounter Comment at line %d\n", lineNumber);
                        break;
                    }
                }

                if (isValidKeyword(tracker[i]) || isValidOperator((char)tracker[i][0]) || isValidDelimiter((char)tracker[i][0]) || isvalidIdentifier(tracker[i]))
                {
                    printf("\n %d> '%s' is Valid Token", lineNumber, (char *)tracker[i]);
                    fprintf_s(output, "%s", tracker[i]);
                }
                else
                {
                    printf("\n %d> '%s' is not valid Token ", i + 1, (char *)tracker[i]);
                    fprintf(output2, "%d line Contain invalid Token %s.\n", lineNumber, tracker[i]);
                    fprintf_s(output, "%s", tracker[i]);
                }
            }
            else
            {
                // terminate Multiline Comment
                if (strcmp(tracker[i], "*") == 0 && strcmp(tracker[i + 2], "/") == 0)
                {
                    flag = false;
                }
            }
        }
        printf("%s", str);
        size--;
    }
}

