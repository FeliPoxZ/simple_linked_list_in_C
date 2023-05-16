#include "list.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node Node;
struct node {
    int data;
    Node *next;
};

struct list {
    Node *first;
};


List* list_create() {
    List *new_list = (List*) malloc(sizeof(List));
    new_list->first = 0;
    return new_list;
}


void list_add(List* list, int value){
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = 0;
   
    if(list->first == 0) {
        list->first = new_node;
        return;
    }
   
    Node* current = list->first;
    while(current->next != 0){
        current = current->next;
    }
   
    current->next = new_node;
}


void list_display(List* list){
    Node* current = list->first;
    printf("[ ");
    while(current != 0) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("]\n");
}


void list_free(List* list){
    while(list->first != 0) {
        Node* aux = list->first;
        list->first = list->first->next;
        free(aux);
        list_display(list);
    }
    free(list);
}


int list_get(List* list, int index){
    Node* current = list->first;
    int count = 0;
    while(current != 0) {
        if(count == index) return current->data;
        current = current->next;
        count++;
    }
   
    printf("Invalid index!\n");
    return -1;
}


void list_set(List* list, int index, int value){
    Node* current = list->first;
    int count = 0;
    while(current != 0){
        if(count == index){
            current->data = value;
            return;
        }
        current = current->next;
        count++;
    }
   
    printf("Invalid index!\n");
}


void list_insert(List* list, int index, int value){
    if(index == 0) {
        Node *new_node = (Node*) malloc(sizeof(Node));
        new_node->data = value;
        new_node->next = list->first->next;
        list->first = new_node;
        return;
    }
   
    Node* current = list->first;
    int count = 0;
    while(current != 0) {
        if(count == index-1) {
            Node *new_node = (Node*) malloc(sizeof(Node));
            new_node->data = value;
            new_node->next = current->next;
            current->next = new_node;
        }
        count++;
        current=current->next;
    }
   
    printf("Invalid index!\n");
}


int list_remove(List* list, int index){
    if(list->first == 0) {
        printf("Empty list!\n");
        return;
    }
   
    if(index == 0) {
        Node* aux = list->first;
        int result = aux->data;
        list->first = list->first->next;
        free(aux);
        return result;
    }
   
    Node* current = list->first;
    int count = 0;
   
    while(current != 0) {
        if(count == index-1) {
            Node* aux = current->next;
            int result = aux->data;
            current->next = current->next->next;
            free(aux);
            return result;
        }
        count++;
        current=current->next;
    }
   
    printf("Invalid index!\n");
    return -1;  
}
