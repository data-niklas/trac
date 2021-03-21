%skeleton "lalr1.cc"
%require  "3.0"
%defines 
%define api.namespace {parser}
%define api.parser.class {TracParser}


%code requires{
   
   #include <memory>
   #include "../variables/literal.h" 
   #include "../variables/ident.h"   
   #include "../variables/call.h"   
   #include "../trac.h"  
   #include "./TracResult.h"
   namespace parser {
      class TracScanner;
      class TracReader;
   }

// The following definitions is missing when "%locations" isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

}

%parse-param { TracScanner &scanner }
%parse-param { TracReader &reader }
%parse-param { TracResult &result }

%code{
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
}

%define api.value.type variant
%define parse.assert

// ### ADD TOKEN DEFINITIONS HERE ###

// Example ---------------------------------------------------------------------

%token               END    0     "end of file"
%token <std::string> STRING
%token <std::string> MALFORMED_STRING
%token <std::string> IDENTIFIER
%token <long> INTEGER
%token <double> FLOAT
%token <bool> BOOL
%token LPAREN
%token RPAREN
%token COLON
%token QUESTION
%token ACTION
%token SEMICOLON
%token VOID


%type <shared_ptr<Variable>> variable
%type <vector<shared_ptr<Variable>>> vars
%type <vector<string>> varnames
%type <vector<Call*>> calls
%type <Call*> call
%type <Trac*> trac

// -----------------------------------------------------------------------------


%locations

%%

tracs
   : /* */ { }
   | trac tracs { result.value.push_back($1); }
   ;

trac
   : IDENTIFIER LPAREN vars RPAREN COLON varnames QUESTION calls ACTION calls SEMICOLON { $$ = new Trac($1, $3, $6, $8, $10); }
   ;


calls
   :/* */ { $$ = vector<Call*>();}
   | call calls { $$ = $2; $$.push_back($1);}
   ;

call
   : IDENTIFIER LPAREN vars RPAREN { $$ = new Call($1, $3);}
   ;


varnames
   :/* */ { $$ = vector<string>();}
   | IDENTIFIER varnames { $$ = $2; $$.push_back($1);}
   ;

vars
   : /* */ { $$ = vector<shared_ptr<Variable>>();}
   | variable vars { $$ = $2; $$.push_back($1);}
   ;
	
variable
   : STRING          { $$ = shared_ptr<String>(new String($1)); }
	| INTEGER         { $$ = shared_ptr<Int>(new Int($1)); }
	| FLOAT           { std::cout << "float: " <<  $1 << std::endl; }
	| IDENTIFIER      { $$ = shared_ptr<Ident>(new Ident($1)); }
	| BOOL            { $$ = shared_ptr<Boolean>(new Boolean($1)); }
	| VOID            { $$ = shared_ptr<Void>(new Void()); }
   | call            { $$ = shared_ptr<Call>($1);   }
	;

// -----------------------------------------------------------------------------  
   
%%

void 
parser::TracParser::error(const parser::TracParser::location_type &l, const std::string &err_message) {
   std::cout << "Parsing Error: " << err_message << " at " << l << "\n";
}
