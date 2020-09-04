
void infixToPostfix(Stack *stack, Queue *queue, String tokenized[], int cnt)
{
    //SCAN
    int i;
    for (i = 0; i < cnt; i++)
    {
        //   printf("%lld Evaluating index %d\n", strlen(input), i);

        if (atoi(tokenized[i]) || strcmp(tokenized[i], "0") == 0) // if it is a number
        {
            //  printf("input %s is an operand \n", tokenized[i]);
            enqueue(queue, tokenized[i]); //output[char_count++] = input[i];
        }
        else if (isOperator(tokenized[i]))
        {
            //              printf("input %c is an operator \n", input[i]);
            //printf(" % c % c ", input[i], top(stack));

            if (stack_empty(stack) || strcmp(top(stack), "(") == 0 || (isOperator(tokenized[i]) > isOperator(top(stack)) || isOperator(tokenized[i]) == 8))
                push_stack(stack, tokenized[i]);
            else
            {
                while (isOperator(tokenized[i]) <= isOperator(top(stack)) && !stack_empty(stack))
                {
                    enqueue(queue, pop_stack(stack)); //output[char_count++] = pop_stack(stack);
                }

                push_stack(stack, tokenized[i]);
            }
        }
        else if (strcmp(tokenized[i], "(") == 0)
        {
            push_stack(stack, tokenized[i]);
        }
        else if (strcmp(tokenized[i], ")") == 0)
        {
            while (strcmp(top(stack), "("))
            {
                enqueue(queue, pop_stack(stack)); // output[char_count++] = pop_stack(stack);
            }
            pop_stack(stack);
        }
    }

    while (!stack_empty(stack))
    {
        enqueue(queue, pop_stack(stack)); //output[char_count++] = pop_stack(stack);
    }
}
