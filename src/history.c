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
  if(list==NULL || str==NULL){
    return; }

  Item *newItem =(Item*)malloc(sizeof(Item));
  if(newItem==NULL){
    return; }
  newItem->str=strdup(str);
  if(newItem->str==NULL){
    free(newItem);
    return; }

  newItem->next=NULL;

  if(list->root==NULL){
    newItem->id=1;
    list->root = newItem;
    return;
  }

  Item *cur = list->root;
  while(cur->next !=NULL){
    cur=cur->next;
  }
  newItem->id= cur->id+1;
  cur->next=newItem;

}//end of add history
  

char *get_history(List *list, int id){
  Item *cur=list->root;
  if(cur==NULL){
   return "No history stored";}
  while(cur!=NULL){
   if(cur->id==id){
    return cur->str;}
   cur=cur->next;}
  return "Invalid Index";
}//end of get history
 
void print_history(List *list){
  if(list->root ==NULL|| list==NULL){
    printf("List is empty\n");
  }
  printf("History: \n");
  
  Item *cur = list->root;

   while(cur!=NULL){
     if(cur->str !=NULL){
       printf("id: %d - input: %s\n",cur->id, cur->str);
       cur = cur->next;
     }
     else{
       printf("id: %d - input: NULL\n",cur->id);
     }
   }
}//end of print_history

void free_history(List *list){
  Item *trash = list->root;
  while(trash !=NULL){
    free(list->root);
    trash=trash->next;
    list->root=list->root->next;
  }
  free(list);
}//end of free_history
