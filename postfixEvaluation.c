#include <string.h>

int postFixEvaluation(Queue *queue, char postfix[]){
    char temp[256];
    char *ptr = strtok(postfix, " ");
    int i = 0;
    while(ptr != NULL){
        enqueue(queue, ptr);
        
        if(isOperator(ptr)){

        }

        ptr = strtok(NULL, " ");
        
    }
    return 0;

}