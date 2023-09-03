#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
}; 
int isEmpty(struct stack * ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack * ptr){
    if(ptr->top == ptr->size-1 ){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack * ptr, int value){
    if(isFull(ptr)){
        printf("stack overflow");
    }
    ptr->top++;
    ptr->arr[ptr->top]=value;
}

void pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("stack is empty");
    }
    ptr->top--;
}
int top(struct stack * ptr){
    return ptr->arr[ptr->top];
}

void printArray(struct stack *ptr){
    for(int i=0;i<=ptr->top;i++){
        printf("Element : %d\n", ptr->arr[i]);
    }
}
int main(){
    // struct stack s;
    // s.size=50;
    // s.top=-1;
    // s.arr=(int*)malloc(s.size * sizeof(int));
    struct stack *s;
    s->size=50;
    s->top=-1;
    s->arr=(int*)malloc(s->size * sizeof(int));
    // if(isEmpty(s)){
    //     printf("stack is empty");
    // }
    push(s,2);
    push(s,6);
    pop(s);
    push(s,5);
    push(s,3);
    push(s,1);
    printArray(s);
    printf("Top element is: %d", top(s));
    return 0;
}