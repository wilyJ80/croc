#include "lexer_test.h"
#include "parser_integration_tests.h"
#include "parser_unit_tests.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  lexerTest();
  lexerCharconTest();
  lexerCharconTest2();

  printf("--- Lexer tests passed\n");

  opRelTest();
  opRelTest2();
  fatorConTest();
  fatorNegFatorTest();
  fatorArrayOutroTest();
  fatorArrayOutroTest2();
  fatorArrayUniTest();
  fatorSingle();
  declVarArrayBadInitCurly();
  // fatorArrayMultTest();

  printf("--- Parser unit tests passed\n");

  progStartKeyword();

  declListVarInvalidType();
  declVarNoId();
  declListVarMulti();
  declListVarMultiFail();
  declVarArrayInvalidSubscript();
  declVarArrayDidntClose();
  declVarBadInit();
  declVarArrayBadInitCurly();
  declVarArrayMultiTooMany();
  declVarArrayInvalidTypeInit();
  declVarArrayMultiInit();
  declVarArrayBadClose();

  declDefProcNoId();
  declDefProcProtNoOpenParen();
  declDefProcProtoInvalidParamType();
  declDefProcProtoNoParamId();
  declDefProcProtoNoValidTokenAfterType();
  declDefProcProtoUnclosedArrayParam();
  declDefProcProtoInvalid2dArrayOpen();
  declDefProcProtoInvalid2dArrayClose();
  declDefProcProtoInvalid3dArray();
  declDefProcProtoMultiParams();

  printf("--- Parser integration tests passed\n");

  return EXIT_SUCCESS;
}
