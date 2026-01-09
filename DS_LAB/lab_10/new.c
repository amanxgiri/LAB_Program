#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
int top = -1;
char stack[MAX];

int isEmpty(){
    if(top == -1) return 1;
    return 0;
}

void push(char c){
    if(top == MAX-1){
        printf("Stack is full");
    }
    else{
        stack[++top] = c;
    }

}

char pop(){
    if(isEmpty()) {
        printf("Stack is empty");
        return '\0';
    }
    else{
        return stack[top--];
    }
}

char peek(){
    if(isEmpty()){
        printf("Stack is empty");
        return'\0';
    }
    else return stack[top];
}

void pofixToInfix(char* infix, char* postfix){
    int k = 0;
    for(int i = 0; infix[i]; i++){
        if(isalnum(infix[i])){
            postfix[k++] = infix[i];
        }
        else if(infix[i] = '('){
            push(infix[i]);
        }
        else if(infix[i] == ')'){
            while(!isEmpty() && peek() !='('){
                postfix[k++] = pop(); 
            }      
        }
    }
}
