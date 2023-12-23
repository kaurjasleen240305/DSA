#include<bits/stdc++.h>
using namespace std;
#include "bt.h"

int getMinimumDifference(TreeNode* root) {
        if(root==NULL){
            return INT_MAX;
        }
        int leftmin=getMinimumDifference(root->left);
        int rightmin=getMinimumDifference(root->right);
        int x=INT_MAX,y=INT_MAX;
        if(root->left!=NULL){
           x=root->val-(root->left->val);
        }
        if(root->right!=NULL){
           y=(root->right->val)-root->val;
        }
        int finalmin;
        if(leftmin<rightmin){
            finalmin=leftmin;
        }
        if(x<finalmin){
            finalmin=x;
        }
        if(y<finalmin){
            finalmin=y;
        }
        return finalmin;

    }

//CP COURSE BST Q1
void insertDuplicateNode(BinaryTreeNode<int>* root){
    if(root==nullptr){
        return;
    }
    insertDuplicateNode(root->left);
    insertDuplicateNode(root->right);
    BinaryTreeNode<int>* root_dup=new BinaryTreeNode<int>(root->data);
    if(root->left==nullptr){
        root->left=root_dup;
    }
    else{
        root_dup->left=root->left;
        root->left=root_dup;
    }
}
//CP COURSE BST 2
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==p->val || root->val==q->val){
            return root;
        }
        TreeNode* from_left=lowestCommonAncestor(root->left,p,q);
        TreeNode* from_right=lowestCommonAncestor(root->right,p,q);
        if(from_left==NULL && from_right!=NULL){
              return from_right;
        }
        else if(from_left!=NULL && from_right==NULL){
            return from_left;
        }
        else if(from_left!=NULL && from_right!=NULL){
            return root;
        }
        else{
            return NULL;
        }
    }