#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

void linkedlist(struct node* head){
    // struct node* p=head;
    // printf("%d ", p->data);
    // p=p->next;
    // while(p!=head){
    //     printf("%d ", p->data);
    //     p=p->next;
    // }
    struct node* p=head;
    do{
        printf("%d ", p->data);
        p=p->next;
    }while(p!=head);
}

struct node* InsertAsHead(struct node*head, int data){
    struct node* ptr =(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    
    // struct node* p=head->next;
    // while(p->next!=head){
    //     p=p->next;
    // }
    struct node* p=head->next;
    do{
        p=p->next;
    }while(p->next!=head);

    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}

int main(){
    struct node* one = (struct node*)malloc(sizeof(struct node));
    struct node* two = (struct node*)malloc(sizeof(struct node));
    struct node* three = (struct node*)malloc(sizeof(struct node));
    struct node* four = (struct node*)malloc(sizeof(struct node));

    one->data = 7;
    one->next = two;
    two->data = 18;
    two->next = three;
    three->data = 25;
    three->next = four;
    four->data = 6;
    four->next = one;
    printf("Circular Linked list befor operation: ");
    linkedlist(one);
    printf("\nCircular Linked list insertion at first: ");
    one = InsertAsHead(one,52);
    linkedlist(one);
}