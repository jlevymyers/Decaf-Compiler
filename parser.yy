%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0.4"
%defines
%define parser_class_name {calcxx_parser}
%define api.token.constructor
%define api.value.type variant
%define parse.assert
%code requires
{
# include <string>
# include <utility>
# include <list>
# include "ast.hh"
# include "ast_node.hh"
# include "visitor.hh"
# include "print_visitor.hh"
class calcxx_driver;
}
// The parsing context.
%param { calcxx_driver& driver }
%locations
%initial-action
{
  // Initialize the initial location.
  @$.begin.filename = @$.end.filename = &driver.file;
};
%define parse.trace
%define parse.error verbose
%code
{
# include "driver.hh"

}
%define api.token.prefix {TOK_}
%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%token END 0 "end of file"

%token  <std::string> FORBIDDEN 
%token 	<std::string> RESERVED 
%token 	<std::string> FPRIMATIVE

	/* literal types */
%token 
  NUL "null" 
  TRUE "true"
  FALSE "false"
%token <int> INTLITERAL 
%token <char>  CHARLITERAL 
%token <std::string> STRLITERAL

	/* primative types */
%token	INTTYPE 
	CHARTYPE 
	BOOLTYPE 
	VOIDTYPE
;
	/* keywords */
%token	BREAK "break" 
	IF  "if"
	ELSE "else"
	CLASS "class"
	CONTINUE "continue"
	EXTENDS "extends"
	NEW "new"
	PRIVATE "private"
	PROTECTED "protected" 
	PUBLIC "public"
	RETURN "return"
	STATIC "static"
	SUPER "super"
	THIS "this"
	WHILE "while"
;

%token
  LPAREN "("
  RPAREN ")"
  LBRACKET "{"
  RBRACKET "}"
  LSQUARE "["
  RSQUARE "]" 
  SEMICOLON ";"
  COMMA ","
  PERIOD "." 
;

	/* operators */
%precedence NOT
%left MULT DIV MOD
%left ADD SUB
%left GR LE GEQ LEQ /* check specs */
%left EQ NEQ AND OR 
%right ASGN

%type <int> unit
%type <ast::class_list*> start
%type <ast::class_node*> class 
%type <ast::super_node*> super
%type <ast::member_list*> memberList
%type <ast::ast_node*> member
%type <int> modifierList
%type <int> modifier
%type <ast::formal_list*> formalArgs
%type <ast::formal_list*> formalArgsList
%type <ast::formal_node*> formalArg
%type <ast::type_node*> type
%type <int> brackets
%type <ast::type_node*> primativeType
%type <ast::field_decl*> fieldDeclList
%type <ast::field_node*> fieldDecl 
%type <ast::field_node*> fieldDeclId 
%type <ast::decl_stat*> localDeclList
%type <ast::local_node*> localDecl 
%type <ast::local_node*> localDeclId 
%type <ast::statement_list*> block
%type <ast::statement_list*> statementList
%type <ast::statement*> statement
%type <ast::statement*> stmtNoIf
%type <ast::expression*> expression
%type <ast::op_exp*> binaryOp
%type <ast::op_exp*> unaryOp
%type <ast::expression*> primary
%type <ast::new_array_exp*> newArrExpr
%type <std::list<ast::expression*>*> dimensionPlus
%type <ast::expression*> dimension
%type <ast::expression*> nonNewArrExpr
%type <ast::array_ref*> arrExpr
%type <ast::expression*> fieldExpr
%type <ast::literal*> literal
%type <ast::expression_list*> actualArgs
%type <ast::expression_list*> exprList

	/* %printer { yyoutput << $$ ; } <*>; */
%%
%start unit;

unit: start {	
		driver.result = $1;
     	$$ = 0;
		};

start:	class { 
			$$ = new ast::class_list($1);}
		|start class {
			$$ = $1;
			$1 -> add_child($2);
		}
		;

class:	CLASS IDENTIFIER super "{" memberList "}" {
     		$$ = new ast::class_node($2, $3, $5);
		}
		;

super:	%empty {$$ = new ast::super_node(new class_type("Object"));} //should be object  
     	|EXTENDS IDENTIFIER {$$ = new ast::super_node(new class_type($2)); }
		;

memberList:	
		%empty {
			$$ = new ast::member_list();
			}
		| memberList member {
			$$ = $1;
			$1 -> add_child($2);
		}
		;

member: 	
		modifierList type fieldDeclList {
			$$ = $3;
			((field_decl*) $$) -> set_type($2);
			((field_decl* )$$) -> set_modifiers($1);
		}
      	|modifierList type IDENTIFIER formalArgs block {$$ = new ast::method_node($1, $3, $2,  new ast::method_body($4, $5));}
		|modifierList IDENTIFIER formalArgs block /* CONSTRUCTOR */
			{$$ = new ast::constructor_node($1, $2, new ast::method_body($3, $4));}
		;

modifierList:	
		%empty {$$ = ast::MOD_NONE;}
		|modifierList modifier 
			{$$ = $$ | $2;}
		;

modifier:	
		STATIC {$$ = ast::MOD_STATIC;}
		|PUBLIC {$$ = ast::MOD_PUBLIC;}
		|PRIVATE {$$ = ast::MOD_PRIVATE;}
		|PROTECTED {$$ = ast::MOD_PROTECTED;}
		;

formalArgs:	
		"(" formalArgsList ")" {$$ = $2;}
	  	|"(" ")" {$$ = new ast::formal_list();}
	  	;

formalArgsList:	
		formalArg {$$ = new ast::formal_list();}
	    |formalArg "," formalArgsList {
			$$ = $3; 
			$$ -> add_child($1);}
		;

formalArg: 	
		/* NOTE: Not pdf syntax */
		type IDENTIFIER {
			$$ = new ast::formal_node($1, $2);
		};

type:	
		primativeType {$$ = $1;}
    	|IDENTIFIER {$$ = new ast::class_type($1);}
		|primativeType brackets {$$ = new ast::array_type_node($1);} 
    	|IDENTIFIER brackets {$$ = new ast::array_type_node(new type_node($1));}
		;

brackets:	"[" "]" {$$ = 1;}
		|brackets  "[" "]" {$$ = $1 + 1;}
		;

primativeType: 	
		BOOLTYPE {$$ = new ast::primative_bool();}
	    |CHARTYPE {$$ = new ast::primative_char();}
		|INTTYPE {$$ = new ast::primative_int();}
		|VOIDTYPE {$$ = new ast::primative_void();}
		;

fieldDeclList:	
		fieldDecl "," fieldDeclList {
			$$ = $3; 
			$$ -> add_child($1);
			}
	   	|fieldDecl {
			$$ = new field_decl();
			$$ -> add_child($1);
			}
		;

fieldDecl: 	
		fieldDeclId {$$ = $1;} 
       	|fieldDeclId ASGN expression {
			$$ = $1;
			$$ -> add_child($3);	
			}
		;

fieldDeclId: 	
		IDENTIFIER brackets {
			$$ = new ast::field_node($1, $2);}
		| IDENTIFIER {
			$$ = new ast::field_node($1, 0);}

localDeclList:
		localDecl "," localDeclList {
			$$ = $3;
			$$ -> add_child($1);}
	   	|localDecl {
			$$ = new ast::decl_stat();
			$$ -> add_child($1);
			}
		;

localDecl: 	
		localDeclId {$$ = $1;} 
       	|localDeclId ASGN expression {
			$$ = $1;
			$$ -> add_child($3);
			}
		;

localDeclId: 	
		IDENTIFIER {$$ = new ast::local_node($1, 0);}
		|IDENTIFIER brackets {
			$$ = new ast::local_node($1, $2);
			}
		;

block:		
		"{" statementList "}" 
		{$$ = $2;}
     	;

statementList: 	
		%empty {
			$$ = new ast::statement_list();
		}
	    |statementList statement {
			$$ = $1; 
			$$ -> add_child($2);}
		;

statement: 	
		";" 
	 		{$$ = new ast::empty_stat();}
	 	|type localDeclList ";" {
			$$ = $2;
			$$ -> insert_child($1);
			}
		|IF "(" expression ")" statement 
			{$$ = new ast::if_stat($3, $5);}
		|IF "(" expression ")" stmtNoIf ELSE statement
			{$$ = new ast::if_stat($3, $5, $7);}
		|expression ";" 
			{$$ = new ast::expression_stat($1);}
		|WHILE "(" expression ")" statement 
			{$$ = new ast::while_stat($3, $5);}
		|RETURN ";"
			{$$ = new ast::return_stat();}
		|RETURN expression ";"
			{$$ = new ast::return_stat($2);}
		|CONTINUE ";"
			{$$ = new ast::continue_stat();}
		|BREAK ";"
			{$$ = new ast::break_stat();}
		|SUPER actualArgs ";"
			{$$ = new ast::super_stat(new call_exp(new name_exp("<init>"), $2));} 
		|block 
			{$$ = new ast::block_stat($1);}	
		;

stmtNoIf: 	
		";"
	 		{$$ = new ast::empty_stat();}
	 	|type localDeclList ";"
			{$$ = $2;
			$$ -> insert_child($1);
			}
		|expression ";" 
			{$$ = new ast::expression_stat($1);}
		|WHILE "(" expression ")" stmtNoIf 
			{$$ = new ast::while_stat($3, $5);}
		|RETURN ";"
			{$$ = new ast::return_stat();}
		|RETURN expression ";"
			{$$ = new ast::return_stat($2);}
		|CONTINUE ";"
			{$$ = new ast::continue_stat();}
		|BREAK ";"
			{$$ = new ast::break_stat();}
		|SUPER actualArgs ";"
			{$$ = new ast::super_stat(new call_exp(new name_exp("<init>"), $2));} 
		|block 
			{$$ = new ast::block_stat($1);}	
		;

expression:	
		unaryOp {$$ = $1;}
  		|binaryOp {$$ = $1;}
		|primary {$$ = $1;}
		;

binaryOp:	
		expression ASGN expression
			{$$ = new ast::op_exp($1, $3);}
		|expression OR expression
			{$$ = new ast::op_exp($1, $3);}
		|expression AND expression
			{$$ = new ast::op_exp($1, $3);}
		|expression EQ expression
			{$$ = new ast::op_exp($1, $3);}
		|expression NEQ expression
			{$$ = new ast::op_exp($1, $3);}
		|expression GR expression
			{$$ = new ast::op_exp($1, $3);}
		|expression LE expression
			{$$ = new ast::op_exp($1, $3);}
		|expression GEQ expression 
			{$$ = new ast::op_exp($1, $3);}
		|expression LEQ expression
			{$$ = new ast::op_exp($1, $3);}
		|expression ADD expression 
			{$$ = new ast::op_exp($1, $3);}
		|expression SUB expression 
			{$$ = new ast::op_exp($1, $3);}
		|expression MULT expression 
			{$$ = new ast::op_exp($1, $3);}
		|expression DIV expression
			{$$ = new ast::op_exp($1, $3);}
		|expression MOD expression
			{$$ = new ast::op_exp($1, $3);}
		;

unaryOp: 	
		ADD expression
			{$$ = new ast::op_exp($2);} 
       	|SUB expression 
			{$$ = new ast::op_exp($2);}
		|NOT expression
			{$$ = new ast::op_exp($2);} 
		;

primary: 	
		newArrExpr {$$ = $1;}
       	|nonNewArrExpr {$$ = $1;}
		|IDENTIFIER {$$ = new ast::name_exp($1);}
		;

newArrExpr: 	
		NEW IDENTIFIER dimensionPlus 
			{$$ = new ast::new_array_exp(new ast::type_node($2));
			std::list<ast::expression*>::iterator iter; 
			for(iter = $3 -> begin(); iter != $3 -> end(); iter++){
				$$ -> add_child(*iter);
			} 
		}
	 	|NEW primativeType dimensionPlus {
			$$ = new ast::new_array_exp($2);
			std::list<ast::expression*>::iterator iter; 
			for(iter = $3 -> begin(); iter != $3 -> end(); iter++){
				$$ -> add_child(*iter);
			}  
		}
		;

dimensionPlus:	
		dimension {
			$$ = new std::list<ast::expression*>();
			$$ -> push_back($1);}
	    |dimensionPlus dimension {
			 $$ = $1;
			 $$ -> push_back($2);}
		;

dimension:	"[" expression "]" {$$ = $2;}
		;

nonNewArrExpr:	
		literal {$$ = $1;}
	    |THIS {$$ = new ast::name_exp("this");}
		|"(" expression ")" {$$ = $2;}
		|NEW IDENTIFIER actualArgs {			
			$$ = new ast::call_exp(new ast::name_exp($2), $3);
		}
		|IDENTIFIER actualArgs {$$ = new ast::call_exp(new ast::name_exp($1), $2);}
		|primary "." IDENTIFIER actualArgs {$$ = new ast::call_exp(new ast::name_exp($3) , $4);}
		|SUPER "." IDENTIFIER actualArgs {$$ = new ast::call_exp(new ast::name_exp($3), $4);}
		|arrExpr {$$ = $1;}
		|fieldExpr {$$ = $1;}
		;

fieldExpr: 	
		primary "." IDENTIFIER {
			$1;
			$$ = new ast::name_exp($3);}
	 	|SUPER "." IDENTIFIER {$$ = new ast::name_exp($3);}
		;

arrExpr:	IDENTIFIER dimension {$$ = new ast::array_ref(new ast::name_exp($1), $2);}
       		|nonNewArrExpr dimension {$$ = new ast::array_ref($1, $2);}
		;

literal: 
		NUL {$$ = new ast::null_literal();}
       	|TRUE {$$ = new ast::bool_literal(true);}
		|FALSE {$$ = new ast::bool_literal(false);}
		|INTLITERAL {$$ = new ast::int_literal($1);}
		|CHARLITERAL {$$ = new ast::char_literal($1);}
		|STRLITERAL {$$ = new ast::string_literal($1);}
		;

actualArgs: 
		"(" ")" {$$ = new ast::expression_list();}
	    |"(" exprList ")" {$$ = $2;}
		;

exprList:	
		expression {
			$$ = new ast::expression_list();
			$$ -> add_child($1);}
		|expression "," exprList {
			$$ = $3; 
			$$ -> add_child($1);
			}
		;
%%
void
yy::calcxx_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
