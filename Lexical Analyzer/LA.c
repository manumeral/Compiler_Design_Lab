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
#define XOR_TOK '^'
#define COLON_TOK ':'

#define DEQ_TOK 256
#define DPLUS_TOK 259
#define DMINUS_TOK 260
#define LOR_TOK 261
#define LAND_TOK 262
#define GE_TOK 263
#define LE_TOK 264
#define NE_TOK 265
#define PE_TOK 266
#define ME_TOK 267
#define MULE_TOK 268
#define DE_TOK 269
#define NULL_TOKEN 450

#define WHILE_TOK 350
#define IF_TOK 351
#define ELSE_TOK 352
#define FOR_TOK 353
#define SWITCH_TOK 354
#define CASE_TOK 355

#define ID_TOK 360
#define INTCONST 361

FILE *fp;
char yytext[128];
int yyleng;
int yylex()
{
	char ch;
	if (fp==NULL)
	{
		fp=stdin;
	}
	/*
	while(isspace(ch))
		ch=getc(fp);
	*/
	int state  = 0 , token  = -1;
	char ch2;
	yyleng = 0 ;
	while(1)
	{
		switch(state)
		{
			case 0:	ch=getc(fp);
					while(isspace(ch))
						ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == 'f') state = 1 ;
					else if(ch == 'w') state = 2 ;
					else if(ch == 'i') state = 3 ;
					else if(ch == 'e') state = 4 ;
					else if(ch == '(') state = 5 ;
					else if(ch == ')') state = 6 ; 
					else if(ch == '+') state = 7 ;
					else if(ch == '-') state = 8 ;
					else if(ch == '=') state = 85 ;
					else if(ch == '*') state = 9 ;
					else if(ch == '/') state = 10 ;
					else if(ch == '%') state = 11 ;
					else if(ch == '>') state = 12 ;
					else if(ch == '<') state = 13 ;
					else if(ch == '&') state = 14 ;
					else if(ch == '!') state = 15 ;
					else if(ch == '^') state = 16 ;
					else if(ch == '|') state = 17 ;
					else if(ch == ';') state = 18 ;
					else if(ch == ':') state = 50 ;
					else if(isalpha(ch)) state = 51 ;
					else if(isdigit(ch)) state = 52 ;
					else if(ch == '{') state = 53 ;
					else if(ch == '}') state = 54 ;
					else return NULL_TOKEN;
					break;
			case 1:	ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == 'o') state = 19 ;
					else if(isalnum(ch)) state = 51 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = ID_TOK ;
						state = -1 ;
					}
					break;
			case 2:	ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == 'h') state = 21 ;
					else if(isalnum(ch)) state = 51 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = ID_TOK ;
						state = -1 ;
					}
					break;
			case 3:	ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == 'f') state = 24 ;
					else if(isalnum(ch)) state = 51 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = ID_TOK ;
						state = -1 ;
					}
					break;
			case 4:	ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == 'l') state = 25 ;
					else if(isalnum(ch)) state = 51 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = ID_TOK ;
						state = -1 ;
					}
					break;
			case 5:	yytext[yyleng]='\0';
					token = LPAREN_TOK ;
					state = -1 ;
					break;
			case 6:	yytext[yyleng]='\0';
					token = RPAREN_TOK ;
					state = -1 ;
					break;
			case 7:	ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == '+') state = 28 ;
					else if(ch == '=') state = 29 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = PLUS_TOK;
						state = -1 ;
					}
					break;
			case 8:	ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == '-') state = 30 ;
					else if(ch == '=') state = 31 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = MINUS_TOK ;
						state = -1 ;
					}
					break;
			case 9:	ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == '=') state = 32 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = MUL_TOK ;
						state = -1 ;
					}
					break;
			case 10:ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == '=') state = 33 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = DIV_TOK ;
						state = -1 ;
					}
					break;
			case 11:yytext[yyleng]='\0';
					token = MOD_TOK ;
					state = -1 ;
					break;
			case 12:ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == '=') state = 56 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = GT_TOK ;
						state = -1 ;
					}
					break;
			case 13:ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == '=') state = 57 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = LT_TOK ;
						state = -1 ;
					}
					break;
			case 14:ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == '&') state = 84 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = BAND_TOK ;
						state = -1 ;
					}
					break;
			case 15:ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == '=') state = 59 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = NOT_TOK ;
						state = -1 ;
					}
					break;
			case 16:yytext[yyleng]='\0';
					token = XOR_TOK ;
					state = -1 ;
					break;
			case 17:ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == '|') state = 58 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = BOR_TOK ;
						state = -1 ;
					}
					break;
			case 18:yytext[yyleng]='\0';
					token = SEMICOLON_TOK ;
					state = -1 ;
					break;
			case 19:ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == 'r') state = 20 ;
					else if(isalnum(ch)) state = 51 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = ID_TOK ;
						state = -1 ;
					}
					break;
			case 20:ch=getc(fp);
					yytext[yyleng++]=ch;
					if(isalnum(ch)) state = 51 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = FOR_TOK ;
						state = -1 ;
					}
					break;
			case 21:ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == 'i') state = 22 ;
					else if(isalnum(ch)) state = 51 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = ID_TOK ;
						state = -1 ;
					}
					break;
			case 22:ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == 'l') state = 23 ;
					else if(isalnum(ch)) state = 51 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = ID_TOK ;
						state = -1 ;
					}
					break;
			case 23:ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == 'e') state = 60 ;
					else if(isalnum(ch)) state = 51 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = ID_TOK ;
						state = -1 ;
					}
					break;
			case 85:ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == '=') state = 86 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = EQ_TOK ;
						state = -1 ;
					}
					break;
			case 86:yytext[yyleng]='\0';
					token = DEQ_TOK ;
					state = -1;
					break;

			case 60:ch=getc(fp);
					yytext[yyleng++]=ch;
					if(isalnum(ch)) state = 51 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = WHILE_TOK ;
						state = -1 ;
					}
					break;
			case 24:ch=getc(fp);
					yytext[yyleng++]=ch;
					if(isalnum(ch)) state = 51 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = IF_TOK ;
						state = -1 ;
					}
					break;
			case 25:ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == 's') state = 26 ;
					else if(isalnum(ch)) state = 51 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = ID_TOK ;
						state = -1 ;
					}
					break;
			case 26:ch=getc(fp);
					yytext[yyleng++]=ch;
					if(ch == 'e') state = 27 ;
					else if(isalnum(ch)) state = 51 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = ID_TOK ;
						state = -1 ;
					}
					break;
			case 27:ch=getc(fp);
					yytext[yyleng++]=ch;
					if(isalnum(ch)) state = 51 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = ELSE_TOK ;
						state = -1 ;
					}
					break;
			case 28:yytext[yyleng]='\0';
					token = DPLUS_TOK ;
					state = -1 ;
					break;
			case 29:yytext[yyleng]='\0';
					token = PE_TOK ;
					state = -1 ;
					break;
			case 30:yytext[yyleng]='\0';
					token = DMINUS_TOK ;
					state = -1 ;
					break;
			case 31:yytext[yyleng]='\0';
					token = ME_TOK ;
					state = -1 ;
					break;
			case 32:yytext[yyleng]='\0';
					token = MULE_TOK ;
					state = -1;
					break;
			case 33:yytext[yyleng]='\0';
					token = MULE_TOK ;
					state = -1;
					break;
			case 56:yytext[yyleng]='\0';
					token = GE_TOK ;
					state = -1;
					break;
			case 57:yytext[yyleng]='\0';
					token = LE_TOK ;
					state = -1;
					break;
			case 84:yytext[yyleng]='\0';
					token = LAND_TOK;
					state = -1;
					break;
			case 59:yytext[yyleng]='\0';
					token = NE_TOK;
					state = -1;
					break;
			case 58:yytext[yyleng]='\0';
					token = LOR_TOK;
					state = -1;
					break;
			case 50:yytext[yyleng]='\0';
					token = COLON_TOK ;
					state = -1 ;
					break;
			case 51:ch=getc(fp);
					yytext[yyleng++]=ch;
					if(isalnum(ch)) state = 51 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = ID_TOK ;
						state = -1 ;
					}
					break;
			case 52:ch=getc(fp);
					yytext[yyleng++]=ch;
					if(isdigit(ch)) state = 52 ;
					else 
					{
						yytext[--yyleng]='\0';
						ungetc(ch,fp);
						token = INTCONST ;
						state = -1 ;
					}
					break;
			case 53:yytext[yyleng]='\0';
					token = LCURLY_TOK ;
					state = -1 ;
					break;
			case 54:yytext[yyleng]='\0';
					token = RCURLY_TOK ;
					state = -1 ;
					break;
			case -1:yyleng=yyleng;
					return token;
				break;
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