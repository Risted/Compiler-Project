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
    tINT = 260,
    tID = 261,
    tBOOL = 262,
    tARRAY = 263,
    tRECORD = 264,
    tEND = 265,
    tDOT = 266,
    tTYPE = 267,
    tVAR = 268,
    tFUNC = 269,
    tASSIGN = 270,
    tEQUALTO = 271,
    tNEQUALTO = 272,
    tAND = 273,
    tPIPE = 274,
    tLPAREN = 275,
    tRPAREN = 276,
    tLBRACE = 277,
    tRBRACE = 278,
    tLSQUARE = 279,
    tRSQUARE = 280,
    tSMALLER = 281,
    tBIGGER = 282,
    tSMALEQUAL = 283,
    tBIGEQUAL = 284,
    tMOD = 285,
    tMULT = 286,
    tDIV = 287,
    tPLUS = 288,
    tSUB = 289,
    tSEMI = 290,
    tCOLON = 291,
    tRETURN = 292,
    tWRITE = 293,
    tALLOCATE = 294,
    tOF = 295,
    tLENGTH = 296,
    tIF = 297,
    tTHEN = 298,
    tELSE = 299,
    tWHILE = 300,
    tDO = 301,
    tNOT = 302,
    tTRUE = 303,
    tFALSE = 304,
    tNULL = 305,
    tCOMMA = 306
  };
#endif
/* Tokens.  */
#define tTYPEINTEGER 258
#define tTYPESTRING 259
#define tINT 260
#define tID 261
#define tBOOL 262
#define tARRAY 263
#define tRECORD 264
#define tEND 265
#define tDOT 266
#define tTYPE 267
#define tVAR 268
#define tFUNC 269
#define tASSIGN 270
#define tEQUALTO 271
#define tNEQUALTO 272
#define tAND 273
#define tPIPE 274
#define tLPAREN 275
#define tRPAREN 276
#define tLBRACE 277
#define tRBRACE 278
#define tLSQUARE 279
#define tRSQUARE 280
#define tSMALLER 281
#define tBIGGER 282
#define tSMALEQUAL 283
#define tBIGEQUAL 284
#define tMOD 285
#define tMULT 286
#define tDIV 287
#define tPLUS 288
#define tSUB 289
#define tSEMI 290
#define tCOLON 291
#define tRETURN 292
#define tWRITE 293
#define tALLOCATE 294
#define tOF 295
#define tLENGTH 296
#define tIF 297
#define tTHEN 298
#define tELSE 299
#define tWHILE 300
#define tDO 301
#define tNOT 302
#define tTRUE 303
#define tFALSE 304
#define tNULL 305
#define tCOMMA 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "exp.y" /* yacc.c:1909  */

   int intconst;
   char *stringconst;
   struct EXP* expression;
   struct STM* statement;
   struct DEC* declaration;
   struct TERM* term;
   struct TYPE* type;
   struct LIST* list;
   struct FUNC* function;

#line 168 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
