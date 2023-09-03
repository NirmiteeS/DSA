#include<stdio.h>
#define max 10
int arr[max];   //global variables
int front=-1;
int rear=-1; 

int isEmpty(){
    if(front==-1 && rear==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(rear==max-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int value){
    if(isFull()){
        printf("Queue is full");
    }
    else if(isEmpty()){
        front=0;
        rear=0;
    }
    else{
        rear++;
    }
    arr[rear]=value;
}
void dequeue(){
    if(isEmpty()){
        printf("queue is empty");
    }
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front++;
    }
}
void printQueue(){
    for(int i=front;i<=rear;i++){
        printf("Element: %d\n", arr[i]);
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