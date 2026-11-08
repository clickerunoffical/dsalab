
/* Program 4: Infix to Postfix Expression */

#include <stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char c)
{
top++;
stack[top] = c;
}

// Pop function
char pop()
{
char c;
c = stack[top];
top--;
return c;
}

// Precedence function
int precedence(char c)
{
if (c == '*' || c == '/')
return 2;

if (c == '+' || c == '-')
return 1;

return 0;
}

int main()
{
char infix[MAX], postfix[MAX];
int i, j = 0;
char c;

printf("Enter an infix expression: ");
scanf("%s", infix);

for (i = 0; infix[i] != '\0'; i++)
{
c = infix[i];

// If operand, add directly to postfix
if ((c >= 'A' && c <= 'Z') ||
(c >= 'a' && c <= 'z'))
{
postfix[j] = c;
j++;
}

// If opening bracket
else if (c == '(')
{
push(c);
}

// If closing bracket
else if (c == ')')
{
while (stack[top] != '(')
{
postfix[j] = pop();
j++;
}
pop(); // Remove '('
}

// If operator
else
{
while (top != -1 &&
precedence(stack[top]) >= precedence(c))
{
postfix[j] = pop();
j++;
}
push(c);
}
}

// Pop remaining operators
while (top != -1)
{
postfix[j] = pop();
j++;
}

postfix[j] = '\0';

printf("Postfix expression: %s", postfix);

return 0;
}

/* Sample Output:

Enter an infix expression: A+B*C
Postfix expression: ABC*+

*/

// Algorithm: Infix to Postfix Conversion

// 1. Start.
// 2. Initialize top = -1.
// 3. Read the infix expression.
// 4. Initialize j = 0.
// 5. Scan the infix expression from left to right.
// 6. If the character is an operand:
//    a. Add it directly to the postfix expression.
// 7. If the character is an opening bracket '(':
//    a. Push it onto the stack.
// 8. If the character is a closing bracket ')':
//    a. Pop operators from the stack.
//    b. Add them to the postfix expression until '(' is found.
//    c. Remove '(' from the stack.
// 9. If the character is an operator:
//    a. Compare its precedence with the stack top.
//    b. Pop operators with higher or equal precedence.
//    c. Add popped operators to postfix.
//    d. Push the current operator onto the stack.
// 10. Pop all remaining operators from the stack.
// 11. Add '\0' at the end of postfix.
// 12. Display the postfix expression.
// 13. Stop.
