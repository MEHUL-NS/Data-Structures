#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void insertStart(struct Node **last , int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    if((*last)==NULL){
        newNode->next=newNode;
        (*last) = newNode;
    }
    else{
        newNode->next = (*last)->next;
        (*last)->next = newNode;
    }
}

void insertEnd(struct Node **last , int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    if((*last)==NULL){
        newNode->next=newNode;
        (*last) = newNode;
    }
    else{
        newNode->next = (*last)->next; 
        (*last)->next = newNode;               
        (*last) = newNode;       
    }
}

void InsertAfter(struct Node **last , struct Node *prev , int val){    
    struct Node *temp=(*last)->next;   
    while(temp!=prev) temp=temp->next;
    if(temp==(*last)) insertEnd(&((*last)->next),val);
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next = temp->next;
    temp->next=newNode;    
}

void printList(struct Node **last){
    struct Node *temp = (*last)->next;
    do{
        printf("%d->",temp->data);
        temp=temp->next;
    }while(temp!=(*last)->next);
}

void deleteHead(struct Node **last){
    struct Node *temp = (*last)->next;
    if((*last)==NULL) printf("Empty");
    else (*last)->next = temp->next;
    free(temp);
}

void deleteEnd(struct Node **last){
    struct Node *temp = (*last)->next;
    while(temp->next!=(*last)) temp=temp->next;
    temp->next = (*last)->next;
    (*last) = temp;   
}

int main(){
    struct Node *head = NULL;
    insertStart(&head,1);
    insertStart(&head,2);
    insertEnd(&head,3);
    insertEnd(&head,4);
    InsertAfter(&head,head->next,7);

    printf("CLL : ");
    printList(&head);

    
   
  
 

    printf("\nCLL : ");
    printList(&head);
}