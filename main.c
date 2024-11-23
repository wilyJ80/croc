#include "./lexer/lexer.h"
#include "./lexer/types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Error. Usage: croc <code>\n");
    return EXIT_FAILURE;
  }

  FILE *fd;

  fd = fopen(argv[1], "r");
  if (fd == NULL) {
    fprintf(stderr, "Error opening file\n");
    return EXIT_FAILURE;
  }

  int lineCount = 1;

  // lexing!
  while (true) {
    struct Token token = lexerGetNextChar(fd, &lineCount);
    if (token.category == END_OF_FILE) {
      fclose(fd);
      return EXIT_SUCCESS;
    }
    switch (token.category) {
    case MALFORMED_TOKEN:
      printf("ERROR: MALFORMED TOKEN %s ON LINE %d\n", token.lexeme, lineCount);
      exit(EXIT_FAILURE);
    case RSV:
      printf("<RSV, %s>", token.lexeme);
      break;
    case ID:
      printf("<ID, %s>", token.lexeme);
      break;
    case CHARCON:
      printf("<CHARCON, %c>", token.lexeme[1]);
      break;
    case STRINGCON:
      printf("<STRINGCON, %s>", token.lexeme);
      break;
    case INTCON:
      printf("<INTCON, %d>", token.intValue);
      break;
    case REALCON:
      printf("<REALCON, %lf>", token.doubleValue);
    case SIGN:
      switch (token.signCode) {
      case ASSIGN:
        printf("<SN, ASSIGN>");
        break;
      case PLUS:
        printf("<SN, PLUS>");
        break;
      case MINUS:
        printf("<SN, MINUS>");
        break;
      case STAR:
        printf("<SN, STAR>");
        break;
      case SLASH:
        printf("<SN, SLASH>");
        break;
      case OPEN_PAR:
        printf("<SN, OPEN_PAR>");
        break;
      case CLOSE_PAR:
        printf("<SN, CLOSE_PAR>");
        break;
      case OPEN_BRACK:
        printf("<SN, OPEN_BRACK>");
        break;
      case CLOSE_BRACK:
        printf("<SN, CLOSE_BRACK>");
        break;
      case COMMA:
        printf("<SN, COMMA>");
        break;
      case COMPARISON:
        printf("<SN, COMPARISON>");
        break;
      case REF:
        printf("<SN, REF>");
        break;
      case AND:
        printf("<SN, AND>");
        break;
      case OR:
        printf("<SN, OR>");
        break;
      case SMALLER_THAN:
        printf("<SN, SMALLER_THAN>");
        break;
      case LARGER_THAN:
        printf("<SN, LARGER_THAN>");
        break;
      case NEGATION:
        printf("<SN, NEGATION>");
        break;
      case DIFFERENT:
        printf("<SN, DIFFERENT>");
        break;
      case SMALLER_EQUAL:
        printf("<SN, SMALLER_EQUAL>");
        break;
      case LARGER_EQUAL:
        printf("<SN, LARGER_EQUAL>");
        break;
      }
      break;
    }
    printf("\n");
  }
}
