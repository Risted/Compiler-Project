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
    tTYPEINTEGER = 258,
    tTYPESTRING = 259,
    tINTCONST = 260,
    tIDENTIFIER = 261,
    tASSIGN = 262,
    tEQUALTO = 263,
    tNEQUALTO = 264,
    tAND = 265,
    tPIPE = 266,
    tLPAREN = 267,
    tRPAREN = 268,
    tLBRACE = 269,
    tRBRACE = 270,
    tSMALLER = 271,
    tBIGGER = 272,
    tSMALEQUAL = 273,
    tBIGEQUAL = 274,
    tMOD = 275,
    tMULT = 276,
    tDIV = 277,
    tPLUS = 278,
    tSUB = 279,
    tSEMI = 280,
    tCOLON = 281,
    tRETURN = 282,
    tWRITE = 283,
    tALLOCATE = 284,
    tOF = 285,
    tLENGTH = 286,
    tIF = 287,
    tTHEN = 288,
    tELSE = 289,
    tWHILE = 290,
    tDO = 291,
    tNOT = 292,
    tTRUE = 293,
    tFALSE = 294,
    tNULL = 295
  };
#endif
/* Tokens.  */
#define tTYPEINTEGER 258
#define tTYPESTRING 259
#define tINTCONST 260
#define tIDENTIFIER 261
#define tASSIGN 262
#define tEQUALTO 263
#define tNEQUALTO 264
#define tAND 265
#define tPIPE 266
#define tLPAREN 267
#define tRPAREN 268
#define tLBRACE 269
#define tRBRACE 270
#define tSMALLER 271
#define tBIGGER 272
#define tSMALEQUAL 273
#define tBIGEQUAL 274
#define tMOD 275
#define tMULT 276
#define tDIV 277
#define tPLUS 278
#define tSUB 279
#define tSEMI 280
#define tCOLON 281
#define tRETURN 282
#define tWRITE 283
#define tALLOCATE 284
#define tOF 285
#define tLENGTH 286
#define tIF 287
#define tTHEN 288
#define tELSE 289
#define tWHILE 290
#define tDO 291
#define tNOT 292
#define tTRUE 293
#define tFALSE 294
#define tNULL 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "exp.y" /* yacc.c:1909  */

   int intconst;
   char *stringconst;
   struct EXP* expression;
   struct STM* statement;
   struct DEC* declaration;
   struct TERM* term;
   struct TYPE* type;

#line 144 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
