%{
#include <string>
#include "Model/nodes.h"
#include <list>
using namespace std;

#include "redapple_parser.hpp"

#define SAVE_TOKEN     yylval.str = maketoken(yytext, yyleng)
#define SAVE_STRING    yylval.str = maketoken(yytext, yyleng)
#define SAVE_STRING_NC yylval.str = maketoken(yytext, yyleng)
extern "C" int yywrap() { return 1; }
char* maketoken(const char* data, int len);
%}

%option yylineno
%option reentrant noyywrap
%option bison-bridge bison-locations

%%

"/*"([^\*]|(\*)*[^\*/])*(\*)*"*/" ; /* 就是这种注释 */ 

#[^\n]*\n               ; /* 井号注释 */ 
"//"[^\n]*\n            ; /* 双线注释 */ 

[ \t\v\n\f]             ; /* 过滤空白字符 */

    /* 一些双元运算符 */
"++"                    return PP;
"--"                    return SS;
"<-"                    return LF;
"->"                    return RF;
"&&"                    return AND;
"||"                    return OR;
"!"                     return '!';
"::"                    return NSP;


"+="                    return PE;
"-="                    return SE;
"*="                    return ME;
"/="                    return DE;
"&="                    return AE;
"|="                    return OE;
"^="                    return XE;
"%="                    return MODE;
"<<="                   return FLE;
">>="                   return FRE;


    /* 比较运算符 */
"=="                    return CEQ;
"<="                    return CLE;
">="                    return CGE;
"!="                    return CNE;
"<"                     return '<';
">"                     return '>';


    /* 界符 */
"("                     return '(';
")"                     return ')';
"["                     return '[';
"]"                     return ']';
"{"                     return '{';
"}"                     return '}';
"."                     return '.';
","                     return ',';
"?"                     return '?';
":"                     return ':';
";"                     return ';';
"[]"                    return SZ;


    /* 基本运算符 */
"="                     return '=';
"+"                     return '+';
"-"                     return '-';
"*"                     return '*';
"/"                     return '/';
"%"                     return '%';
"^"                     return '^';
"&"                     return '&';
"|"                     return '|';
"~"                     return '~';

    /* 宏运算符 */
"@"                     return '@';
",@"                    return MBK;
"`"                     return '`';

[a-zA-Z_][a-zA-Z0-9_]*  SAVE_TOKEN; return ID; /* 标识符 */

-?[0-9]*\.[0-9]*        SAVE_TOKEN; return DOUBLE;
-?[0-9]+                SAVE_TOKEN; return INTEGER;
0x[0-9A-Fa-f]+          SAVE_TOKEN; return INTEGER;

\"(\\.|[^\\"])*\"       SAVE_STRING; return STRING; /* 字符串 */
@\"(\\.|[^\\"])*\"      SAVE_STRING_NC; return STRING; /* 无转义字符串 */
\'(\\.|.)\'             SAVE_STRING; return CHAR;   /* 字符 */

.                       printf("Unknown Token!\n"); yyterminate();

%%


char* maketoken(const char* data, int len) {
    char* str = new char[len+1];
    strncpy(str, data, len);
    str[len] = 0;
    return str;
}
