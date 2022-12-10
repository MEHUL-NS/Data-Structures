#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data;   
    new_node->next = (*head_ref);    
    (*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, int new_data){
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;} 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL){
    *head_ref = new_node;
    return;}
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

void printList(struct Node *node){
  while (node != NULL){  
     printf(" %d ", node->data);
     node = node->next;}  
}


void deleteNode(struct Node** node , int key){
    struct Node *temp = *node, *prev;
    if(temp!=NULL && temp->data==key){
        *node = temp->next;
        free(temp);
        return;
    } 
    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL) return;//If key is not present
    prev->next=temp->next;//Removing the node
    free(temp);
}

void deleteathead(struct Node** node){
    struct Node *temp = *node;
    *node = temp->next;
    free(temp);
    return; 
}

void deleteatend(struct Node** node){
    struct Node *temp = *node , *prev;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
    return;
}
int main()
{

  struct Node* head = NULL;   
  append(&head, 1);  
  append(&head, 2); 
  append(&head, 3);  
  insertAfter(head->next, 4); 
  append(&head, 5);  
  append(&head, 6); 
  printf("Created Linked list is : \n ");
  printList(head);
  deleteNode(&head,4);printf("\n");
  printList(head);
  deleteathead(&head); printf("\n");printList(head);
  deleteatend(&head); printf("\n");printList(head);
  return 0;
}
