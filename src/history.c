#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

List *init_history(){
  List *lst= (List*) malloc(sizeof(List));
  lst ->root =NULL;
  return lst;
}

void add_history(List *list, char *str){
  if(list == NULL || str == NULL){
    return;
  }
  Item *newAdd =malloc(sizeof(Item));
  if(newAdd==NULL){
    printf("memory failure");
    return;
  }

  int id =0;
  Item *cur = list->root;
  while (cur !=NULL){
    id++;
    cur = cur->next;
  }

  newAdd->id =id;
  newAdd->str = maloc(sizeof(;//add malloc for size, online test.
  newAdd->next =NULL;

  if(list->root==NULL){
    list->root=newAdd;
    return;
  }
 
}//end of add_history

char *get_history(List *list, int id){
  Item *cur=list->root;
  if(cur==NULL){
   return "No history stored";}
  while(cur!=NULL){
   if(cur->id==id){
    return cur->str;}
   cur=cur->next;}
  return "Error in get history";}//end of get history
 
void print_history(List *list){
  if(list ==NULL){
    printf("List is empty\n");
  }
  
  Item *cur = list->root;
  if(cur==NULL){
   printf("Nothing available to print\n");
   return;
  }
  printf("All input so far: \n");
   while(cur!=NULL){
     printf("%d: %s\n",cur->id, cur->str);
     cur=cur->next;
   }
}//end of print_history

void free_history(List *list){
  if(list ==NULL){
    return;
  }
  else{
    free(list);
  }
}//end of free_history
