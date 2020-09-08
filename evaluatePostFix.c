
void evaluatePostfix (String queue[], int length) {
	int ctr, op1, op2, currentDigit, result, final;
	String currentResult;
	Stack* stack = NULL;
	
	stack = malloc(sizeof(Stack));
	create_stack(stack);
	
	for (ctr = 0; ctr < length; ctr++) {
		currentDigit = atoi(queue[ctr]);
		
		if (currentDigit != 0)
			push_stack(stack, queue[ctr]);
		
		else {
			op2 = atoi(pop_stack(stack));
			op1 = atoi(pop_stack(stack));
						
			if (strcmp(queue[ctr], "+") == 0) {
				result = op1 + op2;
			}
			
			else if (strcmp(queue[ctr], "-") == 0) {
				result = op1 - op2;
			}
			
			else if (strcmp(queue[ctr], "*") == 0) {
				result = op1 * op2;
			}
			
			else if (strcmp(queue[ctr], "/") == 0) {
				if (op2 == 0)
					break;
				
				else if (op1 == 0)
					result = 0;
				
				else
					result = op1 / op2;
			}
			
			else if (strcmp(queue[ctr], "%") == 0) {
				result = op1 % op2;
			}
			
			else if (strcmp(queue[ctr], "^") == 0) {
				result = pow(op1, op2);
			}
			
			else if (strcmp(queue[ctr], "!") == 0) {
				if (op2 == 0)
					result = 1;
				
				else
					result = 0;
			}
			
			else if (strcmp(queue[ctr], "&&") == 0) {
				if (op1 != 0 && op2 != 0)
					result = 1;
				
				else
					result = 0;
			}
			
			else if (strcmp(queue[ctr], "||") == 0) {
				if (op1 != 0 || op2 != 0)
					result = 1;
				
				else
					result = 0;
			}
			
			else if (strcmp(queue[ctr], "==") == 0) {
				if (op1 == op2)
					result = 1;
				
				else
					result = 0;
			}
			
			else if (strcmp(queue[ctr], ">") == 0) {
				if (op1 > op2)
					result = 1;
				
				else
					result = 0;
			}
			
			else if (strcmp(queue[ctr], ">=") == 0) {
				if (op1 >= op2)
					result = 1;
				
				else
					result = 0;
			}
			
			else if (strcmp(queue[ctr], "<") == 0) {
				if (op1 < op2)
					result = 1;
				
				else
					result = 0;
			}
			
			else if (strcmp(queue[ctr], "<=") == 0) {
				if (op1 <= op2)
					result = 1;
				
				else
					result = 0;
			}
			
			
			else if (strcmp(queue[ctr], "!=") == 0) {
				if (op1 != op2)
					result = 1;
				
				else
					result = 0;
			}
			
			push_stack(stack, itoa(result, currentResult, 10));
		}
	}
	
	if (op2 == 0 && strcmp(queue[ctr], "/") == 0)
		printf("Division by zero error!");
	
	else {
		final = atoi(pop_stack(stack));
		printf("%d", final);
	}
}
