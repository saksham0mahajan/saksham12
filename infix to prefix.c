#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if the given character is an operator
int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
        return 1;
    }
    return 0;
}

// Function to get the precedence of an operator
int getPrecedence(char ch) {
    if (ch == '^') {
        return 3;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    }
    return 0;
}

// Function to reverse a string
void reverseString(char* str) {
    int len = strlen(str);
    int i, j;
    char temp;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to convert infix expression to prefix expression
void infixToPrefix(char* infix, char* prefix) {
    char stack[MAX_SIZE];
    int top = -1;
    int i, j;

    // Reverse the infix expression
    reverseString(infix);

    // Traverse the reversed infix expression
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (infix[i] == ' ' || infix[i] == '\t') {
            continue;
        } else if (isOperator(infix[i])) {
            // Pop operators from the stack and add them to the prefix string
            while (top != -1 && getPrecedence(stack[top]) > getPrecedence(infix[i])) {
                prefix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            stack[++top] = infix[i];
        } else if (infix[i] == '(') {
            while (top != -1 && stack[top] != ')') {
                prefix[j++] = stack[top--];
            }
            if (top != -1) {
                top--;  // Pop the ')'
            }
        } else {
            // Add operands to the prefix string
            prefix[j++] = infix[i];
        }
    }

    // Pop any remaining operators from the stack and add them to the prefix string
    while (top != -1) {
        prefix[j++] = stack[top--];
    }

    prefix[j] = '\0';

    // Reverse the prefix string to get the final result
    reverseString(prefix);
}

int main() {
    char infix[MAX_SIZE];
    char prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
