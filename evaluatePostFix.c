int isStringDigit(String s)
{

	int i;
	for (i = 0; i < strlen(s); i++)
	{
		if (isdigit(s[i]))
		{
			return 1;
		}
	}

	return 0;
}

void evaluatePostfix(Queue *queue)
{
	int op1, op2 = -1, result, final;
	String currentResult;
	String dequeued;
	Stack *stack = NULL;

	stack = malloc(sizeof(Stack));
	create_stack(stack);

	while (!queue_empty(queue))
	{
		strcpy(dequeued, dequeue(queue));
		if (isStringDigit(dequeued))
		{
			push_stack(stack, dequeued);
		}

		else
		{
			op2 = atoi(pop_stack(stack));
			op1 = atoi(pop_stack(stack));

			if (strcmp(dequeued, "+") == 0)
			{
				result = op1 + op2;
			}

			else if (strcmp(dequeued, "-") == 0)
			{
				result = op1 - op2;
			}

			else if (strcmp(dequeued, "*") == 0)
			{
				result = op1 * op2;
			}

			else if (strcmp(dequeued, "/") == 0)
			{
				if (op2 == 0)
					break;

				else if (op1 == 0)
					result = 0;

				else
					result = op1 / op2;
			}

			else if (strcmp(dequeued, "%%") == 0)
			{
				result = op1 % op2;
			}

			else if (strcmp(dequeued, "^") == 0)
			{
				result = pow(op1, op2);
			}

			else if (strcmp(dequeued, "!") == 0)
			{
				if (op2 == 0)
					result = 1;

				else
					result = 0;
			}

			else if (strcmp(dequeued, "&&") == 0)
			{
				if (op1 != 0 && op2 != 0)
					result = 1;

				else
					result = 0;
			}

			else if (strcmp(dequeued, "||") == 0)
			{
				if (op1 != 0 || op2 != 0)
					result = 1;

				else
					result = 0;
			}

			else if (strcmp(dequeued, "==") == 0)
			{
				if (op1 == op2)
					result = 1;

				else
					result = 0;
			}

			else if (strcmp(dequeued, ">") == 0)
			{
				if (op1 > op2)
					result = 1;

				else
					result = 0;
			}

			else if (strcmp(dequeued, ">=") == 0)
			{
				if (op1 >= op2)
					result = 1;

				else
					result = 0;
			}

			else if (strcmp(dequeued, "<") == 0)
			{
				if (op1 < op2)
					result = 1;

				else
					result = 0;
			}

			else if (strcmp(dequeued, "<=") == 0)
			{
				if (op1 <= op2)
					result = 1;

				else
					result = 0;
			}

			else if (strcmp(dequeued, "!=") == 0)
			{
				if (op1 != op2)
					result = 1;

				else
					result = 0;
			}
			push_stack(stack, itoa(result, currentResult, 10));
		}
	}

	if (op2 == 0 && strcmp(dequeued, "/") == 0)
		printf("Division by zero error!\n");

	else
	{
		final = atoi(pop_stack(stack));
		printf("%d\n", final);
	}
}
