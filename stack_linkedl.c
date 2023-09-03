#include<stdio.h>
#include<stdlib.h>

//inserting and deleting at the end (i.e where is null) is not feaseble due to time complexity of O(n)
//inserting and deleting at the head is recommended due to time complexity O(1)

struct node{
    int data;
    struct node * next;
};
struct node* top=NULL;

void push(int value){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=value;
    ptr->next=top;
    top=ptr;
}
void pop(){
    if(top==NULL){
        printf("Stack is empty");
    }
    struct node * p=top;
    top=top->next;
    free(p);
}

void printStack(){
    while(top!=NULL){
        printf("Element: %d\n", top->data);
        top=top->next;
    }
}

int main(){
    push(33);
    push(20);
    push(9);
    push(11);
    pop();
    printStack();
    return 0;
}
