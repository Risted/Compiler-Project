/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tINTCONST = 258,
    tIDENTIFIER = 259,
    tEQUAL = 260,
    tEQUALTO = 261,
    tNEQUALTO = 262,
    tAND = 263,
    tPIPE = 264,
    tLPAREN = 265,
    tRPAREN = 266,
    tLBRACE = 267,
    tRBRACE = 268,
    tSMALLER = 269,
    tBIGGER = 270,
    tSMALEQUAL = 271,
    tBIGEQUAL = 272,
    tMOD = 273,
    tMULT = 274,
    tDIV = 275,
    tPLUS = 276,
    tSUB = 277,
    tRETURN = 278
  };
#endif
/* Tokens.  */
#define tINTCONST 258
#define tIDENTIFIER 259
#define tEQUAL 260
#define tEQUALTO 261
#define tNEQUALTO 262
#define tAND 263
#define tPIPE 264
#define tLPAREN 265
#define tRPAREN 266
#define tLBRACE 267
#define tRBRACE 268
#define tSMALLER 269
#define tBIGGER 270
#define tSMALEQUAL 271
#define tBIGEQUAL 272
#define tMOD 273
#define tMULT 274
#define tDIV 275
#define tPLUS 276
#define tSUB 277
#define tRETURN 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "exp.y" /* yacc.c:1909  */

   int intconst;
   char *stringconst;
   struct EXP* expression;
   struct STM* statement;

#line 107 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
