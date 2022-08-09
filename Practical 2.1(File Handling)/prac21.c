//Practical 2.1.1
//Read the contents of one text file and write to another text file

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void main()
{
    FILE *fp1,*fp2;
    char ch[20];

    fp1 = fopen("file1.txt","r");
    fp2 = fopen("file2.txt","a");

    if(fp1 == NULL || fp2 == NULL)
    {
        printf("We Can not perform the operation");
    }
    else
    {
        while(!(feof(fp1)))
        {
            fscanf(fp1, "%s", ch);
            fprintf(fp2, "%s ", ch);
        }

        printf("File copied Successfully!");
        fclose(fp1);
        fclose(fp2);

    }
}

