#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    struct node *left , *right , *parent;
};

struct node* createNode(char ch){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = ch;
    newNode->left = newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

struct node* insert(struct node* node , char ch){
    if(node==NULL) return createNode(ch);

    if(ch=='(') {node->left = insert(node->left,ch); node->left->parent=node;}
    else if(ch=='+' || ch=='-' || ch=='*' || ch=='/') {node->right = insert(node->right,ch); node->right->parent=node;}
    else if(ch==')') return node->parent;
    else{
        node = insert(node,ch);
        return node->parent;
    }
    return node;
}

//Traversals
void preorder(struct node* root){
    if(root == NULL) return;
    printf("%d -> ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d -> ",root->data);
    inorder(root->right);
}
void postorder(struct node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d -> ",root->data);
}



int main(){
    char exp[50];
    printf("Enter the expression : \n");
    scanf("%s",exp);
    
    char *e = exp;
    struct node* root = NULL;

    printf("%c",e+1);
    
    printf("Root = %c" , root->data);
    while(*e != '\0'){
        printf("Entered");
        root = insert(root,*e);
        e++;
    }


    printf("BST : \n");
    preorder(root);
}