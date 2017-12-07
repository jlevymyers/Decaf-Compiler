// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "parser.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.hh"

// User implementation prologue.

#line 51 "parser.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 30 "parser.yy" // lalr1.cc:413

# include "driver.hh"


#line 58 "parser.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 144 "parser.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  calcxx_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  calcxx_parser::calcxx_parser (calcxx_driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  calcxx_parser::~calcxx_parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  calcxx_parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  calcxx_parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  calcxx_parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  calcxx_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  calcxx_parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  calcxx_parser::symbol_number_type
  calcxx_parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  calcxx_parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  calcxx_parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 91: // arrExpr
        value.move< ast::array_ref* > (that.value);
        break;

      case 63: // member
        value.move< ast::ast_node* > (that.value);
        break;

      case 59: // start
        value.move< ast::class_list* > (that.value);
        break;

      case 60: // class
        value.move< ast::class_node* > (that.value);
        break;

      case 75: // localDeclList
        value.move< ast::decl_stat* > (that.value);
        break;

      case 82: // expression
      case 85: // primary
      case 88: // dimension
      case 89: // nonNewArrExpr
      case 90: // fieldExpr
        value.move< ast::expression* > (that.value);
        break;

      case 93: // actualArgs
      case 94: // exprList
        value.move< ast::expression_list* > (that.value);
        break;

      case 72: // fieldDeclList
        value.move< ast::field_decl* > (that.value);
        break;

      case 73: // fieldDecl
      case 74: // fieldDeclId
        value.move< ast::field_node* > (that.value);
        break;

      case 66: // formalArgs
      case 67: // formalArgsList
        value.move< ast::formal_list* > (that.value);
        break;

      case 68: // formalArg
        value.move< ast::formal_node* > (that.value);
        break;

      case 92: // literal
        value.move< ast::literal* > (that.value);
        break;

      case 76: // localDecl
      case 77: // localDeclId
        value.move< ast::local_node* > (that.value);
        break;

      case 62: // memberList
        value.move< ast::member_list* > (that.value);
        break;

      case 86: // newArrExpr
        value.move< ast::new_array_exp* > (that.value);
        break;

      case 83: // binaryOp
      case 84: // unaryOp
        value.move< ast::op_exp* > (that.value);
        break;

      case 80: // statement
      case 81: // stmtNoIf
        value.move< ast::statement* > (that.value);
        break;

      case 78: // block
      case 79: // statementList
        value.move< ast::statement_list* > (that.value);
        break;

      case 61: // super
        value.move< ast::super_node* > (that.value);
        break;

      case 69: // type
      case 71: // primativeType
        value.move< ast::type_node* > (that.value);
        break;

      case 12: // CHARLITERAL
        value.move< char > (that.value);
        break;

      case 4: // "number"
      case 11: // INTLITERAL
      case 58: // unit
      case 64: // modifierList
      case 65: // modifier
      case 70: // brackets
        value.move< int > (that.value);
        break;

      case 87: // dimensionPlus
        value.move< std::list<ast::expression*>* > (that.value);
        break;

      case 3: // "identifier"
      case 5: // FORBIDDEN
      case 6: // RESERVED
      case 7: // FPRIMATIVE
      case 13: // STRLITERAL
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  calcxx_parser::stack_symbol_type&
  calcxx_parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 91: // arrExpr
        value.copy< ast::array_ref* > (that.value);
        break;

      case 63: // member
        value.copy< ast::ast_node* > (that.value);
        break;

      case 59: // start
        value.copy< ast::class_list* > (that.value);
        break;

      case 60: // class
        value.copy< ast::class_node* > (that.value);
        break;

      case 75: // localDeclList
        value.copy< ast::decl_stat* > (that.value);
        break;

      case 82: // expression
      case 85: // primary
      case 88: // dimension
      case 89: // nonNewArrExpr
      case 90: // fieldExpr
        value.copy< ast::expression* > (that.value);
        break;

      case 93: // actualArgs
      case 94: // exprList
        value.copy< ast::expression_list* > (that.value);
        break;

      case 72: // fieldDeclList
        value.copy< ast::field_decl* > (that.value);
        break;

      case 73: // fieldDecl
      case 74: // fieldDeclId
        value.copy< ast::field_node* > (that.value);
        break;

      case 66: // formalArgs
      case 67: // formalArgsList
        value.copy< ast::formal_list* > (that.value);
        break;

      case 68: // formalArg
        value.copy< ast::formal_node* > (that.value);
        break;

      case 92: // literal
        value.copy< ast::literal* > (that.value);
        break;

      case 76: // localDecl
      case 77: // localDeclId
        value.copy< ast::local_node* > (that.value);
        break;

      case 62: // memberList
        value.copy< ast::member_list* > (that.value);
        break;

      case 86: // newArrExpr
        value.copy< ast::new_array_exp* > (that.value);
        break;

      case 83: // binaryOp
      case 84: // unaryOp
        value.copy< ast::op_exp* > (that.value);
        break;

      case 80: // statement
      case 81: // stmtNoIf
        value.copy< ast::statement* > (that.value);
        break;

      case 78: // block
      case 79: // statementList
        value.copy< ast::statement_list* > (that.value);
        break;

      case 61: // super
        value.copy< ast::super_node* > (that.value);
        break;

      case 69: // type
      case 71: // primativeType
        value.copy< ast::type_node* > (that.value);
        break;

      case 12: // CHARLITERAL
        value.copy< char > (that.value);
        break;

      case 4: // "number"
      case 11: // INTLITERAL
      case 58: // unit
      case 64: // modifierList
      case 65: // modifier
      case 70: // brackets
        value.copy< int > (that.value);
        break;

      case 87: // dimensionPlus
        value.copy< std::list<ast::expression*>* > (that.value);
        break;

      case 3: // "identifier"
      case 5: // FORBIDDEN
      case 6: // RESERVED
      case 7: // FPRIMATIVE
      case 13: // STRLITERAL
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  calcxx_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  calcxx_parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  calcxx_parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  calcxx_parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  calcxx_parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  calcxx_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  calcxx_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  calcxx_parser::debug_level_type
  calcxx_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  calcxx_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline calcxx_parser::state_type
  calcxx_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  calcxx_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  calcxx_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  calcxx_parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 23 "parser.yy" // lalr1.cc:745
{
  // Initialize the initial location.
  yyla.location.begin.filename = yyla.location.end.filename = &driver.file;
}

#line 652 "parser.cc" // lalr1.cc:745

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 91: // arrExpr
        yylhs.value.build< ast::array_ref* > ();
        break;

      case 63: // member
        yylhs.value.build< ast::ast_node* > ();
        break;

      case 59: // start
        yylhs.value.build< ast::class_list* > ();
        break;

      case 60: // class
        yylhs.value.build< ast::class_node* > ();
        break;

      case 75: // localDeclList
        yylhs.value.build< ast::decl_stat* > ();
        break;

      case 82: // expression
      case 85: // primary
      case 88: // dimension
      case 89: // nonNewArrExpr
      case 90: // fieldExpr
        yylhs.value.build< ast::expression* > ();
        break;

      case 93: // actualArgs
      case 94: // exprList
        yylhs.value.build< ast::expression_list* > ();
        break;

      case 72: // fieldDeclList
        yylhs.value.build< ast::field_decl* > ();
        break;

      case 73: // fieldDecl
      case 74: // fieldDeclId
        yylhs.value.build< ast::field_node* > ();
        break;

      case 66: // formalArgs
      case 67: // formalArgsList
        yylhs.value.build< ast::formal_list* > ();
        break;

      case 68: // formalArg
        yylhs.value.build< ast::formal_node* > ();
        break;

      case 92: // literal
        yylhs.value.build< ast::literal* > ();
        break;

      case 76: // localDecl
      case 77: // localDeclId
        yylhs.value.build< ast::local_node* > ();
        break;

      case 62: // memberList
        yylhs.value.build< ast::member_list* > ();
        break;

      case 86: // newArrExpr
        yylhs.value.build< ast::new_array_exp* > ();
        break;

      case 83: // binaryOp
      case 84: // unaryOp
        yylhs.value.build< ast::op_exp* > ();
        break;

      case 80: // statement
      case 81: // stmtNoIf
        yylhs.value.build< ast::statement* > ();
        break;

      case 78: // block
      case 79: // statementList
        yylhs.value.build< ast::statement_list* > ();
        break;

      case 61: // super
        yylhs.value.build< ast::super_node* > ();
        break;

      case 69: // type
      case 71: // primativeType
        yylhs.value.build< ast::type_node* > ();
        break;

      case 12: // CHARLITERAL
        yylhs.value.build< char > ();
        break;

      case 4: // "number"
      case 11: // INTLITERAL
      case 58: // unit
      case 64: // modifierList
      case 65: // modifier
      case 70: // brackets
        yylhs.value.build< int > ();
        break;

      case 87: // dimensionPlus
        yylhs.value.build< std::list<ast::expression*>* > ();
        break;

      case 3: // "identifier"
      case 5: // FORBIDDEN
      case 6: // RESERVED
      case 7: // FPRIMATIVE
      case 13: // STRLITERAL
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 138 "parser.yy" // lalr1.cc:859
    {	
		driver.result = yystack_[0].value.as< ast::class_list* > ();
     	yylhs.value.as< int > () = 0;
		}
#line 882 "parser.cc" // lalr1.cc:859
    break;

  case 3:
#line 143 "parser.yy" // lalr1.cc:859
    { 
			yylhs.value.as< ast::class_list* > () = new ast::class_list(yystack_[0].value.as< ast::class_node* > ());}
#line 889 "parser.cc" // lalr1.cc:859
    break;

  case 4:
#line 145 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::class_list* > () = yystack_[1].value.as< ast::class_list* > ();
			yystack_[1].value.as< ast::class_list* > () -> add_child(yystack_[0].value.as< ast::class_node* > ());
		}
#line 898 "parser.cc" // lalr1.cc:859
    break;

  case 5:
#line 151 "parser.yy" // lalr1.cc:859
    {
     		yylhs.value.as< ast::class_node* > () = new ast::class_node(yystack_[4].value.as< std::string > (), yystack_[3].value.as< ast::super_node* > (), yystack_[1].value.as< ast::member_list* > ());
		}
#line 906 "parser.cc" // lalr1.cc:859
    break;

  case 6:
#line 156 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::super_node* > () = new ast::super_node(new class_type("Object"));}
#line 912 "parser.cc" // lalr1.cc:859
    break;

  case 7:
#line 157 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::super_node* > () = new ast::super_node(new class_type(yystack_[0].value.as< std::string > ())); }
#line 918 "parser.cc" // lalr1.cc:859
    break;

  case 8:
#line 161 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::member_list* > () = new ast::member_list();
			}
#line 926 "parser.cc" // lalr1.cc:859
    break;

  case 9:
#line 164 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::member_list* > () = yystack_[1].value.as< ast::member_list* > ();
			yystack_[1].value.as< ast::member_list* > () -> add_child(yystack_[0].value.as< ast::ast_node* > ());
		}
#line 935 "parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 171 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::ast_node* > () = yystack_[0].value.as< ast::field_decl* > ();
			((field_decl*) yylhs.value.as< ast::ast_node* > ()) -> set_type(yystack_[1].value.as< ast::type_node* > ());
			((field_decl* )yylhs.value.as< ast::ast_node* > ()) -> set_modifiers(yystack_[2].value.as< int > ());
		}
#line 945 "parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 176 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::ast_node* > () = new ast::method_node(yystack_[4].value.as< int > (), yystack_[2].value.as< std::string > (), yystack_[3].value.as< ast::type_node* > (),  new ast::method_body(yystack_[1].value.as< ast::formal_list* > (), yystack_[0].value.as< ast::statement_list* > ()));}
#line 951 "parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 178 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::ast_node* > () = new ast::constructor_node(yystack_[3].value.as< int > (), yystack_[2].value.as< std::string > (), new ast::method_body(yystack_[1].value.as< ast::formal_list* > (), yystack_[0].value.as< ast::statement_list* > ()));}
#line 957 "parser.cc" // lalr1.cc:859
    break;

  case 13:
#line 182 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< int > () = ast::MOD_NONE;}
#line 963 "parser.cc" // lalr1.cc:859
    break;

  case 14:
#line 184 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< int > () = yylhs.value.as< int > () | yystack_[0].value.as< int > ();}
#line 969 "parser.cc" // lalr1.cc:859
    break;

  case 15:
#line 188 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< int > () = ast::MOD_STATIC;}
#line 975 "parser.cc" // lalr1.cc:859
    break;

  case 16:
#line 189 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< int > () = ast::MOD_PUBLIC;}
#line 981 "parser.cc" // lalr1.cc:859
    break;

  case 17:
#line 190 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< int > () = ast::MOD_PRIVATE;}
#line 987 "parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 191 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< int > () = ast::MOD_PROTECTED;}
#line 993 "parser.cc" // lalr1.cc:859
    break;

  case 19:
#line 195 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::formal_list* > () = yystack_[1].value.as< ast::formal_list* > ();}
#line 999 "parser.cc" // lalr1.cc:859
    break;

  case 20:
#line 196 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::formal_list* > () = new ast::formal_list();}
#line 1005 "parser.cc" // lalr1.cc:859
    break;

  case 21:
#line 200 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::formal_list* > () = new ast::formal_list();}
#line 1011 "parser.cc" // lalr1.cc:859
    break;

  case 22:
#line 201 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::formal_list* > () = yystack_[0].value.as< ast::formal_list* > (); 
			yylhs.value.as< ast::formal_list* > () -> add_child(yystack_[2].value.as< ast::formal_node* > ());}
#line 1019 "parser.cc" // lalr1.cc:859
    break;

  case 23:
#line 208 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::formal_node* > () = new ast::formal_node(yystack_[1].value.as< ast::type_node* > (), yystack_[0].value.as< std::string > ());
		}
#line 1027 "parser.cc" // lalr1.cc:859
    break;

  case 24:
#line 213 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::type_node* > () = yystack_[0].value.as< ast::type_node* > ();}
#line 1033 "parser.cc" // lalr1.cc:859
    break;

  case 25:
#line 214 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::type_node* > () = new ast::class_type(yystack_[0].value.as< std::string > ());}
#line 1039 "parser.cc" // lalr1.cc:859
    break;

  case 26:
#line 215 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::type_node* > () = new ast::array_type_node(yystack_[1].value.as< ast::type_node* > ());}
#line 1045 "parser.cc" // lalr1.cc:859
    break;

  case 27:
#line 216 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::type_node* > () = new ast::array_type_node(new type_node(yystack_[1].value.as< std::string > ()));}
#line 1051 "parser.cc" // lalr1.cc:859
    break;

  case 28:
#line 219 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< int > () = 1;}
#line 1057 "parser.cc" // lalr1.cc:859
    break;

  case 29:
#line 220 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< int > () = yystack_[2].value.as< int > () + 1;}
#line 1063 "parser.cc" // lalr1.cc:859
    break;

  case 30:
#line 224 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::type_node* > () = new ast::primative_bool();}
#line 1069 "parser.cc" // lalr1.cc:859
    break;

  case 31:
#line 225 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::type_node* > () = new ast::primative_char();}
#line 1075 "parser.cc" // lalr1.cc:859
    break;

  case 32:
#line 226 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::type_node* > () = new ast::primative_int();}
#line 1081 "parser.cc" // lalr1.cc:859
    break;

  case 33:
#line 227 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::type_node* > () = new ast::primative_void();}
#line 1087 "parser.cc" // lalr1.cc:859
    break;

  case 34:
#line 231 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::field_decl* > () = yystack_[0].value.as< ast::field_decl* > (); 
			yylhs.value.as< ast::field_decl* > () -> add_child(yystack_[2].value.as< ast::field_node* > ());
			}
#line 1096 "parser.cc" // lalr1.cc:859
    break;

  case 35:
#line 235 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::field_decl* > () = new field_decl();
			yylhs.value.as< ast::field_decl* > () -> add_child(yystack_[0].value.as< ast::field_node* > ());
			}
#line 1105 "parser.cc" // lalr1.cc:859
    break;

  case 36:
#line 242 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::field_node* > () = yystack_[0].value.as< ast::field_node* > ();}
#line 1111 "parser.cc" // lalr1.cc:859
    break;

  case 37:
#line 243 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::field_node* > () = yystack_[2].value.as< ast::field_node* > ();
			yylhs.value.as< ast::field_node* > () -> add_child(yystack_[0].value.as< ast::expression* > ());	
			}
#line 1120 "parser.cc" // lalr1.cc:859
    break;

  case 38:
#line 250 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::field_node* > () = new ast::field_node(yystack_[1].value.as< std::string > (), yystack_[0].value.as< int > ());}
#line 1127 "parser.cc" // lalr1.cc:859
    break;

  case 39:
#line 252 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::field_node* > () = new ast::field_node(yystack_[0].value.as< std::string > (), 0);}
#line 1134 "parser.cc" // lalr1.cc:859
    break;

  case 40:
#line 256 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::decl_stat* > () = yystack_[0].value.as< ast::decl_stat* > ();
			yylhs.value.as< ast::decl_stat* > () -> add_child(yystack_[2].value.as< ast::local_node* > ());}
#line 1142 "parser.cc" // lalr1.cc:859
    break;

  case 41:
#line 259 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::decl_stat* > () = new ast::decl_stat();
			yylhs.value.as< ast::decl_stat* > () -> add_child(yystack_[0].value.as< ast::local_node* > ());
			}
#line 1151 "parser.cc" // lalr1.cc:859
    break;

  case 42:
#line 266 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::local_node* > () = yystack_[0].value.as< ast::local_node* > ();}
#line 1157 "parser.cc" // lalr1.cc:859
    break;

  case 43:
#line 267 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::local_node* > () = yystack_[2].value.as< ast::local_node* > ();
			yylhs.value.as< ast::local_node* > () -> add_child(yystack_[0].value.as< ast::expression* > ());
			}
#line 1166 "parser.cc" // lalr1.cc:859
    break;

  case 44:
#line 274 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::local_node* > () = new ast::local_node(yystack_[0].value.as< std::string > (), 0);}
#line 1172 "parser.cc" // lalr1.cc:859
    break;

  case 45:
#line 275 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::local_node* > () = new ast::local_node(yystack_[1].value.as< std::string > (), yystack_[0].value.as< int > ());
			}
#line 1180 "parser.cc" // lalr1.cc:859
    break;

  case 46:
#line 282 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement_list* > () = yystack_[1].value.as< ast::statement_list* > ();}
#line 1186 "parser.cc" // lalr1.cc:859
    break;

  case 47:
#line 286 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::statement_list* > () = new ast::statement_list();
		}
#line 1194 "parser.cc" // lalr1.cc:859
    break;

  case 48:
#line 289 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::statement_list* > () = yystack_[1].value.as< ast::statement_list* > (); 
			yylhs.value.as< ast::statement_list* > () -> add_child(yystack_[0].value.as< ast::statement* > ());}
#line 1202 "parser.cc" // lalr1.cc:859
    break;

  case 49:
#line 296 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = new ast::empty_stat();}
#line 1208 "parser.cc" // lalr1.cc:859
    break;

  case 50:
#line 297 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::statement* > () = yystack_[1].value.as< ast::decl_stat* > ();
			yylhs.value.as< ast::statement* > () -> insert_child(yystack_[2].value.as< ast::type_node* > ());
			}
#line 1217 "parser.cc" // lalr1.cc:859
    break;

  case 51:
#line 302 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = new ast::if_stat(yystack_[2].value.as< ast::expression* > (), yystack_[0].value.as< ast::statement* > ());}
#line 1223 "parser.cc" // lalr1.cc:859
    break;

  case 52:
#line 304 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = new ast::if_stat(yystack_[4].value.as< ast::expression* > (), yystack_[2].value.as< ast::statement* > (), yystack_[0].value.as< ast::statement* > ());}
#line 1229 "parser.cc" // lalr1.cc:859
    break;

  case 53:
#line 306 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = new ast::expression_stat(yystack_[1].value.as< ast::expression* > ());}
#line 1235 "parser.cc" // lalr1.cc:859
    break;

  case 54:
#line 308 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = new ast::while_stat(yystack_[2].value.as< ast::expression* > (), yystack_[0].value.as< ast::statement* > ());}
#line 1241 "parser.cc" // lalr1.cc:859
    break;

  case 55:
#line 310 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = new ast::return_stat();}
#line 1247 "parser.cc" // lalr1.cc:859
    break;

  case 56:
#line 312 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = new ast::return_stat(yystack_[1].value.as< ast::expression* > ());}
#line 1253 "parser.cc" // lalr1.cc:859
    break;

  case 57:
#line 314 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = new ast::continue_stat();}
#line 1259 "parser.cc" // lalr1.cc:859
    break;

  case 58:
#line 316 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = new ast::break_stat();}
#line 1265 "parser.cc" // lalr1.cc:859
    break;

  case 59:
#line 318 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = new ast::super_stat(new call_exp(new name_exp("<init>"), yystack_[1].value.as< ast::expression_list* > ()));}
#line 1271 "parser.cc" // lalr1.cc:859
    break;

  case 60:
#line 320 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = new ast::block_stat(yystack_[0].value.as< ast::statement_list* > ());}
#line 1277 "parser.cc" // lalr1.cc:859
    break;

  case 61:
#line 325 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = new ast::empty_stat();}
#line 1283 "parser.cc" // lalr1.cc:859
    break;

  case 62:
#line 327 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = yystack_[1].value.as< ast::decl_stat* > ();
			yylhs.value.as< ast::statement* > () -> insert_child(yystack_[2].value.as< ast::type_node* > ());
			}
#line 1291 "parser.cc" // lalr1.cc:859
    break;

  case 63:
#line 331 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = new ast::expression_stat(yystack_[1].value.as< ast::expression* > ());}
#line 1297 "parser.cc" // lalr1.cc:859
    break;

  case 64:
#line 333 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = new ast::while_stat(yystack_[2].value.as< ast::expression* > (), yystack_[0].value.as< ast::statement* > ());}
#line 1303 "parser.cc" // lalr1.cc:859
    break;

  case 65:
#line 335 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = new ast::return_stat();}
#line 1309 "parser.cc" // lalr1.cc:859
    break;

  case 66:
#line 337 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = new ast::return_stat(yystack_[1].value.as< ast::expression* > ());}
#line 1315 "parser.cc" // lalr1.cc:859
    break;

  case 67:
#line 339 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = new ast::continue_stat();}
#line 1321 "parser.cc" // lalr1.cc:859
    break;

  case 68:
#line 341 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = new ast::break_stat();}
#line 1327 "parser.cc" // lalr1.cc:859
    break;

  case 69:
#line 343 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = new ast::super_stat(new call_exp(new name_exp("<init>"), yystack_[1].value.as< ast::expression_list* > ()));}
#line 1333 "parser.cc" // lalr1.cc:859
    break;

  case 70:
#line 345 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::statement* > () = new ast::block_stat(yystack_[0].value.as< ast::statement_list* > ());}
#line 1339 "parser.cc" // lalr1.cc:859
    break;

  case 71:
#line 349 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::expression* > () = yystack_[0].value.as< ast::op_exp* > ();}
#line 1345 "parser.cc" // lalr1.cc:859
    break;

  case 72:
#line 350 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::expression* > () = yystack_[0].value.as< ast::op_exp* > ();}
#line 1351 "parser.cc" // lalr1.cc:859
    break;

  case 73:
#line 351 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::expression* > () = yystack_[0].value.as< ast::expression* > ();}
#line 1357 "parser.cc" // lalr1.cc:859
    break;

  case 74:
#line 356 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::op_exp* > () = new ast::op_exp(yystack_[2].value.as< ast::expression* > (), yystack_[0].value.as< ast::expression* > ());}
#line 1363 "parser.cc" // lalr1.cc:859
    break;

  case 75:
#line 358 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::op_exp* > () = new ast::op_exp(yystack_[2].value.as< ast::expression* > (), yystack_[0].value.as< ast::expression* > ());}
#line 1369 "parser.cc" // lalr1.cc:859
    break;

  case 76:
#line 360 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::op_exp* > () = new ast::op_exp(yystack_[2].value.as< ast::expression* > (), yystack_[0].value.as< ast::expression* > ());}
#line 1375 "parser.cc" // lalr1.cc:859
    break;

  case 77:
#line 362 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::op_exp* > () = new ast::op_exp(yystack_[2].value.as< ast::expression* > (), yystack_[0].value.as< ast::expression* > ());}
#line 1381 "parser.cc" // lalr1.cc:859
    break;

  case 78:
#line 364 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::op_exp* > () = new ast::op_exp(yystack_[2].value.as< ast::expression* > (), yystack_[0].value.as< ast::expression* > ());}
#line 1387 "parser.cc" // lalr1.cc:859
    break;

  case 79:
#line 366 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::op_exp* > () = new ast::op_exp(yystack_[2].value.as< ast::expression* > (), yystack_[0].value.as< ast::expression* > ());}
#line 1393 "parser.cc" // lalr1.cc:859
    break;

  case 80:
#line 368 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::op_exp* > () = new ast::op_exp(yystack_[2].value.as< ast::expression* > (), yystack_[0].value.as< ast::expression* > ());}
#line 1399 "parser.cc" // lalr1.cc:859
    break;

  case 81:
#line 370 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::op_exp* > () = new ast::op_exp(yystack_[2].value.as< ast::expression* > (), yystack_[0].value.as< ast::expression* > ());}
#line 1405 "parser.cc" // lalr1.cc:859
    break;

  case 82:
#line 372 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::op_exp* > () = new ast::op_exp(yystack_[2].value.as< ast::expression* > (), yystack_[0].value.as< ast::expression* > ());}
#line 1411 "parser.cc" // lalr1.cc:859
    break;

  case 83:
#line 374 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::op_exp* > () = new ast::op_exp(yystack_[2].value.as< ast::expression* > (), yystack_[0].value.as< ast::expression* > ());}
#line 1417 "parser.cc" // lalr1.cc:859
    break;

  case 84:
#line 376 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::op_exp* > () = new ast::op_exp(yystack_[2].value.as< ast::expression* > (), yystack_[0].value.as< ast::expression* > ());}
#line 1423 "parser.cc" // lalr1.cc:859
    break;

  case 85:
#line 378 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::op_exp* > () = new ast::op_exp(yystack_[2].value.as< ast::expression* > (), yystack_[0].value.as< ast::expression* > ());}
#line 1429 "parser.cc" // lalr1.cc:859
    break;

  case 86:
#line 380 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::op_exp* > () = new ast::op_exp(yystack_[2].value.as< ast::expression* > (), yystack_[0].value.as< ast::expression* > ());}
#line 1435 "parser.cc" // lalr1.cc:859
    break;

  case 87:
#line 382 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::op_exp* > () = new ast::op_exp(yystack_[2].value.as< ast::expression* > (), yystack_[0].value.as< ast::expression* > ());}
#line 1441 "parser.cc" // lalr1.cc:859
    break;

  case 88:
#line 387 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::op_exp* > () = new ast::op_exp(yystack_[0].value.as< ast::expression* > ());}
#line 1447 "parser.cc" // lalr1.cc:859
    break;

  case 89:
#line 389 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::op_exp* > () = new ast::op_exp(yystack_[0].value.as< ast::expression* > ());}
#line 1453 "parser.cc" // lalr1.cc:859
    break;

  case 90:
#line 391 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::op_exp* > () = new ast::op_exp(yystack_[0].value.as< ast::expression* > ());}
#line 1459 "parser.cc" // lalr1.cc:859
    break;

  case 91:
#line 395 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::expression* > () = yystack_[0].value.as< ast::new_array_exp* > ();}
#line 1465 "parser.cc" // lalr1.cc:859
    break;

  case 92:
#line 396 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::expression* > () = yystack_[0].value.as< ast::expression* > ();}
#line 1471 "parser.cc" // lalr1.cc:859
    break;

  case 93:
#line 397 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::expression* > () = new ast::name_exp(yystack_[0].value.as< std::string > ());}
#line 1477 "parser.cc" // lalr1.cc:859
    break;

  case 94:
#line 402 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::new_array_exp* > () = new ast::new_array_exp(new ast::type_node(yystack_[1].value.as< std::string > ()));
			std::list<ast::expression*>::iterator iter; 
			for(iter = yystack_[0].value.as< std::list<ast::expression*>* > () -> begin(); iter != yystack_[0].value.as< std::list<ast::expression*>* > () -> end(); iter++){
				yylhs.value.as< ast::new_array_exp* > () -> add_child(*iter);
			} 
		}
#line 1488 "parser.cc" // lalr1.cc:859
    break;

  case 95:
#line 408 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::new_array_exp* > () = new ast::new_array_exp(yystack_[1].value.as< ast::type_node* > ());
			std::list<ast::expression*>::iterator iter; 
			for(iter = yystack_[0].value.as< std::list<ast::expression*>* > () -> begin(); iter != yystack_[0].value.as< std::list<ast::expression*>* > () -> end(); iter++){
				yylhs.value.as< ast::new_array_exp* > () -> add_child(*iter);
			}  
		}
#line 1500 "parser.cc" // lalr1.cc:859
    break;

  case 96:
#line 418 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< std::list<ast::expression*>* > () = new std::list<ast::expression*>();
			yylhs.value.as< std::list<ast::expression*>* > () -> push_back(yystack_[0].value.as< ast::expression* > ());}
#line 1508 "parser.cc" // lalr1.cc:859
    break;

  case 97:
#line 421 "parser.yy" // lalr1.cc:859
    {
			 yylhs.value.as< std::list<ast::expression*>* > () = yystack_[1].value.as< std::list<ast::expression*>* > ();
			 yylhs.value.as< std::list<ast::expression*>* > () -> push_back(yystack_[0].value.as< ast::expression* > ());}
#line 1516 "parser.cc" // lalr1.cc:859
    break;

  case 98:
#line 426 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::expression* > () = yystack_[1].value.as< ast::expression* > ();}
#line 1522 "parser.cc" // lalr1.cc:859
    break;

  case 99:
#line 430 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::expression* > () = yystack_[0].value.as< ast::literal* > ();}
#line 1528 "parser.cc" // lalr1.cc:859
    break;

  case 100:
#line 431 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::expression* > () = new ast::name_exp("this");}
#line 1534 "parser.cc" // lalr1.cc:859
    break;

  case 101:
#line 432 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::expression* > () = yystack_[1].value.as< ast::expression* > ();}
#line 1540 "parser.cc" // lalr1.cc:859
    break;

  case 102:
#line 433 "parser.yy" // lalr1.cc:859
    {			
			yylhs.value.as< ast::expression* > () = new ast::call_exp(new ast::name_exp(yystack_[1].value.as< std::string > ()), yystack_[0].value.as< ast::expression_list* > ());
		}
#line 1548 "parser.cc" // lalr1.cc:859
    break;

  case 103:
#line 436 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::expression* > () = new ast::call_exp(new ast::name_exp(yystack_[1].value.as< std::string > ()), yystack_[0].value.as< ast::expression_list* > ());}
#line 1554 "parser.cc" // lalr1.cc:859
    break;

  case 104:
#line 437 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::expression* > () = new ast::call_exp(new ast::name_exp(yystack_[1].value.as< std::string > ()) , yystack_[0].value.as< ast::expression_list* > ());}
#line 1560 "parser.cc" // lalr1.cc:859
    break;

  case 105:
#line 438 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::expression* > () = new ast::call_exp(new ast::name_exp(yystack_[1].value.as< std::string > ()), yystack_[0].value.as< ast::expression_list* > ());}
#line 1566 "parser.cc" // lalr1.cc:859
    break;

  case 106:
#line 439 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::expression* > () = yystack_[0].value.as< ast::array_ref* > ();}
#line 1572 "parser.cc" // lalr1.cc:859
    break;

  case 107:
#line 440 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::expression* > () = yystack_[0].value.as< ast::expression* > ();}
#line 1578 "parser.cc" // lalr1.cc:859
    break;

  case 108:
#line 444 "parser.yy" // lalr1.cc:859
    {
			yystack_[2].value.as< ast::expression* > ();
			yylhs.value.as< ast::expression* > () = new ast::name_exp(yystack_[0].value.as< std::string > ());}
#line 1586 "parser.cc" // lalr1.cc:859
    break;

  case 109:
#line 447 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::expression* > () = new ast::name_exp(yystack_[0].value.as< std::string > ());}
#line 1592 "parser.cc" // lalr1.cc:859
    break;

  case 110:
#line 450 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::array_ref* > () = new ast::array_ref(new ast::name_exp(yystack_[1].value.as< std::string > ()), yystack_[0].value.as< ast::expression* > ());}
#line 1598 "parser.cc" // lalr1.cc:859
    break;

  case 111:
#line 451 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::array_ref* > () = new ast::array_ref(yystack_[1].value.as< ast::expression* > (), yystack_[0].value.as< ast::expression* > ());}
#line 1604 "parser.cc" // lalr1.cc:859
    break;

  case 112:
#line 455 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::literal* > () = new ast::null_literal();}
#line 1610 "parser.cc" // lalr1.cc:859
    break;

  case 113:
#line 456 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::literal* > () = new ast::bool_literal(true);}
#line 1616 "parser.cc" // lalr1.cc:859
    break;

  case 114:
#line 457 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::literal* > () = new ast::bool_literal(false);}
#line 1622 "parser.cc" // lalr1.cc:859
    break;

  case 115:
#line 458 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::literal* > () = new ast::int_literal(yystack_[0].value.as< int > ());}
#line 1628 "parser.cc" // lalr1.cc:859
    break;

  case 116:
#line 459 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::literal* > () = new ast::char_literal(yystack_[0].value.as< char > ());}
#line 1634 "parser.cc" // lalr1.cc:859
    break;

  case 117:
#line 460 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::literal* > () = new ast::string_literal(yystack_[0].value.as< std::string > ());}
#line 1640 "parser.cc" // lalr1.cc:859
    break;

  case 118:
#line 464 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::expression_list* > () = new ast::expression_list();}
#line 1646 "parser.cc" // lalr1.cc:859
    break;

  case 119:
#line 465 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< ast::expression_list* > () = yystack_[1].value.as< ast::expression_list* > ();}
#line 1652 "parser.cc" // lalr1.cc:859
    break;

  case 120:
#line 469 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::expression_list* > () = new ast::expression_list();
			yylhs.value.as< ast::expression_list* > () -> add_child(yystack_[0].value.as< ast::expression* > ());}
#line 1660 "parser.cc" // lalr1.cc:859
    break;

  case 121:
#line 472 "parser.yy" // lalr1.cc:859
    {
			yylhs.value.as< ast::expression_list* > () = yystack_[0].value.as< ast::expression_list* > (); 
			yylhs.value.as< ast::expression_list* > () -> add_child(yystack_[2].value.as< ast::expression* > ());
			}
#line 1669 "parser.cc" // lalr1.cc:859
    break;


#line 1673 "parser.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  calcxx_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  calcxx_parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short int calcxx_parser::yypact_ninf_ = -155;

  const signed char calcxx_parser::yytable_ninf_ = -71;

  const short int
  calcxx_parser::yypact_[] =
  {
     -16,     3,     8,   -16,  -155,   -12,  -155,  -155,    26,    -3,
    -155,  -155,    -1,  -155,  -155,   125,   -17,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,    34,     9,    11,    12,
      16,    10,   -17,  -155,    13,    -4,    10,     9,  -155,    24,
      33,    73,  -155,  -155,  -155,    41,    16,    10,    75,   393,
    -155,    40,  -155,   153,  -155,  -155,     9,  -155,     1,  -155,
    -155,  -155,  -155,  -155,  -155,   234,    39,  -155,   393,   393,
     393,   393,   589,  -155,  -155,    42,  -155,    48,  -155,  -155,
    -155,  -155,     7,    47,    55,    50,   233,   -26,    58,  -155,
    -155,   101,  -155,  -155,   504,   273,   393,  -155,  -155,     1,
      48,   102,   398,   589,   239,   239,   393,   393,   393,   393,
     393,   393,   393,   393,   393,   393,   393,   393,   393,   393,
     106,  -155,   313,  -155,   393,  -155,  -155,   522,    71,   393,
       9,    72,    78,    66,  -155,  -155,   575,    91,   486,    48,
    -155,  -155,    48,    96,  -155,   600,   600,   600,   239,   239,
     200,   200,   200,   200,    76,    76,    76,    76,    76,    96,
     421,  -155,  -155,   444,    10,  -155,   101,   393,   393,  -155,
    -155,  -155,  -155,  -155,    84,   193,  -155,   589,  -155,    94,
      97,   353,   -26,   104,   115,   101,   118,  -155,   123,   540,
    -155,   124,   126,   127,   558,   114,   393,   116,   193,   137,
     140,   154,   467,   158,  -155,    84,  -155
  };

  const unsigned char
  calcxx_parser::yydefact_[] =
  {
       0,     0,     0,     2,     3,     6,     1,     4,     0,     0,
       7,     8,    13,     5,     9,     0,    25,    32,    31,    30,
      33,    17,    18,    16,    15,    14,     0,    24,     0,     0,
       0,    27,    39,    10,    35,    36,    26,    25,    20,     0,
      21,     0,    28,    47,    12,     0,     0,    38,     0,     0,
      19,     0,    23,     0,    29,    11,    39,    34,    93,   112,
     113,   114,   115,   116,   117,     0,     0,   100,     0,     0,
       0,     0,    37,    72,    71,    73,    91,    92,   107,   106,
      99,    22,    93,     0,     0,     0,     0,     0,     0,    46,
      49,     0,    60,    48,     0,     0,     0,   110,   103,     0,
       0,     0,     0,    90,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,     0,    58,     0,    57,    55,     0,     0,     0,
      44,     0,    41,    42,    53,   118,   120,     0,     0,    94,
      96,   102,    95,   109,   101,    85,    86,    87,    83,    84,
      79,    80,    81,    82,    77,    78,    76,    75,    74,   108,
       0,    56,    59,     0,    45,    50,     0,     0,     0,   119,
      98,    97,   105,   104,     0,     0,    40,    43,   121,     0,
       0,     0,     0,     0,    49,     0,    60,    51,     0,     0,
      54,    58,    57,    55,     0,     0,     0,     0,     0,    53,
      56,    59,     0,    50,    52,     0,    64
  };

  const short int
  calcxx_parser::yypgoto_[] =
  {
    -155,  -155,  -155,   170,  -155,  -155,  -155,  -155,  -155,   147,
     129,  -155,   -15,   -23,   117,   139,  -155,  -155,  -154,  -155,
    -155,   -29,  -155,   -50,   -14,   -47,  -155,  -155,  -155,  -155,
      93,   -58,  -155,  -155,  -155,  -155,   -69,    29
  };

  const short int
  calcxx_parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,     9,    12,    14,    15,    25,    30,
      39,    40,    91,    31,    27,    33,    34,    35,   131,   132,
     133,    92,    53,   190,   188,    94,    73,    74,    75,    76,
     139,    97,    77,    78,    79,    80,    98,   137
  };

  const short int
  calcxx_parser::yytable_[] =
  {
      26,    44,    72,    93,    36,     1,     5,    95,     6,    47,
     -25,     8,   176,    41,    37,   101,    28,    55,   128,   121,
      29,   102,   103,   104,   105,    17,    18,    19,    20,    10,
     141,   197,    11,    47,    95,    13,    41,    32,    96,   127,
      95,   140,   140,    37,   122,    38,    29,    45,   136,   138,
      42,    43,    49,    48,    17,    18,    19,    20,    50,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    51,   172,   138,    52,   160,    56,    54,
     101,   171,   163,   120,   171,    96,   123,    82,   124,   125,
     173,   129,    59,    60,    61,    62,    63,    64,    17,    18,
      19,    20,   179,    84,   130,   143,   180,   164,    65,   159,
     162,   165,   181,   195,   182,    67,   183,    68,   166,    43,
     177,   136,   167,   184,   187,   169,    69,   189,    16,    95,
      70,    71,   119,   191,   194,   -61,   192,   196,   -70,    17,
      18,    19,    20,   198,   -68,   186,   -67,   -65,   204,   202,
      21,    22,    23,   201,    24,   203,    82,   -63,   189,   185,
     -66,    59,    60,    61,    62,    63,    64,    17,    18,    19,
      20,    83,    84,     7,   -69,    85,   186,    65,   -62,    46,
      81,    86,   100,    87,    67,    88,    68,    57,    43,    89,
     185,   206,    90,   142,     0,    69,    82,   178,     0,    70,
      71,    59,    60,    61,    62,    63,    64,    17,    18,    19,
      20,    83,    84,     0,     0,    85,     0,    65,     0,     0,
       0,    86,     0,    87,    67,    88,    68,     0,    43,     0,
       0,     0,    90,     0,     0,    69,    58,    99,     0,    70,
      71,    59,    60,    61,    62,    63,    64,     0,    17,    18,
      19,    20,   115,   116,   117,   118,   119,    65,     0,     0,
       0,     0,     0,    66,    67,     0,    68,     0,     0,     0,
       0,     0,   126,     0,     0,    69,    58,     0,     0,    70,
      71,    59,    60,    61,    62,    63,    64,   111,   112,   113,
     114,   115,   116,   117,   118,   119,     0,    65,     0,     0,
       0,     0,     0,    66,    67,     0,    68,   135,     0,     0,
       0,     0,     0,     0,     0,    69,    58,     0,     0,    70,
      71,    59,    60,    61,    62,    63,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,     0,     0,
       0,     0,     0,    66,    67,     0,    68,     0,     0,     0,
       0,    42,     0,     0,     0,    69,    58,     0,     0,    70,
      71,    59,    60,    61,    62,    63,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,     0,     0,
       0,     0,     0,    66,    67,     0,    68,     0,     0,     0,
       0,     0,   193,     0,     0,    69,    58,     0,     0,    70,
      71,    59,    60,    61,    62,    63,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,     0,     0,
       0,     0,     0,    66,    67,     0,    68,     0,     0,     0,
       0,     0,   144,     0,     0,    69,     0,     0,     0,    70,
      71,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   174,     0,     0,     0,     0,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   175,     0,
       0,     0,     0,     0,     0,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   205,     0,     0,     0,     0,     0,     0,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   170,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   134,     0,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   161,     0,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   199,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   200,     0,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   168,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119
  };

  const short int
  calcxx_parser::yycheck_[] =
  {
      15,    30,    49,    53,    27,    21,     3,    33,     0,    32,
       3,    23,   166,    28,     3,    41,    33,    46,    87,    77,
      37,    68,    69,    70,    71,    14,    15,    16,    17,     3,
      99,   185,    35,    56,    33,    36,    51,     3,    37,    86,
      33,    99,   100,     3,    37,    34,    37,    37,    95,    96,
      38,    35,    56,    40,    14,    15,    16,    17,    34,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    40,   143,   122,     3,   124,     3,    38,
      41,   139,   129,    41,   142,    37,    39,     3,    33,    39,
     159,    33,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     3,     3,    22,   130,    24,     3,
      39,    39,    28,   182,    30,    31,    32,    33,    40,    35,
     167,   168,    56,    39,   174,    34,    42,   174,     3,    33,
      46,    47,    56,    39,   181,    20,    39,    33,    20,    14,
      15,    16,    17,    20,    20,   174,    20,    20,   198,   196,
      25,    26,    27,    39,    29,    39,     3,    20,   205,   174,
      20,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     3,    20,    22,   205,    24,    20,    32,
      51,    28,    65,    30,    31,    32,    33,    48,    35,    36,
     205,   205,    39,   100,    -1,    42,     3,   168,    -1,    46,
      47,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    22,    -1,    24,    -1,    -1,
      -1,    28,    -1,    30,    31,    32,    33,    -1,    35,    -1,
      -1,    -1,    39,    -1,    -1,    42,     3,     3,    -1,    46,
      47,     8,     9,    10,    11,    12,    13,    -1,    14,    15,
      16,    17,    52,    53,    54,    55,    56,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    42,     3,    -1,    -1,    46,
      47,     8,     9,    10,    11,    12,    13,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,     3,    -1,    -1,    46,
      47,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    42,     3,    -1,    -1,    46,
      47,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    42,     3,    -1,    -1,    46,
      47,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    42,    -1,    -1,    -1,    46,
      47,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    38,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    39,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    39,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    39,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    39,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    40,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56
  };

  const unsigned char
  calcxx_parser::yystos_[] =
  {
       0,    21,    58,    59,    60,     3,     0,    60,    23,    61,
       3,    35,    62,    36,    63,    64,     3,    14,    15,    16,
      17,    25,    26,    27,    29,    65,    69,    71,    33,    37,
      66,    70,     3,    72,    73,    74,    70,     3,    34,    67,
      68,    69,    38,    35,    78,    37,    66,    70,    40,    56,
      34,    40,     3,    79,    38,    78,     3,    72,     3,     8,
       9,    10,    11,    12,    13,    24,    30,    31,    33,    42,
      46,    47,    82,    83,    84,    85,    86,    89,    90,    91,
      92,    67,     3,    18,    19,    22,    28,    30,    32,    36,
      39,    69,    78,    80,    82,    33,    37,    88,    93,     3,
      71,    41,    82,    82,    82,    82,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      41,    88,    37,    39,    33,    39,    39,    82,    93,    33,
       3,    75,    76,    77,    39,    34,    82,    94,    82,    87,
      88,    93,    87,     3,    34,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,     3,
      82,    39,    39,    82,    70,    39,    40,    56,    40,    34,
      38,    88,    93,    93,    34,    34,    75,    82,    94,    18,
      22,    28,    30,    32,    39,    69,    78,    80,    81,    82,
      80,    39,    39,    39,    82,    93,    33,    75,    20,    39,
      39,    39,    82,    39,    80,    34,    81
  };

  const unsigned char
  calcxx_parser::yyr1_[] =
  {
       0,    57,    58,    59,    59,    60,    61,    61,    62,    62,
      63,    63,    63,    64,    64,    65,    65,    65,    65,    66,
      66,    67,    67,    68,    69,    69,    69,    69,    70,    70,
      71,    71,    71,    71,    72,    72,    73,    73,    74,    74,
      75,    75,    76,    76,    77,    77,    78,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    82,    82,    82,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    84,    84,
      84,    85,    85,    85,    86,    86,    87,    87,    88,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    90,    90,
      91,    91,    92,    92,    92,    92,    92,    92,    93,    93,
      94,    94
  };

  const unsigned char
  calcxx_parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     6,     0,     2,     0,     2,
       3,     5,     4,     0,     2,     1,     1,     1,     1,     3,
       2,     1,     3,     2,     1,     1,     2,     2,     2,     3,
       1,     1,     1,     1,     3,     1,     1,     3,     2,     1,
       3,     1,     1,     3,     1,     2,     3,     0,     2,     1,
       3,     5,     7,     2,     5,     2,     3,     2,     2,     3,
       1,     1,     3,     2,     5,     2,     3,     2,     2,     3,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     1,     1,     1,     3,     3,     1,     2,     3,     1,
       1,     3,     3,     2,     4,     4,     1,     1,     3,     3,
       2,     2,     1,     1,     1,     1,     1,     1,     2,     3,
       1,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const calcxx_parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"identifier\"",
  "\"number\"", "FORBIDDEN", "RESERVED", "FPRIMATIVE", "\"null\"",
  "\"true\"", "\"false\"", "INTLITERAL", "CHARLITERAL", "STRLITERAL",
  "INTTYPE", "CHARTYPE", "BOOLTYPE", "VOIDTYPE", "\"break\"", "\"if\"",
  "\"else\"", "\"class\"", "\"continue\"", "\"extends\"", "\"new\"",
  "\"private\"", "\"protected\"", "\"public\"", "\"return\"", "\"static\"",
  "\"super\"", "\"this\"", "\"while\"", "\"(\"", "\")\"", "\"{\"", "\"}\"",
  "\"[\"", "\"]\"", "\";\"", "\",\"", "\".\"", "NOT", "MULT", "DIV", "MOD",
  "ADD", "SUB", "GR", "LE", "GEQ", "LEQ", "EQ", "NEQ", "AND", "OR", "ASGN",
  "$accept", "unit", "start", "class", "super", "memberList", "member",
  "modifierList", "modifier", "formalArgs", "formalArgsList", "formalArg",
  "type", "brackets", "primativeType", "fieldDeclList", "fieldDecl",
  "fieldDeclId", "localDeclList", "localDecl", "localDeclId", "block",
  "statementList", "statement", "stmtNoIf", "expression", "binaryOp",
  "unaryOp", "primary", "newArrExpr", "dimensionPlus", "dimension",
  "nonNewArrExpr", "fieldExpr", "arrExpr", "literal", "actualArgs",
  "exprList", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  calcxx_parser::yyrline_[] =
  {
       0,   138,   138,   143,   145,   151,   156,   157,   161,   164,
     171,   176,   177,   182,   183,   188,   189,   190,   191,   195,
     196,   200,   201,   208,   213,   214,   215,   216,   219,   220,
     224,   225,   226,   227,   231,   235,   242,   243,   250,   252,
     256,   259,   266,   267,   274,   275,   281,   286,   289,   295,
     297,   301,   303,   305,   307,   309,   311,   313,   315,   317,
     319,   324,   326,   330,   332,   334,   336,   338,   340,   342,
     344,   349,   350,   351,   355,   357,   359,   361,   363,   365,
     367,   369,   371,   373,   375,   377,   379,   381,   386,   388,
     390,   395,   396,   397,   401,   408,   418,   421,   426,   430,
     431,   432,   433,   436,   437,   438,   439,   440,   444,   447,
     450,   451,   455,   456,   457,   458,   459,   460,   464,   465,
     469,   472
  };

  // Print the state stack on the debug stream.
  void
  calcxx_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  calcxx_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 2283 "parser.cc" // lalr1.cc:1167
#line 477 "parser.yy" // lalr1.cc:1168

void
yy::calcxx_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
