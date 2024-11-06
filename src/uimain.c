#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main() {
  char input[100];
  List *history = init_history();
  char **tokens = NULL;
 
  while (1) {
    printf("Please enter a phrase: \n");
    if (scanf("%99[^\n]", input) != 1) {// read up to 99 characters
      fprintf(stderr, "Error with input.\n");
      break;
    }
    
    add_history(history, input);
    tokens = tokenize(input);
    if (tokens == NULL) {
      fprintf(stderr, "Tokenize failure.\n");
      continue;
    }

    char option;
    printf("Type: h= history, p = to print tokens, q= quit, t=tokenize\n");
    if (scanf(" %c", &option) != 1) {//user choice
      fprintf(stderr, "Error reading option.\n");
      break;
    }

    if (option == 'h') {
      print_history(history);
    } else if (option == 'p') {
      print_tokens(tokens);
    } else if (option == 'q') {
      break;
    } else if (option =='t'){
      continue;
    }else{
      printf("Invalid option,please try again");
    }
  }//end of while

  free_tokens(tokens);
  free_history(history);
  return 0;
}
