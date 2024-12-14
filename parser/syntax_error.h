#ifndef SYNTAX_ERROR_H
#define SYNTAX_ERROR_H

#include "../lexer/types.h"
#include <stdbool.h>

enum SYNTAX_ERROR {
  NO_ERROR,
  // prog
  INVALID_PROG_START_KEYWORD,
  // decl_list_var
  TYPE_NOT_DETECTED,
  INVALID_TYPE,
  INVALID_VAR_LIST_DEC,
  // decl_var
  NO_VAR_ID,
  NO_VAR_ASSIGNMENT,
  INVALID_VAR_TYPE_INIT,
  INVALID_ARRAY_SUBSCRIPT_DEC,
  INVALID_ARRAY_BRACKET_DEC_OPEN,
  INVALID_ARRAY_BRACKET_DEC_CLOSE,
  INVALID_ARRAY_INIT_CURLY_OPEN,
  INVALID_ARRAY_INIT_CURLY_CLOSE,
  INVALID_ARRAY_TYPE_INIT,
  INVALID_ARRAY_DIMENSION_DECLARATION,
  INVALID_ARRAY_MULTIPLE_ITEM_INIT,
  INVALID_ARRAY_END,
  // decl_def_proc
  INVALID_FUNCTION_KEYWORD,
  NO_FUNCTION_ID,
  NO_PROTO_ID,
  INVALID_PROTO_PAREN_OPEN,
  INVALID_PROTO_PAREN_CLOSE,
  NO_PROTO_TYPE_AFTER_REF,
  INVALID_PROTO_PARAM_TYPE,
  NO_PROTO_VALID_TOKEN_AFTER_TYPE,
  INVALID_ARRAY_PROTO_PARAM_BRACKET_OPEN,
  INVALID_ARRAY_PROTO_PARAM_BRACKET_CLOSE,
  INVALID_PROTO_PARAM_LIST,
  NO_PROTO_VALID_TOKEN_AFTER_BRACKET_CLOSE,
  NO_DEF_ID,
  INVALID_DEF_PAREN_OPEN,
  INVALID_DEF_PAREN_CLOSE,
  INVALID_DEF_PARAM_TYPE,
  NO_DEF_VALID_TOKEN_AFTER_ID,
  NO_DEF_PARAM_ID,
  INVALID_ARRAY_DEF_PARAM_SUBSCRIPT_TYPE,
  INVALID_ARRAY_DEF_PARAM_BRACKET_OPEN,
  INVALID_ARRAY_DEF_PARAM_BRACKET_CLOSE,
  INVALID_DEF_PARAM_LIST,
  NO_DEF_END_KEYWORD,
  NO_DEF_VALID_TOKEN_AFTER_PAREN,
  NO_FUNCTION_END_PAREN_CLOSE,
  // cmd
  INVALID_CMD_CONTENT,
  // cmd (do)
  INVALID_FUNCTION_CALL_ID,
  INVALID_FUNCTION_CALL_PAREN_OPEN,
  INVALID_FUNCTION_CALL_PAREN_CLOSE,
  INVALID_FUNCTION_CALL_ARGUMENT_LIST,
  // cmd (while)
  INVALID_WHILE_PAREN_OPEN,
  INVALID_WHILE_PAREN_CLOSE,
  NO_WHILE_END_KEYWORD,
  // cmd (var): to disambiguate "var" from variable, we call it for
  NO_FOR_ID,
  NO_FOR_FROM,
  NO_FOR_EXPR1,
  NO_FOR_TO_OR_DT,
  NO_FOR_EXPR2,
  INVALID_FOR_BY_INC_OR_DEC_TYPE,
  NO_FOR_END_KEYWORD,
  // cmd (if)
  INVALID_IF_PAREN_OPEN,
  INVALID_IF_PAREN_CLOSE,
  INVALID_ELIF_PAREN_OPEN,
  INVALID_ELIF_PAREN_CLOSE,
  NO_IF_END_KEYWORD,
  // getint
  NO_GETINT_ID,
  // getreal
  NO_GETREAL_ID,
  // getchar
  NO_GETCHAR_ID,
  // getstr
  NO_GETSTR_ID,
  // putint
  INVALID_PUTINT_ELEMENT,
  // putreal
  INVALID_PUTREAL_ELEMENT,
  // putchar
  INVALID_PUTCHAR_ELEMENT,
  // putstr
  INVALID_PUTSTR_ELEMENT,
  // atrib
  NO_ATRIB_ID,
  NO_ATRIB_ASSIGN,
  NO_ATRIB_EXPR,
  NO_ATRIB_VALID_TOKEN_AFTER_ID,
  NO_ATRIB_BRACKET_CLOSE,
  // expr
  NO_EXPR_EXPR_SIMP,
  NO_EXPR_EXPR_SIMP_AFTER_OP_REL,
  // expr_simp
  NO_EXPR_SIMP_TERM,
  NO_EXPR_SIMP_TERM_VALID_SIGN_BEFORE,
  NO_EXPR_SIMP_TERM_VALID_SIGN_AFTER,
  NO_EXPR_SIMP_TERM_AFTER_VALID_SIGN,
  // termo
  NO_TERM_FACTOR,
  NO_TERM_FACTOR_VALID_SIGN_AFTER,
  NO_TERM_FACTOR_AFTER_FACTOR_VALID_SIGN,
  // fator
  NO_FACTOR_VALID_START_SYMBOL,
  NO_FACTOR_VALID_SYMBOL_AFTER_ID,
  INVALID_FACTOR_ARRAY_BRACKET_OPEN,
  INVALID_FACTOR_ARRAY_BRACKET_CLOSE,
  INVALID_FACTOR_EXPR_PAREN_OPEN,
  INVALID_FACTOR_EXPR_PAREN_CLOSE,
  NO_FACTOR_AFTER_BANG,
  // op_rel
  INVALID_OPERATOR,
};

void printSyntaxError(enum SYNTAX_ERROR error, int *lineCount);

struct ErrorMessage {
  enum SYNTAX_ERROR error;
  const char *message;
};

#endif // !SYNTAX_ERROR_H
