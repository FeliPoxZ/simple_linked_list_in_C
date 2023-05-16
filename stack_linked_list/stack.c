#include "stack.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
//verify if stack has an elementy.
int stack_has_elementy(Stack*);
typedef struct node Node;

struct node {
  int data;
  Node *next;
};
struct stack {
  Node *first;
  Node *last;
  int size;
  int lenght;
};

Stack *stack_create(int size) {
  Stack *new_stack = (Stack *)malloc(sizeof(Stack));
  if (new_stack != NULL) { // If malloc worked if success
    new_stack->size = size;
    new_stack->lenght = 0;
    new_stack->first = NULL;
    new_stack->last = NULL;
    return new_stack;
  }
  return NULL;
}

void stack_free(Stack *stack) {
  Node *aux;
  while (stack->first != NULL) {
    aux = stack->first;
    stack->first = stack->first->next;
    free(aux);
    stack->last = NULL;
  }
  stack->last = NULL;
  free(stack);
  return;
}

void stack_push(Stack *stack, int value){
  if (stack->lenght == stack->size){
    printf("Stack is full\n");
    return;
  }

  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->data = value;
  new_node->next = NULL;

  if (stack->first == NULL){ //NAO POSSUI NADA NA LISTA AINDA (LISTA VAZIA)
    stack->first = new_node;
    stack->last = new_node;
    stack->lenght = stack->lenght + 1;
    return;
  }
  stack->last->next = new_node;
  stack->last = new_node;
  stack->lenght = stack->lenght + 1;
  return;
}


int stack_pop(Stack *stack){
  if (stack->lenght == 0) {
    printf("Erro! Stack is Empty\n");
    return -1;
  }

  int returned_value = stack->last->data;
  Node* current = stack->first;
  if (stack->last == stack->first) {
    free(stack->last);
    stack->first = NULL;
    stack->last = NULL;
    stack->lenght = stack->lenght -1;
    return returned_value;
  }
  while (current->next != stack->last) {
    current = current->next;
  }
  free(stack->last);
  stack->last = current;
  stack->lenght = stack->lenght -1;
  current->next = NULL;
  return returned_value;
}

int stack_peek(Stack *stack, int index){
  if (stack->lenght == 0) {
    printf("Error Stack is Empty\n");
    return -1;
  }

  int count = 0;
  Node* current = stack->first;
  while (current != NULL) {
    if (count == index){
      return current->data;
    }
    current = current->next;
    count++;
  }
  printf("Erro Invalid index\n");
  return -1;
}

int stack_top(Stack *stack){
  if (stack->lenght == 0){
    printf("ERRO! Empty stack\n");
    return -1;
  }
  return stack->last->data;
}

int stack_is_empty(Stack *stack){
  if (stack->lenght == 0) {
    return 1;
  }
  return 0;
}

int stack_has_elementy(Stack *stack){
  return !stack_is_empty(stack);
}

int stack_is_full(Stack *stack){
  if (stack->lenght == stack->size){
    return 1;
  }
  return 0;
}

void stack_display(Stack *stack){
  if (stack_is_empty(stack) == 1){
    printf("Empty list\n");
    return;
  }
  Node *current = stack->first;
  printf("[");
  while (current != NULL) {
    printf("%i ", current->data);
    current = current->next;
  }
  printf("]\n");
  return;
}