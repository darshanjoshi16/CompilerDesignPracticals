//Practical 2.1.3
//Read data line by line and write to another text file

#include <stdio.h>

int main(int argc, char* argv[])
{
 FILE *fp1, *fp2;
   char ch;
 
   fp1 = fopen("file1.txt", "r");
   fp2 = fopen("file2.txt", "w");
   if ((fp1 == NULL) || (fp2==NULL)){
      printf("Cannot open file ");
      exit(0);
   }
   char line[500];

	while (fgets(line, sizeof(line), fp1)) {
		fputs(line,fp2);
	}
	printf("Content of first file is copied to another file successfully.");
	fclose(fp1);
	fclose(fp2);
	return 0;
}
