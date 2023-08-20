#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

void linkedList(struct node* ptr){
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct node * InsertAtFirst(struct node* head,int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

struct node * InsertAtIndex(struct node* head, int data, int index){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node * p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    ptr->data=data;
    return head;
}

struct node * InsertAtEnd(struct node* head, int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    ptr->data=data;
    return head;
}

struct node * InsertAfterNode(struct node* prevnode,struct node* head,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
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
    four->next = NULL;

    printf("Linked list before insertion: ");
    linkedList(one);
    
    // printf("\nInsertion at the beginning: ");
    // one = InsertAtFirst(one,29);
    // linkedList(one);
    
    // printf("\nInsertion in between: ");
    // InsertAtIndex(one,8,3);
    // linkedList(one);
   
    // printf("\nInsertion at the end: ");
    // InsertAtEnd(one,1);
    // linkedList(one);

    printf("\nInsertion after node: ");
    InsertAfterNode(two, one,10);
    linkedList(one);
    return 0;
}