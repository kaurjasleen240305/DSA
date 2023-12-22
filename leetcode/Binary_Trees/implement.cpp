#include<iostream>
#include<queue>
#include "bt.h"
using namespace std;

void printTree(BinaryTreeNode<int>* root){
    if(root==nullptr){
        return ;
    }
    cout<<root->data<<":";
    if(root->left!=nullptr){
        cout<<"L"<<(root->left->data);
    }
    if(root->right!=nullptr){
        cout<<",R"<<(root->right->data);
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);

}

BinaryTreeNode<int>* takeinput(){
    int rootdata;
    char s;
    cout<<"Enter root data:"<<endl;
    cin>>rootdata;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
    cout<<"Enter Y if u need left node of"<<root->data<<" else N:"<<endl;
    cin>>s;
    if(s=='Y'){
        root->left=takeinput();
    }
    cout<<"Enter Y if u need right nodeof"<<root->data<<" else N:"<<endl;
    cin>>s;
    if(s=='Y'){
        root->right=takeinput();
    }
    return root;

}

BinaryTreeNode<int>* takeInputLevel(){
    int rdata;
    cout<<"ROOT DATA"<<endl;
    cin>>rdata;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rdata);
    queue<BinaryTreeNode<int>*> pending;
    pending.push(root);
    while(!pending.empty()){
        int ldata,ridata;
        cout<<"Enter -1 if not need left else right data of L of"<<pending.front()->data<<endl;
        cin>>ldata;
        if(ldata!=-1){
            pending.front()->left=new BinaryTreeNode<int>(ldata);
            pending.push(pending.front()->left);
        }
        cout<<"Enter -1 if not need right else right data of R of"<<pending.front()->data<<endl;
        cin>>ridata;
        if(ridata!=-1){
            pending.front()->right=new BinaryTreeNode<int>(ridata);
            pending.push(pending.front()->right);
        }
        pending.pop();
    }
    return root;
    
}

void mirror_image(BinaryTreeNode<int>* root){
    if(root==nullptr){
        return;
    }
    mirror_image(root->left);
    mirror_image(root->right);
    BinaryTreeNode<int>* temp=root->left;
    root->left=root->right;
    root->right=temp;
}

void Inorder_printing(BinaryTreeNode<int>* root){
    if(root==nullptr){
        return;
    }
    Inorder_printing(root->left);
    cout<<root->data<<endl;
    Inorder_printing(root->right);
    
}
void preOrder(BinaryTreeNode<int>* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(BinaryTreeNode<int>* root){
    if(root==nullptr){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
int main(){
    BinaryTreeNode<int>* root=takeInputLevel();
    printTree(root);
    Inorder_printing(root);
    mirror_image(root);
    printTree(root);
    delete root;
}

