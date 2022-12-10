#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next,*prev;    
};



void insert_begining(struct Node** head_ref, int new_data){    
    struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));  
    new_node->data = new_data;  
    new_node->next = (*head_ref);
    new_node->prev = NULL;  
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;   
    (*head_ref) = new_node;
}

void insert_end(struct Node **headRef , int new){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = (*headRef);
    newNode->data = new;
    newNode->next = NULL;   
    while(temp->next!=NULL) temp = temp->next;
    newNode->prev = temp;  
    temp->next = newNode;
}
void insertAfter(struct Node* prev_node, int new_data){ 
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }   
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;  
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node; 
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void printList(struct Node* node){
    struct Node* last;  
    while (node != NULL) {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }
}

void deleteNode(struct Node** head_ref, struct Node* del){
    if (*head_ref == NULL || del == NULL)
        return;   
    if (*head_ref == del)
        *head_ref = del->next;   
    if (del->next != NULL)
        del->next->prev = del->prev;   
    if (del->prev != NULL)
        del->prev->next = del->next;   
    free(del);
    return;
}

void deleteHead(struct Node **headRef){
    struct Node *temp = *headRef;
    *headRef = temp->next;
    (*headRef)->prev=NULL;
    free(temp);
    return;    
}

void deleteEnd(struct Node **headRef){
    struct Node *temp = *headRef , *prev;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
}

int main(){ 
    struct Node* head = NULL;   
    insert_begining(&head, 1);
    insert_begining(&head, 2);
    insert_end(&head,3);
    insert_end(&head,4);
    // push(&head, 3);
    // push(&head, 4);
    // push(&head, 5);
    // push(&head, 6);
    // push(&head, 7);
    printf("DLL : ");
    printList(head);

    deleteHead(&head);
    deleteEnd(&head);
    
   

    printf("\nDLL after deletion : ");
    printList(head);
    
    return 0;
}
