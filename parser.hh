// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton interface for Bison LALR(1) parsers in C++

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

/**
 ** \file parser.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_PARSER_HH_INCLUDED
# define YY_YY_PARSER_HH_INCLUDED
// //                    "%code requires" blocks.
#line 9 "parser.yy" // lalr1.cc:392

# include <string>
# include <utility>
# include <list>
# include "ast.hh"
# include "ast_node.hh"
# include "visitor.hh"
# include "print_visitor.hh"
class calcxx_driver;

#line 55 "parser.hh" // lalr1.cc:392

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>
# include "stack.hh"
# include "location.hh"
#include <typeinfo>
#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif


namespace yy {
#line 132 "parser.hh" // lalr1.cc:392



  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
      : yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    variant (const T& t)
      : yytypeid_ (&typeid (T))
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (t);
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {
      YYASSERT (!yytypeid_);
    }

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    build ()
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T;
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    build (const T& t)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsability.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == *other.yytypeid_);
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
      build<T> ();
      swap<T> (other);
      other.destroy<T> ();
    }

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      build<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator=(const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };


  /// A Bison parser.
  class calcxx_parser
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // arrExpr
      char dummy1[sizeof(ast::array_ref*)];

      // member
      char dummy2[sizeof(ast::ast_node*)];

      // start
      char dummy3[sizeof(ast::class_list*)];

      // class
      char dummy4[sizeof(ast::class_node*)];

      // localDeclList
      char dummy5[sizeof(ast::decl_stat*)];

      // expression
      // primary
      // dimension
      // nonNewArrExpr
      // fieldExpr
      char dummy6[sizeof(ast::expression*)];

      // actualArgs
      // exprList
      char dummy7[sizeof(ast::expression_list*)];

      // fieldDeclList
      char dummy8[sizeof(ast::field_decl*)];

      // fieldDecl
      // fieldDeclId
      char dummy9[sizeof(ast::field_node*)];

      // formalArgs
      // formalArgsList
      char dummy10[sizeof(ast::formal_list*)];

      // formalArg
      char dummy11[sizeof(ast::formal_node*)];

      // literal
      char dummy12[sizeof(ast::literal*)];

      // localDecl
      // localDeclId
      char dummy13[sizeof(ast::local_node*)];

      // memberList
      char dummy14[sizeof(ast::member_list*)];

      // newArrExpr
      char dummy15[sizeof(ast::new_array_exp*)];

      // binaryOp
      // unaryOp
      char dummy16[sizeof(ast::op_exp*)];

      // statement
      // stmtNoIf
      char dummy17[sizeof(ast::statement*)];

      // block
      // statementList
      char dummy18[sizeof(ast::statement_list*)];

      // super
      char dummy19[sizeof(ast::super_node*)];

      // type
      // primativeType
      char dummy20[sizeof(ast::type_node*)];

      // CHARLITERAL
      char dummy21[sizeof(char)];

      // "number"
      // INTLITERAL
      // unit
      // modifierList
      // modifier
      // brackets
      char dummy22[sizeof(int)];

      // dimensionPlus
      char dummy23[sizeof(std::list<ast::expression*>*)];

      // "identifier"
      // FORBIDDEN
      // RESERVED
      // FPRIMATIVE
      // STRLITERAL
      char dummy24[sizeof(std::string)];
};

    /// Symbol semantic values.
    typedef variant<sizeof(union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m);
      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        TOK_END = 0,
        TOK_IDENTIFIER = 258,
        TOK_NUMBER = 259,
        TOK_FORBIDDEN = 260,
        TOK_RESERVED = 261,
        TOK_FPRIMATIVE = 262,
        TOK_NUL = 263,
        TOK_TRUE = 264,
        TOK_FALSE = 265,
        TOK_INTLITERAL = 266,
        TOK_CHARLITERAL = 267,
        TOK_STRLITERAL = 268,
        TOK_INTTYPE = 269,
        TOK_CHARTYPE = 270,
        TOK_BOOLTYPE = 271,
        TOK_VOIDTYPE = 272,
        TOK_BREAK = 273,
        TOK_IF = 274,
        TOK_ELSE = 275,
        TOK_CLASS = 276,
        TOK_CONTINUE = 277,
        TOK_EXTENDS = 278,
        TOK_NEW = 279,
        TOK_PRIVATE = 280,
        TOK_PROTECTED = 281,
        TOK_PUBLIC = 282,
        TOK_RETURN = 283,
        TOK_STATIC = 284,
        TOK_SUPER = 285,
        TOK_THIS = 286,
        TOK_WHILE = 287,
        TOK_LPAREN = 288,
        TOK_RPAREN = 289,
        TOK_LBRACKET = 290,
        TOK_RBRACKET = 291,
        TOK_LSQUARE = 292,
        TOK_RSQUARE = 293,
        TOK_SEMICOLON = 294,
        TOK_COMMA = 295,
        TOK_PERIOD = 296,
        TOK_NOT = 297,
        TOK_MULT = 298,
        TOK_DIV = 299,
        TOK_MOD = 300,
        TOK_ADD = 301,
        TOK_SUB = 302,
        TOK_GR = 303,
        TOK_LE = 304,
        TOK_GEQ = 305,
        TOK_LEQ = 306,
        TOK_EQ = 307,
        TOK_NEQ = 308,
        TOK_AND = 309,
        TOK_OR = 310,
        TOK_ASGN = 311
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols, and symbols from each type.

  basic_symbol (typename Base::kind_type t, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::array_ref* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::ast_node* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::class_list* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::class_node* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::decl_stat* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::expression* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::expression_list* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::field_decl* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::field_node* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::formal_list* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::formal_node* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::literal* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::local_node* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::member_list* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::new_array_exp* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::op_exp* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::statement* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::statement_list* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::super_node* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::type_node* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const char v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const int v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::list<ast::expression*>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l);


      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v,
                    const location_type& l);

      /// Destroy the symbol.
      ~basic_symbol ();

      /// Destroy contents, and record that is empty.
      void clear ();

      /// Whether empty.
      bool empty () const;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    // Symbol constructors declarations.
    static inline
    symbol_type
    make_END (const location_type& l);

    static inline
    symbol_type
    make_IDENTIFIER (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_NUMBER (const int& v, const location_type& l);

    static inline
    symbol_type
    make_FORBIDDEN (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_RESERVED (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_FPRIMATIVE (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_NUL (const location_type& l);

    static inline
    symbol_type
    make_TRUE (const location_type& l);

    static inline
    symbol_type
    make_FALSE (const location_type& l);

    static inline
    symbol_type
    make_INTLITERAL (const int& v, const location_type& l);

    static inline
    symbol_type
    make_CHARLITERAL (const char& v, const location_type& l);

    static inline
    symbol_type
    make_STRLITERAL (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_INTTYPE (const location_type& l);

    static inline
    symbol_type
    make_CHARTYPE (const location_type& l);

    static inline
    symbol_type
    make_BOOLTYPE (const location_type& l);

    static inline
    symbol_type
    make_VOIDTYPE (const location_type& l);

    static inline
    symbol_type
    make_BREAK (const location_type& l);

    static inline
    symbol_type
    make_IF (const location_type& l);

    static inline
    symbol_type
    make_ELSE (const location_type& l);

    static inline
    symbol_type
    make_CLASS (const location_type& l);

    static inline
    symbol_type
    make_CONTINUE (const location_type& l);

    static inline
    symbol_type
    make_EXTENDS (const location_type& l);

    static inline
    symbol_type
    make_NEW (const location_type& l);

    static inline
    symbol_type
    make_PRIVATE (const location_type& l);

    static inline
    symbol_type
    make_PROTECTED (const location_type& l);

    static inline
    symbol_type
    make_PUBLIC (const location_type& l);

    static inline
    symbol_type
    make_RETURN (const location_type& l);

    static inline
    symbol_type
    make_STATIC (const location_type& l);

    static inline
    symbol_type
    make_SUPER (const location_type& l);

    static inline
    symbol_type
    make_THIS (const location_type& l);

    static inline
    symbol_type
    make_WHILE (const location_type& l);

    static inline
    symbol_type
    make_LPAREN (const location_type& l);

    static inline
    symbol_type
    make_RPAREN (const location_type& l);

    static inline
    symbol_type
    make_LBRACKET (const location_type& l);

    static inline
    symbol_type
    make_RBRACKET (const location_type& l);

    static inline
    symbol_type
    make_LSQUARE (const location_type& l);

    static inline
    symbol_type
    make_RSQUARE (const location_type& l);

    static inline
    symbol_type
    make_SEMICOLON (const location_type& l);

    static inline
    symbol_type
    make_COMMA (const location_type& l);

    static inline
    symbol_type
    make_PERIOD (const location_type& l);

    static inline
    symbol_type
    make_NOT (const location_type& l);

    static inline
    symbol_type
    make_MULT (const location_type& l);

    static inline
    symbol_type
    make_DIV (const location_type& l);

    static inline
    symbol_type
    make_MOD (const location_type& l);

    static inline
    symbol_type
    make_ADD (const location_type& l);

    static inline
    symbol_type
    make_SUB (const location_type& l);

    static inline
    symbol_type
    make_GR (const location_type& l);

    static inline
    symbol_type
    make_LE (const location_type& l);

    static inline
    symbol_type
    make_GEQ (const location_type& l);

    static inline
    symbol_type
    make_LEQ (const location_type& l);

    static inline
    symbol_type
    make_EQ (const location_type& l);

    static inline
    symbol_type
    make_NEQ (const location_type& l);

    static inline
    symbol_type
    make_AND (const location_type& l);

    static inline
    symbol_type
    make_OR (const location_type& l);

    static inline
    symbol_type
    make_ASGN (const location_type& l);


    /// Build a parser object.
    calcxx_parser (calcxx_driver& driver_yyarg);
    virtual ~calcxx_parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    calcxx_parser (const calcxx_parser&);
    calcxx_parser& operator= (const calcxx_parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short int yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short int yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short int yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short int yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short int yytable_[];

  static const short int yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short int yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 656,     ///< Last index in yytable_.
      yynnts_ = 38,  ///< Number of nonterminal symbols.
      yyfinal_ = 6, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 57  ///< Number of tokens.
    };


    // User arguments.
    calcxx_driver& driver;
  };

  // Symbol number corresponding to token number t.
  inline
  calcxx_parser::token_number_type
  calcxx_parser::yytranslate_ (token_type t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
    };
    const unsigned int user_token_number_max_ = 311;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  inline
  calcxx_parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  calcxx_parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  calcxx_parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 91: // arrExpr
        value.copy< ast::array_ref* > (other.value);
        break;

      case 63: // member
        value.copy< ast::ast_node* > (other.value);
        break;

      case 59: // start
        value.copy< ast::class_list* > (other.value);
        break;

      case 60: // class
        value.copy< ast::class_node* > (other.value);
        break;

      case 75: // localDeclList
        value.copy< ast::decl_stat* > (other.value);
        break;

      case 82: // expression
      case 85: // primary
      case 88: // dimension
      case 89: // nonNewArrExpr
      case 90: // fieldExpr
        value.copy< ast::expression* > (other.value);
        break;

      case 93: // actualArgs
      case 94: // exprList
        value.copy< ast::expression_list* > (other.value);
        break;

      case 72: // fieldDeclList
        value.copy< ast::field_decl* > (other.value);
        break;

      case 73: // fieldDecl
      case 74: // fieldDeclId
        value.copy< ast::field_node* > (other.value);
        break;

      case 66: // formalArgs
      case 67: // formalArgsList
        value.copy< ast::formal_list* > (other.value);
        break;

      case 68: // formalArg
        value.copy< ast::formal_node* > (other.value);
        break;

      case 92: // literal
        value.copy< ast::literal* > (other.value);
        break;

      case 76: // localDecl
      case 77: // localDeclId
        value.copy< ast::local_node* > (other.value);
        break;

      case 62: // memberList
        value.copy< ast::member_list* > (other.value);
        break;

      case 86: // newArrExpr
        value.copy< ast::new_array_exp* > (other.value);
        break;

      case 83: // binaryOp
      case 84: // unaryOp
        value.copy< ast::op_exp* > (other.value);
        break;

      case 80: // statement
      case 81: // stmtNoIf
        value.copy< ast::statement* > (other.value);
        break;

      case 78: // block
      case 79: // statementList
        value.copy< ast::statement_list* > (other.value);
        break;

      case 61: // super
        value.copy< ast::super_node* > (other.value);
        break;

      case 69: // type
      case 71: // primativeType
        value.copy< ast::type_node* > (other.value);
        break;

      case 12: // CHARLITERAL
        value.copy< char > (other.value);
        break;

      case 4: // "number"
      case 11: // INTLITERAL
      case 58: // unit
      case 64: // modifierList
      case 65: // modifier
      case 70: // brackets
        value.copy< int > (other.value);
        break;

      case 87: // dimensionPlus
        value.copy< std::list<ast::expression*>* > (other.value);
        break;

      case 3: // "identifier"
      case 5: // FORBIDDEN
      case 6: // RESERVED
      case 7: // FPRIMATIVE
      case 13: // STRLITERAL
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 91: // arrExpr
        value.copy< ast::array_ref* > (v);
        break;

      case 63: // member
        value.copy< ast::ast_node* > (v);
        break;

      case 59: // start
        value.copy< ast::class_list* > (v);
        break;

      case 60: // class
        value.copy< ast::class_node* > (v);
        break;

      case 75: // localDeclList
        value.copy< ast::decl_stat* > (v);
        break;

      case 82: // expression
      case 85: // primary
      case 88: // dimension
      case 89: // nonNewArrExpr
      case 90: // fieldExpr
        value.copy< ast::expression* > (v);
        break;

      case 93: // actualArgs
      case 94: // exprList
        value.copy< ast::expression_list* > (v);
        break;

      case 72: // fieldDeclList
        value.copy< ast::field_decl* > (v);
        break;

      case 73: // fieldDecl
      case 74: // fieldDeclId
        value.copy< ast::field_node* > (v);
        break;

      case 66: // formalArgs
      case 67: // formalArgsList
        value.copy< ast::formal_list* > (v);
        break;

      case 68: // formalArg
        value.copy< ast::formal_node* > (v);
        break;

      case 92: // literal
        value.copy< ast::literal* > (v);
        break;

      case 76: // localDecl
      case 77: // localDeclId
        value.copy< ast::local_node* > (v);
        break;

      case 62: // memberList
        value.copy< ast::member_list* > (v);
        break;

      case 86: // newArrExpr
        value.copy< ast::new_array_exp* > (v);
        break;

      case 83: // binaryOp
      case 84: // unaryOp
        value.copy< ast::op_exp* > (v);
        break;

      case 80: // statement
      case 81: // stmtNoIf
        value.copy< ast::statement* > (v);
        break;

      case 78: // block
      case 79: // statementList
        value.copy< ast::statement_list* > (v);
        break;

      case 61: // super
        value.copy< ast::super_node* > (v);
        break;

      case 69: // type
      case 71: // primativeType
        value.copy< ast::type_node* > (v);
        break;

      case 12: // CHARLITERAL
        value.copy< char > (v);
        break;

      case 4: // "number"
      case 11: // INTLITERAL
      case 58: // unit
      case 64: // modifierList
      case 65: // modifier
      case 70: // brackets
        value.copy< int > (v);
        break;

      case 87: // dimensionPlus
        value.copy< std::list<ast::expression*>* > (v);
        break;

      case 3: // "identifier"
      case 5: // FORBIDDEN
      case 6: // RESERVED
      case 7: // FPRIMATIVE
      case 13: // STRLITERAL
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::array_ref* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::ast_node* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::class_list* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::class_node* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::decl_stat* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::expression* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::expression_list* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::field_decl* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::field_node* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::formal_list* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::formal_node* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::literal* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::local_node* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::member_list* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::new_array_exp* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::op_exp* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::statement* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::statement_list* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::super_node* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::type_node* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const char v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const int v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::list<ast::expression*>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  calcxx_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  calcxx_parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  calcxx_parser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 91: // arrExpr
        value.template destroy< ast::array_ref* > ();
        break;

      case 63: // member
        value.template destroy< ast::ast_node* > ();
        break;

      case 59: // start
        value.template destroy< ast::class_list* > ();
        break;

      case 60: // class
        value.template destroy< ast::class_node* > ();
        break;

      case 75: // localDeclList
        value.template destroy< ast::decl_stat* > ();
        break;

      case 82: // expression
      case 85: // primary
      case 88: // dimension
      case 89: // nonNewArrExpr
      case 90: // fieldExpr
        value.template destroy< ast::expression* > ();
        break;

      case 93: // actualArgs
      case 94: // exprList
        value.template destroy< ast::expression_list* > ();
        break;

      case 72: // fieldDeclList
        value.template destroy< ast::field_decl* > ();
        break;

      case 73: // fieldDecl
      case 74: // fieldDeclId
        value.template destroy< ast::field_node* > ();
        break;

      case 66: // formalArgs
      case 67: // formalArgsList
        value.template destroy< ast::formal_list* > ();
        break;

      case 68: // formalArg
        value.template destroy< ast::formal_node* > ();
        break;

      case 92: // literal
        value.template destroy< ast::literal* > ();
        break;

      case 76: // localDecl
      case 77: // localDeclId
        value.template destroy< ast::local_node* > ();
        break;

      case 62: // memberList
        value.template destroy< ast::member_list* > ();
        break;

      case 86: // newArrExpr
        value.template destroy< ast::new_array_exp* > ();
        break;

      case 83: // binaryOp
      case 84: // unaryOp
        value.template destroy< ast::op_exp* > ();
        break;

      case 80: // statement
      case 81: // stmtNoIf
        value.template destroy< ast::statement* > ();
        break;

      case 78: // block
      case 79: // statementList
        value.template destroy< ast::statement_list* > ();
        break;

      case 61: // super
        value.template destroy< ast::super_node* > ();
        break;

      case 69: // type
      case 71: // primativeType
        value.template destroy< ast::type_node* > ();
        break;

      case 12: // CHARLITERAL
        value.template destroy< char > ();
        break;

      case 4: // "number"
      case 11: // INTLITERAL
      case 58: // unit
      case 64: // modifierList
      case 65: // modifier
      case 70: // brackets
        value.template destroy< int > ();
        break;

      case 87: // dimensionPlus
        value.template destroy< std::list<ast::expression*>* > ();
        break;

      case 3: // "identifier"
      case 5: // FORBIDDEN
      case 6: // RESERVED
      case 7: // FPRIMATIVE
      case 13: // STRLITERAL
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  calcxx_parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  calcxx_parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 91: // arrExpr
        value.move< ast::array_ref* > (s.value);
        break;

      case 63: // member
        value.move< ast::ast_node* > (s.value);
        break;

      case 59: // start
        value.move< ast::class_list* > (s.value);
        break;

      case 60: // class
        value.move< ast::class_node* > (s.value);
        break;

      case 75: // localDeclList
        value.move< ast::decl_stat* > (s.value);
        break;

      case 82: // expression
      case 85: // primary
      case 88: // dimension
      case 89: // nonNewArrExpr
      case 90: // fieldExpr
        value.move< ast::expression* > (s.value);
        break;

      case 93: // actualArgs
      case 94: // exprList
        value.move< ast::expression_list* > (s.value);
        break;

      case 72: // fieldDeclList
        value.move< ast::field_decl* > (s.value);
        break;

      case 73: // fieldDecl
      case 74: // fieldDeclId
        value.move< ast::field_node* > (s.value);
        break;

      case 66: // formalArgs
      case 67: // formalArgsList
        value.move< ast::formal_list* > (s.value);
        break;

      case 68: // formalArg
        value.move< ast::formal_node* > (s.value);
        break;

      case 92: // literal
        value.move< ast::literal* > (s.value);
        break;

      case 76: // localDecl
      case 77: // localDeclId
        value.move< ast::local_node* > (s.value);
        break;

      case 62: // memberList
        value.move< ast::member_list* > (s.value);
        break;

      case 86: // newArrExpr
        value.move< ast::new_array_exp* > (s.value);
        break;

      case 83: // binaryOp
      case 84: // unaryOp
        value.move< ast::op_exp* > (s.value);
        break;

      case 80: // statement
      case 81: // stmtNoIf
        value.move< ast::statement* > (s.value);
        break;

      case 78: // block
      case 79: // statementList
        value.move< ast::statement_list* > (s.value);
        break;

      case 61: // super
        value.move< ast::super_node* > (s.value);
        break;

      case 69: // type
      case 71: // primativeType
        value.move< ast::type_node* > (s.value);
        break;

      case 12: // CHARLITERAL
        value.move< char > (s.value);
        break;

      case 4: // "number"
      case 11: // INTLITERAL
      case 58: // unit
      case 64: // modifierList
      case 65: // modifier
      case 70: // brackets
        value.move< int > (s.value);
        break;

      case 87: // dimensionPlus
        value.move< std::list<ast::expression*>* > (s.value);
        break;

      case 3: // "identifier"
      case 5: // FORBIDDEN
      case 6: // RESERVED
      case 7: // FPRIMATIVE
      case 13: // STRLITERAL
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  calcxx_parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  calcxx_parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  calcxx_parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  calcxx_parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  calcxx_parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  calcxx_parser::by_type::type_get () const
  {
    return type;
  }

  inline
  calcxx_parser::token_type
  calcxx_parser::by_type::token () const
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short int
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }
  // Implementation of make_symbol for each symbol type.
  calcxx_parser::symbol_type
  calcxx_parser::make_END (const location_type& l)
  {
    return symbol_type (token::TOK_END, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_IDENTIFIER (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_IDENTIFIER, v, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_NUMBER (const int& v, const location_type& l)
  {
    return symbol_type (token::TOK_NUMBER, v, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_FORBIDDEN (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_FORBIDDEN, v, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_RESERVED (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_RESERVED, v, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_FPRIMATIVE (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_FPRIMATIVE, v, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_NUL (const location_type& l)
  {
    return symbol_type (token::TOK_NUL, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_TRUE (const location_type& l)
  {
    return symbol_type (token::TOK_TRUE, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_FALSE (const location_type& l)
  {
    return symbol_type (token::TOK_FALSE, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_INTLITERAL (const int& v, const location_type& l)
  {
    return symbol_type (token::TOK_INTLITERAL, v, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_CHARLITERAL (const char& v, const location_type& l)
  {
    return symbol_type (token::TOK_CHARLITERAL, v, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_STRLITERAL (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_STRLITERAL, v, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_INTTYPE (const location_type& l)
  {
    return symbol_type (token::TOK_INTTYPE, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_CHARTYPE (const location_type& l)
  {
    return symbol_type (token::TOK_CHARTYPE, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_BOOLTYPE (const location_type& l)
  {
    return symbol_type (token::TOK_BOOLTYPE, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_VOIDTYPE (const location_type& l)
  {
    return symbol_type (token::TOK_VOIDTYPE, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_BREAK (const location_type& l)
  {
    return symbol_type (token::TOK_BREAK, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_IF (const location_type& l)
  {
    return symbol_type (token::TOK_IF, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_ELSE (const location_type& l)
  {
    return symbol_type (token::TOK_ELSE, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_CLASS (const location_type& l)
  {
    return symbol_type (token::TOK_CLASS, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_CONTINUE (const location_type& l)
  {
    return symbol_type (token::TOK_CONTINUE, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_EXTENDS (const location_type& l)
  {
    return symbol_type (token::TOK_EXTENDS, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_NEW (const location_type& l)
  {
    return symbol_type (token::TOK_NEW, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_PRIVATE (const location_type& l)
  {
    return symbol_type (token::TOK_PRIVATE, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_PROTECTED (const location_type& l)
  {
    return symbol_type (token::TOK_PROTECTED, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_PUBLIC (const location_type& l)
  {
    return symbol_type (token::TOK_PUBLIC, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_RETURN (const location_type& l)
  {
    return symbol_type (token::TOK_RETURN, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_STATIC (const location_type& l)
  {
    return symbol_type (token::TOK_STATIC, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_SUPER (const location_type& l)
  {
    return symbol_type (token::TOK_SUPER, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_THIS (const location_type& l)
  {
    return symbol_type (token::TOK_THIS, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_WHILE (const location_type& l)
  {
    return symbol_type (token::TOK_WHILE, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_LPAREN (const location_type& l)
  {
    return symbol_type (token::TOK_LPAREN, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_RPAREN (const location_type& l)
  {
    return symbol_type (token::TOK_RPAREN, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_LBRACKET (const location_type& l)
  {
    return symbol_type (token::TOK_LBRACKET, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_RBRACKET (const location_type& l)
  {
    return symbol_type (token::TOK_RBRACKET, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_LSQUARE (const location_type& l)
  {
    return symbol_type (token::TOK_LSQUARE, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_RSQUARE (const location_type& l)
  {
    return symbol_type (token::TOK_RSQUARE, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_SEMICOLON (const location_type& l)
  {
    return symbol_type (token::TOK_SEMICOLON, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_COMMA (const location_type& l)
  {
    return symbol_type (token::TOK_COMMA, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_PERIOD (const location_type& l)
  {
    return symbol_type (token::TOK_PERIOD, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_NOT (const location_type& l)
  {
    return symbol_type (token::TOK_NOT, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_MULT (const location_type& l)
  {
    return symbol_type (token::TOK_MULT, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_DIV (const location_type& l)
  {
    return symbol_type (token::TOK_DIV, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_MOD (const location_type& l)
  {
    return symbol_type (token::TOK_MOD, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_ADD (const location_type& l)
  {
    return symbol_type (token::TOK_ADD, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_SUB (const location_type& l)
  {
    return symbol_type (token::TOK_SUB, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_GR (const location_type& l)
  {
    return symbol_type (token::TOK_GR, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_LE (const location_type& l)
  {
    return symbol_type (token::TOK_LE, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_GEQ (const location_type& l)
  {
    return symbol_type (token::TOK_GEQ, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_LEQ (const location_type& l)
  {
    return symbol_type (token::TOK_LEQ, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_EQ (const location_type& l)
  {
    return symbol_type (token::TOK_EQ, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_NEQ (const location_type& l)
  {
    return symbol_type (token::TOK_NEQ, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_AND (const location_type& l)
  {
    return symbol_type (token::TOK_AND, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_OR (const location_type& l)
  {
    return symbol_type (token::TOK_OR, l);
  }

  calcxx_parser::symbol_type
  calcxx_parser::make_ASGN (const location_type& l)
  {
    return symbol_type (token::TOK_ASGN, l);
  }



} // yy
#line 2248 "parser.hh" // lalr1.cc:392




#endif // !YY_YY_PARSER_HH_INCLUDED
