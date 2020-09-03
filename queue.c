#include "queue.h"

void create_queue(Queue *queue){
    queue->cap = 4;
    queue->S = malloc(sizeof(char) * queue->cap);
    queue->head = 0;
    queue->tail = 0;   
}

int queue_empty(Queue *queue){
    return queue->tail == queue->head;
}

int queue_full(Queue *queue){
    return queue->head == (queue->tail+1) % queue->cap;
}

void enqueue(Queue *queue, char item){
    if(queue_full(queue)){
        printf("Overflow error\n");
    }
    else{
        queue->S[queue->tail] = item;
        if(queue->tail == queue->cap)
            queue->tail = 1;
        else
            queue->tail++;
    }
}

char dequeue(Queue *queue){
    char c = '\0';
    if(queue_empty(queue)){
        printf("underflow error\n");
    }
    else{
        c = queue->S[queue->head];
        if(queue->head == queue->cap)
            queue->head = 1;
        else
            queue->head++;
    }
    return c;
}

char queue_head(Queue *queue){
    return queue->S[queue->head];
}

char queue_tail(Queue *queue){
    return queue->S[queue->tail - 1];
}


