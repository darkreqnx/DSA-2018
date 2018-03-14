#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int four()
{
    char stack[100];
    int top = -1;

    printf("Enter properly bracketed infix expression: ");
    char input[100];
    scanf("%s",input);
    int write = -1;
    int length = strlen(input);
    int i;
    for(i=0;i<length;i++){
        if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/' || input[i]=='(') stack[++top] = input[i];
        else if (input[i] == ')'){
            input[++write] = stack[top];
            top-=2;
        }
        else input[++write] = input[i];
    }
    printf("\nPostfix expression: ");
    for(i=0;i<=write;i++){
        printf("%c",input[i]);
    }
    return 0;
}


