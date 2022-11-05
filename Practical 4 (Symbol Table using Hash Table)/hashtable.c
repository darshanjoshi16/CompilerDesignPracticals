//Importing the libraries for the creating the hashtable for the symbol table
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defining the size for the entry and hashtable
#define N 10
#define M 20
char hashTable[N][M], symbol[M], ch;

//defining the lookup functionalities for the symbol table
int lookup(int index) 
{
    if (hashTable[index][0] == '0') 
        return 1;
    return 0;
}

//implementation of linear probing for collision resolution techniques if the index is preoccupied
int linearProbing(int index) 
{
    int count = 0;
    while (!lookup(index)) 
    {
            if (count == N - 1) 
                return -1;
            if (index == N - 1) 
                index = 0;
            else 
                index++;
            count++;
    }
    return index;
}

//defining the finding index from the ascii sum we have calculated for the input.
int findIndex(int asciiSum) 
{
    int index = asciiSum % N;
    if (lookup(index)) 
        return index;

    return linearProbing(index);
}

//copying symbols from symbol table to hash table
void copyFromStringToTable(int index) 
{
    for (int i = 0; i < M; ++i) 
    {
        hashTable[index][i] = symbol[i];
        symbol[i] = '0';
    }
}

//function for printing the hash table
void printTable() 
{
    printf("\n");
    for (int i = 0; i < N; i++) 
    {
        printf("hash[%d] = ", i);
        for (int j = 0; j < M; j++) 
        {
            if (hashTable[i][j] != '0') 
                printf("%c", hashTable[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//storing the value into the hashtable
int calculateAndStore(int asciiSum) 
{
    int index = findIndex(asciiSum);
    if (index == -1) 
    {
        printTable();
        printf("%sError: Hashtable overflow !\n\n", "\x1B[31m");
        exit(0);
    }

    else 
    {
        copyFromStringToTable(index);
    }
    return index;
}

//main function from file handling
int main(void) 
{
    FILE *reader = fopen("input.txt", "r");
    int hashIndex = 0, strIndex = 0, asciiSum = 0;

    if (reader == NULL) 
    {
        printf("Error in opening file!, \n");
        exit(1);
    }

   //initialize the hash table
    memset(hashTable, '0', sizeof hashTable);

    while (ch != EOF) 
    {
        ch = fgetc(reader);
        if (ch == '\n') 
        {
            calculateAndStore(asciiSum);
            asciiSum = 0, strIndex = 0;
        }

        else 
        {
            symbol[strIndex++] = ch;
            asciiSum += ch;
        }
    }

    calculateAndStore(asciiSum + 1);
    printTable();
    fclose(reader);
    return 0;
}