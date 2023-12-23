#include<bits/stdc++.h>
using namespace std;
#include "bst.h"
#include "ll.h"

vector<int>* getRoot_to_Node(BinaryTreeNode<int>* root,int data){
    if(root==nullptr){
        return nullptr;
    }
    if(root->data==data){
        vector<int>* v=new vector<int>();
        v->push_back(root->data);
        return v;
    }
    vector<int>* left=getRoot_to_Node(root->left,data);
    if(left!=nullptr){
        left->push_back(root->data);
        return left;
    }
    vector<int>* right=getRoot_to_Node(root->right,data);
    if(right!=nullptr){
        right->push_back(root->data);
        return right;
    }
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

int main(){
    BinaryTreeNode<int>* root=takeInputLevel();
    int n;
    cin>>n;
    vector<int>* v=getRoot_to_Node(root,n);
    for(int i=0;i<(v->size());i++){
        cout<<v->at(i)<<endl;
    }
}