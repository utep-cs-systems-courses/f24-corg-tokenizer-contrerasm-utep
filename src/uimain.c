#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#include <string.h> //added for input
#include <stdlib.h>


int main() {

  char input[100];//input for strings
  char choice;//users input
  int id;//id for token
  char *storage;//holds tokens
  List *history=init_history();//start list

  printf("Welcome\n");

  while(1){
    printf("\n Please select: t=tokenize strings, h=get history, g=get an item, q=quit\n");
    scanf("\n%c",&choice);

    switch(choice){
    case 't':
      printf("\n Enter a string: \n");
      scanf(" %[^\n]",&input);
      char **newTokens=tokenize(input);
      printf("\n");
      add_history(history,input);
      print_tokens(newTokens);
      free_tokens(newTokens);
      break;
    case 'h':
      print_history(history);
      break;
    case 'g':
      printf("\nPlease choose based on id\n");
      scanf("%d",&id);

      if(get_history(history,id) != NULL){
	storage = get_history(history,id);
      }
      else{
	break;
      }
      char **picked = tokenize(storage);
      printf("\nSelected:\n");
      print_tokens(picked);
      break;

    case 'q':
      free_history(history);
      printf("ending program");
      return 0;
    default:
      printf("\nError,default hit");
      
    }//end of switch
  }//end of while
  return 0;
}//end of main

