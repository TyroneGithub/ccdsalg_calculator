#include "stacks.h"

void create_stack(Stack *stack)
{
    stack->cap = 256;
    stack->S = malloc(sizeof(String) * stack->cap);
    stack->top = 0;
}

int stack_full(Stack *stack)
{
    return stack->top == stack->cap - 1;
}

int stack_empty(Stack *stack)
{
    return stack->top == 0;
}

void push_stack(Stack *stack, String item)
{
    if (stack_full(stack))
    {
        printf("Overflow Error!\n");
    }
    else
    {
        strcpy(stack->S[stack->top], item);
        stack->top++;
    }
}

char *top(Stack *stack)
{
    return stack->S[stack->top - 1];
}

char *pop_stack(Stack *stack)
{
    char *top1 = malloc(sizeof(String));
    if (stack_empty(stack))
    {
        printf("Underflow Error!\n");
        return "";
    }
    else
    {
        strcpy(top1, top(stack));
        stack->top--;
        return top1;
    }
}
