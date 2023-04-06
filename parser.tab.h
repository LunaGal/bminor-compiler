/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_EOF = 258,
     TOKEN_ARRAY = 259,
     TOKEN_BOOLEAN = 260,
     TOKEN_CHAR = 261,
     TOKEN_ELSE = 262,
     TOKEN_FALSE = 263,
     TOKEN_FOR = 264,
     TOKEN_FUNCTION = 265,
     TOKEN_IF = 266,
     TOKEN_INTEGER = 267,
     TOKEN_PRINT = 268,
     TOKEN_RETURN = 269,
     TOKEN_STRING = 270,
     TOKEN_TRUE = 271,
     TOKEN_VOID = 272,
     TOKEN_WHILE = 273,
     TOKEN_ID = 274,
     TOKEN_INT_LTRL = 275,
     TOKEN_STR_LTRL = 276,
     TOKEN_COLON = 277,
     TOKEN_SEMI = 278,
     TOKEN_L_PAREN = 279,
     TOKEN_R_PAREN = 280,
     TOKEN_L_BRACE = 281,
     TOKEN_R_BRACE = 282,
     TOKEN_ASSIGN = 283,
     TOKEN_EQUIV = 284
   };
#endif
/* Tokens.  */
#define TOKEN_EOF 258
#define TOKEN_ARRAY 259
#define TOKEN_BOOLEAN 260
#define TOKEN_CHAR 261
#define TOKEN_ELSE 262
#define TOKEN_FALSE 263
#define TOKEN_FOR 264
#define TOKEN_FUNCTION 265
#define TOKEN_IF 266
#define TOKEN_INTEGER 267
#define TOKEN_PRINT 268
#define TOKEN_RETURN 269
#define TOKEN_STRING 270
#define TOKEN_TRUE 271
#define TOKEN_VOID 272
#define TOKEN_WHILE 273
#define TOKEN_ID 274
#define TOKEN_INT_LTRL 275
#define TOKEN_STR_LTRL 276
#define TOKEN_COLON 277
#define TOKEN_SEMI 278
#define TOKEN_L_PAREN 279
#define TOKEN_R_PAREN 280
#define TOKEN_L_BRACE 281
#define TOKEN_R_BRACE 282
#define TOKEN_ASSIGN 283
#define TOKEN_EQUIV 284




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

