%{
    int count = 0;
%}
%%
[aeiouAEIOU][A-Za-z]+              {printf("\nWord starting with vowel"); count++; }
[A-Za-z(^aeiouAEIOU)][A-Za-z]+      {printf("\nWord not starting with vowel");}
     ;
%%
main()
{
     yylex();
     printf("\n Count of words = %d\n",count);
}
int yywrap()
{
     return 1;
}