#include<iostream>
#include<bits/stdc++.h>
#include "bt.h"
#include<cmath>
#include<queue>
using namespace std;

class BST_min_Max{
    public:
      bool isBST;
      int min;
      int max;
};

BinaryTreeNode<int>* bin_search(BinaryTreeNode<int>* root,int search){
    if(root==nullptr){
        return NULL;
    }
    if(root->data>search){
        return bin_search(root->left,search);
    }
    else if(root->data<search){
        return bin_search(root->right,search);
    }
    else{
        return root;
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

void elementsInrange(BinaryTreeNode<int>* root,int min,int max){
    if(root==nullptr){
        return;
    }
    if(root->data<min){
        elementsInrange(root->right,min,max);
    }
    if(root->data>max){
        elementsInrange(root->left,min,max);
    }
    if(root->data==min){
        elementsInrange(root->right,min,max);
        cout<<root->data<<" ";
    }
    if(root->data==max){
        elementsInrange(root->left,min,max);
        cout<<root->data<<" ";
    }
    if(root->data<max && root->data>min){
         elementsInrange(root->left,min,max);
         elementsInrange(root->right,min,max);
         cout<<root->data<<" ";
    }
}

int maximum(BinaryTreeNode<int>* root,int maxi){
    if(root==nullptr){
        return maxi;
    }
    if(root->data>maxi){
        maxi=root->data;
    }
    int leftmax=maximum(root->left,maxi);
    int rightmax=maximum(root->right,maxi);
    return (max(maxi,max(leftmax,rightmax)));
    
}
int minimum(BinaryTreeNode<int>* root,int mini){
    if(root==nullptr){
        return mini ;
    }
    if(root->data<mini){
        mini=root->data;
    }
    int leftmin=minimum(root->left,mini);
    int rightmin=maximum(root->right,mini);
    return (min(mini,min(leftmin,rightmin)));
}


bool is_bt_bst(BinaryTreeNode<int>* root){
    if(root==nullptr){
        return false;
    }
    int leftmax=maximum(root->left,INT_MIN);
    int rightmin=minimum(root->right,INT_MAX);
    bool output=(root->data>leftmax) && (root->data<rightmin) && (is_bt_bst(root->left))&& (is_bt_bst(root->right)) ;
    return output;
}   //-->has time complexity of O(n2)

BST_min_Max is_bt_BST(BinaryTreeNode<int>* root){
    if(root==nullptr){
        BST_min_Max output;
        output.isBST=true;
        output.min=INT_MAX;
        output.max=INT_MIN;
        return output;
    }
    BST_min_Max leftout=is_bt_BST(root->left);
    BST_min_Max rightout=is_bt_BST(root->right);
    int minimum=min(root->data,min(leftout.min,rightout.min));
    int maximum=max(root->data,max(leftout.max,rightout.max));
    bool isBSTfinal=(root->data>leftout.max)&& (root->data<=rightout.min) && (leftout.isBST) && (rightout.isBST);
    BST_min_Max output;
    output.min=minimum;
    output.max=maximum;
    output.isBST=isBSTfinal;
    return output;
}

int main(){
   BinaryTreeNode<int>* root=takeInputLevel();
//    int n,k;
//    cout<<"ENter what number to searh"<<endl;
//    cin>>n>>k;
//    BinaryTreeNode<int>* found=bin_search(root,n);
//    elementsInrange(root,n,k);
   BST_min_Max out=is_bt_BST(root);
   cout<<out.isBST<<endl;
}
