#include<stdio.h>
#include<stdlib.h>

typedef struct tree {
    int data;
    struct tree *left, *right;
} tree;

tree *create();
void preorder(tree *);
void inorder(tree *);
void postorder(tree *);

int main() {
    tree *root;
    printf("\nBinary Tree Traversals\n");
    root = create();
    printf("\nTree created successfully\n");
    printf("\nPre-order Traversal: ");
    preorder(root);
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPost-order Traversal: ");
    postorder(root);
    return 0;
}

tree* create() {
    int key;
    printf("\nEnter 1 to enter node data, 0 otherwise: ");
    scanf("%d", &key);
    if(key==1) {
        tree *temp;
        temp = (tree *)malloc(sizeof(tree));
        printf("\nEnter the node data: ");
        scanf("%d", &temp->data);
        printf("\nLeft node of %d: ", temp->data);
        temp->left = create();
        printf("\nRight node of %d: ", temp->data);
        temp->right = create();
        return temp;
    }
    else {
        return NULL;
    }
}

void preorder(tree* root) {
    if(root==NULL) {
        return;
    }
    else {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(tree* root) {
    if(root==NULL) {
        return;
    }
    else {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(tree* root) {
    if(root==NULL) {
        return;
    }
    else {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}