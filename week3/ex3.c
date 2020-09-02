#include <stdio.h>
#include <stdlib.h>

struct Linked_List{
  int value;
  struct Linked_List* next;
};

void print_list(struct Linked_List* node){
  while (node!=NULL){
    printf("%d\n", node->value);
    node = node->next;
  }
}

void insert_node(struct Linked_List* node, int integ){
  
  struct Linked_List* inserted = (struct Linked_List*) malloc(sizeof(struct Linked_List));
  while(node->next!=NULL){
    node = node->next;
  }
  node->next = inserted;
  inserted->value = integ;
}

void delete_node(struct Linked_List* list, int key){
  struct Linked_List* current = list->next;
  struct Linked_List* temp = list;
  if (temp->value==key){
    list = temp->next;
    if (current==NULL){
      list = NULL;
    }
    free(temp);
    //printf("%d\n", list->value);
    
    return;

  }
  else{
    while (current!=NULL){
      if (current->value == key){
        list->next = current->next;
        free(current);
        return;
    }
      list=current;
      current = list->next;
    }
  }
    printf("No element\n");
}

int main(void) {
  struct Linked_List* first = (struct Linked_List*) malloc(sizeof(struct Linked_List));
  struct Linked_List* second = (struct Linked_List*) malloc(sizeof(struct Linked_List));
  struct Linked_List* third = (struct Linked_List*) malloc(sizeof(struct Linked_List));
  first->value = 1;
  first->next = second;
  second->value = 2;
  second->next = third;
  third->value = 3;
  insert_node(first, 4);
  delete_node(first, 4);
  print_list(first);
}
