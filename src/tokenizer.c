#include <stdio.h>
#include "tokenizer.h"
#include <stdlib.h>

  int space_char(char c){//returns true if character is a white space character.
    if(c=='\t'|| c=='\n'|| c==' '){
      return 1;}
    else{
      return 0;}
  }//end of space_char
  
  int non_space_char(char c){//returns true if character is not a white space character
    return !space_char(c);
    
  }//end of non_space_char
  
  char *token_start(char *tkn){
    if(tkn==NULL||*tkn =='\0'){//check if empty
      return NULL;
    }
    while(*tkn!='\0'&& space_char(*tkn)){//continue pointer until terminator or not a white space
      tkn++;
    }
    return (*tkn=='\0') ?NULL :tkn;//terminator return null else pointer to first character
  }//end of token_start
  
  int count_tokens(char *tkn){
    int count =0;
    char *start =tkn;

    if(tkn==NULL){//check if empty
      return 0;
    }
    while((start =token_start(start)) != NULL){//count tokens while theres tokens remain
      count ++;
      start= token_terminator(start);//identify next token
    }
    return count;
  }//end of count_tokens
  
  char *token_terminator(char *tkn){
    while(*tkn != '\0' && non_space_char(*tkn)){//go through characters
      tkn++;}
    return tkn;//return then end of the token
  }//end of token_terminator

  char *copy_str(char *intStr, short len){
    char *copy = malloc((len+1)*sizeof(char));//allocate memory

    for (int i=0; i<len;i++){
      copy[i]= intStr[i];
    }
    
    copy[len]='\0';
    return copy;
  }//end of copy str
  
  char **tokenize(char *str){
    int total = count_tokens(str);
    char *token = str;
    char **tokens = malloc(sizeof(char*) * (total+1));//allocate memormy for token array

    for( int i=0; i<total;i++){
      
      token=token_start(token);//pointer to start of token
      char *tokEnd= token_terminator(token);//find end of current token
      int len = tokEnd-token;//calculate the length
      tokens[i]=copy_str(token,len);//copys into array index i
      token=tokEnd;//pointer to start of next token
    }
    
    tokens[total]='\0';//mark the end of token list
    return tokens;
  }//end of tokenize
  
  void print_tokens(char **tokens){
    if(tokens == NULL){
      return; }
    
    for(int i=0; tokens[i] != NULL;i++){//traverse token array
      printf("Token[%d]: %s\n",i,tokens[i]);
    }
  }
  
  void free_tokens(char **tokens){
    if(tokens == NULL){
      return;}
    for(int i=0;tokens[i] != NULL;i++){//traverse token array
      free(tokens[i]);
    }
    free(tokens);
  }//end of free_tokens
