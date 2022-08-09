//Practical 2.1.2
//Read data character by character and write to another text file 

#include <stdio.h>
void main()
{
    FILE *fp1, *fp2;
    char ch;
  
    // open the file for reading
    fp1 = fopen("file1.txt", "r");
    // open the file for writing
    fp2 = fopen("file2.txt", "w");
  
    // Read the contents of the file
    while((ch = getc(fp1)) != EOF)
        putc(ch, fp2);
  
    fclose(fp1);
    fclose(fp2);
    printf("File successfully copied");
}
