#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};


//Creating the Node
struct node *createNode(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
}


//Insert left or right
struct node *insertLeft(struct node *root , int value){
    root->left = createNode(value);
    return root->left;
}
struct node *insertRight(struct node *root , int value){
    root->right = createNode(value);
    return root->right;
}



 //insertion with controlled BST
struct node *insert(struct node *root , int value){ 
    if(root==NULL)  return createNode(value);
    if(root->data < value) root->right = insert(root->right , value);                          
    else if(root->data > value) root->left = insert(root->left , value);
    return root;  
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

//Deleting a particular Node
struct node *minNode(struct node *n){
    struct node* current = n;
    while(current && current->left != NULL)
        current=current->left;
    return current;
}

struct node *deleteNode(struct node* root, int val){
    if(root==NULL) return root;
    if(root->data > val) root->left=deleteNode(root->left,val);
    else if(root->data < val) root->right=deleteNode(root->right,val);

    else{//Node found
        if(root->left==NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        //Node with two children...get min in right subtree
        struct node* temp = minNode(root->right);
        root->data = temp->data;//copying min in this node
        root->right = deleteNode(root->right,temp->data);
    }
    return root;
}


int main(){
    int choice,val,rootValue;
    struct node *root = NULL;
    printf("Enter the root node value");
    scanf("%d",&rootValue);
    root=insert(root,rootValue);
    do{
        printf("Enter the value...");
        scanf("%d",&val);
        root=insert(root,val);
        printf("Enter 0 to insert more .....\n");
        scanf("%d",&choice);
    }while(choice==0);
    
    printf("Preorder : ");
    preorder(root);
    printf("\nInorder : ");
    inorder(root);
    printf("\nPostorder : ");
    postorder(root);    

    int v;
    
    printf("Enter to be deleted");scanf("%d",&v);
    root=deleteNode(root,v);
}