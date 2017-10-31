%x blockComment inlineComment string


FORBIDDEN abstract|byte|case|catch|const|default|do|double|final|finally|for|implements|import|instanceof|interface|long|native|goto|package|short|switch|synchronized|throw|throws|transient|try|volatile

RESERVED byvalue|cast|future|generic|inner|none|operator|outer|rest|var

PRIMATIVE boolean|char|int|void

FPRIMATIVE byte|double|float|long|short

OPERATOR "="|">"|"<"|"!"|"=="|">="|"<="|"!="|"+"|"-"|"*"|"/"|"&&"|"||"|"%" 

PUNCTUATION "("|")"|"{"|"}"|"["|"]"|";"|","|"."

%{
#include "../parser/parser.tab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void yyerror(char *);
%}

%option yylineno

%%


	/* block  comments */
"/*" BEGIN(blockComment);
<blockComment>. {}
<blockComment>"*/" {BEGIN(0); }

	/* inline comments */ 
"//" BEGIN(inlineComment);
<inlineComment>"\n" {BEGIN(0); }
<inlineComment>. {}

	/* string literals */
"\"" BEGIN(string);
<string>[^\"] {}
<string>"\\\"" {}
<string>"\"" {
	BEGIN(0);
	yylval.strval = strdup(yytext);
	return STRLITERAL;
}

	/* literals */
true { return TRUE;}
false { return FALSE;}
null { return NUL;}

	/* keywords */
break { return BREAK;}
class {	return CLASS;}
else { return ELSE;}
extends { return EXTENDS;}
if { return IF;}
new { return NEW;}
private {return PRIVATE;}
protected {return PROTECTED;}
public {return PUBLIC;}
return {return RETURN;}
static {return STATIC;}
super {return SUPER;}
this {return THIS;}
while {return WHILE;}


	/* primatives */
void {return VOIDTYPE;}
char {return CHARTYPE;}
int {return INTTYPE;}
boolean {return BOOLTYPE;}


{FORBIDDEN} {
	yylval.strval = strdup(yytext);
	return FORBIDDEN;
	}

{RESERVED} {
	yylval.strval = strdup(yytext);
	return RESERVED;
	}

{FPRIMATIVE} {
	yylval.strval = strdup(yytext); 
	return FPRIMATIVE;
	}

{PUNCTUATION} {
	return *yytext;
}

	/* operators */
"=" { return EQ;}
">" { return GR;}
"<" { return LE;}
"!" { return NOT;}
"==" {return EQ;}
">=" {return GEQ;}
"<=" {return LEQ;}
"!=" {return NEQ;}
"+" {return ADD;}
"-" {return SUB;}
"*" {return MULT;}
"/" {return DIV;}
"&&" {return AND;}
"||" {return OR;}
"%" {return MOD;}


(0|([1-9]+[0-9]*)) {
	yylval.intval = atoi(yytext);
	return INTLITERAL;
	}

([a-zA-Z]|_)+([a-zA-Z0-9]|_)* {
	yylval.strval = strdup(yytext);
	return IDENTIFIER;
	}

'[^\']' {
	yylval.charval = *yytext;
	return CHARLITERAL;
	}

'\\[^nt]' {
	yylval.charval = yytext[1];
	return CHARLITERAL;
	}

'\\t'  {
	yylval.charval = '\t';
	return CHARLITERAL;
	}
'\\n' {
	yylval.charval = '\n';
	return CHARLITERAL;
	}

yyerror("Unknown token");

%%

