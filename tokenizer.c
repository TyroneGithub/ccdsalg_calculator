int isOperator(String s)
{
    if (strcmp("^", s) == 0)
        return 8;
    else if (strcmp("!", s) == 0)
        return 7;
    else if (strcmp("*", s) == 0 || strcmp("/", s) == 0 || strcmp("%%", s) == 0)
        return 6;
    else if (strcmp("+", s) == 0 || strcmp("-", s) == 0)
        return 5;
    else if (strcmp(">", s) == 0 || strcmp("<", s) == 0 || strcmp(">=", s) == 0 || strcmp("<=", s) == 0)
        return 4;
    else if (strcmp("==", s) == 0 || strcmp("!=", s) == 0)
        return 3;
    else if (strcmp("&&", s) == 0)
        return 2;
    else if (strcmp("||", s) == 0)
        return 1;
    else if (strcmp("=", s) == 0 || strcmp("|", s) == 0 || strcmp("&", s) == 0) // used as part of tokenizer
        return -1;
    else
        return 0; // Not an Operator
    /*
    switch (s)
    {
    case "^":
        return 5;
    case "*":
    case "/":
    case "%":
        return 4;
    case "+":
    case "-":
        return 3;
    default:
        return 0; // not an operator
*/
}
void convertCharToString(char c, String temp)
{
    temp[0] = c;
    temp[1] = '\0';
}

int tokenizer(char input[], String tokenized[])
{
    int i, cnt = 0, subcnt;
    String temp;
    for (i = 0; i < strlen(input); i++)
    {
        subcnt = 0;
        if (input[i] != ' ')
        {
            convertCharToString(input[i], temp);

            if (isdigit(input[i]))
            {
                tokenized[cnt][subcnt++] = input[i];

                while (isdigit(input[i + 1]))
                {
                    i++;
                    tokenized[cnt][subcnt++] = input[i];
                }
            }
            else if (isOperator(temp))
            {
                tokenized[cnt][subcnt++] = input[i];
                convertCharToString(input[i + 1], temp);

                while (isOperator(temp))
                {
                    i++;
                    tokenized[cnt][subcnt++] = input[i];
                    convertCharToString(input[i + 1], temp);
                }
            }
            else
            {
                tokenized[cnt][subcnt++] = input[i]; // if '(' or ')'
            }
            tokenized[cnt][subcnt] = '\0';
            cnt++;
        }
    }
    return cnt - 1;
}