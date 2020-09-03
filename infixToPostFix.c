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

void infixToPostfix(Stack *stack, char input[], char output[])
{
    int char_count = 0;
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
                    output[char_count++] = input[i];
                else
                {
                    output[char_count++] = ' ';
                    output[char_count++] = input[i];
                }
            }
            else
            {
                output[char_count++] = input[i];
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
                    output[char_count++] = ' ';
                    output[char_count++] = pop_stack(stack);
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
                output[char_count++] = pop_stack(stack);
            }
            pop_stack(stack);
        }
    }

    while (!stack_empty(stack))
    {
        output[char_count++] = ' ';
        output[char_count++] = pop_stack(stack);
    }
    output[char_count] = '\0';
}
