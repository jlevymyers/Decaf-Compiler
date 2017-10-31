%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int yylex();
int yyparse();
extern int yylineno;

void yyerror(char const *str){
	fprintf(stderr, "error: %s, line: %d", str, yylineno);
}

int yywrap(){
	return 1;
}

int main(void){
	yyparse();
}

%}

%union {
	int intval;
	char charval;
	char *strval;
}

%define parse.error verbose

%token  <strval> IDENTIFIER 
%token  <strval> FORBIDDEN 
%token 	<strval> RESERVED 
%token 	<strval> FPRIMATIVE

	/* literal types */
%token NUL TRUE FALSE
%token <intval> INTLITERAL 
%token <charval>  CHARLITERAL 
%token <strval> STRLITERAL

	/* primative types */
%token INTTYPE CHARTYPE BOOLTYPE VOIDTYPE

	/* keywords */
%token BREAK IF ELSE CLASS CONTINUE EXTENDS NEW PRIVATE PROTECTED PUBLIC RETURN STATIC SUPER THIS WHILE 

	/* operators */
%precedence NOT
%left MULT DIV MOD
%left ADD SUB
%left GR LE GEQ LEQ /* check specs */
%left EQ NEQ AND OR 
%right ASGN

%start start
%%

start:		class 
		|start class 
		;

class:		CLASS IDENTIFIER super '{' memberList '}'
		;

super:		%empty
     		|EXTENDS IDENTIFIER
		;

memberList:	%empty
		| memberList member
		;

member: 	modifierList type fieldOrMethod
		|modifierList ctor
		;

fieldOrMethod:	field
	   	|method
		;

field:		varDeclList ';'
     		;

method:		IDENTIFIER formalArgs block
		;

ctor:		IDENTIFIER formalArgs block
		;

modifierList:	%empty
		|modifierList modifier
		;

modifier:	STATIC
		|PUBLIC
		|PRIVATE
		|PROTECTED
		;

formalArgs:	'(' formalArgsList ')'
	  	|'(' ')'
	  	;

formalArgsList:	formalArg
	      	|formalArg ',' formalArgsList
		;

formalArg: 	type varDeclId
	 	;

	/* to get rid of shift/redice conflict -- ask spr */

type:		primativeType	
    		|IDENTIFIER
		|primativeType brackets  
    		|IDENTIFIER brackets 
		;

	/* why does right recusion fix shift/reduce */

brackets:	'[' ']'
		|brackets  '[' ']' 
		;

primativeType: 	BOOLTYPE
	     	|CHARTYPE
		|INTTYPE
		|VOIDTYPE
		;

varDeclList:	varDecl ',' varDeclList
	   	|varDecl
		;

varDecl: 	varDeclId 
       		|varDeclId EQ expression

varDeclId: 	IDENTIFIER
		|varDeclId '[' ']'
		;

block:		'{' statementList '}'
     		;

statementList: 	%empty
	     	|statementList statement
		;

statement: 	';'
	 	|type varDeclList ';'
		|IF '(' expression ')' statement
		|IF '(' expression ')' stmtNoIf ELSE statement
		|expression ';'
		|WHILE '(' expression ')' statement
		|RETURN returnStuff ';'
		|CONTINUE ';'
		|BREAK ';'
		|SUPER actualArgs ';'
		|block 
		;

stmtNoIf: 	';'
	 	|type varDeclList ';'
		|expression ';'
		|WHILE '(' expression ')' stmtNoIf
		|RETURN returnStuff ';'
		|CONTINUE ';'
		|BREAK ';'
		|SUPER actualArgs ';'
		|block 
		;

returnStuff: 	%empty	
	   	|expression
		;

expression:	unaryOp
  		|expression binaryOp
		|primary
		;

binaryOp:	ASGN expression
		|OR expression
		|AND expression
		|EQ expression
		|NEQ expression
		|GR expression
		|LE expression
		|GEQ expression 
		|LEQ expression
		|ADD expression 
		|SUB expression 
		|MULT expression 
		|DIV expression
		|MOD expression
		;

unaryOp: 	ADD expression 
       		|SUB expression 
		|NOT expression 
		;

primary: 	newArrExpr
       		|nonNewArrExpr
		|IDENTIFIER
		;

newArrExpr: 	NEW IDENTIFIER dimensionPlus
	 	|NEW primativeType dimensionPlus
		;

dimensionPlus:	dimension
	     	|dimensionPlus dimension
		;

dimension:	'[' expression ']'
		;

nonNewArrExpr:	literal
	     	|THIS
		|'(' expression ')'
		|NEW IDENTIFIER actualArgs
		|IDENTIFIER actualArgs
		|primary '.' IDENTIFIER actualArgs
		|SUPER '.' IDENTIFIER actualArgs
		|arrExpr
		|fieldExpr
		;

fieldExpr: 	primary '.' IDENTIFIER
	 	|SUPER '.' IDENTIFIER
		;

arrExpr:	IDENTIFIER dimension
       		|nonNewArrExpr dimension
		;

literal: 	NUL
       		|TRUE
		|FALSE
		|INTLITERAL
		|CHARLITERAL
		|STRLITERAL
		;

actualArgs:	'(' exprListQ ')'
	  	;

exprListQ: 	%empty
	    	|exprList
		;

exprList:	 expression 
		|expression ',' exprList
		;
		


	 		

