#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct stack{
    int size;
    int top;
    char * arr;
};
int isFull(struct stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack * ptr , int val){
    if(isFull(ptr)){
        printf("Stack Overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int pop(struct stack * ptr){
    if(isEmpty(ptr)){
        return 0;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int stackTop(struct stack * ptr){
    return ptr->arr[ptr->top];
}
int stackBottom(struct stack * ptr){
    return ptr->arr[0];
}
int isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
        return 1;
    }
    else{
        return 0;
    }
}
int prec(char ch){
    if(ch=='*' || ch=='/')
    return 3;
    else if(ch=='+' || ch=='-')
    return 2;
    else
    return 1;
}
int i=0 , j=0;
char * infixTopostfix(char * infix){
    struct stack * sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*) malloc((sp->size)*sizeof(char));
    char * postfix = (char*)malloc((strlen(infix+1))*sizeof(char));
    int i=0 , j=0;
    while(infix[i] != '\0'){
        if(! isOperator(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else{
            if(prec(infix[i]>stackTop(sp))){
                push(sp , infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while(! isEmpty(sp)){
    postfix[j]=pop(sp);
    j++;
}
postfix[j]='\0';
return postfix;
}

int main(){
    char * infix = "a * b";
    printf(infixTopostfix(infix));
    return 0;
}
