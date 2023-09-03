#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};
struct node* front=NULL;
struct node* rear=NULL;

void enqueue(int value){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=value;
    ptr->next=NULL;
    if(front==NULL && rear==NULL){
        front = rear = ptr;
    }
        rear->next=ptr;
        rear=ptr;
}
void dequeue(){
    struct node * p=front;
    if(front==NULL){
        printf("queue is empty");
    }
    if(front==rear){
        front=rear=NULL;
    }
    else{
    front=front->next;
    }
    free(p);
}

void printQueue(){
    while(rear!=NULL){
        printf("Element: %d\n", front->data);
        front=front->next;
    }
}

int main(){
    enqueue(2);
    enqueue(5);
    enqueue(3);
    enqueue(10);
    dequeue();
    dequeue();
    printQueue();
    return 0;
}
