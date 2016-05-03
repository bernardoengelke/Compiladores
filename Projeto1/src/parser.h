/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    D_INT = 258,
    D_REAL = 259,
    D_BOOL = 260,
    T_VAR = 261,
    T_INT = 262,
    T_REAL = 263,
    T_TRUE = 264,
    T_FALSE = 265,
    T_PLUS = 266,
    T_SUB = 267,
    T_MULT = 268,
    T_DIV = 269,
    T_COMMA = 270,
    T_SEPARATOR = 271,
    T_ASSIGN = 272,
    T_EOFL = 273,
    T_EQUALS = 274,
    T_NEQUALS = 275,
    T_BIGGEST = 276,
    T_SMALLEST = 277,
    T_BIGOREQUALS = 278,
    T_SMALLOREQUALS = 279,
    T_AND = 280,
    T_OR = 281,
    T_NOT = 282,
    T_OPENP = 283,
    T_CLOSEP = 284
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 15 "parser.y" /* yacc.c:1909  */

    const char * string;
    int integer;
    float real;
    bool boolean;

    VAR::Node *node;
    VAR::Block *block;

#line 94 "parser.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
