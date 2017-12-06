%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <string>
# include "driver.hh"
# include "parser.hh"
# include "visitor.hh"
# include "print_visitor.hh"

// Work around an incompatibility in flex (at least versions
// 2.5.31 through 2.5.33): it generates code that does
// not conform to C89.  See Debian bug 333231
// <http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=333231>.
# undef yywrap
# define yywrap() 1

// The location of the current token.
static yy::location loc;
%}

	/* rules for comments */ 
%x blockComment inlineComment string

FORBIDDEN abstract|byte|case|catch|const|default|do|double|final|finally|for|implements|import|instanceof|interface|long|native|goto|package|short|switch|synchronized|throw|throws|transient|try|volatile

RESERVED byvalue|cast|future|generic|inner|none|operator|outer|rest|var

FPRIMATIVE byte|double|float|long|short

blank [ \t]
identifier ([a-zA-Z]|_)+([a-zA-Z0-9]|_)* 
intliteral (0|([1-9]+[0-9]*)) 
basicchar '[^\']' 
wildchar '\\[^nt]' 

%option noyywrap nounput batch debug noinput

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}

%%

%{
  // Code run each time yylex is called.
  loc.step ();
%}

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
	return yy::calcxx_parser::make_STRLITERAL(yytext, loc);
}

	/* literals */
"true" { return yy::calcxx_parser::make_TRUE(loc);}
"false" { return yy::calcxx_parser::make_FALSE(loc);}
"null" { return yy::calcxx_parser::make_NUL(loc);}

	/* keywords */
"break" 	{ return yy::calcxx_parser::make_BREAK(loc);}
"class" { return yy::calcxx_parser::make_CLASS(loc);}
"else" { return yy::calcxx_parser::make_ELSE(loc);}
"extends" { return yy::calcxx_parser::make_EXTENDS(loc);}
"if" { return yy::calcxx_parser::make_IF(loc);}
"new" { return yy::calcxx_parser::make_NEW(loc);}
"private" {return yy::calcxx_parser::make_PRIVATE(loc);}
"protected" {return yy::calcxx_parser::make_PROTECTED(loc);}
"public" {return yy::calcxx_parser::make_PUBLIC(loc);}
"return" {return yy::calcxx_parser::make_RETURN(loc);}
"static" {return yy::calcxx_parser::make_STATIC(loc);}
"super" {return yy::calcxx_parser::make_SUPER(loc);}
"this" {return yy::calcxx_parser::make_THIS(loc);}
"while" {return yy::calcxx_parser::make_WHILE(loc);}

	/* primatives */
"void" {return yy::calcxx_parser::make_VOIDTYPE(loc);}
"char" {return yy::calcxx_parser::make_CHARTYPE(loc);}
"int" {return yy::calcxx_parser::make_INTTYPE(loc);}
"boolean" {return yy::calcxx_parser::make_BOOLTYPE(loc);}


{FORBIDDEN} { return yy::calcxx_parser::make_FORBIDDEN(yytext, loc);}

{RESERVED} { return yy::calcxx_parser::make_RESERVED(yytext, loc);}

{FPRIMATIVE} {return yy::calcxx_parser::make_FPRIMATIVE(yytext, loc);}

"(" { return yy::calcxx_parser::make_LPAREN(loc);} 
")" { return yy::calcxx_parser::make_RPAREN(loc);} 
"{" {return yy::calcxx_parser::make_LBRACKET(loc);} 
"}" {return yy::calcxx_parser::make_RBRACKET(loc);} 
"[" {return yy::calcxx_parser::make_LSQUARE(loc);} 
"]" {return yy::calcxx_parser::make_RSQUARE(loc);} 
";" {return yy::calcxx_parser::make_SEMICOLON(loc);} 
"," {return yy::calcxx_parser::make_COMMA(loc);} 
"." {return yy::calcxx_parser::make_PERIOD(loc);} 

	/* operators */
"=" { return yy::calcxx_parser::make_ASGN(loc);}
">" { return yy::calcxx_parser::make_GR(loc);}
"<" { return yy::calcxx_parser::make_LE(loc);}
"!" { return yy::calcxx_parser::make_NOT(loc);}
"==" {return yy::calcxx_parser::make_EQ(loc);}
">=" {return yy::calcxx_parser::make_GEQ(loc);}
"<=" {return yy::calcxx_parser::make_LEQ(loc);}
"!=" {return yy::calcxx_parser::make_NEQ(loc);}
"+" {return yy::calcxx_parser::make_ADD(loc);}
"-" {return yy::calcxx_parser::make_SUB(loc);}
"*" {return yy::calcxx_parser::make_MULT(loc);}
"/" {return yy::calcxx_parser::make_DIV(loc);}
"&&" {return yy::calcxx_parser::make_AND(loc);}
"||" {return yy::calcxx_parser::make_OR(loc);}
"%" {return yy::calcxx_parser::make_MOD(loc);}

{blank}+   loc.step ();
[\n]+      loc.lines (yyleng); loc.step ();

{intliteral} return yy::calcxx_parser::make_INTLITERAL(atoi(yytext), loc);
 
{identifier} return yy::calcxx_parser::make_IDENTIFIER(yytext, loc);

{basicchar} return yy::calcxx_parser::make_CHARLITERAL(*yytext, loc);

{wildchar} return yy::calcxx_parser::make_CHARLITERAL(yytext[1], loc);

'\\t'  {return yy::calcxx_parser::make_CHARLITERAL('\t', loc);}
'\\n' {return yy::calcxx_parser::make_CHARLITERAL('\n' ,loc);}
<<EOF>> {return yy::calcxx_parser::make_END(loc);}

%%

void
calcxx_driver::scan_begin ()
{
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      error ("cannot open " + file + ": " + strerror(errno));
      exit (EXIT_FAILURE);
    }
}



void
calcxx_driver::scan_end ()
{
  fclose (yyin);
}

