#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//char c[] is interpreted as char *c by compiler
struct stack{
    char a[20];
    int top;
};

void push(struct stack * ptr, char ch){
    ptr->top++;
    ptr->a[ptr->top]=ch;
}

void pop(struct stack * ptr){
    ptr->top--;
}

void reverse(char *c,int n){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->top=-1;
    for(int i=0;i<n;i++){
        push(s,c[i]);
    }
    for(int i=0;i<n;i++){
        c[i]= s->a[s->top];
        pop(s);
    }
}

int main(){
    char c[20];
    printf("Enter a string: ");
    gets(c);
    printf("Before reverse: %s\n", c);
    reverse(c,strlen(c));
    printf("After reverse: %s", c);
    return 0;
}