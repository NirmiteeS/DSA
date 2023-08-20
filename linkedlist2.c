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

struct node * DeleteFirstNode(struct node* head){
    struct node* p=head;
    head=head->next;
    free(p);
    return head;
}

struct node * DeleteAtIndex(struct node* head, int index){
    struct node* p=head;
    for(int i=0;i<index-1;i++){
        p=p->next;
    }
    struct node* q=p->next;
    p->next=q->next;
    free(q);
    return head;
}

struct node * DeleteAtEnd(struct node* head){
    struct node* p=head;
    struct node* q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

struct node * DeleteAtGivenValue(struct node* head, int value){
    struct node* p=head;
    struct node* q=head->next;
    while(q->data!=value && q->next!=NULL){
        p=p->next;
        q=q->next;
    }

    if(q->data==value){
        p->next=q->next;
        free(q);
    }
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

     printf("Linked list before deletion: ");
    linkedList(one);
    
    // printf("\nDeletion at the beginning: ");
    // one=DeleteFirstNode(one);
    // linkedList(one);

    // printf("\nDeletion at index: ");
    // DeleteAtIndex(one,2);
    // linkedList(one);

    // printf("\nDeletion at End: ");
    // DeleteAtEnd(one);
    // linkedList(one);

    printf("\nDeletion at Given Value: ");
    DeleteAtGivenValue(one, 18);
    linkedList(one);
}