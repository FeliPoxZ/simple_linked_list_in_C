#include <endian.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct node Node;

struct node{
    int data;
    Node *next;
};

struct queue{
    Node *first;
    Node *last;
    int size;
    int lenght;
};

Queue* queue_create(int size){
    Queue *new_queue = (Queue*)malloc(sizeof(Queue));
    if (new_queue != NULL) { //IF WORKED MALLOC WORKED WITH SUCCESS
        new_queue->first = NULL;
        new_queue->last = NULL;
        new_queue->size = size;
        new_queue->lenght = 0;
        return new_queue;
    }
    return NULL;
}

void queue_free(Queue* queue){
    Node* aux;
    while (queue->first != NULL) {
        aux = queue->first;
        queue->first = queue->first->next;
        free (aux);
        queue->last = NULL;
    }
    queue->last = NULL;
    free(queue);
    return;
}

void queue_enqueue(Queue* queue, int value){
    if (queue->lenght == queue->size) {
        printf("Erro! Queue is full\n");
        return;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    if (queue->first == NULL){
        queue->first = new_node;
        queue->last = new_node;
        queue->lenght++;
        return;
    }

    queue->last->next = new_node;
    queue->last = new_node;
    queue->lenght++;
    return;
}

int queue_dequeue(Queue* queue){
    int returned_value;
    if (queue->lenght == 0) {
        printf("ERROR! Queue is empty\n");
        return -1;
    }
    returned_value = queue->first->data;
    if (queue->last == queue->first){
        free(queue->first);
        queue->last = NULL;
        queue->first = NULL;
        queue->lenght--;
        return returned_value;
    }

    Node *aux = queue->first;
    queue->first = queue->first->next;
    free(aux);
    queue->lenght--;
    return returned_value;
}

int queue_first(Queue* queue){
    if (queue->lenght == 0) {
        printf("ERROR! Queue is empty\n");
        return -1;
    }
    return queue->first->data;
}

int queue_last(Queue* queue){
    if (queue->lenght == 0) {
        printf("ERROR! Queue is empty\n");
        return -1;
    }
    return queue->last->data;
}

int queue_is_empty(Queue* queue){
    if (queue->lenght == 0){
        return 1;
    }
    return 0;
}

//caso retorne 1 - possui um item
//caso retorne 0 - esta vazia
int queue_has_element (Queue* queue){
    return !queue_is_empty(queue);
}

int queue_is_full(Queue* queue){
    if (queue->lenght == queue->size) {
        return 1;
    }
    return 0;
}

void queue_display(Queue *queue){
    if (queue_is_empty(queue) == 1){
        printf("Queue empty\n");
        return;
    }
    Node* current = queue->first;
    printf("[");
    while (current!=NULL) {
        printf("%i ", current->data);
        current = current->next;
    }
    printf("]\n");
    return;
}