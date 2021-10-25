#include "bits/stdc++.h"
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
queue<int> q;
void leftview(Node* root,int level){
    if(root==NULL){
        return;
    }
    if(level==q.size()){
        q.push(root->data);
    }
    leftview(root->left,level+1);
    leftview(root->right,level+1);
    
}



int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->right=new Node(6);
    leftview(root,0);
    while(!q.empty()){
        cout<<q.front();
        q.pop();
    }
     
 }
