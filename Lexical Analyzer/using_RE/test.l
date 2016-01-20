%{
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
	#define HASH_TOK '#'
	#define COM_TOK ','
	#define SQ_TOK '\''
	#define DQ_TOK '\"'
	#define BS_TOK '\\'
	#define LSB_TOK '['
	#define RSB_TOK ']'

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
	#define EOF_TOKEN 450

	#define WHILE_TOK 350
	#define IF_TOK 351
	#define ELSE_TOK 352
	#define FOR_TOK 353
	#define SWITCH_TOK 354
	#define CASE_TOK 355
	#define INT_TOK 356
	#define FLOAT_TOK 358
	#define CHAR_TOK 359
	#define ID_TOK 360
	#define INTCONST 361	
	#define MAIN_TOK 362
	#define BR_TOK 	363
	#define CON_TOK 364
	#define RET_TOK 365
	#define INC_TOK 366
	#define DEF_TOK 367
	#define DOT_TOK 368
	#define LONG_TOK 369
	#define SHORT_TOK 370
	#define DOUBLE_TOK 371
	#define UNSIGNED_TOK 372
	FILE *fp;
%}

%%

[ \t\n] {continue;}
(int) {return INT_TOK;}
(float) {return FLOAT_TOK;}
(%) {return MOD_TOK;}
(#)	{return HASH_TOK;}
(\')	{return SQ_TOK;}
(\")	{return DQ_TOK;}
(,)	{return COM_TOK;}
(\\) {return BS_TOK; }

(break)	{return BR_TOK;}
(continue)	{return CON_TOK;}	
(;)	{return SEMICOLON_TOK; }
(:)	{return COLON_TOK; }
(\.)	{return DOT_TOK;}
(return)	{return RET_TOK;}
(include)	{return INC_TOK;}
(define)	{return DEF_TOK;}
(char) {return CHAR_TOK ;}
(long)	{return LONG_TOK;}
(short)	{return SHORT_TOK ;}
(unsigned) {return UNSIGNED_TOK;}
(double) {return DOUBLE_TOK;}
(main)	{return MAIN_TOK ;}
(if)	{return IF_TOK ;}
(while) {return WHILE_TOK ;}
(for) {return FOR_TOK ; }
(else) {return ELSE_TOK ;}
(switch) {return SWITCH_TOK ;}
(case) {return CASE_TOK ;}
[0-9]+	{return INTCONST ;}
[a-zA-Z_][a-zA-Z0-9_]*	{return ID_TOK ;}
(!)	{return NOT_TOK;}
(==)	{return DEQ_TOK ;}
(=)	{return EQ_TOK ;}
(>=)	{return GE_TOK ;}
(>)	{return GT_TOK ;}
(<=)	{return LE_TOK ;}
(<)	{return LT_TOK ;}
(&&)	{return LAND_TOK ;}
(&)	{return BAND_TOK ;}
(\|\|)	{return BAND_TOK ;}
(\|)	{return BOR_TOK ;}
(\()	{return LPAREN_TOK;}
(\[)	{return LSB_TOK;}
(\])	{return RSB_TOK;}
(\))	{return RPAREN_TOK;}
(\{)	{return LCURLY_TOK;}
(\})	{return RCURLY_TOK;}
(\+=)	{return PE_TOK;}
(\+\+)	{return DPLUS_TOK;}
(\+)	{return PLUS_TOK;}
(\*=)	{return MULE_TOK;}
(\*)	{return MUL_TOK;}
(-=)	{return ME_TOK;}
(--)	{return DMINUS_TOK;}
(-)	{return MINUS_TOK;}
(\/=)	{return DE_TOK;}
(\/)	{return DIV_TOK;}




.	{printf("UNIDENTIFIED CHARACTER:"); ECHO ; printf("\n");}

%%

int main(int argc, char *argv[]) {
	int token;
	if(argc != 2)
	{
		fprintf(stderr,"Usage %s <inputfilename>\n",argv[0]);
		exit(1);
	} 
	else
	{
		fp=fopen(argv[1],"r");
		yyin=fp;
		while(fp != 0)
		{
			if((token=yylex()) != 0)
				printf("%d %s\n",token,yytext);
			else
				break;
		}
		fclose(fp);
	}
}

int yywrap() {

}
