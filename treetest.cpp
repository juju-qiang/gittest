#include<iostream>
#include<stdio.h>
#include<stack>

using namespace  std;

struct Node{
    int value;
    Node *left;
    Node *right;
    Node(int x){
        value=x;
        left=NULL;
        right=NULL;
    }
};

void insertNode(Node *node,int x){
    
    if(x<=node->value){
        if(node->left==NULL){
            node->left=new Node(x);
        }
        else{
            insertNode(node->left,x);
        }
    }
    else{
        if(node->right==NULL){
            node->right=new Node(x);
        }
        else{
            insertNode(node->right,x);
        }
    }
}

void preOrder(Node *root){
    if(root==NULL){
        return ;
    }
    cout<<root->value;
    if(root->left){
        preOrder(root->left);
    }
    if(root->right){
        preOrder(root->right);
    }
}
void inOrder(Node *root){
    if(root==NULL){
        return ;
    }
    if(root->left){
        inOrder(root->left);
    }
    cout<<root->value;
    if(root->right){
        inOrder(root->right);
    }
}
void posOrder(Node *root){
    if(root==NULL){
        return ;
    }
    if(root->left){
        posOrder(root->left);
    }
    if(root->right){
        posOrder(root->right);
    }
    cout<<root->value;
}
void preOrder1(Node *node){
    stack<Node *> nstack;
    nstack.push(node);
    while(!nstack.empty()){
        Node *temp=nstack.top();
        cout<<temp->value;
        nstack.pop();
        if(temp->right){
            nstack.push(temp->right);
        }
        if(temp->left){
            nstack.push(temp->left);
        }
    }
}

void inOrder1(Node *node){
    stack<Node *> nstack;
   // nstack.push(node);
    Node *temp=node;
    while(temp||!nstack.empty()){
       if(temp){
           nstack.push(temp);
           temp=temp->left;
       }
        else{
            temp=nstack.top();
            cout<<temp->value;
            nstack.pop();
            temp=temp->right;
        }
    }
}

void posOrder1(Node *node){
    stack<Node *>nstack1,nstack2;
    nstack1.push(node);
    Node *temp=node;
    while(!nstack1.empty()){
        temp=nstack1.top();
        nstack1.pop();
        nstack2.push(temp);
        if(temp->left){
            nstack1.push(temp->left);
        }
        if(temp->right){
            nstack1.push(temp->right);
            
        }
        
    }
    while(!nstack2.empty()){
        temp=nstack2.top();
        cout<<temp->value;
        nstack2.pop();
    }
}
int main(){
    //int n;
    //cin>>n;
    int value=3;
   // cin>>value;
    Node root(value);
    //n--;
   // while(n--){
        int x[4]={1,2,4,5};
        for(int i=0;i<4;i++)
        {
        insertNode(&root,x[i]);
        }

    //}
    //preOrder(&root);
    //inOrder(&root);
   // posOrder(&root);
    //preOrder1(&root);
    //inOrder1(&root);
    posOrder1(&root);
    return 0;
}