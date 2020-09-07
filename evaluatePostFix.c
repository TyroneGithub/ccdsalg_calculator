int* stack;
int topIndex = -1;

void push (int num) {
	topIndex++;
	stack[topIndex] = num;
}

int pop () {
	int result = stack[topIndex];
	topIndex--;
	
	return result;
}


void evaluatePostfix(String queue[], int length) {
	int ctr, op1, op2, result, final;
	int currentDigit;
	
	stack = malloc(sizeof(int) * length);
	
	for (ctr = 0; ctr < length; ctr++) {
		currentDigit = atoi(queue[ctr]);
		
		if (currentDigit != 0) {
			push(currentDigit);
			
		} else {
			op2 = pop();
			op1 = pop();
			
			if (strcmp(queue[ctr], "+") == 0) {
				result = op1 + op2;
				
			} else if (strcmp(queue[ctr], "-") == 0) {
				result = op1 - op2;
				
			} else if (strcmp(queue[ctr], "*") == 0) {
				result = op1 * op2;
				
			} else if (strcmp(queue[ctr], "/") == 0) {
				if (op2 == 0) 
					break;
				
				result = op1 / op2;
			
			} else if (strcmp(queue[ctr], "%") == 0) {
				result = op1 % op2;
				
			} else if (strcmp(queue[ctr], "^") == 0) {
				result = pow(op1, op2);
				
			} else if (strcmp(queue[ctr], "!") == 0) {
				if (op2 == 0) 
					result = 1;
				
				else
					result = 0;
				
			} else if (strcmp(queue[ctr], "&&") == 0) {
				if (op1 != 0 && op2 != 0) 
					result = 1;
					
				else
					result = 0;
				
				
			} else if (strcmp(queue[ctr], "||") == 0) {
				if (op1 != 0 || op2 != 0) 
					result = 1;
				
				else 
					result = 0;
				
				
			} else if (strcmp(queue[ctr], "==") == 0) {
				if (op1 == op2)
					result = 1;
				
				else
					result = 0;
				
			} else if (strcmp(queue[ctr], ">") == 0) {
				if (op1 > op2)
					result = 1;
				
				else
					result = 0;
				
			} else if (strcmp(queue[ctr], ">=") == 0) {
				if (op1 >= op2)
					result = 1;
				else
					result = 0;
				
			} else if (strcmp(queue[ctr], "<") == 0) {
				if (op1 < op2)
					result = 1;
				
				else
					result = 0;
				
			} else if (strcmp(queue[ctr], "<=") == 0) {
				if (op1 <= op2)
					result = 1;
				
				else
					result = 0;
				
			} else if (strcmp(queue[ctr], "!=") == 0) {
				if (op1 != op2)
					result = 1;
				
				else
					result = 0;
				
			}
							
			push(result);
		}
	}
	
	if (op2 == 0 && strcmp(queue[ctr], "/") == 0) 
		printf("Division by zero error!");
		
	else {
		final = pop();
	
		printf("%d", final);
	}
}
