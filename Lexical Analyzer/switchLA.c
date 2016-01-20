#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define fr(i,j,s) for(i = j ; i < s ; i++)
#define LPAREN_TOK '('
#define RPAREN_TOK ')'
#define GT_TOK '>'
#define EQ_TOK '='
#define MINUS_TOK '-'
#define SEMICOLON_TOK ';'
#define LCURLY_TOK '{'
#define RCURLY_TOK '}'
#define PLUS_TOK '+'
#define MUL_TOK '*'
#define DIV_TOK '/'
#define MOD_TOK '%'
#define LT_TOK '<'
#define NOT_TOK '!'
#define BAND_TOK '&'
#define BOR_TOK '|'
#define SEMICOL_TOK ';'
#define XOR_TOK '^'

#define DEQ_TOK 256
#define DPLUS_TOK 259
#define DMINUS_TOK 260
#define LOR_TOK 261
#define LAND_TOK 262

#define WHILE_TOK 350
#define IF_TOK 351
#define ELSE_TOK 352
#define FOR_TOK 353
#define SWITCH_TOK 354
#define CASE_TOK 355

#define ID_TOK 360
#define INTCONST 361
FILE *fp,*fp;
char yytext[128];
int yyleng;
char while_test[5] = {'w','h','i','l','e'};
char if_test[2] = {'i','f'};
char switch_test[6] = {'s','w','i','t','c','h'};
char else_test[4] = {'e','l','s','e'};
char for_test[3] = {'f','o','r'};
char case_test[4] ={'c','a','s','e'};
bool check(char initial,int length,char *test)
{
	int i ;
	char ch =initial;
	yytext[0]=initial;
	yyleng=1;
	fr(i,1,length)
	{
		if( (ch=getc(fp)) != test[i] )
		{
			break;
		}
		else
		{
			yytext[i] =ch;
			yyleng++;
		}
	}
	if(i==length)
	{
		if( isspace(ch=getc(fp)) || !(isalnum(ch)) )
		{
			if(!isspace(ch))
			{
				ungetc(ch,fp);
			}
			yytext[i]='\0';
			return true;
		}
		else
		{
			yytext[i]=ch;
			yyleng++;
			i++;
			while( ! (isspace(ch=getc(fp)) ))
			{
				yytext[i]=ch;
				yyleng++;
				i++;
			}
			yytext[i]='\0';
			return false;
		}
	}
	else
	{
		while( (isalnum(ch) ))
		{
			yytext[i]=ch;
			yyleng++;
			i++;
			ch=getc(fp);
		}
		yytext[i]='\0';
		ungetc(ch,fp);
		return false;
	}
}
void test_digit(char initial)
{
	int i = 1;
	char ch =initial;
	yytext[0]=initial;
	yyleng=1;
	while( (isdigit(ch=getc(fp)) ))
	{
		yytext[i]=ch;
		yyleng++;
		i++;
	}
	yytext[i]='\0';
	if( !isspace(ch) )
	{
		ungetc(ch,fp);
	}
}
void test_identifier(char initial)
{
	int i = 1;
	char ch =initial;
	yytext[0]=initial;
	yyleng=1;
	while (isalnum(ch=getc(fp)) )
	{
		yytext[i]=ch;
		yyleng++;
		i++;
	}
	yytext[i]='\0';
	if( !isspace(ch) )
	{
		ungetc(ch,fp);
	}
}
int yylex()
{
	char ch;
	if (fp==NULL)
	{
		fp=stdin;
	}
	ch=getc(fp);
	while(isspace(ch))
		ch=getc(fp);
	char ch2;
	switch(ch)
	{
		case LPAREN_TOK:
		case RPAREN_TOK:
		case GT_TOK :
		case SEMICOLON_TOK :
		case LCURLY_TOK :
		case RCURLY_TOK :
		case MUL_TOK :
		case DIV_TOK :
		case MOD_TOK :
		case LT_TOK :
		case NOT_TOK :
		case XOR_TOK :	yytext[0]=ch;
						yytext[1]='\0';
						yyleng=1;
						return ch;

		case BAND_TOK : if((ch2 =getc(fp)) == BAND_TOK)
						{
							yytext[0]='&';
							yytext[1]='&';
							yytext[2]='\0';
							yyleng=2;
							return LAND_TOK;
						}
						else
						{
							yytext[0]='&';
							yytext[1]='\0';
							yyleng=1;
							ungetc(ch2,fp);
							return BAND_TOK;
						}
		case BOR_TOK : if((ch2 =getc(fp)) == BOR_TOK)
						{
							yytext[0]='|';
							yytext[1]='|';
							yytext[2]='\0';
							yyleng=2;
							return LOR_TOK;
						}
						else
						{
							yytext[0]='|';
							yytext[1]='\0';
							yyleng=1;
							ungetc(ch2,fp);
							return BOR_TOK;
						}

		case EQ_TOK : 	if((ch2 =getc(fp)) == EQ_TOK)
						{
							yytext[0]='=';
							yytext[1]='=';
							yytext[2]='\0';
							yyleng=2;
							return DEQ_TOK;
						}
						else
						{
							yytext[0]='=';
							yytext[1]='\0';
							yyleng=1;
							ungetc(ch2,fp);
							return EQ_TOK;
						}

		case PLUS_TOK : if((ch2 =getc(fp)) == PLUS_TOK)
						{
							yytext[0]='+';
							yytext[1]='+';
							yytext[2]='\0';
							yyleng=2;
							return DPLUS_TOK;
						}	
						else
						{
							yytext[0]='+';
							yytext[1]='\0';
							yyleng=1;
							ungetc(ch2,fp);
							return PLUS_TOK;
						}
		
		case MINUS_TOK : if((ch2 =getc(fp)) == MINUS_TOK)
						{
							yytext[0]='-';
							yytext[1]='-';
							yytext[2]='\0';
							yyleng=2;
							return DMINUS_TOK;
						}
						else
						{
							yytext[0]='-';
							yytext[1]='\0';
							yyleng=1;
							ungetc(ch2,fp);
							return MINUS_TOK;
						}
		
		case 'w':	if(check('w',5,while_test))
					{
						return WHILE_TOK;
					}
					else
					{
						return ID_TOK;
					} 
		case 'f':	if(check('f',3,for_test))
					{
						return FOR_TOK;
					}
					else
					{
						return ID_TOK;
					}
		case 'i':	if(check('i',2,if_test))
					{
						return IF_TOK;	
					}
					else
					{
						return ID_TOK;
					}
		case 's':	if(check('s',6,switch_test))
					{
						return SWITCH_TOK;	
					}
					else
					{
						return ID_TOK;
					}
		case 'c':	if(check('c',4,case_test))
					{
						return CASE_TOK;	
					}
					else
					{
						return ID_TOK;
					}
		case 'e':	if(check('e',4,else_test))
					{
						return ELSE_TOK;	
					}
					else
					{
						return ID_TOK;
					}

		default : 	if(isdigit(ch))
					{
						test_digit(ch);
						return INTCONST;
					}
					else
					{
						test_identifier(ch);
						return ID_TOK;
					} 
	}
}
 

int main(int argc,char *argv[])
{
	int token;
	if(argc != 2)
	{
		fprintf(stderr,"Usage %s <inputfilename>\n",argv[0]);
		exit(1);
	} 
	else
	{
		fp=fopen(argv[1],"r");
		while(!feof(fp))
		{
			token=yylex();
			printf("%d %s\n",token,yytext);
		}
		fclose(fp);
	}
}