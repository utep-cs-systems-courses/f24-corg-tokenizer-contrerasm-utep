#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#include <string.h> //added for input

int main() {
  char input[100];// testing ****REMOVE ME******
  List *history = init_history();
  char **tokens = NULL;
 
  while (1) {
    printf("Please enter a phrase: \n");
    // scanf("%s",input);
    // printf("User input: %s\n",input);
    fgets(input,100,stdin);
    printf(input);
    /**
    printf("prior to add_history");//testing *****REMOVE ME******
    add_history(history, input);
    printf("add_history success");//testing ****REMOVE ME*******
    tokens = tokenize(input);
    printf("tokenize success");//testing *****REMOVE ME*****
    
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
    **/
  }
  return 0;
}
