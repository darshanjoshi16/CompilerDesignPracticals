//Practical 2.1.4
//Display the content of both the file

#include <stdio.h>

int main(int argc, char* argv[])
{
	FILE* file1 = fopen("file1.txt", "r"); 
	FILE* file2 = fopen("file2.txt", "r"); 
	if(!file1){
		printf("\n Unable to open");
		return -1	;
	}
	char line[500];
	printf("Content of example file is here. \n");
	while (fgets(line, sizeof(line), file1)) {
		printf("%s", line); 
	}
	fclose(file1);
	printf("\n");
	if(!file2){
		printf("\n Unable to open ");
		return -1	;
	}
	char line2[500];
	printf("Content of copy file is here. \n");
	while (fgets(line2, sizeof(line2), file2)) {
		printf("%s", line2); 
	}
	fclose(file2);
	
	return 0;
}
