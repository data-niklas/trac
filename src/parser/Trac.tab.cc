// A Bison parser, made by GNU Bison 3.7.3.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "Trac.tab.hh"


// Unqualified %code blocks.
#line 36 "Trac.yy"

   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   #include <string>
   #include <vector>

   using namespace std;
   
   #include "./TracReader.h"
   #include "./TracScanner.h" 

   #undef yylex
   #define yylex scanner.yylex

#line 62 "Trac.tab.cc"


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


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
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
    while (false)
# endif


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
      *yycdebug_ << '\n';                       \
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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 4 "Trac.yy"
namespace parser {
#line 155 "Trac.tab.cc"

  /// Build a parser object.
  TracParser::TracParser (TracScanner &scanner_yyarg, TracReader &reader_yyarg, TracResult &result_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      reader (reader_yyarg),
      result (result_yyarg)
  {}

  TracParser::~TracParser ()
  {}

  TracParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
  TracParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_call: // call
        value.copy< Call* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_trac: // trac
        value.copy< Trac* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable: // variable
        value.copy< shared_ptr<Variable> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_MALFORMED_STRING: // MALFORMED_STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_calls: // calls
        value.copy< vector<Call*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_vars: // vars
        value.copy< vector<shared_ptr<Variable>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_varnames: // varnames
        value.copy< vector<string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  TracParser::symbol_kind_type
  TracParser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  TracParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  TracParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_call: // call
        value.move< Call* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_trac: // trac
        value.move< Trac* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< long > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_variable: // variable
        value.move< shared_ptr<Variable> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_MALFORMED_STRING: // MALFORMED_STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_calls: // calls
        value.move< vector<Call*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_vars: // vars
        value.move< vector<shared_ptr<Variable>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_varnames: // varnames
        value.move< vector<string> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  TracParser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  TracParser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  TracParser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  TracParser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
  TracParser::by_kind::clear ()
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  TracParser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  TracParser::symbol_kind_type
  TracParser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  TracParser::symbol_kind_type
  TracParser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  // by_state.
  TracParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  TracParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  TracParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  TracParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  TracParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  TracParser::symbol_kind_type
  TracParser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  TracParser::stack_symbol_type::stack_symbol_type ()
  {}

  TracParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_call: // call
        value.YY_MOVE_OR_COPY< Call* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_trac: // trac
        value.YY_MOVE_OR_COPY< Trac* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.YY_MOVE_OR_COPY< long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable: // variable
        value.YY_MOVE_OR_COPY< shared_ptr<Variable> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_MALFORMED_STRING: // MALFORMED_STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_calls: // calls
        value.YY_MOVE_OR_COPY< vector<Call*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_vars: // vars
        value.YY_MOVE_OR_COPY< vector<shared_ptr<Variable>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_varnames: // varnames
        value.YY_MOVE_OR_COPY< vector<string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  TracParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_call: // call
        value.move< Call* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_trac: // trac
        value.move< Trac* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable: // variable
        value.move< shared_ptr<Variable> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_MALFORMED_STRING: // MALFORMED_STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_calls: // calls
        value.move< vector<Call*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_vars: // vars
        value.move< vector<shared_ptr<Variable>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_varnames: // varnames
        value.move< vector<string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  TracParser::stack_symbol_type&
  TracParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_call: // call
        value.copy< Call* > (that.value);
        break;

      case symbol_kind::S_trac: // trac
        value.copy< Trac* > (that.value);
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< long > (that.value);
        break;

      case symbol_kind::S_variable: // variable
        value.copy< shared_ptr<Variable> > (that.value);
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_MALFORMED_STRING: // MALFORMED_STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_calls: // calls
        value.copy< vector<Call*> > (that.value);
        break;

      case symbol_kind::S_vars: // vars
        value.copy< vector<shared_ptr<Variable>> > (that.value);
        break;

      case symbol_kind::S_varnames: // varnames
        value.copy< vector<string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  TracParser::stack_symbol_type&
  TracParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_call: // call
        value.move< Call* > (that.value);
        break;

      case symbol_kind::S_trac: // trac
        value.move< Trac* > (that.value);
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< long > (that.value);
        break;

      case symbol_kind::S_variable: // variable
        value.move< shared_ptr<Variable> > (that.value);
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_MALFORMED_STRING: // MALFORMED_STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_calls: // calls
        value.move< vector<Call*> > (that.value);
        break;

      case symbol_kind::S_vars: // vars
        value.move< vector<shared_ptr<Variable>> > (that.value);
        break;

      case symbol_kind::S_varnames: // varnames
        value.move< vector<string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  TracParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  TracParser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YYUSE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  TracParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  TracParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  TracParser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  TracParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  TracParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  TracParser::debug_level_type
  TracParser::debug_level () const
  {
    return yydebug_;
  }

  void
  TracParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  TracParser::state_type
  TracParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  TracParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  TracParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  TracParser::operator() ()
  {
    return parse ();
  }

  int
  TracParser::parse ()
  {
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

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

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
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_call: // call
        yylhs.value.emplace< Call* > ();
        break;

      case symbol_kind::S_trac: // trac
        yylhs.value.emplace< Trac* > ();
        break;

      case symbol_kind::S_BOOL: // BOOL
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        yylhs.value.emplace< long > ();
        break;

      case symbol_kind::S_variable: // variable
        yylhs.value.emplace< shared_ptr<Variable> > ();
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_MALFORMED_STRING: // MALFORMED_STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_calls: // calls
        yylhs.value.emplace< vector<Call*> > ();
        break;

      case symbol_kind::S_vars: // vars
        yylhs.value.emplace< vector<shared_ptr<Variable>> > ();
        break;

      case symbol_kind::S_varnames: // varnames
        yylhs.value.emplace< vector<string> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // tracs: %empty
#line 90 "Trac.yy"
           { }
#line 934 "Trac.tab.cc"
    break;

  case 3: // tracs: trac tracs
#line 91 "Trac.yy"
                { result.value.push_back(yystack_[1].value.as < Trac* > ()); }
#line 940 "Trac.tab.cc"
    break;

  case 4: // trac: IDENTIFIER LPAREN vars RPAREN COLON varnames QUESTION calls ACTION calls SEMICOLON
#line 95 "Trac.yy"
                                                                                        { yylhs.value.as < Trac* > () = new Trac(yystack_[10].value.as < std::string > (), yystack_[8].value.as < vector<shared_ptr<Variable>> > (), yystack_[5].value.as < vector<string> > (), yystack_[3].value.as < vector<Call*> > (), yystack_[1].value.as < vector<Call*> > ()); }
#line 946 "Trac.tab.cc"
    break;

  case 5: // calls: %empty
#line 100 "Trac.yy"
          { yylhs.value.as < vector<Call*> > () = vector<Call*>();}
#line 952 "Trac.tab.cc"
    break;

  case 6: // calls: call calls
#line 101 "Trac.yy"
                { yylhs.value.as < vector<Call*> > () = yystack_[0].value.as < vector<Call*> > (); yylhs.value.as < vector<Call*> > ().push_back(yystack_[1].value.as < Call* > ());}
#line 958 "Trac.tab.cc"
    break;

  case 7: // call: IDENTIFIER LPAREN vars RPAREN
#line 105 "Trac.yy"
                                   { yylhs.value.as < Call* > () = new Call(yystack_[3].value.as < std::string > (), yystack_[1].value.as < vector<shared_ptr<Variable>> > ());}
#line 964 "Trac.tab.cc"
    break;

  case 8: // varnames: %empty
#line 110 "Trac.yy"
          { yylhs.value.as < vector<string> > () = vector<string>();}
#line 970 "Trac.tab.cc"
    break;

  case 9: // varnames: IDENTIFIER varnames
#line 111 "Trac.yy"
                         { yylhs.value.as < vector<string> > () = yystack_[0].value.as < vector<string> > (); yylhs.value.as < vector<string> > ().push_back(yystack_[1].value.as < std::string > ());}
#line 976 "Trac.tab.cc"
    break;

  case 10: // vars: %empty
#line 115 "Trac.yy"
           { yylhs.value.as < vector<shared_ptr<Variable>> > () = vector<shared_ptr<Variable>>();}
#line 982 "Trac.tab.cc"
    break;

  case 11: // vars: variable vars
#line 116 "Trac.yy"
                   { yylhs.value.as < vector<shared_ptr<Variable>> > () = yystack_[0].value.as < vector<shared_ptr<Variable>> > (); yylhs.value.as < vector<shared_ptr<Variable>> > ().push_back(yystack_[1].value.as < shared_ptr<Variable> > ());}
#line 988 "Trac.tab.cc"
    break;

  case 12: // variable: STRING
#line 120 "Trac.yy"
                     { yylhs.value.as < shared_ptr<Variable> > () = shared_ptr<String>(new String(yystack_[0].value.as < std::string > ())); }
#line 994 "Trac.tab.cc"
    break;

  case 13: // variable: INTEGER
#line 121 "Trac.yy"
                          { yylhs.value.as < shared_ptr<Variable> > () = shared_ptr<Int>(new Int(yystack_[0].value.as < long > ())); }
#line 1000 "Trac.tab.cc"
    break;

  case 14: // variable: FLOAT
#line 122 "Trac.yy"
                          { std::cout << "float: " <<  yystack_[0].value.as < double > () << std::endl; }
#line 1006 "Trac.tab.cc"
    break;

  case 15: // variable: IDENTIFIER
#line 123 "Trac.yy"
                          { yylhs.value.as < shared_ptr<Variable> > () = shared_ptr<Ident>(new Ident(yystack_[0].value.as < std::string > ())); }
#line 1012 "Trac.tab.cc"
    break;

  case 16: // variable: BOOL
#line 124 "Trac.yy"
                          { yylhs.value.as < shared_ptr<Variable> > () = shared_ptr<Boolean>(new Boolean(yystack_[0].value.as < bool > ())); }
#line 1018 "Trac.tab.cc"
    break;

  case 17: // variable: VOID
#line 125 "Trac.yy"
                          { yylhs.value.as < shared_ptr<Variable> > () = shared_ptr<Void>(new Void()); }
#line 1024 "Trac.tab.cc"
    break;

  case 18: // variable: call
#line 126 "Trac.yy"
                     { yylhs.value.as < shared_ptr<Variable> > () = shared_ptr<Call>(yystack_[0].value.as < Call* > ());   }
#line 1030 "Trac.tab.cc"
    break;


#line 1034 "Trac.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
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
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
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
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  TracParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  TracParser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0





  const signed char TracParser::yypact_ninf_ = -22;

  const signed char TracParser::yytable_ninf_ = -1;

  const signed char
  TracParser::yypact_[] =
  {
      -4,     2,    15,    -4,    -3,   -22,   -22,   -22,     7,   -22,
     -22,   -22,   -22,   -22,     8,    -3,    -3,     6,   -22,     9,
      16,   -22,    16,    10,   -22,    18,     7,    11,    18,    18,
     -22,    12,   -22
  };

  const signed char
  TracParser::yydefact_[] =
  {
       2,     0,     0,     2,    10,     1,     3,    12,    15,    13,
      14,    16,    17,    18,     0,    10,    10,     0,    11,     0,
       8,     7,     8,     0,     9,     5,     0,     0,     5,     5,
       6,     0,     4
  };

  const signed char
  TracParser::yypgoto_[] =
  {
     -22,    17,   -22,   -21,   -19,     3,    -2,   -22
  };

  const signed char
  TracParser::yydefgoto_[] =
  {
      -1,     2,     3,    27,    13,    23,    14,    15
  };

  const signed char
  TracParser::yytable_[] =
  {
       7,     1,     8,     9,    10,    11,    28,    30,    31,    28,
      28,     4,    12,    18,    19,     5,    16,    20,    17,    21,
       6,    22,    25,    26,    29,    24,    32
  };

  const signed char
  TracParser::yycheck_[] =
  {
       3,     5,     5,     6,     7,     8,    25,    28,    29,    28,
      29,     9,    15,    15,    16,     0,     9,    11,    10,    10,
       3,     5,    12,     5,    13,    22,    14
  };

  const signed char
  TracParser::yystos_[] =
  {
       0,     5,    17,    18,     9,     0,    17,     3,     5,     6,
       7,     8,    15,    20,    22,    23,     9,    10,    22,    22,
      11,    10,     5,    21,    21,    12,     5,    19,    20,    13,
      19,    19,    14
  };

  const signed char
  TracParser::yyr1_[] =
  {
       0,    16,    17,    17,    18,    19,    19,    20,    21,    21,
      22,    22,    23,    23,    23,    23,    23,    23,    23
  };

  const signed char
  TracParser::yyr2_[] =
  {
       0,     2,     0,     2,    11,     0,     2,     4,     0,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const TracParser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "STRING",
  "MALFORMED_STRING", "IDENTIFIER", "INTEGER", "FLOAT", "BOOL", "LPAREN",
  "RPAREN", "COLON", "QUESTION", "ACTION", "SEMICOLON", "VOID", "$accept",
  "tracs", "trac", "calls", "call", "varnames", "vars", "variable", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const signed char
  TracParser::yyrline_[] =
  {
       0,    90,    90,    91,    95,   100,   101,   105,   110,   111,
     115,   116,   120,   121,   122,   123,   124,   125,   126
  };

  void
  TracParser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  TracParser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  TracParser::symbol_kind_type
  TracParser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
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
      15
    };
    // Last valid token kind.
    const int code_max = 270;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 4 "Trac.yy"
} // parser
#line 1397 "Trac.tab.cc"

#line 131 "Trac.yy"


void 
parser::TracParser::error(const parser::TracParser::location_type &l, const std::string &err_message) {
   std::cout << "Parsing Error: " << err_message << " at " << l << "\n";
}
