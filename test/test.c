#include "lexer_test.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  lexerTest();
  lexerCharconTest();
  lexerCharconTest2();

  printf("--- Lexer test passed\n");

  return EXIT_SUCCESS;
}
