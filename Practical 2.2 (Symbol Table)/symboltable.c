/* This is a program to generate a symbol table. */

#include<stdio.h>
#include<string.h>	//Necessary Header Files
#include<conio.h>
#include<ctype.h>

FILE *fp;	//Creating File Pointer for accessing the file

/* Array of Felimiters to check in the file */
char delim[18]={' ','\t','\n',',','(',')','[',']','{','}','#','+','-','*','/','%','=','!'};

/* 2-D Array to hold all possible Keywords for checking with the tokens from the file */
char key[21][12]={"int","float","char","double","bool","void","extern","auto","bool","goto","static","class","struct","for","if","else","return","register","long","while","do"};

/* Array to hold the Datatype of the identifier to be put into the symbol table */
char ctype[12];

/* Array to avoid the preprocessor directives and some functions like printf, scanf and getch */
char avoid[5][12]={"include","define","getch","printf","scanf"};
struct symtab
{				//Structure to create Symbol Table
       char id[20];		//Identifier variable
       char type[20];		//Datatype variable
}p[30];			//Array of Structures

int in=0;	//Index to keep count of the number of entries in the Symbol Table

void construct();	//Function to construct the tokens
int isdelim(char);	//Function to check if the retrieved character is a delimiter
void check(char[]);	//Function to check for the redeclarations, multiple declarations and also to enter the tokens into the symbol tables
int checkkey(char[]);	//Function to check if the tokens match any keywords
void showtable();	//Function to display the Symbol Table

void main()		//Main Function
{
	char fname[12];
	
	printf("\nEnter the filename : ");
	scanf("%s",fname);
	fp=fopen(fname,"r");		//Opening the file
	if(fp==NULL)			//Checking for existence of File
		printf("\nThe file doesn't exist.");
	else				//If Check Successful
	{
		construct();		//Construct the tokens and subsequently enter into the table
		showtable();		//Show the Constructed Symbol Table
	}
	fclose(fp);			//Close the File
	getch();
}			//End Main

void construct()	//Function to construct the tokens
{
	char c,ch,token[12];	//Necessary variables to generate tokens
	int f=0,j=0,kf=0;	//Necessary flag variables
	strcpy(ctype,"NULL");	//Initialising as "NULL"
	while(!feof(fp))	//While not end of file
	{
		c=getc(fp);	//Retrieve the characters from the File one-by-one
		if(c==';'||c=='(')	//If the character is a semi-colon or an opening simple brace
		{
			if(f==1)	//If Flag is 1
			{
				token[j]='\0';	//Load Null Character
				j=0;		
				f=0;
				kf=checkkey(token);	//Check if token has been formed and if it is a keyword
				if(kf==0)		//if Not a Keyword and token is formed,Enter into the Symbol table after
					check(token);	//checking for redeclarations and multiple declarations
			}
			strcpy(ctype,"NULL");		//If Flag is 0 put "NULL" into 'ctype'
		}
		else if(c=='"')		//If retrieved character is '"'
		{	
			while((c=getc(fp))!='"');	//Continue untill we encounter another '"'. This is to eliminate the statements inside the printf statements.
		}
		else if(c=='<')		//If '<' is encountered
		{
			while((c=getc(fp))!='>');	//Continue untill a '>' symbol is encountered
		}
		else if(isdelim(c))	//If the character is a delimiter
		{
			if(f==1)	//If the flag is 1
			{
				token[j]='\0';	//Load Null Character into token array
				j=0;
				f=0;
				kf=checkkey(token);	//Check if token has been formed and if it is a keyword
				if(kf==0)		//if Not a Keyword and token is formed,Enter into the Symbol table after
					check(token);	//checking for redeclarations and multiple declarations
			}
		}
		else if(isalpha(c)||c=='_')	//If the character is an alphabet or an underscore
		{
			token[j++]=c;		//Load the character into the token array
			f=1;			//Set Flag to 1
		}
	}
}

int isdelim(char c)	//Function to check if the retrieved character is a delimiter
{
	int i;
	for(i=0;i<18;i++)
	{
		if(c==delim[i])		//Checking with delimiter array
			return 1;
	}
	return 0;
}

int checkkey(char t[])	//Function to check if the token matches any keywords or the preprocessor directives, etc.
{
	int i;
	for(i=0;i<5;i++)	
		if(strcmp(avoid[i],t)==0)	//Checking token with 'avoid' array.
			return 1;
	for(i=0;i<21;i++)
		if(strcmp(key[i],t)==0)		//Chekcing token with keywords array called 'key'.
		{
			strcpy(ctype,key[i]);	//If Keyword, set 'ctype' as that token.
			return 1;
		}
	return 0;
}	

void check(char t[])	//Function to load tokens into symbol table after checking for redeclarations and multiple declarations
{
	int i;
	for(i=0;i<in;i++)
	{
		//Checking for Redeclaration
		if(((strcmp(t,p[i].id))==0)&&((strcmp(ctype,p[i].type))==0))
		{
			printf("\nRedeclaration for '%s'",t);
			return;
		}
		//Checking for Multiple Declarations
		else if(((strcmp(t,p[i].id))==0)&&((strcmp(ctype,p[i].type))!=0)&&((strcmp(ctype,"NULL")!=0)))
		{
			printf("\nMultiple declaration for %s",t);
			return;
		}
	}
	//Entering tokens into the Symbol Table
	if(strcmp(ctype,"NULL")==0)
	{
		for(i=0;i<in;i++)
		{
			if(strcmp(t,p[i].id)==0)
				return;
		}
		printf("\n%s Undeclared ",t);
		return;
	}
	strcpy(p[in].id,t);		//Enter the identifier into the Symbol Table
	strcpy(p[in].type,ctype);	//Enter the corresponding Datatype into the Symbol Table
	in++;			//Increment the index to keep track of the number of entries in the Symbol Table
}

void showtable()
{
	int i;
	if(in==0)
	{
		printf("\nSymbol table is empty.");
		return;
	}
	printf("\nSymbol table");
	printf("\n------------");
	printf("\nIdentifier\tType");
	printf("\n----------\t----");
	for(i=0;i<in;i++)
		printf("\n%s\t\t%s",p[i].id,p[i].type);
}