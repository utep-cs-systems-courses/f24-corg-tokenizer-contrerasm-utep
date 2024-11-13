#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

List *init_history(){
  List *lst= (List*) malloc(sizeof(List));//allocate memory
  lst ->root =NULL;
  return lst;//return pointer to created list
}


void add_history(List *list, char *str){
  if(list==NULL || str==NULL){//check if list or pintter in null
    return;
  }

  Item *newItem =(Item*)malloc(sizeof(Item));//allocate memory
  if(newItem==NULL){//check if it failed to allocate memory
    return;
  }
  newItem->str=strdup(str);//make copy
  if(newItem->str==NULL){
    free(newItem);
    return;
  }

  newItem->next=NULL;//set next to null

  if(list->root==NULL){
    newItem->id=1;//make the first item
    list->root = newItem;
    return;
  }

  Item *cur = list->root;
  while(cur->next !=NULL){//add everything else after the first item
    cur=cur->next;
  }
  newItem->id= cur->id+1;//assign new id
  cur->next=newItem;//set pointer of last item to new item

}//end of add history
  

char *get_history(List *list, int id){
  Item *cur=list->root;
  if(cur==NULL){//check if empty
   return "No history stored";
  }
  while(cur!=NULL){//go through the list
    if(cur->id==id){
      return cur->str;//return thr str field
   }
   cur=cur->next;
  }
  return "Invalid Index";
}//end of get history
 
void print_history(List *list){
  if(list->root ==NULL|| list==NULL){//check if empty
    printf("List is empty\n");
  }
  printf("History: \n");
  
  Item *cur = list->root;//initialize to root of list

  while(cur!=NULL){//go through the list
     if(cur->str !=NULL){
       printf("id %d = %s\n",cur->id, cur->str);
       cur = cur->next;
     }
     else{
       printf("id %d = NULL\n",cur->id);
     }
   }
}//end of print_history

void free_history(List *list){
  Item *trash = list->root;//initialize to root
  while(trash !=NULL){//go through lust
    free(list->root);
    trash=trash->next;
    list->root=list->root->next;//update root pointer,remove current node
  }
  free(list);
}//end of free_history
