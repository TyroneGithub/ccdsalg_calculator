#include <string.h>
#include <ctype.h>
int isOperator(char c)
{
    switch (c)
    {
    case '^':
        return 5;
    case '*':
    case '/':
    case '%':
        return 4;
    case '+':
    case '-':
        return 3;
    default:
        return 0; // not an operator
    }
}

void infixToPostfix(Stack *stack, char input[], Queue *queue)
{
    //SCAN
    int i;
    for (i = 0; i < strlen(input); i++)
    {
        //   printf("%lld Evaluating index %d\n", strlen(input), i);

        if (isdigit(input[i]))
        {
            //                printf("input %c is an operand \n", input[i]);
            if (i != 0)
            {
                if (isdigit(input[i - 1]))
                    enqueue(queue, input[i]);
                else
                {
                    enqueue(queue, ' ');      //output[char_count++] = ' ';
                    enqueue(queue, input[i]); //output[char_count++] = input[i];
                }
            }
            else
            {
                enqueue(queue, input[i]); //output[char_count++] = input[i];
            }
        }
        else if (isOperator(input[i]))
        {
            //              printf("input %c is an operator \n", input[i]);
            //printf(" % c % c ", input[i], top(stack));

            if (stack_empty(stack) || top(stack) == '(' || (isOperator(input[i]) > isOperator(top(stack)) || isOperator(input[i]) == 5))
                push_stack(stack, input[i]);
            else
            {
                while (isOperator(input[i]) <= isOperator(top(stack)) && !stack_empty(stack))
                {
                    enqueue(queue, ' ');              //                    output[char_count++] = ' ';
                    enqueue(queue, pop_stack(stack)); //output[char_count++] = pop_stack(stack);
                }

                push_stack(stack, input[i]);
            }
        }
        else if (input[i] == '(')
        {
            push_stack(stack, input[i]);
        }
        else if (input[i] == ')')
        {
            while (top(stack) != '(')
            {
                enqueue(queue, ' ');
                enqueue(queue, pop_stack(stack)); // output[char_count++] = pop_stack(stack);
            }
            pop_stack(stack);
        }
    }

    while (!stack_empty(stack))
    {
        enqueue(queue, ' ');              //output[char_count++] = ' ';
        enqueue(queue, pop_stack(stack)); //output[char_count++] = pop_stack(stack);
    }
    enqueue(queue, '\0'); //output[char_count] = '\0';
}
