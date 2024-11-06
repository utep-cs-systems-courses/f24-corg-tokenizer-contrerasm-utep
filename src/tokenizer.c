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
    if(space_char(c)){
      return 0;}
    else{
      return 1;}
  }//end of non_space_char
  
  char *token_start(char *tkn){
    if(*tkn =='\0'){
      return 0;}//rerturn 0 if string doesnt contain tokens
    while(space_char(*tkn)){
      tkn++;}
    return tkn;
  }//end of token_start
  
  int count_tokens(char *tkn){
    int num_tokens=0;
    while(*tkn !='\0'){//add token_start
      tkn = token_start(tkn);
      tkn = token_terminator(tkn);
      num_tokens++;
    }
	return num_tokens;
  }//end of count_tokens
  
  char *token_terminator(char *tkn){
    while(non_space_char(*tkn)){
      tkn++;}
    return tkn;
  }//end of token_terminator

  char *copy_str(char *intStr, short len){
    char *str_cpy= malloc((len+1) * sizeof(char));
    int i;
    for(i=0;i<len;i++){
      str_cpy[i] = intStr[i];
    }
    str_cpy[i] ='\0';
    return str_cpy;
  }//end of copy str
  
  char **tokenize(char *str){
    char **tokVec, **tvp;
    int numTokens = count_tokens(str);
    tokVec = (char**)calloc(numTokens+1,sizeof(char *));//allocate memory +1 for terminal symbol
    char *start=token_start(str);
    while(start){
      char *end = token_terminator(start);
      char *tokCopy = copy_str(str,numTokens);
      *tvp=tokCopy;
      tvp++;
      start=token_start(end);
    }
    *tvp = 0;
    return tokVec;
  }//end of tokenize
  
  void print_tokens(char **tokens){
    if(tokens == NULL){
      return; }
    
    for(int i=0; tokens[i] != NULL;i++){
      printf("Token[%d]: %s\n",i,tokens[i]);
    }
  }
  
  void free_tokens(char **tokens){
    if(tokens == NULL){
      return;}
    for(int i=0;tokens[i] != NULL;i++){
      free(tokens[i]);
    }
    free(tokens);
  }//end of free_tokens
