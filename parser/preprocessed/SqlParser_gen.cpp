/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         quickstep_yyparse
#define yylex           quickstep_yylex
#define yyerror         quickstep_yyerror
#define yydebug         quickstep_yydebug
#define yynerrs         quickstep_yynerrs


/* Copy the first part of user declarations.  */
#line 35 "../SqlParser.ypp" /* yacc.c:339  */


/* Override the default definition, as we only need <first_line> and <first_column>. */
typedef struct YYLTYPE {
  int first_line;
  int first_column;
} YYLTYPE;

#define YYLTYPE_IS_DECLARED 1

/*
 * Modified from the default YYLLOC_DEFAULT
 * (http://www.gnu.org/software/bison/manual/html_node/Location-Default-Action.html).
 * The assignments for last_line and last_column are removed as they are not used.
 */
#define YYLLOC_DEFAULT(current, rhs, n)                         \
  do {                                                          \
    if (n) {                                                    \
      (current).first_line   = YYRHSLOC(rhs, 1).first_line;     \
      (current).first_column = YYRHSLOC(rhs, 1).first_column;   \
    } else {                                                    \
      /* empty RHS */                                           \
      (current).first_line = YYRHSLOC(rhs, 0).first_line;       \
      (current).first_column = YYRHSLOC(rhs, 0).first_column;   \
    }                                                           \
  } while (0)

#line 64 "../SqlParser.ypp" /* yacc.c:339  */

#include <cstdlib>
#include <string>
#include <utility>

#include "catalog/PartitionSchemeHeader.hpp"
#include "parser/ParseAssignment.hpp"
#include "parser/ParseAttributeDefinition.hpp"
#include "parser/ParseBasicExpressions.hpp"
#include "parser/ParseBlockProperties.hpp"
#include "parser/ParseCaseExpressions.hpp"
#include "parser/ParseExpression.hpp"
#include "parser/ParseGeneratorTableReference.hpp"
#include "parser/ParseGroupBy.hpp"
#include "parser/ParseHaving.hpp"
#include "parser/ParseJoinedTableReference.hpp"
#include "parser/ParseKeyValue.hpp"
#include "parser/ParseLimit.hpp"
#include "parser/ParseLiteralValue.hpp"
#include "parser/ParseOrderBy.hpp"
#include "parser/ParsePartitionClause.hpp"
#include "parser/ParsePredicate.hpp"
#include "parser/ParsePredicateExists.hpp"
#include "parser/ParsePredicateInTableQuery.hpp"
#include "parser/ParsePriority.hpp"
#include "parser/ParserUtil.hpp"
#include "parser/ParseSample.hpp"
#include "parser/ParseSelect.hpp"
#include "parser/ParseSelectionClause.hpp"
#include "parser/ParseSetOperation.hpp"
#include "parser/ParseSimpleTableReference.hpp"
#include "parser/ParseStatement.hpp"
#include "parser/ParseString.hpp"
#include "parser/ParseSubqueryExpression.hpp"
#include "parser/ParseSubqueryTableReference.hpp"
#include "parser/ParseTableReference.hpp"
#include "parser/ParseWindow.hpp"
#include "storage/StorageBlockInfo.hpp"
#include "types/Type.hpp"
#include "types/TypeFactory.hpp"
#include "types/TypeID.hpp"
#include "types/operations/comparisons/Comparison.hpp"
#include "types/operations/comparisons/ComparisonFactory.hpp"
#include "types/operations/comparisons/ComparisonID.hpp"
#include "utility/PtrList.hpp"
#include "utility/PtrVector.hpp"

// Needed for Bison 2.6 and higher, which do not automatically provide this typedef.
typedef void* yyscan_t;

#line 151 "SqlParser_gen.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "SqlParser_gen.hpp".  */
#ifndef YY_QUICKSTEP_YY_SQLPARSER_GEN_HPP_INCLUDED
# define YY_QUICKSTEP_YY_SQLPARSER_GEN_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int quickstep_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOKEN_COMMAND = 258,
    TOKEN_NAME = 259,
    TOKEN_STRING_SINGLE_QUOTED = 260,
    TOKEN_STRING_DOUBLE_QUOTED = 261,
    TOKEN_UNSIGNED_NUMVAL = 262,
    TOKEN_OR = 263,
    TOKEN_AND = 264,
    TOKEN_NOT = 265,
    TOKEN_EQ = 266,
    TOKEN_LT = 267,
    TOKEN_LEQ = 268,
    TOKEN_GT = 269,
    TOKEN_GEQ = 270,
    TOKEN_NEQ = 271,
    TOKEN_LIKE = 272,
    TOKEN_REGEXP = 273,
    TOKEN_BETWEEN = 274,
    TOKEN_IS = 275,
    UNARY_PLUS = 276,
    UNARY_MINUS = 277,
    TOKEN_ALL = 278,
    TOKEN_UNION = 279,
    TOKEN_INTERSECT = 280,
    TOKEN_ADD = 281,
    TOKEN_ALTER = 282,
    TOKEN_AS = 283,
    TOKEN_ASC = 284,
    TOKEN_BIGINT = 285,
    TOKEN_BIT = 286,
    TOKEN_BITWEAVING = 287,
    TOKEN_BLOCKPROPERTIES = 288,
    TOKEN_BLOCKSAMPLE = 289,
    TOKEN_BLOOM_FILTER = 290,
    TOKEN_CSB_TREE = 291,
    TOKEN_BY = 292,
    TOKEN_CASE = 293,
    TOKEN_CAST = 294,
    TOKEN_CHARACTER = 295,
    TOKEN_CHECK = 296,
    TOKEN_COLUMN = 297,
    TOKEN_CONSTRAINT = 298,
    TOKEN_COPY = 299,
    TOKEN_CREATE = 300,
    TOKEN_CURRENT = 301,
    TOKEN_DATE = 302,
    TOKEN_DATETIME = 303,
    TOKEN_DAY = 304,
    TOKEN_DECIMAL = 305,
    TOKEN_DEFAULT = 306,
    TOKEN_DELETE = 307,
    TOKEN_DELIMITER = 308,
    TOKEN_DESC = 309,
    TOKEN_DISTINCT = 310,
    TOKEN_DOUBLE = 311,
    TOKEN_DROP = 312,
    TOKEN_ELSE = 313,
    TOKEN_END = 314,
    TOKEN_ESCAPE_STRINGS = 315,
    TOKEN_EXISTS = 316,
    TOKEN_EXTRACT = 317,
    TOKEN_FALSE = 318,
    TOKEN_FIRST = 319,
    TOKEN_FLOAT = 320,
    TOKEN_FOLLOWING = 321,
    TOKEN_FOR = 322,
    TOKEN_FOREIGN = 323,
    TOKEN_FROM = 324,
    TOKEN_FULL = 325,
    TOKEN_GROUP = 326,
    TOKEN_HASH = 327,
    TOKEN_HAVING = 328,
    TOKEN_HOUR = 329,
    TOKEN_IN = 330,
    TOKEN_INDEX = 331,
    TOKEN_INNER = 332,
    TOKEN_INSERT = 333,
    TOKEN_INTEGER = 334,
    TOKEN_INTERVAL = 335,
    TOKEN_INTO = 336,
    TOKEN_JOIN = 337,
    TOKEN_KEY = 338,
    TOKEN_LAST = 339,
    TOKEN_LEFT = 340,
    TOKEN_LIMIT = 341,
    TOKEN_LONG = 342,
    TOKEN_MINUTE = 343,
    TOKEN_MONTH = 344,
    TOKEN_NULL = 345,
    TOKEN_NULLS = 346,
    TOKEN_OFF = 347,
    TOKEN_ON = 348,
    TOKEN_ORDER = 349,
    TOKEN_OUTER = 350,
    TOKEN_OVER = 351,
    TOKEN_PARTITION = 352,
    TOKEN_PARTITIONS = 353,
    TOKEN_PERCENT = 354,
    TOKEN_PRECEDING = 355,
    TOKEN_PRIMARY = 356,
    TOKEN_PRIORITY = 357,
    TOKEN_QUIT = 358,
    TOKEN_RANGE = 359,
    TOKEN_REAL = 360,
    TOKEN_REFERENCES = 361,
    TOKEN_RIGHT = 362,
    TOKEN_ROW = 363,
    TOKEN_ROW_DELIMITER = 364,
    TOKEN_ROWS = 365,
    TOKEN_SECOND = 366,
    TOKEN_SELECT = 367,
    TOKEN_SET = 368,
    TOKEN_SMA = 369,
    TOKEN_SMALLINT = 370,
    TOKEN_SUBSTRING = 371,
    TOKEN_TABLE = 372,
    TOKEN_THEN = 373,
    TOKEN_TIME = 374,
    TOKEN_TIMESTAMP = 375,
    TOKEN_TRUE = 376,
    TOKEN_TUPLESAMPLE = 377,
    TOKEN_UNBOUNDED = 378,
    TOKEN_UNIQUE = 379,
    TOKEN_UPDATE = 380,
    TOKEN_USING = 381,
    TOKEN_VALUES = 382,
    TOKEN_VARCHAR = 383,
    TOKEN_WHEN = 384,
    TOKEN_WHERE = 385,
    TOKEN_WINDOW = 386,
    TOKEN_WITH = 387,
    TOKEN_YEAR = 388,
    TOKEN_YEARMONTH = 389,
    TOKEN_EOF = 390,
    TOKEN_LEX_ERROR = 391
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 115 "../SqlParser.ypp" /* yacc.c:355  */

  quickstep::ParseString *string_value_;

  quickstep::PtrList<quickstep::ParseString> *string_list_;

  bool boolean_value_;

  quickstep::NumericParseLiteralValue *numeric_literal_value_;
  quickstep::ParseLiteralValue *literal_value_;
  quickstep::PtrList<quickstep::ParseScalarLiteral> *literal_value_list_;

  quickstep::ParseExpression *expression_;

  quickstep::ParseScalarLiteral *scalar_literal_;
  quickstep::ParseAttribute *attribute_;
  quickstep::PtrList<quickstep::ParseAttribute> *attribute_list_;

  quickstep::ParsePredicate *predicate_;

  quickstep::ParseSubqueryExpression *subquery_expression_;

  quickstep::PtrVector<quickstep::ParseSimpleWhenClause> *simple_when_clause_list_;
  quickstep::ParseSimpleWhenClause *simple_when_clause_;

  quickstep::PtrVector<quickstep::ParseSearchedWhenClause> *searched_when_clause_list_;
  quickstep::ParseSearchedWhenClause *searched_when_clause_;

  quickstep::ParseSelectionClause *selection_;
  quickstep::ParseSelectionItem *selection_item_;
  quickstep::ParseSelectionList *selection_list_;

  quickstep::ParseSetOperation *set_operation_;

  quickstep::ParseTableReference *table_reference_;
  quickstep::PtrList<quickstep::ParseTableReference> *table_reference_list_;
  quickstep::ParseTableReferenceSignature *table_reference_signature_;

  quickstep::ParseJoinedTableReference::JoinType join_type_;

  quickstep::ParseDataType *data_type_;
  quickstep::ParseAttributeDefinition *attribute_definition_;
  quickstep::ParseColumnConstraint *column_constraint_;
  quickstep::PtrList<quickstep::ParseColumnConstraint> *column_constraint_list_;
  quickstep::PtrList<quickstep::ParseAttributeDefinition> *attribute_definition_list_;

  quickstep::ParseKeyValue *key_value_;
  quickstep::PtrList<quickstep::ParseKeyValue> *key_value_list_;
  quickstep::ParseKeyStringValue *key_string_value_;
  quickstep::ParseKeyStringList *key_string_list_;
  quickstep::ParseKeyIntegerValue *key_integer_value_;

  quickstep::ParseCopyFromParams *copy_from_params_;

  quickstep::ParseAssignment *assignment_;
  quickstep::PtrList<quickstep::ParseAssignment> *assignment_list_;

  quickstep::ParseCommand *command_;
  quickstep::PtrVector<quickstep::ParseString> *command_argument_list_;

  quickstep::ParseStatement *statement_;
  quickstep::ParseStatementSetOperation *set_operation_statement_;
  quickstep::ParseStatementUpdate *update_statement_;
  quickstep::ParseStatementInsert *insert_statement_;
  quickstep::ParseStatementDelete *delete_statement_;
  quickstep::ParseStatementCopyFrom *copy_from_statement_;
  quickstep::ParseStatementCreateTable *create_table_statement_;
  quickstep::ParsePartitionClause *partition_clause_;
  quickstep::ParseBlockProperties *block_properties_;
  quickstep::ParseStatementDropTable *drop_table_statement_;
  quickstep::ParseStatementQuit *quit_statement_;

  const quickstep::Comparison *comparison_;
  quickstep::ParseString *unary_operation_;
  quickstep::ParseString *binary_operation_;

  quickstep::ParseFunctionCall *function_call_;
  quickstep::PtrList<quickstep::ParseExpression> *expression_list_;

  quickstep::ParseSelect *select_query_;
  quickstep::ParseGroupBy *opt_group_by_clause_;
  quickstep::ParseHaving *opt_having_clause_;
  quickstep::ParseOrderBy *opt_order_by_clause_;
  bool *order_direction_;
  quickstep::ParseLimit *opt_limit_clause_;

  quickstep::ParseSample *opt_sample_clause_;

  quickstep::PtrList<quickstep::ParseWindow> *opt_window_clause_;
  quickstep::ParseWindow *window_definition_;
  quickstep::PtrList<quickstep::ParseExpression> *window_partition_by_list_;
  quickstep::PtrList<quickstep::ParseOrderByItem> *window_order_by_list_;
  quickstep::ParseFrameInfo *window_frame_info_;

  quickstep::PtrList<quickstep::ParseOrderByItem> *order_commalist_;
  quickstep::ParseOrderByItem *order_item_;

  quickstep::PtrVector<quickstep::ParseSubqueryTableReference> *with_list_;
  quickstep::ParseSubqueryTableReference *with_list_element_;

  quickstep::ParsePriority *opt_priority_clause_;

#line 430 "SqlParser_gen.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int quickstep_yyparse (yyscan_t yyscanner, quickstep::ParseStatement **parsedStatement);

#endif /* !YY_QUICKSTEP_YY_SQLPARSER_GEN_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 217 "../SqlParser.ypp" /* yacc.c:358  */

/* This header needs YYSTYPE, which is defined by the %union directive above */
#include "SqlLexer_gen.hpp"
void NotSupported(const YYLTYPE *location, yyscan_t yyscanner, const std::string &feature);

#line 465 "SqlParser_gen.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
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


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1432

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  148
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  110
/* YYNRULES -- Number of rules.  */
#define YYNRULES  296
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  552

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   391

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     143,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   147,     2,     2,
     144,   145,    23,    21,   146,    22,    27,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   142,
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
      15,    16,    17,    18,    19,    20,    25,    26,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   633,   633,   637,   641,   645,   649,   652,   659,   662,
     665,   668,   671,   674,   677,   680,   683,   686,   692,   698,
     705,   711,   718,   727,   732,   741,   746,   751,   755,   761,
     766,   769,   772,   777,   780,   783,   786,   789,   792,   795,
     798,   801,   804,   816,   819,   822,   840,   860,   863,   866,
     871,   876,   882,   888,   897,   901,   907,   910,   915,   920,
     925,   932,   939,   943,   949,   952,   957,   960,   965,   968,
     973,   976,   995,   998,  1003,  1007,  1013,  1016,  1019,  1024,
    1027,  1034,  1039,  1050,  1055,  1059,  1063,  1069,  1072,  1078,
    1086,  1089,  1092,  1098,  1103,  1106,  1111,  1115,  1119,  1123,
    1129,  1134,  1139,  1143,  1149,  1158,  1161,  1166,  1169,  1188,
    1193,  1197,  1203,  1209,  1218,  1223,  1231,  1237,  1243,  1246,
    1249,  1254,  1257,  1262,  1266,  1272,  1275,  1278,  1283,  1288,
    1293,  1296,  1299,  1304,  1307,  1310,  1313,  1316,  1319,  1322,
    1325,  1330,  1333,  1338,  1342,  1346,  1349,  1353,  1356,  1361,
    1364,  1369,  1372,  1377,  1381,  1387,  1390,  1395,  1398,  1403,
    1406,  1411,  1414,  1433,  1436,  1441,  1445,  1451,  1457,  1462,
    1465,  1470,  1473,  1478,  1481,  1486,  1489,  1494,  1495,  1498,
    1503,  1504,  1507,  1512,  1516,  1522,  1529,  1532,  1535,  1540,
    1543,  1546,  1552,  1555,  1560,  1565,  1574,  1579,  1588,  1593,
    1596,  1601,  1604,  1609,  1615,  1621,  1624,  1627,  1630,  1633,
    1636,  1642,  1651,  1657,  1662,  1668,  1673,  1678,  1683,  1686,
    1689,  1692,  1696,  1700,  1703,  1706,  1709,  1712,  1715,  1720,
    1724,  1728,  1731,  1736,  1750,  1761,  1772,  1780,  1791,  1794,
    1799,  1803,  1809,  1814,  1818,  1824,  1829,  1832,  1837,  1841,
    1847,  1850,  1853,  1856,  1868,  1872,  1891,  1904,  1919,  1922,
    1925,  1928,  1931,  1934,  1939,  1943,  1949,  1952,  1957,  1961,
    1968,  1971,  1974,  1977,  1980,  1983,  1986,  1989,  1992,  1995,
    2000,  2011,  2014,  2019,  2022,  2025,  2031,  2035,  2041,  2044,
    2052,  2055,  2058,  2061,  2067,  2072,  2077
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_COMMAND", "TOKEN_NAME",
  "TOKEN_STRING_SINGLE_QUOTED", "TOKEN_STRING_DOUBLE_QUOTED",
  "TOKEN_UNSIGNED_NUMVAL", "TOKEN_OR", "TOKEN_AND", "TOKEN_NOT",
  "TOKEN_EQ", "TOKEN_LT", "TOKEN_LEQ", "TOKEN_GT", "TOKEN_GEQ",
  "TOKEN_NEQ", "TOKEN_LIKE", "TOKEN_REGEXP", "TOKEN_BETWEEN", "TOKEN_IS",
  "'+'", "'-'", "'*'", "'/'", "UNARY_PLUS", "UNARY_MINUS", "'.'",
  "TOKEN_ALL", "TOKEN_UNION", "TOKEN_INTERSECT", "TOKEN_ADD",
  "TOKEN_ALTER", "TOKEN_AS", "TOKEN_ASC", "TOKEN_BIGINT", "TOKEN_BIT",
  "TOKEN_BITWEAVING", "TOKEN_BLOCKPROPERTIES", "TOKEN_BLOCKSAMPLE",
  "TOKEN_BLOOM_FILTER", "TOKEN_CSB_TREE", "TOKEN_BY", "TOKEN_CASE",
  "TOKEN_CAST", "TOKEN_CHARACTER", "TOKEN_CHECK", "TOKEN_COLUMN",
  "TOKEN_CONSTRAINT", "TOKEN_COPY", "TOKEN_CREATE", "TOKEN_CURRENT",
  "TOKEN_DATE", "TOKEN_DATETIME", "TOKEN_DAY", "TOKEN_DECIMAL",
  "TOKEN_DEFAULT", "TOKEN_DELETE", "TOKEN_DELIMITER", "TOKEN_DESC",
  "TOKEN_DISTINCT", "TOKEN_DOUBLE", "TOKEN_DROP", "TOKEN_ELSE",
  "TOKEN_END", "TOKEN_ESCAPE_STRINGS", "TOKEN_EXISTS", "TOKEN_EXTRACT",
  "TOKEN_FALSE", "TOKEN_FIRST", "TOKEN_FLOAT", "TOKEN_FOLLOWING",
  "TOKEN_FOR", "TOKEN_FOREIGN", "TOKEN_FROM", "TOKEN_FULL", "TOKEN_GROUP",
  "TOKEN_HASH", "TOKEN_HAVING", "TOKEN_HOUR", "TOKEN_IN", "TOKEN_INDEX",
  "TOKEN_INNER", "TOKEN_INSERT", "TOKEN_INTEGER", "TOKEN_INTERVAL",
  "TOKEN_INTO", "TOKEN_JOIN", "TOKEN_KEY", "TOKEN_LAST", "TOKEN_LEFT",
  "TOKEN_LIMIT", "TOKEN_LONG", "TOKEN_MINUTE", "TOKEN_MONTH", "TOKEN_NULL",
  "TOKEN_NULLS", "TOKEN_OFF", "TOKEN_ON", "TOKEN_ORDER", "TOKEN_OUTER",
  "TOKEN_OVER", "TOKEN_PARTITION", "TOKEN_PARTITIONS", "TOKEN_PERCENT",
  "TOKEN_PRECEDING", "TOKEN_PRIMARY", "TOKEN_PRIORITY", "TOKEN_QUIT",
  "TOKEN_RANGE", "TOKEN_REAL", "TOKEN_REFERENCES", "TOKEN_RIGHT",
  "TOKEN_ROW", "TOKEN_ROW_DELIMITER", "TOKEN_ROWS", "TOKEN_SECOND",
  "TOKEN_SELECT", "TOKEN_SET", "TOKEN_SMA", "TOKEN_SMALLINT",
  "TOKEN_SUBSTRING", "TOKEN_TABLE", "TOKEN_THEN", "TOKEN_TIME",
  "TOKEN_TIMESTAMP", "TOKEN_TRUE", "TOKEN_TUPLESAMPLE", "TOKEN_UNBOUNDED",
  "TOKEN_UNIQUE", "TOKEN_UPDATE", "TOKEN_USING", "TOKEN_VALUES",
  "TOKEN_VARCHAR", "TOKEN_WHEN", "TOKEN_WHERE", "TOKEN_WINDOW",
  "TOKEN_WITH", "TOKEN_YEAR", "TOKEN_YEARMONTH", "TOKEN_EOF",
  "TOKEN_LEX_ERROR", "';'", "'\\n'", "'('", "')'", "','", "'%'", "$accept",
  "start", "sql_statement", "quit_statement", "alter_table_statement",
  "create_table_statement", "create_index_statement",
  "drop_table_statement", "column_def", "column_def_commalist",
  "data_type", "column_constraint_def", "column_constraint_def_list",
  "opt_column_constraint_def_list", "table_constraint_def",
  "table_constraint_def_commalist", "opt_table_constraint_def_commalist",
  "opt_column_list", "opt_block_properties", "opt_partition_clause",
  "partition_type", "key_value_list", "key_value", "key_string_value",
  "key_string_list", "key_integer_value", "index_type",
  "opt_index_properties", "insert_statement", "copy_from_statement",
  "opt_copy_from_params", "copy_from_params", "update_statement",
  "delete_statement", "assignment_list", "assignment_item",
  "set_operation_statement", "opt_priority_clause", "with_clause",
  "with_list", "with_list_element", "set_operation_union",
  "set_operation_intersect", "select_query", "opt_all_distinct",
  "selection", "selection_item_commalist", "selection_item", "from_clause",
  "subquery_expression", "opt_sample_clause", "join_type",
  "joined_table_reference", "table_reference", "table_reference_signature",
  "table_reference_signature_primary", "joined_table_reference_commalist",
  "opt_group_by_clause", "opt_having_clause", "opt_order_by_clause",
  "opt_limit_clause", "opt_window_clause", "window_declaration_list",
  "window_declaration", "window_definition", "opt_window_partition",
  "opt_window_order", "opt_window_frame", "frame_mode", "frame_preceding",
  "frame_following", "order_commalist", "order_item",
  "opt_order_direction", "opt_nulls_first", "opt_where_clause",
  "where_clause", "or_expression", "and_expression", "not_expression",
  "predicate_expression_base", "add_expression", "multiply_expression",
  "unary_expression", "expression_base", "function_call", "cast_function",
  "extract_function", "substr_function", "case_expression",
  "simple_when_clause_list", "simple_when_clause",
  "searched_when_clause_list", "searched_when_clause", "opt_else_clause",
  "expression_list", "literal_value", "datetime_unit",
  "literal_value_commalist", "attribute_ref", "attribute_ref_list",
  "comparison_operation", "unary_operation", "add_operation",
  "multiply_operation", "name_commalist", "any_name", "boolean_value",
  "command", "command_argument_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    43,    45,    42,    47,   276,   277,    46,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,    59,    10,    40,    41,    44,    37
};
# endif

#define YYPACT_NINF -253

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-253)))

#define YYTABLE_NINF -134

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      86,  -253,  -253,   -32,   242,   -40,    45,    69,    96,  -253,
      42,   242,   242,  -253,   132,   139,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,   -26,     9,   191,  -253,
     131,   224,   242,  -253,  -253,   168,   242,   242,   242,   242,
     242,  -253,  -253,   723,   144,   111,  -253,   240,   136,  -253,
    -253,  -253,   190,     9,    42,   177,  -253,   170,  -253,  -253,
    -253,    41,   285,   205,   163,   179,  -253,    75,  -253,  -253,
     310,   312,  -253,  -253,  -253,   816,   181,   188,  -253,   236,
    -253,  -253,   192,  -253,  -253,   361,  -253,  -253,  -253,  -253,
     225,  -253,  -253,   234,   297,   909,   379,   316,   252,  -253,
    -253,   289,     6,  -253,  -253,   302,  -253,  -253,  -253,  -253,
    -253,  -253,  1095,   -13,   242,   242,   260,   242,   242,  -253,
     170,   398,  -253,    46,   153,   269,   242,   242,   630,  -253,
    -253,   264,   242,  -253,  -253,  -253,   630,    24,    -7,  -253,
    1188,   402,  -253,   145,   145,  1188,   404,  -253,    -3,    27,
    -253,    17,   179,  1188,  -253,  -253,   242,  1188,  -253,  -253,
    -253,  -253,  1188,    21,   312,  -253,   242,   412,   -50,  -253,
     401,  -253,   170,  -253,    60,  -253,   170,   191,  -253,   242,
     162,   242,   242,   270,  -253,   271,  -253,    65,  1293,  1002,
     260,   537,   405,   411,  -253,  -253,   498,   403,  1241,   156,
      34,  1188,     3,  -253,  1188,  -253,   357,    62,   277,  -253,
    -253,  -253,  -253,  -253,  -253,   350,  -253,    32,   280,  -253,
    -253,    16,    82,   138,  -253,   281,    82,    39,   352,  -253,
    -253,     6,  -253,   327,  -253,  -253,   286,  1188,  -253,   284,
     167,   242,  -253,  1188,  -253,   242,  -253,  -253,   288,   348,
     351,   294,  -253,  -253,  -253,    15,   242,   309,   162,   242,
    -253,   134,  -253,  -253,     4,   346,   630,   630,   214,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  1188,   298,  1188,
      89,  -253,   182,   311,  1188,    47,  -253,   377,   284,  -253,
     263,  -253,  1188,   437,  -253,   -11,   242,  -253,  -253,   345,
    -253,   349,   354,   363,    17,  -253,   444,   445,    82,   416,
     381,   418,   317,   362,  -253,   184,  -253,  1188,  -253,   284,
    -253,   630,   319,   322,   242,   463,   146,   194,  -253,   196,
     443,    68,  -253,   325,   337,  -253,   380,   332,  1241,  -253,
     392,   242,  -253,  -253,   134,  -253,  -253,   411,  -253,  -253,
    -253,  1188,   339,   176,   909,  -253,   284,   386,  -253,  -253,
    1241,   340,   284,  1188,  -253,   341,   342,    29,   -29,  -253,
    -253,  -253,  -253,  -253,    17,   138,   384,   388,  -253,  1188,
     630,   391,  1188,  -253,   451,    87,  -253,   284,     5,   242,
     242,   198,  -253,  -253,  -253,  -253,  -253,  -253,  -253,   212,
    -253,   242,  -253,  -253,  -253,  -253,   355,   162,   447,   393,
    -253,   630,  -253,  -253,   356,  -253,   244,   909,  -253,  1188,
     200,  -253,  -253,  1241,   284,  -253,  -253,  -253,   487,  -253,
     400,  -253,  -253,   359,   405,   460,   427,   359,  1188,  -253,
    -253,  -253,   502,  -253,   204,   207,  -253,   518,   146,  -253,
     242,  -253,  -253,   383,   482,  -253,    23,   242,  1188,   226,
     284,  -253,   229,   385,   630,  1188,   521,   389,   394,  -253,
     275,    10,   420,  -253,  -253,  -253,   231,  -253,  -253,  -253,
    -253,    12,   242,   127,  -253,   390,   284,  -253,  -253,  -253,
     405,   394,  -253,   242,  -253,   389,  -253,  1188,  -253,  -253,
     433,   434,   425,   441,   539,   242,  -253,   242,  -253,  -253,
     242,  -253,   235,  -253,  -253,   406,  -253,   516,  -253,  -253,
     -14,  -253,  -253,  -253,  -253,    53,   408,  -253,   247,  -253,
     242,   409,  -253,  -253,   483,   442,   489,  -253,   242,  -253,
     249,   327,  -253,  -253,  -253,   255,   458,   417,  -253,   556,
    -253,  -253
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     6,   296,     0,     0,     0,     0,     0,     0,    18,
     118,     0,     0,     7,     0,     0,    15,     8,    10,    11,
      13,    14,     9,    17,    12,    16,     0,   107,   114,   116,
       0,   294,     0,   288,   289,     0,     0,     0,     0,     0,
       0,   119,   120,     0,     0,   109,   110,     0,   151,     1,
       3,     2,     0,   107,   118,     0,   105,     0,     5,     4,
     295,     0,     0,     0,     0,   192,    25,     0,   254,   251,
       0,   280,   121,    40,    29,     0,     0,     0,    30,    31,
      34,    36,     0,    37,    39,     0,    41,   250,    35,    38,
       0,    32,    33,     0,     0,     0,     0,     0,   122,   123,
     228,   127,   213,   215,   217,   220,   223,   224,   225,   226,
     219,   218,     0,   266,     0,     0,     0,     0,     0,   106,
       0,     0,   115,     0,     0,    94,     0,     0,     0,   101,
     193,     0,     0,    91,   252,   253,     0,     0,   246,   243,
       0,     0,    43,     0,   255,     0,     0,    44,     0,     0,
     257,     0,   192,     0,   281,   282,     0,     0,   126,   284,
     285,   283,     0,     0,     0,   216,     0,     0,   192,   103,
       0,   111,     0,   112,     0,   286,     0,   113,   108,     0,
       0,     0,     0,     0,    93,    66,    27,     0,     0,     0,
       0,     0,   194,   196,   198,   200,     0,   218,     0,     0,
       0,     0,   246,   240,     0,   244,     0,     0,     0,   260,
     261,   262,   259,   263,   258,     0,   256,     0,     0,   129,
     227,     0,     0,   153,   142,   128,   147,   130,   155,   124,
     125,   212,   214,   169,   221,   267,     0,     0,   229,   248,
       0,     0,   100,     0,   152,     0,    92,    19,     0,     0,
       0,     0,    20,    21,    22,     0,     0,     0,    64,     0,
      42,    56,   199,   207,     0,     0,     0,     0,     0,   270,
     272,   273,   274,   275,   271,   276,   278,     0,     0,     0,
       0,   264,     0,     0,     0,     0,   241,     0,   247,   239,
       0,    45,     0,     0,    46,   133,     0,   143,   149,   139,
     134,   135,   137,     0,     0,   146,     0,     0,   145,     0,
     157,     0,     0,   171,   230,     0,   231,     0,   102,   104,
     287,     0,     0,     0,     0,     0,     0,     0,   268,     0,
     266,     0,    63,    65,    68,    28,     0,     0,     0,    47,
       0,     0,    49,    55,    57,    26,   206,   195,   197,   277,
     279,     0,     0,     0,     0,   208,   205,     0,   204,    90,
       0,     0,   245,     0,   238,     0,     0,     0,     0,   148,
     150,   140,   136,   138,     0,   154,     0,     0,   144,     0,
       0,   159,     0,   222,     0,   173,   232,   249,     0,     0,
       0,     0,    96,   292,   293,   291,   290,    97,    95,     0,
      67,     0,    83,    84,    85,    86,    87,     0,     0,    70,
      48,     0,    51,    50,     0,    54,     0,     0,   210,     0,
       0,   203,   265,     0,   242,   233,   234,   235,     0,   236,
       0,   131,   132,   156,   158,     0,   161,   170,     0,   176,
     175,   168,     0,    61,     0,     0,    58,     0,     0,   269,
       0,    24,    62,     0,     0,    23,     0,     0,     0,     0,
     201,   209,     0,     0,     0,     0,     0,   163,   172,   183,
     186,     0,     0,    59,    98,    99,     0,    74,    76,    77,
      78,     0,     0,     0,    52,     0,   202,   211,    89,   237,
     141,   160,   162,     0,   117,   164,   165,     0,   187,   188,
     189,     0,     0,     0,     0,     0,    88,     0,    82,    80,
       0,    79,     0,    72,    73,     0,    53,     0,   166,   184,
       0,   185,   177,   179,   178,     0,     0,    75,     0,    69,
       0,     0,   190,   191,     0,     0,     0,   174,     0,    81,
       0,   169,   180,   182,   181,     0,     0,     0,    60,     0,
     167,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -135,  -253,
    -111,   220,  -253,  -253,  -252,  -253,  -253,  -253,  -253,  -253,
    -253,    83,    59,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,   326,  -253,   515,  -253,  -253,
     454,    74,   450,    -5,   517,  -253,  -253,   421,  -253,   -92,
    -253,  -253,  -184,   201,  -187,    -8,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,    81,    36,  -253,  -253,  -253,  -253,  -253,
    -253,   114,    88,  -253,  -253,   -76,  -253,  -133,   318,   320,
     397,   -28,   426,   429,   476,  -140,  -253,  -253,  -253,  -253,
    -253,   395,  -253,   455,   399,  -228,  -193,   452,   171,  -126,
    -253,  -253,  -253,  -253,  -253,  -131,    -4,   147,  -253,  -253
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    18,    19,    20,   186,   187,
      96,   343,   344,   345,   252,   333,   334,   257,   409,   455,
     515,   476,   477,   478,   479,   480,   406,   451,    21,    22,
     184,   327,    23,    24,   168,   169,    25,    56,    26,    45,
      46,   148,    28,    29,    43,    97,    98,    99,   152,   100,
     308,   303,   223,   224,   297,   298,   225,   310,   381,   436,
     467,   494,   495,   496,   312,   313,   385,   441,   442,   504,
     537,   468,   469,   500,   521,   129,   130,   192,   193,   194,
     195,   196,   102,   103,   104,   105,   106,   107,   108,   109,
     202,   203,   138,   139,   206,   240,   110,   215,   282,   111,
     329,   279,   112,   157,   162,   174,   113,   397,    30,    31
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,   199,   197,   200,    47,   281,   332,    44,    48,   315,
     197,   226,   266,   266,   166,   101,    33,   501,    34,   508,
      33,    33,    34,    34,   173,    33,    54,    34,    61,   159,
     160,   266,    63,    64,    65,    66,    67,   295,    54,   305,
     509,    36,   266,   428,   247,   154,   155,   137,   154,   155,
     154,   155,   122,   154,   155,   532,   204,    52,   264,   222,
     534,   502,   133,   197,   299,   197,   204,   149,   154,   155,
      41,   300,   123,   325,    27,   533,   228,   261,   306,   301,
     326,   226,    37,   154,   155,   128,    33,     1,    34,     2,
      32,    10,   242,   179,   180,   290,   241,   158,   263,   357,
      53,   302,    42,   124,   535,   402,   293,    47,   403,   404,
     170,    48,   207,   175,   176,   296,   429,   217,     3,    38,
     375,   378,   185,   188,   335,   101,   420,   136,   175,   222,
     328,   167,    49,    10,   369,     4,     5,   201,   503,   239,
     197,   197,   219,     6,   336,   412,    55,   227,     7,   346,
     443,   433,   230,   161,   437,   452,   510,   284,   201,   234,
     221,   221,   235,   265,   226,   233,   307,   422,   484,     8,
     363,   246,   220,   285,   427,   188,   288,   253,   254,   365,
     337,   536,    40,   167,   358,   419,   355,   405,   388,   459,
     338,    39,    10,   391,     9,   197,   439,   154,   155,   209,
     181,   182,   440,    10,   513,   244,   245,   131,   248,   239,
     258,   259,   222,   299,   393,   319,    11,   227,    48,   132,
     300,    57,    48,    12,   210,  -133,    13,    60,   301,   339,
     281,   349,   350,   351,   226,   249,   514,   170,   211,   212,
     340,   320,    62,   394,   395,   341,    33,   434,    34,   353,
     302,   356,   330,   458,   197,   188,   362,   115,   444,   445,
     418,   213,   114,   342,   367,   154,   155,    33,   250,    34,
     447,    58,   396,   116,    59,   449,   118,   448,   456,    50,
     117,    51,   222,   214,   121,   197,   366,    10,   370,   387,
     125,   251,    48,    33,   352,    34,   154,   155,    73,    74,
     227,   283,   245,   126,    48,   154,   155,   127,    77,   498,
     154,   155,   316,   317,   128,    78,    79,   134,    80,   135,
     175,   142,   156,   416,    81,   140,   239,   359,   360,   386,
     317,   490,   141,    83,   499,   424,   143,   414,   197,   398,
     399,   400,   401,   446,   245,   461,   317,    84,   260,   472,
     245,   239,   473,   245,   239,    86,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   144,   154,   155,   145,
     227,   487,   317,    88,   488,   360,   506,   507,   146,   528,
     529,   507,   147,    89,   150,   175,   175,    91,    92,   239,
     151,   460,   539,   245,   546,   245,    93,   330,   153,   540,
     548,   245,    94,   163,   172,   178,   183,   545,   198,   208,
     470,   218,   243,   266,   255,   256,    33,    68,    34,    69,
     267,   289,   291,   280,   292,   294,   278,   304,   309,   311,
     486,   314,   321,    70,    71,   236,   322,   470,   324,   323,
     331,   364,   354,   361,   368,   371,   481,    73,    74,   372,
     374,   376,   377,   485,   373,    75,    76,    77,   379,   380,
     382,   384,   383,   389,    78,    79,   390,    80,   392,   470,
     166,   407,   237,    81,   408,   410,   411,   511,   481,    82,
     413,   421,    83,   417,   423,   453,   425,   426,   431,   517,
     435,   220,   432,   438,   463,   454,    84,    85,   464,   450,
     457,   526,   465,   481,    86,   317,   175,    87,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   466,   154,
     155,   471,    88,   474,   483,   493,   175,   482,   492,   520,
     489,   505,    89,    90,   175,   516,    91,    92,   523,   522,
     497,    33,    68,    34,    69,    93,   524,   189,   525,   531,
     530,    94,   538,   541,   542,   543,    95,   238,    70,    71,
     544,   549,   550,   551,   415,   512,   527,   318,   119,   171,
     177,   120,    73,    74,   229,   430,   518,   547,   278,   491,
      75,    76,    77,   231,   347,   519,   262,   348,   165,    78,
      79,   232,    80,   205,   462,   475,   216,   286,    81,     0,
       0,   287,     0,   190,    82,     0,     0,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,    85,     0,     0,     0,     0,     0,     0,    86,
       0,     0,    87,     0,    33,    68,    34,    69,     0,     0,
     189,     0,     0,     0,     0,     0,     0,    88,     0,     0,
       0,    70,    71,     0,    10,     0,     0,    89,    90,     0,
       0,    91,    92,     0,     0,    73,    74,     0,     0,     0,
      93,     0,     0,    75,    76,    77,    94,     0,     0,     0,
       0,   191,    78,    79,     0,    80,     0,     0,     0,     0,
       0,    81,     0,     0,     0,     0,   190,    82,     0,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    85,     0,     0,     0,     0,
       0,     0,    86,     0,     0,    87,     0,    33,    68,    34,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,     0,     0,     0,    70,    71,    72,     0,     0,     0,
      89,    90,     0,     0,    91,    92,     0,     0,    73,    74,
       0,     0,     0,    93,     0,     0,    75,    76,    77,    94,
       0,     0,     0,     0,   191,    78,    79,     0,    80,     0,
       0,     0,     0,     0,    81,     0,     0,     0,     0,     0,
      82,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    85,     0,
       0,     0,     0,     0,     0,    86,     0,     0,    87,     0,
      33,    68,    34,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,     0,     0,     0,    70,    71,     0,
       0,     0,     0,    89,    90,     0,     0,    91,    92,     0,
       0,    73,    74,     0,     0,     0,    93,     0,     0,    75,
      76,    77,    94,     0,     0,     0,     0,    95,    78,    79,
       0,    80,     0,     0,     0,     0,     0,    81,     0,     0,
       0,     0,     0,    82,     0,     0,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    85,     0,     0,     0,     0,     0,     0,    86,     0,
       0,    87,     0,    33,    68,    34,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,     0,     0,     0,
      70,    71,     0,     0,     0,     0,    89,    90,     0,     0,
      91,    92,     0,     0,    73,    74,     0,     0,     0,    93,
     136,     0,    75,    76,    77,    94,     0,     0,     0,     0,
      95,    78,    79,     0,    80,     0,     0,     0,     0,     0,
      81,     0,     0,     0,     0,     0,    82,     0,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,    85,     0,     0,     0,     0,     0,
       0,    86,     0,     0,    87,     0,    33,    68,    34,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
       0,     0,     0,    70,    71,     0,    10,     0,     0,    89,
      90,     0,     0,    91,    92,     0,     0,    73,    74,     0,
       0,     0,    93,     0,     0,    75,    76,    77,    94,     0,
       0,     0,     0,    95,    78,    79,     0,    80,     0,     0,
       0,     0,     0,    81,     0,     0,     0,     0,   190,    82,
       0,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    85,     0,     0,
       0,     0,     0,     0,    86,     0,     0,    87,     0,    33,
      68,    34,    69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    88,     0,     0,     0,    70,   164,     0,     0,
       0,     0,    89,    90,     0,     0,    91,    92,     0,     0,
      73,    74,     0,     0,     0,    93,     0,     0,    75,    76,
      77,    94,     0,     0,     0,     0,   191,    78,    79,     0,
      80,     0,     0,     0,     0,     0,    81,     0,     0,     0,
       0,     0,    82,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
      85,     0,     0,     0,     0,     0,     0,    86,     0,     0,
      87,     0,    33,    68,    34,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,     0,     0,     0,    70,
      71,     0,     0,     0,     0,    89,    90,     0,     0,    91,
      92,     0,     0,    73,    74,     0,     0,     0,    93,     0,
       0,    75,    76,    77,    94,     0,     0,     0,     0,    95,
      78,    79,     0,    80,     0,     0,    68,     0,    69,    81,
       0,     0,     0,     0,     0,    82,     0,     0,    83,     0,
       0,     0,    70,   164,     0,     0,     0,     0,     0,     0,
       0,     0,    84,    85,     0,     0,    73,    74,     0,     0,
      86,     0,     0,    87,     0,     0,    77,     0,     0,     0,
       0,     0,     0,    78,    79,     0,    80,     0,    88,     0,
       0,     0,    81,     0,     0,     0,     0,     0,    89,    90,
       0,    83,    91,    92,     0,     0,     0,     0,     0,     0,
       0,    93,     0,     0,     0,    84,    85,    94,    73,    74,
       0,     0,    95,    86,     0,     0,    87,     0,    77,     0,
       0,     0,     0,     0,     0,    78,    79,     0,    80,     0,
       0,    88,     0,     0,    81,     0,     0,     0,     0,     0,
       0,    89,     0,    83,     0,    91,    92,     0,     0,     0,
       0,     0,     0,     0,    93,     0,     0,    84,   260,     0,
      94,     0,     0,     0,     0,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,     0,     0,     0,    91,    92,     0,
       0,     0,     0,     0,     0,     0,    93,     0,     0,     0,
       0,     0,    94
};

static const yytype_int16 yycheck[] =
{
       4,   132,   128,   136,    12,   198,   258,    11,    12,   237,
     136,   151,     8,     8,    27,    43,     4,     7,     6,     7,
       4,     4,     6,     6,   116,     4,    29,     6,    32,    23,
      24,     8,    36,    37,    38,    39,    40,   221,    29,   226,
      28,    81,     8,    72,   179,    21,    22,    75,    21,    22,
      21,    22,    57,    21,    22,    69,    63,    83,   191,   151,
       7,    51,    67,   189,    75,   191,    63,    95,    21,    22,
      28,    82,    31,    58,     0,    89,   152,   188,    39,    90,
      65,   221,   122,    21,    22,   135,     4,     1,     6,     3,
     122,   117,   168,    47,    48,    33,   146,   101,   190,    10,
      26,   112,    60,    62,    51,    37,    74,   115,    40,    41,
     114,   115,   140,   117,   118,    33,   145,   145,    32,    74,
     304,   308,   126,   127,   259,   153,   354,   134,   132,   221,
     256,   144,     0,   117,   145,    49,    50,   134,   128,   167,
     266,   267,   145,    57,    10,   338,   137,   151,    62,   145,
     145,   379,   156,   147,   382,   407,   144,   123,   134,   163,
     144,   144,   166,   191,   304,   144,   127,   360,   145,    83,
     123,   176,   145,   201,   145,   179,   204,   181,   182,   290,
      46,   128,    86,   144,    95,     9,   278,   119,   321,   417,
      56,   122,   117,   324,   108,   321,   109,    21,    22,    54,
      47,    48,   115,   117,    77,   145,   146,   132,    46,   237,
     145,   146,   304,    75,    68,   243,   130,   221,   222,   144,
      82,    30,   226,   137,    79,    87,   140,     3,    90,    95,
     423,    17,    18,    19,   374,    73,   109,   241,    93,    94,
     106,   245,    74,    97,    98,   111,     4,   380,     6,   277,
     112,   279,   256,     9,   380,   259,   284,   146,   389,   390,
     352,   116,   118,   129,   292,    21,    22,     4,   106,     6,
      58,   140,   126,    33,   143,   401,    86,    65,   411,   140,
     144,   142,   374,   138,   107,   411,   290,   117,   296,   317,
       5,   129,   296,     4,    80,     6,    21,    22,    35,    36,
     304,   145,   146,    98,   308,    21,    22,   144,    45,    34,
      21,    22,   145,   146,   135,    52,    53,     7,    55,     7,
     324,    85,    33,   351,    61,   144,   354,   145,   146,   145,
     146,   464,   144,    70,    59,   363,   144,   341,   464,   145,
     146,   145,   146,   145,   146,   145,   146,    84,    85,   145,
     146,   379,   145,   146,   382,    92,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,     5,    21,    22,   144,
     374,   145,   146,   110,   145,   146,   145,   146,   144,   510,
     145,   146,    85,   120,     5,   389,   390,   124,   125,   417,
      74,   419,   145,   146,   145,   146,   133,   401,   146,   530,
     145,   146,   139,   101,   144,     7,   137,   538,   144,     7,
     438,     7,    11,     8,   144,   144,     4,     5,     6,     7,
       9,    64,   145,    20,    74,   145,    80,   146,    76,   102,
     458,   145,   144,    21,    22,    23,    88,   465,   144,    88,
     131,    64,   144,   132,     7,   100,   450,    35,    36,   100,
      87,     7,     7,   457,   100,    43,    44,    45,    42,    78,
      42,    99,   145,   144,    52,    53,   144,    55,     5,   497,
      27,   146,    60,    61,   137,    95,   144,   481,   482,    67,
      88,    95,    70,   144,   144,    38,   145,   145,   104,   493,
      99,   145,   104,    42,     7,   102,    84,    85,    98,   144,
     144,   505,    42,   507,    92,   146,   510,    95,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    91,    21,
      22,    19,   110,     5,    42,   136,   530,   144,     7,    96,
     145,   111,   120,   121,   538,   145,   124,   125,   113,   105,
     146,     4,     5,     6,     7,   133,   105,    10,     9,    33,
     144,   139,   144,   144,    71,   113,   144,   145,    21,    22,
      71,   103,   145,     7,   344,   482,   507,   241,    53,   115,
     120,    54,    35,    36,   153,   374,   495,   541,    80,   465,
      43,    44,    45,   157,   266,   497,   189,   267,   112,    52,
      53,   162,    55,   138,   423,   448,   144,   202,    61,    -1,
      -1,   202,    -1,    66,    67,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    95,    -1,     4,     5,     6,     7,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,
      -1,    21,    22,    -1,   117,    -1,    -1,   120,   121,    -1,
      -1,   124,   125,    -1,    -1,    35,    36,    -1,    -1,    -1,
     133,    -1,    -1,    43,    44,    45,   139,    -1,    -1,    -1,
      -1,   144,    52,    53,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    95,    -1,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,    -1,
     120,   121,    -1,    -1,   124,   125,    -1,    -1,    35,    36,
      -1,    -1,    -1,   133,    -1,    -1,    43,    44,    45,   139,
      -1,    -1,    -1,    -1,   144,    52,    53,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,    -1,    -1,    -1,    21,    22,    -1,
      -1,    -1,    -1,   120,   121,    -1,    -1,   124,   125,    -1,
      -1,    35,    36,    -1,    -1,    -1,   133,    -1,    -1,    43,
      44,    45,   139,    -1,    -1,    -1,    -1,   144,    52,    53,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    95,    -1,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,   120,   121,    -1,    -1,
     124,   125,    -1,    -1,    35,    36,    -1,    -1,    -1,   133,
     134,    -1,    43,    44,    45,   139,    -1,    -1,    -1,    -1,
     144,    52,    53,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    95,    -1,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
      -1,    -1,    -1,    21,    22,    -1,   117,    -1,    -1,   120,
     121,    -1,    -1,   124,   125,    -1,    -1,    35,    36,    -1,
      -1,    -1,   133,    -1,    -1,    43,    44,    45,   139,    -1,
      -1,    -1,    -1,   144,    52,    53,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    66,    67,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,    -1,    -1,    -1,    21,    22,    -1,    -1,
      -1,    -1,   120,   121,    -1,    -1,   124,   125,    -1,    -1,
      35,    36,    -1,    -1,    -1,   133,    -1,    -1,    43,    44,
      45,   139,    -1,    -1,    -1,    -1,   144,    52,    53,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      95,    -1,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    21,
      22,    -1,    -1,    -1,    -1,   120,   121,    -1,    -1,   124,
     125,    -1,    -1,    35,    36,    -1,    -1,    -1,   133,    -1,
      -1,    43,    44,    45,   139,    -1,    -1,    -1,    -1,   144,
      52,    53,    -1,    55,    -1,    -1,     5,    -1,     7,    61,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,
      -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    -1,    -1,    35,    36,    -1,    -1,
      92,    -1,    -1,    95,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    53,    -1,    55,    -1,   110,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,   120,   121,
      -1,    70,   124,   125,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   133,    -1,    -1,    -1,    84,    85,   139,    35,    36,
      -1,    -1,   144,    92,    -1,    -1,    95,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    -1,    55,    -1,
      -1,   110,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,    70,    -1,   124,   125,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    84,    85,    -1,
     139,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,   124,   125,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,   139
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,     3,    32,    49,    50,    57,    62,    83,   108,
     117,   130,   137,   140,   149,   150,   151,   152,   153,   154,
     155,   176,   177,   180,   181,   184,   186,   189,   190,   191,
     256,   257,   122,     4,     6,   254,    81,   122,    74,   122,
      86,    28,    60,   192,   254,   187,   188,   203,   254,     0,
     140,   142,    83,   189,    29,   137,   185,    30,   140,   143,
       3,   254,    74,   254,   254,   254,   254,   254,     5,     7,
      21,    22,    23,    35,    36,    43,    44,    45,    52,    53,
      55,    61,    67,    70,    84,    85,    92,    95,   110,   120,
     121,   124,   125,   133,   139,   144,   158,   193,   194,   195,
     197,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     244,   247,   250,   254,   118,   146,    33,   144,    86,   185,
     192,   107,   191,    31,    62,     5,    98,   144,   135,   223,
     224,   132,   144,   191,     7,     7,   134,   229,   240,   241,
     144,   144,    85,   144,     5,   144,   144,    85,   189,   229,
       5,    74,   196,   146,    21,    22,    33,   251,   254,    23,
      24,   147,   252,   101,    22,   232,    27,   144,   182,   183,
     254,   188,   144,   197,   253,   254,   254,   190,     7,    47,
      48,    47,    48,   137,   178,   254,   156,   157,   254,    10,
      66,   144,   225,   226,   227,   228,   229,   247,   144,   253,
     225,   134,   238,   239,    63,   241,   242,   229,     7,    54,
      79,    93,    94,   116,   138,   245,   245,   229,     7,   145,
     145,   144,   197,   200,   201,   204,   233,   254,   223,   195,
     254,   230,   231,   144,   254,   254,    23,    60,   145,   229,
     243,   146,   223,    11,   145,   146,   191,   156,    46,    73,
     106,   129,   162,   254,   254,   144,   144,   165,   145,   146,
      85,   158,   228,   197,   225,   229,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    80,   249,
      20,   244,   246,   145,   123,   229,   239,   242,   229,    64,
      33,   145,    74,    74,   145,   200,    33,   202,   203,    75,
      82,    90,   112,   199,   146,   202,    39,   127,   198,    76,
     205,   102,   212,   213,   145,   243,   145,   146,   183,   229,
     254,   144,    88,    88,   144,    58,    65,   179,   247,   248,
     254,   131,   162,   163,   164,   156,    10,    46,    56,    95,
     106,   111,   129,   159,   160,   161,   145,   226,   227,    17,
      18,    19,    80,   229,   144,   197,   229,    10,    95,   145,
     146,   132,   229,   123,    64,   158,   254,   229,     7,   145,
     203,   100,   100,   100,    87,   200,     7,     7,   202,    42,
      78,   206,    42,   145,    99,   214,   145,   229,   225,   144,
     144,   253,     5,    68,    97,    98,   126,   255,   145,   146,
     145,   146,    37,    40,    41,   119,   174,   146,   137,   166,
      95,   144,   244,    88,   254,   159,   229,   144,   197,     9,
     243,    95,   244,   144,   229,   145,   145,   145,    72,   145,
     201,   104,   104,   243,   225,    99,   207,   243,    42,   109,
     115,   215,   216,   145,   253,   253,   145,    58,    65,   247,
     144,   175,   162,    38,   102,   167,   225,   144,     9,   243,
     229,   145,   246,     7,    98,    42,    91,   208,   219,   220,
     229,    19,   145,   145,     5,   255,   169,   170,   171,   172,
     173,   254,   144,    42,   145,   254,   229,   145,   145,   145,
     225,   219,     7,   136,   209,   210,   211,   146,    34,    59,
     221,     7,    51,   128,   217,   111,   145,   146,     7,    28,
     144,   254,   169,    77,   109,   168,   145,   254,   211,   220,
      96,   222,   105,   113,   105,     9,   254,   170,   253,   145,
     144,    33,    69,    89,     7,    51,   128,   218,   144,   145,
     253,   144,    71,   113,    71,   253,   145,   212,   145,   103,
     145,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   148,   149,   149,   149,   149,   149,   149,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   151,   152,
     152,   152,   152,   153,   154,   155,   156,   157,   157,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   159,   159,   159,
     159,   159,   159,   159,   160,   160,   161,   161,   162,   162,
     162,   162,   163,   163,   164,   164,   165,   165,   166,   166,
     167,   167,   168,   168,   169,   169,   170,   170,   170,   171,
     171,   172,   173,   174,   174,   174,   174,   175,   175,   176,
     176,   176,   176,   177,   178,   178,   179,   179,   179,   179,
     180,   181,   182,   182,   183,   184,   184,   185,   185,   186,
     187,   187,   188,   189,   189,   190,   190,   191,   192,   192,
     192,   193,   193,   194,   194,   195,   195,   195,   196,   197,
     198,   198,   198,   199,   199,   199,   199,   199,   199,   199,
     199,   200,   200,   201,   201,   201,   201,   201,   201,   202,
     202,   203,   203,   204,   204,   205,   205,   206,   206,   207,
     207,   208,   208,   209,   209,   210,   210,   211,   212,   213,
     213,   214,   214,   215,   215,   216,   216,   217,   217,   217,
     218,   218,   218,   219,   219,   220,   221,   221,   221,   222,
     222,   222,   223,   223,   224,   225,   225,   226,   226,   227,
     227,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   229,   229,   230,   230,   231,   231,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   233,
     233,   233,   233,   234,   234,   235,   236,   236,   237,   237,
     238,   238,   239,   240,   240,   241,   242,   242,   243,   243,
     244,   244,   244,   244,   244,   244,   244,   244,   245,   245,
     245,   245,   245,   245,   246,   246,   247,   247,   248,   248,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     250,   251,   251,   252,   252,   252,   253,   253,   254,   254,
     255,   255,   255,   255,   256,   257,   257
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     6,
       6,     6,     6,     9,     9,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     4,     4,     1,     2,     1,
       2,     2,     4,     5,     2,     1,     0,     1,     4,     5,
      10,     4,     3,     1,     0,     1,     0,     3,     0,     5,
       0,     8,     1,     1,     1,     3,     1,     1,     1,     2,
       2,     4,     2,     1,     1,     1,     1,     0,     3,    10,
       7,     4,     5,     5,     0,     4,     2,     2,     4,     4,
       5,     4,     3,     1,     3,     2,     3,     0,     3,     2,
       1,     3,     3,     4,     1,     3,     1,    10,     0,     1,
       1,     1,     1,     1,     3,     3,     2,     1,     2,     3,
       0,     3,     3,     0,     1,     1,     2,     1,     2,     1,
       2,     6,     1,     2,     3,     2,     2,     1,     3,     1,
       2,     1,     4,     1,     3,     0,     3,     0,     2,     0,
       3,     0,     2,     0,     1,     1,     2,     6,     3,     0,
       3,     0,     3,     0,     5,     1,     1,     2,     2,     2,
       2,     2,     2,     1,     3,     3,     0,     1,     1,     0,
       2,     2,     0,     1,     2,     3,     1,     3,     1,     2,
       1,     5,     6,     4,     3,     3,     3,     2,     3,     5,
       4,     6,     3,     1,     3,     1,     2,     1,     1,     1,
       1,     3,     5,     1,     1,     1,     1,     3,     1,     3,
       4,     4,     5,     6,     6,     6,     6,     8,     5,     4,
       1,     2,     4,     1,     2,     4,     0,     2,     1,     3,
       1,     1,     2,     2,     1,     2,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     2,     2,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (&yylloc, yyscanner, parsedStatement, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, yyscanner, parsedStatement); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t yyscanner, quickstep::ParseStatement **parsedStatement)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (yyscanner);
  YYUSE (parsedStatement);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t yyscanner, quickstep::ParseStatement **parsedStatement)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, yyscanner, parsedStatement);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, yyscan_t yyscanner, quickstep::ParseStatement **parsedStatement)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , yyscanner, parsedStatement);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, yyscanner, parsedStatement); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yyscan_t yyscanner, quickstep::ParseStatement **parsedStatement)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (yyscanner);
  YYUSE (parsedStatement);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 3: /* TOKEN_COMMAND  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2010 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 4: /* TOKEN_NAME  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2020 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 5: /* TOKEN_STRING_SINGLE_QUOTED  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2030 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 6: /* TOKEN_STRING_DOUBLE_QUOTED  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2040 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 7: /* TOKEN_UNSIGNED_NUMVAL  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).numeric_literal_value_) != nullptr) {
    delete ((*yyvaluep).numeric_literal_value_);
  }
}
#line 2050 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 150: /* sql_statement  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).statement_) != nullptr) {
    delete ((*yyvaluep).statement_);
  }
}
#line 2060 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 151: /* quit_statement  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).quit_statement_) != nullptr) {
    delete ((*yyvaluep).quit_statement_);
  }
}
#line 2070 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 152: /* alter_table_statement  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).statement_) != nullptr) {
    delete ((*yyvaluep).statement_);
  }
}
#line 2080 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 153: /* create_table_statement  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).create_table_statement_) != nullptr) {
    delete ((*yyvaluep).create_table_statement_);
  }
}
#line 2090 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 154: /* create_index_statement  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).statement_) != nullptr) {
    delete ((*yyvaluep).statement_);
  }
}
#line 2100 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 155: /* drop_table_statement  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).drop_table_statement_) != nullptr) {
    delete ((*yyvaluep).drop_table_statement_);
  }
}
#line 2110 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 156: /* column_def  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_definition_) != nullptr) {
    delete ((*yyvaluep).attribute_definition_);
  }
}
#line 2120 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 157: /* column_def_commalist  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_definition_list_) != nullptr) {
    delete ((*yyvaluep).attribute_definition_list_);
  }
}
#line 2130 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 158: /* data_type  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).data_type_) != nullptr) {
    delete ((*yyvaluep).data_type_);
  }
}
#line 2140 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 159: /* column_constraint_def  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).column_constraint_) != nullptr) {
    delete ((*yyvaluep).column_constraint_);
  }
}
#line 2150 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 160: /* column_constraint_def_list  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).column_constraint_list_) != nullptr) {
    delete ((*yyvaluep).column_constraint_list_);
  }
}
#line 2160 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 161: /* opt_column_constraint_def_list  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).column_constraint_list_) != nullptr) {
    delete ((*yyvaluep).column_constraint_list_);
  }
}
#line 2170 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 165: /* opt_column_list  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_list_) != nullptr) {
    delete ((*yyvaluep).attribute_list_);
  }
}
#line 2180 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 166: /* opt_block_properties  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).block_properties_) != nullptr) {
    delete ((*yyvaluep).block_properties_);
  }
}
#line 2190 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 167: /* opt_partition_clause  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).partition_clause_) != nullptr) {
    delete ((*yyvaluep).partition_clause_);
  }
}
#line 2200 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 168: /* partition_type  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2210 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 169: /* key_value_list  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_value_list_) != nullptr) {
    delete ((*yyvaluep).key_value_list_);
  }
}
#line 2220 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 170: /* key_value  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_value_) != nullptr) {
    delete ((*yyvaluep).key_value_);
  }
}
#line 2230 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 171: /* key_string_value  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_string_value_) != nullptr) {
    delete ((*yyvaluep).key_string_value_);
  }
}
#line 2240 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 172: /* key_string_list  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_string_list_) != nullptr) {
    delete ((*yyvaluep).key_string_list_);
  }
}
#line 2250 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 173: /* key_integer_value  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_integer_value_) != nullptr) {
    delete ((*yyvaluep).key_integer_value_);
  }
}
#line 2260 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 174: /* index_type  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2270 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 175: /* opt_index_properties  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_value_list_) != nullptr) {
    delete ((*yyvaluep).key_value_list_);
  }
}
#line 2280 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 176: /* insert_statement  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).insert_statement_) != nullptr) {
    delete ((*yyvaluep).insert_statement_);
  }
}
#line 2290 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 177: /* copy_from_statement  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).copy_from_statement_) != nullptr) {
    delete ((*yyvaluep).copy_from_statement_);
  }
}
#line 2300 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 178: /* opt_copy_from_params  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).copy_from_params_) != nullptr) {
    delete ((*yyvaluep).copy_from_params_);
  }
}
#line 2310 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 179: /* copy_from_params  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).copy_from_params_) != nullptr) {
    delete ((*yyvaluep).copy_from_params_);
  }
}
#line 2320 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 180: /* update_statement  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).update_statement_) != nullptr) {
    delete ((*yyvaluep).update_statement_);
  }
}
#line 2330 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 181: /* delete_statement  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).delete_statement_) != nullptr) {
    delete ((*yyvaluep).delete_statement_);
  }
}
#line 2340 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 182: /* assignment_list  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).assignment_list_) != nullptr) {
    delete ((*yyvaluep).assignment_list_);
  }
}
#line 2350 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 183: /* assignment_item  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).assignment_) != nullptr) {
    delete ((*yyvaluep).assignment_);
  }
}
#line 2360 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 184: /* set_operation_statement  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).set_operation_statement_) != nullptr) {
    delete ((*yyvaluep).set_operation_statement_);
  }
}
#line 2370 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 185: /* opt_priority_clause  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_priority_clause_) != nullptr) {
    delete ((*yyvaluep).opt_priority_clause_);
  }
}
#line 2380 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 186: /* with_clause  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).with_list_) != nullptr) {
    delete ((*yyvaluep).with_list_);
  }
}
#line 2390 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 187: /* with_list  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).with_list_) != nullptr) {
    delete ((*yyvaluep).with_list_);
  }
}
#line 2400 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 188: /* with_list_element  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).with_list_element_) != nullptr) {
    delete ((*yyvaluep).with_list_element_);
  }
}
#line 2410 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 189: /* set_operation_union  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).set_operation_) != nullptr) {
    delete ((*yyvaluep).set_operation_);
  }
}
#line 2420 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 190: /* set_operation_intersect  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).set_operation_) != nullptr) {
    delete ((*yyvaluep).set_operation_);
  }
}
#line 2430 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 191: /* select_query  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).select_query_) != nullptr) {
    delete ((*yyvaluep).select_query_);
  }
}
#line 2440 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 192: /* opt_all_distinct  */
#line 620 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2446 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 193: /* selection  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).selection_) != nullptr) {
    delete ((*yyvaluep).selection_);
  }
}
#line 2456 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 194: /* selection_item_commalist  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).selection_list_) != nullptr) {
    delete ((*yyvaluep).selection_list_);
  }
}
#line 2466 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 195: /* selection_item  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).selection_item_) != nullptr) {
    delete ((*yyvaluep).selection_item_);
  }
}
#line 2476 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 196: /* from_clause  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_list_) != nullptr) {
    delete ((*yyvaluep).table_reference_list_);
  }
}
#line 2486 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 197: /* subquery_expression  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).subquery_expression_) != nullptr) {
    delete ((*yyvaluep).subquery_expression_);
  }
}
#line 2496 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 198: /* opt_sample_clause  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_sample_clause_) != nullptr) {
    delete ((*yyvaluep).opt_sample_clause_);
  }
}
#line 2506 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 199: /* join_type  */
#line 622 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2512 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 200: /* joined_table_reference  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_) != nullptr) {
    delete ((*yyvaluep).table_reference_);
  }
}
#line 2522 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 201: /* table_reference  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_) != nullptr) {
    delete ((*yyvaluep).table_reference_);
  }
}
#line 2532 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 202: /* table_reference_signature  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_signature_) != nullptr) {
    delete ((*yyvaluep).table_reference_signature_);
  }
}
#line 2542 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 203: /* table_reference_signature_primary  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_signature_) != nullptr) {
    delete ((*yyvaluep).table_reference_signature_);
  }
}
#line 2552 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 204: /* joined_table_reference_commalist  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_list_) != nullptr) {
    delete ((*yyvaluep).table_reference_list_);
  }
}
#line 2562 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 205: /* opt_group_by_clause  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_group_by_clause_) != nullptr) {
    delete ((*yyvaluep).opt_group_by_clause_);
  }
}
#line 2572 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 206: /* opt_having_clause  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_having_clause_) != nullptr) {
    delete ((*yyvaluep).opt_having_clause_);
  }
}
#line 2582 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 207: /* opt_order_by_clause  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_order_by_clause_) != nullptr) {
    delete ((*yyvaluep).opt_order_by_clause_);
  }
}
#line 2592 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 208: /* opt_limit_clause  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_limit_clause_) != nullptr) {
    delete ((*yyvaluep).opt_limit_clause_);
  }
}
#line 2602 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 209: /* opt_window_clause  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_window_clause_) != nullptr) {
    delete ((*yyvaluep).opt_window_clause_);
  }
}
#line 2612 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 210: /* window_declaration_list  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_window_clause_) != nullptr) {
    delete ((*yyvaluep).opt_window_clause_);
  }
}
#line 2622 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 211: /* window_declaration  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).window_definition_) != nullptr) {
    delete ((*yyvaluep).window_definition_);
  }
}
#line 2632 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 212: /* window_definition  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).window_definition_) != nullptr) {
    delete ((*yyvaluep).window_definition_);
  }
}
#line 2642 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 213: /* opt_window_partition  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).window_partition_by_list_) != nullptr) {
    delete ((*yyvaluep).window_partition_by_list_);
  }
}
#line 2652 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 214: /* opt_window_order  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).window_order_by_list_) != nullptr) {
    delete ((*yyvaluep).window_order_by_list_);
  }
}
#line 2662 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 215: /* opt_window_frame  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).window_frame_info_) != nullptr) {
    delete ((*yyvaluep).window_frame_info_);
  }
}
#line 2672 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 216: /* frame_mode  */
#line 620 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2678 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 217: /* frame_preceding  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).numeric_literal_value_) != nullptr) {
    delete ((*yyvaluep).numeric_literal_value_);
  }
}
#line 2688 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 218: /* frame_following  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).numeric_literal_value_) != nullptr) {
    delete ((*yyvaluep).numeric_literal_value_);
  }
}
#line 2698 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 219: /* order_commalist  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_commalist_) != nullptr) {
    delete ((*yyvaluep).order_commalist_);
  }
}
#line 2708 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 220: /* order_item  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_item_) != nullptr) {
    delete ((*yyvaluep).order_item_);
  }
}
#line 2718 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 221: /* opt_order_direction  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_direction_) != nullptr) {
    delete ((*yyvaluep).order_direction_);
  }
}
#line 2728 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 222: /* opt_nulls_first  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_direction_) != nullptr) {
    delete ((*yyvaluep).order_direction_);
  }
}
#line 2738 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 223: /* opt_where_clause  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2748 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 224: /* where_clause  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2758 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 225: /* or_expression  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2768 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 226: /* and_expression  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2778 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 227: /* not_expression  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2788 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 228: /* predicate_expression_base  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2798 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 229: /* add_expression  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2808 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 230: /* multiply_expression  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2818 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 231: /* unary_expression  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2828 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 232: /* expression_base  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2838 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 233: /* function_call  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).function_call_) != nullptr) {
    delete ((*yyvaluep).function_call_);
  }
}
#line 2848 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 234: /* cast_function  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2858 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 235: /* extract_function  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2868 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 236: /* substr_function  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2878 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 237: /* case_expression  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2888 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 238: /* simple_when_clause_list  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).simple_when_clause_list_) != nullptr) {
    delete ((*yyvaluep).simple_when_clause_list_);
  }
}
#line 2898 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 239: /* simple_when_clause  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).simple_when_clause_) != nullptr) {
    delete ((*yyvaluep).simple_when_clause_);
  }
}
#line 2908 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 240: /* searched_when_clause_list  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).searched_when_clause_list_) != nullptr) {
    delete ((*yyvaluep).searched_when_clause_list_);
  }
}
#line 2918 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 241: /* searched_when_clause  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).searched_when_clause_) != nullptr) {
    delete ((*yyvaluep).searched_when_clause_);
  }
}
#line 2928 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 242: /* opt_else_clause  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2938 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 243: /* expression_list  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_list_) != nullptr) {
    delete ((*yyvaluep).expression_list_);
  }
}
#line 2948 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 244: /* literal_value  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_) != nullptr) {
    delete ((*yyvaluep).literal_value_);
  }
}
#line 2958 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 245: /* datetime_unit  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2968 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 246: /* literal_value_commalist  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_list_) != nullptr) {
    delete ((*yyvaluep).literal_value_list_);
  }
}
#line 2978 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 247: /* attribute_ref  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_) != nullptr) {
    delete ((*yyvaluep).attribute_);
  }
}
#line 2988 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 248: /* attribute_ref_list  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_list_) != nullptr) {
    delete ((*yyvaluep).attribute_list_);
  }
}
#line 2998 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 249: /* comparison_operation  */
#line 621 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 3004 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 250: /* unary_operation  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).unary_operation_) != nullptr) {
    delete ((*yyvaluep).unary_operation_);
  }
}
#line 3014 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 251: /* add_operation  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).binary_operation_) != nullptr) {
    delete ((*yyvaluep).binary_operation_);
  }
}
#line 3024 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 252: /* multiply_operation  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).binary_operation_) != nullptr) {
    delete ((*yyvaluep).binary_operation_);
  }
}
#line 3034 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 253: /* name_commalist  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_list_) != nullptr) {
    delete ((*yyvaluep).string_list_);
  }
}
#line 3044 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 254: /* any_name  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 3054 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 255: /* boolean_value  */
#line 620 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 3060 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 256: /* command  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).command_) != nullptr) {
    delete ((*yyvaluep).command_);
  }
}
#line 3070 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 257: /* command_argument_list  */
#line 624 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).command_argument_list_) != nullptr) {
    delete ((*yyvaluep).command_argument_list_);
  }
}
#line 3080 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t yyscanner, quickstep::ParseStatement **parsedStatement)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, yyscanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 633 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    *parsedStatement = (yyvsp[-1].statement_);
    YYACCEPT;
  }
#line 3377 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 3:
#line 637 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    *parsedStatement = (yyvsp[-1].statement_);
    YYACCEPT;
  }
#line 3386 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 4:
#line 641 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    *parsedStatement = (yyvsp[-1].command_);
    YYACCEPT;
  }
#line 3395 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 5:
#line 645 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    *parsedStatement = (yyvsp[-1].command_);
    YYACCEPT;
  }
#line 3404 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 6:
#line 649 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    YYABORT;
  }
#line 3412 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 7:
#line 652 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    // Regular yyparse() return codes are non-negative, so use a negative one here.
    return -1;
  }
#line 3421 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 8:
#line 659 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.statement_) = (yyvsp[0].statement_);
  }
#line 3429 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 9:
#line 662 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.statement_) = (yyvsp[0].copy_from_statement_);
  }
#line 3437 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 10:
#line 665 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.statement_) = (yyvsp[0].create_table_statement_);
  }
#line 3445 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 11:
#line 668 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.statement_) = (yyvsp[0].statement_);
  }
#line 3453 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 12:
#line 671 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.statement_) = (yyvsp[0].delete_statement_);
  }
#line 3461 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 13:
#line 674 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.statement_) = (yyvsp[0].drop_table_statement_);
  }
#line 3469 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 14:
#line 677 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.statement_) = (yyvsp[0].insert_statement_);
  }
#line 3477 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 15:
#line 680 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.statement_) = (yyvsp[0].quit_statement_);
  }
#line 3485 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 16:
#line 683 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.statement_) = (yyvsp[0].set_operation_statement_);
  }
#line 3493 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 17:
#line 686 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.statement_) = (yyvsp[0].update_statement_);
  }
#line 3501 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 18:
#line 692 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.quit_statement_) = new quickstep::ParseStatementQuit((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 3509 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 19:
#line 698 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[0].attribute_definition_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3521 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 20:
#line 705 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    delete (yyvsp[-3].string_value_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3532 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 21:
#line 711 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[0].string_value_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3544 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 22:
#line 718 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[0].string_value_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3556 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 23:
#line 727 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.create_table_statement_) = new quickstep::ParseStatementCreateTable((yylsp[-8]).first_line, (yylsp[-8]).first_column, (yyvsp[-6].string_value_), (yyvsp[-4].attribute_definition_list_), (yyvsp[-1].block_properties_), (yyvsp[0].partition_clause_));
  }
#line 3564 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 24:
#line 732 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    if ((yyvsp[0].key_value_list_)) {
      (yyval.statement_) = new quickstep::ParseStatementCreateIndex((yylsp[-8]).first_line, (yylsp[-8]).first_column, (yyvsp[-6].string_value_), (yyvsp[-4].string_value_), (yyvsp[-3].attribute_list_), (yyvsp[-1].string_value_), (yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].key_value_list_));
    } else {
      (yyval.statement_) = new quickstep::ParseStatementCreateIndex((yylsp[-8]).first_line, (yylsp[-8]).first_column, (yyvsp[-6].string_value_), (yyvsp[-4].string_value_), (yyvsp[-3].attribute_list_), (yyvsp[-1].string_value_));
    }
  }
#line 3576 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 25:
#line 741 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.drop_table_statement_) = new quickstep::ParseStatementDropTable((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].string_value_));
  }
#line 3584 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 26:
#line 746 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.attribute_definition_) = new quickstep::ParseAttributeDefinition((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_value_), (yyvsp[-1].data_type_), (yyvsp[0].column_constraint_list_));
  }
#line 3592 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 27:
#line 751 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.attribute_definition_list_) = new quickstep::PtrList<quickstep::ParseAttributeDefinition>();
    (yyval.attribute_definition_list_)->push_back((yyvsp[0].attribute_definition_));
  }
#line 3601 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 28:
#line 755 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.attribute_definition_list_) = (yyvsp[-2].attribute_definition_list_);
    (yyval.attribute_definition_list_)->push_back((yyvsp[0].attribute_definition_));
  }
#line 3610 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 29:
#line 761 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.data_type_) = nullptr;
    NotSupported(&(yylsp[0]), yyscanner, "BIT data type");
    YYERROR;
  }
#line 3620 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 30:
#line 766 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDate));
  }
#line 3628 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 31:
#line 769 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetime));
  }
#line 3636 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 32:
#line 772 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.data_type_) = nullptr;
    NotSupported(&(yylsp[0]), yyscanner, "TIME data type");
    YYERROR;
  }
#line 3646 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 33:
#line 777 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetime));
  }
#line 3654 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 34:
#line 780 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDouble));
  }
#line 3662 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 35:
#line 783 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDouble));
  }
#line 3670 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 36:
#line 786 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDouble));
  }
#line 3678 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 37:
#line 789 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kFloat));
  }
#line 3686 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 38:
#line 792 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kInt));
  }
#line 3694 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 39:
#line 795 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kInt));
  }
#line 3702 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 40:
#line 798 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kLong));
  }
#line 3710 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 41:
#line 801 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kLong));
  }
#line 3718 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 42:
#line 804 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    /**
     * NOTE(chasseur): This pattern exhibits a shift/reduce conflict with the
     * TOKEN_INTERVAL case in 'literal_value'. Bison prefers to shift rather
     * than reduce, so the case in 'literal_value' has precedence over this.
     **/
    (yyval.data_type_) = nullptr;
    quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr,
        "INTERVAL is ambiguous as a column type. Specify either DATETIME INTERVAL "
        "or YEARMONTH INTERVAL");
    YYERROR;
  }
#line 3735 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 43:
#line 816 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetimeInterval));
  }
#line 3743 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 44:
#line 819 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kYearMonthInterval));
  }
#line 3751 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 45:
#line 822 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    if ((yyvsp[-1].numeric_literal_value_)->float_like()) {
      delete (yyvsp[-1].numeric_literal_value_);
      (yyval.data_type_) = NULL;
      quickstep_yyerror(&(yylsp[-1]), yyscanner, nullptr, "Non-integer length supplied for CHAR type");
      YYERROR;
    } else {
      if ((yyvsp[-1].numeric_literal_value_)->long_value() <= 0) {
        delete (yyvsp[-1].numeric_literal_value_);
        (yyval.data_type_) = NULL;
        quickstep_yyerror(&(yylsp[-1]), yyscanner, nullptr, "Length for CHAR type must be at least 1");
        YYERROR;
      } else {
        (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kChar, (yyvsp[-1].numeric_literal_value_)->long_value(), false));
        delete (yyvsp[-1].numeric_literal_value_);
      }
    }
  }
#line 3774 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 46:
#line 840 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    if ((yyvsp[-1].numeric_literal_value_)->float_like()) {
      delete (yyvsp[-1].numeric_literal_value_);
      (yyval.data_type_) = NULL;
      quickstep_yyerror(&(yylsp[-1]), yyscanner, nullptr, "Non-integer length supplied for VARCHAR type");
      YYERROR;
    } else {
      if ((yyvsp[-1].numeric_literal_value_)->long_value() < 0) {
        delete (yyvsp[-1].numeric_literal_value_);
        (yyval.data_type_) = NULL;
        quickstep_yyerror(&(yylsp[-1]), yyscanner, nullptr, "Negative length supplied for VARCHAR type");
        YYERROR;
      } else {
        (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kVarChar, (yyvsp[-1].numeric_literal_value_)->long_value(), false));
        delete (yyvsp[-1].numeric_literal_value_);
      }
    }
  }
#line 3797 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 47:
#line 860 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.column_constraint_) = new quickstep::ParseColumnConstraintNull((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 3805 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 48:
#line 863 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.column_constraint_) = new quickstep::ParseColumnConstraintNotNull((yylsp[-1]).first_line, (yylsp[-1]).first_column);
  }
#line 3813 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 49:
#line 866 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.column_constraint_) = nullptr;
    NotSupported(&(yylsp[0]), yyscanner, "Column Constraints (UNIQUE)");
    YYERROR;
  }
#line 3823 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 50:
#line 871 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.column_constraint_) = nullptr;
    NotSupported(&(yylsp[-1]), yyscanner, "Column Constraints (PRIMARY KEY)");
    YYERROR;
  }
#line 3833 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 51:
#line 876 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.column_constraint_) = nullptr;
    delete (yyvsp[0].literal_value_);
    NotSupported(&(yylsp[-1]), yyscanner, "Column Constraints (DEFAULT)");
    YYERROR;
  }
#line 3844 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 52:
#line 882 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.column_constraint_) = nullptr;
    delete (yyvsp[-1].predicate_);
    NotSupported(&(yylsp[-3]), yyscanner, "Column Constraints (CHECK)");
    YYERROR;
  }
#line 3855 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 53:
#line 888 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.column_constraint_) = nullptr;
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[-1].string_value_);
    NotSupported(&(yylsp[-4]), yyscanner, "Foreign Keys");
    YYERROR;
  }
#line 3867 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 54:
#line 897 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.column_constraint_list_) = (yyvsp[-1].column_constraint_list_);
    (yyval.column_constraint_list_)->push_back((yyvsp[0].column_constraint_));
  }
#line 3876 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 55:
#line 901 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.column_constraint_list_) = new quickstep::PtrList<quickstep::ParseColumnConstraint>();
    (yyval.column_constraint_list_)->push_back((yyvsp[0].column_constraint_));
  }
#line 3885 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 56:
#line 907 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.column_constraint_list_) = nullptr;
  }
#line 3893 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 57:
#line 910 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.column_constraint_list_) = (yyvsp[0].column_constraint_list_);
  }
#line 3901 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 58:
#line 915 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    delete (yyvsp[-1].string_list_);
    NotSupported(&(yylsp[-3]), yyscanner, "Table Constraints (UNIQUE)");
    YYERROR;
  }
#line 3911 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 59:
#line 920 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    delete (yyvsp[-1].string_list_);
    NotSupported(&(yylsp[-4]), yyscanner, "Table Constraints (PRIMARY KEY)");
    YYERROR;
  }
#line 3921 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 60:
#line 925 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    delete (yyvsp[-6].string_list_);
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[-1].string_list_);
    NotSupported(&(yylsp[-9]), yyscanner, "Table Constraints (FOREIGN KEY)");
    YYERROR;
  }
#line 3933 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 61:
#line 932 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    delete (yyvsp[-1].predicate_);
    NotSupported(&(yylsp[-3]), yyscanner, "Table Constraints (CHECK)");
    YYERROR;
  }
#line 3943 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 62:
#line 939 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    NotSupported(&(yylsp[-2]), yyscanner, "Table Constraints");
    YYERROR;
  }
#line 3952 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 63:
#line 943 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    NotSupported(&(yylsp[0]), yyscanner, "Table Constraints");
    YYERROR;
  }
#line 3961 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 64:
#line 949 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    /* $$ = nullptr; */
  }
#line 3969 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 65:
#line 952 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    /* $$ = $1; */
  }
#line 3977 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 66:
#line 957 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.attribute_list_) = nullptr;
  }
#line 3985 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 67:
#line 960 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.attribute_list_) = (yyvsp[-1].attribute_list_);
  }
#line 3993 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 68:
#line 965 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.block_properties_) = nullptr;
  }
#line 4001 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 69:
#line 968 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.block_properties_) = new quickstep::ParseBlockProperties((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-1].key_value_list_));
  }
#line 4009 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 70:
#line 973 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.partition_clause_) = nullptr;
  }
#line 4017 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 71:
#line 976 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    if ((yyvsp[0].numeric_literal_value_)->float_like()) {
      delete (yyvsp[0].numeric_literal_value_);
      (yyval.partition_clause_) = NULL;
      quickstep_yyerror(&(yylsp[0]), yyscanner, NULL, "NUMBER OF PARTITIONS must be an integer");
      YYERROR;
    } else {
      if ((yyvsp[0].numeric_literal_value_)->long_value() <= 0 || (yyvsp[0].numeric_literal_value_)->long_value() > 64) {
        delete (yyvsp[0].numeric_literal_value_);
        (yyval.partition_clause_) = NULL;
        quickstep_yyerror(&(yylsp[0]), yyscanner, NULL, "NUMBER OF PARITIONS must be between 1 and 64");
        YYERROR;
      } else {
        (yyval.partition_clause_) = new quickstep::ParsePartitionClause((yylsp[-7]).first_line, (yylsp[-7]).first_column, (yyvsp[-5].string_value_), (yyvsp[-3].string_list_), (yyvsp[0].numeric_literal_value_));
      }
    }
  }
#line 4039 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 72:
#line 995 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, quickstep::kHashPartitionType);
  }
#line 4047 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 73:
#line 998 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, quickstep::kRangePartitionType);
  }
#line 4055 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 74:
#line 1003 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.key_value_list_) = new quickstep::PtrList<quickstep::ParseKeyValue>();
    (yyval.key_value_list_)->push_back((yyvsp[0].key_value_));
  }
#line 4064 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 75:
#line 1007 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.key_value_list_) = (yyvsp[-2].key_value_list_);
    (yyval.key_value_list_)->push_back((yyvsp[0].key_value_));
  }
#line 4073 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 76:
#line 1013 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.key_value_) = (yyvsp[0].key_string_value_);
  }
#line 4081 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 77:
#line 1016 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.key_value_) = (yyvsp[0].key_string_list_);
  }
#line 4089 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 78:
#line 1019 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.key_value_) = (yyvsp[0].key_integer_value_);
  }
#line 4097 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 79:
#line 1024 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.key_string_value_) = new quickstep::ParseKeyStringValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].string_value_));
  }
#line 4105 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 80:
#line 1027 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    // This is a special case to handle the COMPRESS ALL option of the BLOCK PROPERTIES.
    (yyval.key_string_value_) = new quickstep::ParseKeyStringValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_),
        new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, "ALL"));
  }
#line 4115 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 81:
#line 1034 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.key_string_list_) = new quickstep::ParseKeyStringList((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].string_list_));
  }
#line 4123 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 82:
#line 1039 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    if ((yyvsp[0].numeric_literal_value_)->float_like()) {
      delete (yyvsp[0].numeric_literal_value_);
      (yyval.key_integer_value_) = nullptr;
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "Value must be an integer");
      YYERROR;
    }
    (yyval.key_integer_value_) = new quickstep::ParseKeyIntegerValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].numeric_literal_value_));
  }
#line 4137 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 83:
#line 1050 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    // Defaults to BitWeavingV, but IndexProperties can change this to H.
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::IndexSubBlockType::kBitWeavingV));
  }
#line 4147 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 84:
#line 1055 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::IndexSubBlockType::kBloomFilter));
  }
#line 4156 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 85:
#line 1059 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::IndexSubBlockType::kCSBTree));
  }
#line 4165 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 86:
#line 1063 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::IndexSubBlockType::kSMA));
  }
#line 4174 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 87:
#line 1069 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.key_value_list_) = nullptr;
  }
#line 4182 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 88:
#line 1072 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.key_value_list_) = (yyvsp[-1].key_value_list_);
  }
#line 4190 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 89:
#line 1078 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    delete (yyvsp[-7].string_value_);
    delete (yyvsp[-5].string_list_);
    delete (yyvsp[-1].literal_value_list_);
    (yyval.insert_statement_) = nullptr;
    NotSupported(&(yylsp[-6]), yyscanner, "list of column names in INSERT statement");
    YYERROR;
  }
#line 4203 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 90:
#line 1086 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.insert_statement_) = new quickstep::ParseStatementInsertTuple((yylsp[-6]).first_line, (yylsp[-6]).first_column, (yyvsp[-4].string_value_), (yyvsp[-1].literal_value_list_));
  }
#line 4211 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 91:
#line 1089 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.insert_statement_) = new quickstep::ParseStatementInsertSelection((yylsp[-3]).first_line, (yylsp[-2]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].select_query_), nullptr);
  }
#line 4219 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 92:
#line 1092 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.insert_statement_) = new quickstep::ParseStatementInsertSelection((yylsp[-4]).first_line, (yylsp[-3]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].select_query_), (yyvsp[-4].with_list_));
  }
#line 4227 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 93:
#line 1098 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.copy_from_statement_) = new quickstep::ParseStatementCopyFrom((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].string_value_), (yyvsp[0].copy_from_params_));
  }
#line 4235 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 94:
#line 1103 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.copy_from_params_) = nullptr;
  }
#line 4243 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 95:
#line 1106 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.copy_from_params_) = (yyvsp[-1].copy_from_params_);
  }
#line 4251 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 96:
#line 1111 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.copy_from_params_) = new quickstep::ParseCopyFromParams((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    (yyval.copy_from_params_)->set_delimiter((yyvsp[0].string_value_));
  }
#line 4260 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 97:
#line 1115 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.copy_from_params_) = new quickstep::ParseCopyFromParams((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    (yyval.copy_from_params_)->escape_strings = (yyvsp[0].boolean_value_);
  }
#line 4269 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 98:
#line 1119 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.copy_from_params_) = (yyvsp[-3].copy_from_params_);
    (yyval.copy_from_params_)->set_delimiter((yyvsp[0].string_value_));
  }
#line 4278 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 99:
#line 1123 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.copy_from_params_) = (yyvsp[-3].copy_from_params_);
    (yyval.copy_from_params_)->escape_strings = (yyvsp[0].boolean_value_);
  }
#line 4287 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 100:
#line 1129 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.update_statement_) = new quickstep::ParseStatementUpdate((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].assignment_list_), (yyvsp[0].predicate_));
  }
#line 4295 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 101:
#line 1134 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.delete_statement_) = new quickstep::ParseStatementDelete((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].predicate_));
  }
#line 4303 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 102:
#line 1139 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.assignment_list_) = (yyvsp[-2].assignment_list_);
    (yyval.assignment_list_)->push_back((yyvsp[0].assignment_));
  }
#line 4312 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 103:
#line 1143 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.assignment_list_) = new quickstep::PtrList<quickstep::ParseAssignment>();
    (yyval.assignment_list_)->push_back((yyvsp[0].assignment_));
  }
#line 4321 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 104:
#line 1149 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.assignment_) = new quickstep::ParseAssignment((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_value_), (yyvsp[0].expression_));
  }
#line 4329 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 105:
#line 1158 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.set_operation_statement_) = new quickstep::ParseStatementSetOperation((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].set_operation_), nullptr, (yyvsp[0].opt_priority_clause_));
  }
#line 4337 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 106:
#line 1161 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.set_operation_statement_) = new quickstep::ParseStatementSetOperation((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-1].set_operation_), (yyvsp[-2].with_list_), (yyvsp[0].opt_priority_clause_));
  }
#line 4345 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 107:
#line 1166 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.opt_priority_clause_) = nullptr;
  }
#line 4353 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 108:
#line 1169 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    if ((yyvsp[0].numeric_literal_value_)->float_like()) {
      delete (yyvsp[0].numeric_literal_value_);
      (yyval.opt_priority_clause_) = nullptr;
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "PRIORITY value must be an integer");
      YYERROR;
    } else {
      if ((yyvsp[0].numeric_literal_value_)->long_value() <= 0) {
        delete (yyvsp[0].numeric_literal_value_);
        (yyval.opt_priority_clause_) = nullptr;
        quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "PRIORITY value must be positive");
        YYERROR;
      } else {
        (yyval.opt_priority_clause_) = new quickstep::ParsePriority((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].numeric_literal_value_));
      }
    }
  }
#line 4375 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 109:
#line 1188 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.with_list_) = (yyvsp[0].with_list_);
  }
#line 4383 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 110:
#line 1193 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.with_list_) = new quickstep::PtrVector<quickstep::ParseSubqueryTableReference>();
    (yyval.with_list_)->push_back((yyvsp[0].with_list_element_));
  }
#line 4392 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 111:
#line 1197 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.with_list_) = (yyvsp[-2].with_list_);
    (yyval.with_list_)->push_back((yyvsp[0].with_list_element_));
  }
#line 4401 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 112:
#line 1203 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.with_list_element_) = new quickstep::ParseSubqueryTableReference((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].subquery_expression_));
    (yyval.with_list_element_)->set_table_reference_signature((yyvsp[-2].table_reference_signature_));
  }
#line 4410 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 113:
#line 1209 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    if ((yyvsp[-1].boolean_value_)) {
      (yyval.set_operation_) = new quickstep::ParseSetOperation((yylsp[-3]).first_line, (yylsp[-3]).first_column, quickstep::ParseSetOperation::kUnion);
    } else {
      (yyval.set_operation_) = new quickstep::ParseSetOperation((yylsp[-3]).first_line, (yylsp[-3]).first_column, quickstep::ParseSetOperation::kUnionAll);
    }
    (yyval.set_operation_)->addOperand((yyvsp[-3].set_operation_));
    (yyval.set_operation_)->addOperand((yyvsp[0].set_operation_));
  }
#line 4424 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 114:
#line 1218 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.set_operation_) = (yyvsp[0].set_operation_);
  }
#line 4432 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 115:
#line 1223 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.set_operation_) = new quickstep::ParseSetOperation((yylsp[-2]).first_line, (yylsp[-2]).first_column, quickstep::ParseSetOperation::kIntersect);
    quickstep::ParseSetOperation *op = new quickstep::ParseSetOperation(
        (yylsp[0]).first_line, (yylsp[0]).first_column, quickstep::ParseSetOperation::kSelect);
    op->addOperand((yyvsp[0].select_query_));
    (yyval.set_operation_)->addOperand((yyvsp[-2].set_operation_));
    (yyval.set_operation_)->addOperand(op);
  }
#line 4445 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 116:
#line 1231 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.set_operation_) = new quickstep::ParseSetOperation((yylsp[0]).first_line, (yylsp[0]).first_column, quickstep::ParseSetOperation::kSelect);
    (yyval.set_operation_)->addOperand((yyvsp[0].select_query_));
  }
#line 4454 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 117:
#line 1238 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.select_query_) = new quickstep::ParseSelect((yylsp[-9]).first_line, (yylsp[-9]).first_column, (yyvsp[-7].selection_), (yyvsp[-6].table_reference_list_), (yyvsp[-5].predicate_), (yyvsp[-4].opt_group_by_clause_), (yyvsp[-3].opt_having_clause_), (yyvsp[-2].opt_order_by_clause_), (yyvsp[-1].opt_limit_clause_), (yyvsp[0].opt_window_clause_));
  }
#line 4462 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 118:
#line 1243 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.boolean_value_) = true;  // Distinct
  }
#line 4470 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 119:
#line 1246 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.boolean_value_) = false;  // All
  }
#line 4478 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 120:
#line 1249 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.boolean_value_) = true;  // Distinct
  }
#line 4486 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 121:
#line 1254 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.selection_) = new quickstep::ParseSelectionStar((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 4494 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 122:
#line 1257 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.selection_) = (yyvsp[0].selection_list_);
  }
#line 4502 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 123:
#line 1262 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.selection_list_) = new quickstep::ParseSelectionList((yylsp[0]).first_line, (yylsp[0]).first_column);
    (yyval.selection_list_)->add((yyvsp[0].selection_item_));
  }
#line 4511 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 124:
#line 1266 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.selection_list_) = (yyvsp[-2].selection_list_);
    (yyval.selection_list_)->add((yyvsp[0].selection_item_));
  }
#line 4520 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 125:
#line 1272 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.selection_item_) = new quickstep::ParseSelectionItem((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].expression_), (yyvsp[0].string_value_));
  }
#line 4528 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 126:
#line 1275 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.selection_item_) = new quickstep::ParseSelectionItem((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].expression_), (yyvsp[0].string_value_));
  }
#line 4536 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 127:
#line 1278 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.selection_item_) = new quickstep::ParseSelectionItem((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].expression_));
  }
#line 4544 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 128:
#line 1283 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.table_reference_list_) = (yyvsp[0].table_reference_list_);
  }
#line 4552 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 129:
#line 1288 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.subquery_expression_) = new quickstep::ParseSubqueryExpression((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-1].set_operation_));
  }
#line 4560 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 130:
#line 1293 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.opt_sample_clause_) = NULL;
  }
#line 4568 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 131:
#line 1296 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.opt_sample_clause_) = new quickstep::ParseSample((yylsp[-2]).first_line, (yylsp[-2]).first_column, true, (yyvsp[-1].numeric_literal_value_));
  }
#line 4576 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 132:
#line 1299 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.opt_sample_clause_) = new quickstep::ParseSample((yylsp[-2]).first_line, (yylsp[-2]).first_column, false, (yyvsp[-1].numeric_literal_value_));
  }
#line 4584 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 133:
#line 1304 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kInnerJoin;
  }
#line 4592 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 134:
#line 1307 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kInnerJoin;
  }
#line 4600 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 135:
#line 1310 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kLeftOuterJoin;
  }
#line 4608 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 136:
#line 1313 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kLeftOuterJoin;
  }
#line 4616 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 137:
#line 1316 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kRightOuterJoin;
  }
#line 4624 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 138:
#line 1319 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kRightOuterJoin;
  }
#line 4632 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 139:
#line 1322 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kFullOuterJoin;
  }
#line 4640 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 140:
#line 1325 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.join_type_) = quickstep::ParseJoinedTableReference::JoinType::kFullOuterJoin;
  }
#line 4648 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 141:
#line 1330 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.table_reference_) = new quickstep::ParseJoinedTableReference((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-4].join_type_), (yyvsp[-5].table_reference_), (yyvsp[-2].table_reference_), (yyvsp[0].predicate_));
  }
#line 4656 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 142:
#line 1333 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.table_reference_) = (yyvsp[0].table_reference_);
  }
#line 4664 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 143:
#line 1338 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.table_reference_) = new quickstep::ParseSubqueryTableReference((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].subquery_expression_));
    (yyval.table_reference_)->set_table_reference_signature((yyvsp[0].table_reference_signature_));
  }
#line 4673 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 144:
#line 1342 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.table_reference_) = new quickstep::ParseSimpleTableReference((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_value_), (yyvsp[-1].opt_sample_clause_));
    (yyval.table_reference_)->set_table_reference_signature((yyvsp[0].table_reference_signature_));
  }
#line 4682 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 145:
#line 1346 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.table_reference_) = new quickstep::ParseSimpleTableReference((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].opt_sample_clause_));
  }
#line 4690 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 146:
#line 1349 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.table_reference_) = new quickstep::ParseGeneratorTableReference((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].function_call_));
    (yyval.table_reference_)->set_table_reference_signature((yyvsp[0].table_reference_signature_));
  }
#line 4699 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 147:
#line 1353 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.table_reference_) = new quickstep::ParseGeneratorTableReference((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].function_call_));
  }
#line 4707 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 148:
#line 1356 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.table_reference_) = (yyvsp[-1].table_reference_);
  }
#line 4715 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 149:
#line 1361 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.table_reference_signature_) = (yyvsp[0].table_reference_signature_);
  }
#line 4723 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 150:
#line 1364 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.table_reference_signature_) = (yyvsp[0].table_reference_signature_);
  }
#line 4731 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 151:
#line 1369 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.table_reference_signature_) = new ::quickstep::ParseTableReferenceSignature((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].string_value_));
  }
#line 4739 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 152:
#line 1372 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.table_reference_signature_) = new ::quickstep::ParseTableReferenceSignature((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].string_list_));
  }
#line 4747 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 153:
#line 1377 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.table_reference_list_) = new quickstep::PtrList<quickstep::ParseTableReference>();
    (yyval.table_reference_list_)->push_back((yyvsp[0].table_reference_));
  }
#line 4756 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 154:
#line 1381 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.table_reference_list_) = (yyvsp[-2].table_reference_list_);
    (yyval.table_reference_list_)->push_back((yyvsp[0].table_reference_));
  }
#line 4765 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 155:
#line 1387 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.opt_group_by_clause_) = nullptr;
  }
#line 4773 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 156:
#line 1390 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.opt_group_by_clause_) = new quickstep::ParseGroupBy((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].expression_list_));
  }
#line 4781 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 157:
#line 1395 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.opt_having_clause_) = nullptr;
  }
#line 4789 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 158:
#line 1398 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.opt_having_clause_) = new quickstep::ParseHaving((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].predicate_));
  }
#line 4797 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 159:
#line 1403 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.opt_order_by_clause_) = nullptr;
  }
#line 4805 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 160:
#line 1406 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.opt_order_by_clause_) = new quickstep::ParseOrderBy((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].order_commalist_));
  }
#line 4813 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 161:
#line 1411 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.opt_limit_clause_) = nullptr;
  }
#line 4821 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 162:
#line 1414 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    if ((yyvsp[0].numeric_literal_value_)->float_like()) {
      delete (yyvsp[0].numeric_literal_value_);
      (yyval.opt_limit_clause_) = nullptr;
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "LIMIT value must be an integer");
      YYERROR;
    } else {
      if ((yyvsp[0].numeric_literal_value_)->long_value() <= 0) {
        delete (yyvsp[0].numeric_literal_value_);
        (yyval.opt_limit_clause_) = nullptr;
        quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "LIMIT value must be positive");
        YYERROR;
      } else {
        (yyval.opt_limit_clause_) = new quickstep::ParseLimit((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].numeric_literal_value_));
      }
    }
  }
#line 4843 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 163:
#line 1433 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.opt_window_clause_) = nullptr;
  }
#line 4851 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 164:
#line 1436 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.opt_window_clause_) = (yyvsp[0].opt_window_clause_);
  }
#line 4859 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 165:
#line 1441 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.opt_window_clause_) = new quickstep::PtrList<quickstep::ParseWindow>();
    (yyval.opt_window_clause_)->push_back((yyvsp[0].window_definition_));
  }
#line 4868 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 166:
#line 1445 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.opt_window_clause_) = (yyvsp[-1].opt_window_clause_);
    (yyval.opt_window_clause_)->push_back((yyvsp[0].window_definition_));
  }
#line 4877 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 167:
#line 1451 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.window_definition_) = (yyvsp[-1].window_definition_);
    (yyval.window_definition_)->setName((yyvsp[-4].string_value_));
  }
#line 4886 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 168:
#line 1457 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.window_definition_) = new quickstep::ParseWindow((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].window_partition_by_list_), (yyvsp[-1].window_order_by_list_), (yyvsp[0].window_frame_info_));
  }
#line 4894 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 169:
#line 1462 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.window_partition_by_list_) = nullptr;
  }
#line 4902 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 170:
#line 1465 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.window_partition_by_list_) = (yyvsp[0].expression_list_);
  }
#line 4910 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 171:
#line 1470 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.window_order_by_list_) = nullptr;
  }
#line 4918 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 172:
#line 1473 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.window_order_by_list_) = (yyvsp[0].order_commalist_);
  }
#line 4926 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 173:
#line 1478 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.window_frame_info_) = nullptr;
  }
#line 4934 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 174:
#line 1481 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.window_frame_info_) = new quickstep::ParseFrameInfo((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-4].boolean_value_), (yyvsp[-2].numeric_literal_value_)->long_value(), (yyvsp[0].numeric_literal_value_)->long_value());
  }
#line 4942 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 175:
#line 1486 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.boolean_value_) = true;
  }
#line 4950 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 176:
#line 1489 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.boolean_value_) = false;
  }
#line 4958 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 178:
#line 1495 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.numeric_literal_value_) = new quickstep::NumericParseLiteralValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, "-1");
  }
#line 4966 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 179:
#line 1498 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.numeric_literal_value_) = new quickstep::NumericParseLiteralValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, "0");
  }
#line 4974 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 181:
#line 1504 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.numeric_literal_value_) = new quickstep::NumericParseLiteralValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, "-1");
  }
#line 4982 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 182:
#line 1507 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.numeric_literal_value_) = new quickstep::NumericParseLiteralValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, "0");
  }
#line 4990 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 183:
#line 1512 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.order_commalist_) = new quickstep::PtrList<quickstep::ParseOrderByItem>();
    (yyval.order_commalist_)->push_back((yyvsp[0].order_item_));
  }
#line 4999 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 184:
#line 1516 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.order_commalist_) = (yyvsp[-2].order_commalist_);
    (yyval.order_commalist_)->push_back((yyvsp[0].order_item_));
  }
#line 5008 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 185:
#line 1522 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.order_item_) = new quickstep::ParseOrderByItem((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].expression_), (yyvsp[-1].order_direction_), (yyvsp[0].order_direction_));
    delete (yyvsp[-1].order_direction_);
    delete (yyvsp[0].order_direction_);
  }
#line 5018 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 186:
#line 1529 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.order_direction_) = nullptr;
  }
#line 5026 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 187:
#line 1532 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.order_direction_) = new bool(true);
  }
#line 5034 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 188:
#line 1535 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.order_direction_) = new bool(false);
  }
#line 5042 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 189:
#line 1540 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.order_direction_) = nullptr;
  }
#line 5050 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 190:
#line 1543 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.order_direction_) = new bool(true);
  }
#line 5058 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 191:
#line 1546 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.order_direction_) = new bool(false);
  }
#line 5066 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 192:
#line 1552 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.predicate_) = nullptr;
  }
#line 5074 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 193:
#line 1555 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 5082 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 194:
#line 1560 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 5090 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 195:
#line 1565 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    if ((yyvsp[-2].predicate_)->getParsePredicateType() == quickstep::ParsePredicate::kDisjunction) {
      (yyval.predicate_) = (yyvsp[-2].predicate_);
    } else {
      (yyval.predicate_) = new quickstep::ParsePredicateDisjunction((yylsp[-2]).first_line, (yylsp[-2]).first_column);
      static_cast<quickstep::ParsePredicateDisjunction *>((yyval.predicate_))->addPredicate((yyvsp[-2].predicate_));
    }
    static_cast<quickstep::ParsePredicateDisjunction *>((yyval.predicate_))->addPredicate((yyvsp[0].predicate_));
  }
#line 5104 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 196:
#line 1574 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 5112 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 197:
#line 1579 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    if ((yyvsp[-2].predicate_)->getParsePredicateType() == quickstep::ParsePredicate::kConjunction) {
      (yyval.predicate_) = (yyvsp[-2].predicate_);
    } else {
      (yyval.predicate_) = new quickstep::ParsePredicateConjunction((yylsp[-2]).first_line, (yylsp[-2]).first_column);
      static_cast<quickstep::ParsePredicateConjunction *>((yyval.predicate_))->addPredicate((yyvsp[-2].predicate_));
    }
    static_cast<quickstep::ParsePredicateConjunction *>((yyval.predicate_))->addPredicate((yyvsp[0].predicate_));
  }
#line 5126 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 198:
#line 1588 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 5134 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 199:
#line 1593 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateNegation((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].predicate_));
  }
#line 5142 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 200:
#line 1596 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 5150 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 201:
#line 1601 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateBetween((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-4].expression_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 5158 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 202:
#line 1604 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateNegation(
        (yylsp[-4]).first_line, (yylsp[-4]).first_column,
        new quickstep::ParsePredicateBetween((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-5].expression_), (yyvsp[-2].expression_), (yyvsp[0].expression_)));
  }
#line 5168 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 203:
#line 1609 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    delete (yyvsp[-3].attribute_);
    (yyval.predicate_) = nullptr;
    NotSupported(&(yylsp[-2]), yyscanner, "NULL comparison predicates");
    YYERROR;
  }
#line 5179 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 204:
#line 1615 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    delete (yyvsp[-2].attribute_);
    (yyval.predicate_) = nullptr;
    NotSupported(&(yylsp[-1]), yyscanner, "NULL comparison predicates");
    YYERROR;
  }
#line 5190 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 205:
#line 1621 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateComparison((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].comparison_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 5198 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 206:
#line 1624 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.predicate_) = (yyvsp[-1].predicate_);
  }
#line 5206 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 207:
#line 1627 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateExists((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].subquery_expression_));
  }
#line 5214 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 208:
#line 1630 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateInTableQuery((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].expression_), (yyvsp[0].subquery_expression_));
  }
#line 5222 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 209:
#line 1633 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateInValueList((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-4].expression_), (yyvsp[-1].expression_list_));
  }
#line 5230 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 210:
#line 1636 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateNegation(
        (yylsp[-2]).first_line,
        (yylsp[-2]).first_column,
        new quickstep::ParsePredicateInTableQuery((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-3].expression_), (yyvsp[0].subquery_expression_)));
  }
#line 5241 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 211:
#line 1642 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateNegation(
        (yylsp[-4]).first_line,
        (yylsp[-4]).first_column,
        new quickstep::ParsePredicateInValueList((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-5].expression_), (yyvsp[-1].expression_list_)));
  }
#line 5252 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 212:
#line 1651 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    auto *arguments = new quickstep::PtrList<quickstep::ParseExpression>();
    arguments->push_back((yyvsp[-2].expression_));
    arguments->push_back((yyvsp[0].expression_));
    (yyval.expression_) = new quickstep::ParseFunctionCall((yylsp[-2]).first_line, (yylsp[-2]).first_column, false, (yyvsp[-1].binary_operation_), arguments);
  }
#line 5263 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 213:
#line 1657 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 5271 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 214:
#line 1662 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    auto *arguments = new quickstep::PtrList<quickstep::ParseExpression>();
    arguments->push_back((yyvsp[-2].expression_));
    arguments->push_back((yyvsp[0].expression_));
    (yyval.expression_) = new quickstep::ParseFunctionCall((yylsp[-2]).first_line, (yylsp[-2]).first_column, false, (yyvsp[-1].binary_operation_), arguments);
  }
#line 5282 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 215:
#line 1668 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 5290 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 216:
#line 1673 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    auto *arguments = new quickstep::PtrList<quickstep::ParseExpression>();
    arguments->push_back((yyvsp[0].expression_));
    (yyval.expression_) = new quickstep::ParseFunctionCall((yylsp[-1]).first_line, (yylsp[-1]).first_column, false, (yyvsp[-1].unary_operation_), arguments);
  }
#line 5300 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 217:
#line 1678 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 5308 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 218:
#line 1683 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.expression_) = (yyvsp[0].attribute_);
  }
#line 5316 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 219:
#line 1686 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.expression_) = new quickstep::ParseScalarLiteral((yyvsp[0].literal_value_));
  }
#line 5324 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 220:
#line 1689 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.expression_) = (yyvsp[0].function_call_);
  }
#line 5332 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 221:
#line 1692 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyvsp[-2].function_call_)->setWindowName((yyvsp[0].string_value_));
    (yyval.expression_) = (yyvsp[-2].function_call_);
  }
#line 5341 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 222:
#line 1696 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyvsp[-4].function_call_)->setWindow((yyvsp[-1].window_definition_));
    (yyval.expression_) = (yyvsp[-4].function_call_);
  }
#line 5350 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 223:
#line 1700 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 5358 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 224:
#line 1703 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 5366 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 225:
#line 1706 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 5374 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 226:
#line 1709 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 5382 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 227:
#line 1712 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.expression_) = (yyvsp[-1].expression_);
  }
#line 5390 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 228:
#line 1715 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.expression_) = (yyvsp[0].subquery_expression_);
  }
#line 5398 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 229:
#line 1720 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall(
        (yylsp[-2]).first_line, (yylsp[-2]).first_column, false, (yyvsp[-2].string_value_), new quickstep::PtrList<quickstep::ParseExpression>());
  }
#line 5407 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 230:
#line 1724 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall(
        (yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].string_value_), new quickstep::ParseStar((yylsp[-1]).first_line, (yylsp[-1]).first_column));
  }
#line 5416 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 231:
#line 1728 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall((yylsp[-3]).first_line, (yylsp[-3]).first_column, false, (yyvsp[-3].string_value_), (yyvsp[-1].expression_list_));
  }
#line 5424 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 232:
#line 1731 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall((yylsp[-4]).first_line, (yylsp[-4]).first_column, true, (yyvsp[-4].string_value_), (yyvsp[-1].expression_list_));
  }
#line 5432 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 233:
#line 1736 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    auto *arguments = new quickstep::PtrList<quickstep::ParseExpression>();
    arguments->push_back((yyvsp[-3].expression_));
    arguments->push_back(new quickstep::ParseScalarLiteral(
        new quickstep::StringParseLiteralValue(
            new quickstep::ParseString((yylsp[-1]).first_line,
                                       (yylsp[-1]).first_column,
                                       (yyvsp[-1].data_type_)->getType().getName()),
            nullptr)));
    delete (yyvsp[-1].data_type_);
    auto *name = new quickstep::ParseString((yylsp[-5]).first_line, (yylsp[-5]).first_column, "cast");
    (yyval.expression_) = new quickstep::ParseFunctionCall(
        (yylsp[-5]).first_line, (yylsp[-5]).first_column, false, name, arguments);
  }
#line 5451 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 234:
#line 1750 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    auto *arguments = new quickstep::PtrList<quickstep::ParseExpression>();
    arguments->push_back((yyvsp[-3].expression_));
    arguments->push_back(new quickstep::ParseScalarLiteral(
        new quickstep::StringParseLiteralValue((yyvsp[-1].string_value_), nullptr)));
    auto *name = new quickstep::ParseString((yylsp[-5]).first_line, (yylsp[-5]).first_column, "cast");
    (yyval.expression_) = new quickstep::ParseFunctionCall(
        (yylsp[-5]).first_line, (yylsp[-5]).first_column, false, name, arguments);
  }
#line 5465 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 235:
#line 1761 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    auto *arguments = new quickstep::PtrList<quickstep::ParseExpression>();
    arguments->push_back((yyvsp[-1].expression_));
    arguments->push_back(new quickstep::ParseScalarLiteral(
        new quickstep::StringParseLiteralValue((yyvsp[-3].string_value_), nullptr)));
    auto *name = new quickstep::ParseString((yylsp[-5]).first_line, (yylsp[-5]).first_column, "extract");
    (yyval.expression_) = new quickstep::ParseFunctionCall(
        (yylsp[-5]).first_line, (yylsp[-5]).first_column, false, name, arguments);
  }
#line 5479 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 236:
#line 1772 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    auto *arguments = new quickstep::PtrList<quickstep::ParseExpression>();
    arguments->push_back((yyvsp[-3].expression_));
    arguments->push_back(new quickstep::ParseScalarLiteral((yyvsp[-1].numeric_literal_value_)));
    auto *name = new quickstep::ParseString((yylsp[-5]).first_line, (yylsp[-5]).first_column, "substring");
    (yyval.expression_) = new quickstep::ParseFunctionCall(
        (yylsp[-5]).first_line, (yylsp[-5]).first_column, false, name, arguments);
  }
#line 5492 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 237:
#line 1780 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    auto *arguments = new quickstep::PtrList<quickstep::ParseExpression>();
    arguments->push_back((yyvsp[-5].expression_));
    arguments->push_back(new quickstep::ParseScalarLiteral((yyvsp[-3].numeric_literal_value_)));
    arguments->push_back(new quickstep::ParseScalarLiteral((yyvsp[-1].numeric_literal_value_)));
    auto *name = new quickstep::ParseString((yylsp[-7]).first_line, (yylsp[-7]).first_column, "substring");
    (yyval.expression_) = new quickstep::ParseFunctionCall(
        (yylsp[-7]).first_line, (yylsp[-7]).first_column, false, name, arguments);
  }
#line 5506 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 238:
#line 1791 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.expression_) = new quickstep::ParseSimpleCaseExpression((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].expression_), (yyvsp[-2].simple_when_clause_list_), (yyvsp[-1].expression_));
  }
#line 5514 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 239:
#line 1794 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.expression_) = new quickstep::ParseSearchedCaseExpression((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-2].searched_when_clause_list_), (yyvsp[-1].expression_));
  }
#line 5522 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 240:
#line 1799 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.simple_when_clause_list_) = new quickstep::PtrVector<quickstep::ParseSimpleWhenClause>;
    (yyval.simple_when_clause_list_)->push_back((yyvsp[0].simple_when_clause_));
  }
#line 5531 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 241:
#line 1803 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.simple_when_clause_list_) = (yyvsp[-1].simple_when_clause_list_);
    (yyval.simple_when_clause_list_)->push_back((yyvsp[0].simple_when_clause_));
  }
#line 5540 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 242:
#line 1809 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.simple_when_clause_) = new quickstep::ParseSimpleWhenClause((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 5548 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 243:
#line 1814 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.searched_when_clause_list_) = new quickstep::PtrVector<quickstep::ParseSearchedWhenClause>;
    (yyval.searched_when_clause_list_)->push_back((yyvsp[0].searched_when_clause_));
  }
#line 5557 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 244:
#line 1818 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.searched_when_clause_list_) = (yyvsp[-1].searched_when_clause_list_);
    (yyval.searched_when_clause_list_)->push_back((yyvsp[0].searched_when_clause_));
  }
#line 5566 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 245:
#line 1824 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.searched_when_clause_) = new quickstep::ParseSearchedWhenClause((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-2].predicate_), (yyvsp[0].expression_));
  }
#line 5574 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 246:
#line 1829 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.expression_) = NULL;
  }
#line 5582 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 247:
#line 1832 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 5590 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 248:
#line 1837 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.expression_list_) = new quickstep::PtrList<quickstep::ParseExpression>();
    (yyval.expression_list_)->push_back((yyvsp[0].expression_));
  }
#line 5599 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 249:
#line 1841 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.expression_list_) = (yyvsp[-2].expression_list_);
    (yyval.expression_list_)->push_back((yyvsp[0].expression_));
  }
#line 5608 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 250:
#line 1847 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.literal_value_) = new quickstep::NullParseLiteralValue((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 5616 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 251:
#line 1850 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.literal_value_) = (yyvsp[0].numeric_literal_value_);
  }
#line 5624 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 252:
#line 1853 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.literal_value_) = (yyvsp[0].numeric_literal_value_);
  }
#line 5632 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 253:
#line 1856 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    /**
     * NOTE(chasseur): This case exhibits a shift/reduce conflict with the
     * minus character as a 'unary_operation' followed by a numeric literal.
     * Because Bison prefers to shift rather than reduce, this case has
     * precedence (i.e. the parser will prefer to interpret the ambiguous
     * pattern as a negative number literal rather than a unary minus operation
     * applied to a non-negative number literal).
     **/
    (yyvsp[0].numeric_literal_value_)->prependMinus();
    (yyval.literal_value_) = (yyvsp[0].numeric_literal_value_);
  }
#line 5649 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 254:
#line 1868 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.literal_value_) = new quickstep::StringParseLiteralValue((yyvsp[0].string_value_),
                                                nullptr);  // No explicit type.
  }
#line 5658 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 255:
#line 1872 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    /**
     * NOTE(chasseur): This case exhibits a shift/reduce conflict with the
     * plain TOKEN_INTERVAL case in 'data_type' reduced and used in the case
     * below. Because Bison prefers to shift rather than reduce, this case has
     * precedence (i.e. the special
     * StringParseLiteralValue::ParseAmbiguousInterval() method will be used to
     * parse the string as either one of the interval types, rather than an
     * error being emitted because of an ambiguous type).
     **/
    quickstep::StringParseLiteralValue *parse_value;
    if (quickstep::StringParseLiteralValue::ParseAmbiguousInterval((yyvsp[0].string_value_), &parse_value)) {
      (yyval.literal_value_) = parse_value;
    } else {
      (yyval.literal_value_) = nullptr;
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "Failed to parse literal as specified type");
      YYERROR;
    }
  }
#line 5682 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 256:
#line 1891 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    quickstep::StringParseLiteralValue *parse_value;
    const std::string &datetime_type_value = (yyvsp[0].string_value_)->value();
    if (quickstep::StringParseLiteralValue::ParseAmbiguousInterval(
        &((yyvsp[-1].string_value_)->append((" " + datetime_type_value).c_str(), datetime_type_value.length() + 1)),
        &parse_value)) {
      (yyval.literal_value_) = parse_value;
    } else {
      (yyval.literal_value_) = nullptr;
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "Failed to parse literal as specified type");
      YYERROR;
    }
  }
#line 5700 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 257:
#line 1904 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    quickstep::StringParseLiteralValue *parse_value
        = new quickstep::StringParseLiteralValue((yyvsp[0].string_value_), &((yyvsp[-1].data_type_)->getType()));
    delete (yyvsp[-1].data_type_);
    if (!parse_value->tryExplicitTypeParse()) {
      delete parse_value;
      (yyval.literal_value_) = nullptr;
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "Failed to parse literal as specified type");
      YYERROR;
    } else {
      (yyval.literal_value_) = parse_value;
    }
  }
#line 5718 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 258:
#line 1919 "../SqlParser.ypp" /* yacc.c:1661  */
    {
     (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("YEAR"));
  }
#line 5726 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 259:
#line 1922 "../SqlParser.ypp" /* yacc.c:1661  */
    {
     (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("MONTH"));
  }
#line 5734 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 260:
#line 1925 "../SqlParser.ypp" /* yacc.c:1661  */
    {
     (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("DAY"));
  }
#line 5742 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 261:
#line 1928 "../SqlParser.ypp" /* yacc.c:1661  */
    {
     (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("HOUR"));
  }
#line 5750 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 262:
#line 1931 "../SqlParser.ypp" /* yacc.c:1661  */
    {
     (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("MINUTE"));
  }
#line 5758 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 263:
#line 1934 "../SqlParser.ypp" /* yacc.c:1661  */
    {
     (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("SECOND"));
  }
#line 5766 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 264:
#line 1939 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.literal_value_list_) = new quickstep::PtrList<quickstep::ParseScalarLiteral>();
    (yyval.literal_value_list_)->push_back(new quickstep::ParseScalarLiteral((yyvsp[0].literal_value_)));
  }
#line 5775 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 265:
#line 1943 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.literal_value_list_) = (yyvsp[-2].literal_value_list_);
    (yyval.literal_value_list_)->push_back(new quickstep::ParseScalarLiteral((yyvsp[0].literal_value_)));
  }
#line 5784 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 266:
#line 1949 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.attribute_) = new quickstep::ParseAttribute((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].string_value_));
  }
#line 5792 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 267:
#line 1952 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.attribute_) = new quickstep::ParseAttribute((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].string_value_), (yyvsp[-2].string_value_));
  }
#line 5800 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 268:
#line 1957 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.attribute_list_) = new quickstep::PtrList<quickstep::ParseAttribute>();
    (yyval.attribute_list_)->push_back((yyvsp[0].attribute_));
  }
#line 5809 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 269:
#line 1961 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.attribute_list_) = (yyvsp[-2].attribute_list_);
    (yyval.attribute_list_)->push_back((yyvsp[0].attribute_));
  }
#line 5818 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 270:
#line 1968 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kEqual);
  }
#line 5826 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 271:
#line 1971 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kNotEqual);
  }
#line 5834 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 272:
#line 1974 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kLess);
  }
#line 5842 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 273:
#line 1977 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kLessOrEqual);
  }
#line 5850 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 274:
#line 1980 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kGreater);
  }
#line 5858 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 275:
#line 1983 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kGreaterOrEqual);
  }
#line 5866 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 276:
#line 1986 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kLike);
  }
#line 5874 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 277:
#line 1989 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kNotLike);
  }
#line 5882 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 278:
#line 1992 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kRegexMatch);
  }
#line 5890 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 279:
#line 1995 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kNotRegexMatch);
  }
#line 5898 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 280:
#line 2000 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    /**
     * NOTE(chasseur): This case exhibits a shift/reduce conflict with the
     * '-' TOKEN_UNSIGNED_NUMVAL case in 'literal_value'. Because Bison prefers
     * to shift rather than reduce, the case in 'literal_value' has precedence
     * over this one.
     **/
    (yyval.unary_operation_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("-"));
  }
#line 5912 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 281:
#line 2011 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.binary_operation_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("+"));
  }
#line 5920 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 282:
#line 2014 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.binary_operation_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("-"));
  }
#line 5928 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 283:
#line 2019 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.binary_operation_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("%"));
  }
#line 5936 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 284:
#line 2022 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.binary_operation_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("*"));
  }
#line 5944 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 285:
#line 2025 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.binary_operation_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, std::string("/"));
  }
#line 5952 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 286:
#line 2031 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.string_list_) = new quickstep::PtrList<quickstep::ParseString>();
    (yyval.string_list_)->push_back((yyvsp[0].string_value_));
  }
#line 5961 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 287:
#line 2035 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.string_list_) = (yyvsp[-2].string_list_);
    (yyval.string_list_)->push_back((yyvsp[0].string_value_));
  }
#line 5970 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 288:
#line 2041 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.string_value_) = (yyvsp[0].string_value_);
  }
#line 5978 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 289:
#line 2044 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    if ((yyvsp[0].string_value_)->value().empty()) {
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "Zero-length identifier");
    }
    (yyval.string_value_) = (yyvsp[0].string_value_);
  }
#line 5989 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 290:
#line 2052 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.boolean_value_) = true;
  }
#line 5997 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 291:
#line 2055 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.boolean_value_) = true;
  }
#line 6005 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 292:
#line 2058 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.boolean_value_) = false;
  }
#line 6013 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 293:
#line 2061 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.boolean_value_) = false;
  }
#line 6021 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 294:
#line 2067 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    (yyval.command_) = new quickstep::ParseCommand((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].command_argument_list_));
  }
#line 6029 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 295:
#line 2072 "../SqlParser.ypp" /* yacc.c:1661  */
    {
    quickstep::PtrVector<quickstep::ParseString> *argument_list = (yyvsp[-1].command_argument_list_);
    argument_list->push_back((yyvsp[0].string_value_));
    (yyval.command_argument_list_) = argument_list;
  }
#line 6039 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;

  case 296:
#line 2077 "../SqlParser.ypp" /* yacc.c:1661  */
    { /* Epsilon, an empy match. */
    (yyval.command_argument_list_) = new quickstep::PtrVector<quickstep::ParseString>();
  }
#line 6047 "SqlParser_gen.cpp" /* yacc.c:1661  */
    break;


#line 6051 "SqlParser_gen.cpp" /* yacc.c:1661  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, yyscanner, parsedStatement, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, yyscanner, parsedStatement, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, yyscanner, parsedStatement);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, yyscanner, parsedStatement);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, yyscanner, parsedStatement, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, yyscanner, parsedStatement);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, yyscanner, parsedStatement);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 2081 "../SqlParser.ypp" /* yacc.c:1906  */


void NotSupported(const YYLTYPE *location, yyscan_t yyscanner, const std::string &feature) {
  std::string msg;
  msg.append(feature);
  msg.append(" is not supported yet");

  quickstep_yyerror(location, yyscanner, nullptr, msg.c_str());
}

int quickstep_yyget_line_number(const YYLTYPE *yyloc) {
  return yyloc->first_line;
}

int quickstep_yyget_column_number(const YYLTYPE *yyloc) {
  return yyloc->first_column;
}
