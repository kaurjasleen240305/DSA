#include "bt.h"
#include<bits/stdc++.h>
class BST{
    BinaryTreeNode<int>* root;
    public:
    BST(){
        root=nullptr;
    }
    ~BST(){
        delete root;
    }
    private:
    bool hasdata(int data,BinaryTreeNode<int>* root){
         if(root==nullptr){
            return false;
         }
         if(root->data==data){
            return true;
         }
         if(root->data>data){
            hasdata(data,root->left);
         }
         else{
            hasdata(data,root->right);
         }
    }
    BinaryTreeNode<int>* smallest_from_right(BinaryTreeNode<int>* root){
        if(root==nullptr){
            BinaryTreeNode<int>* to_return=new BinaryTreeNode<int>(INT_MAX);
        }
        BinaryTreeNode<int>* mini=smallest_from_right(root->left);
        if(root->data<mini->data){
            return root;
        }
        else{
            return mini;
        }
    }
    public:
    bool hasData(int data){
       return hasdata(data,root);
    }
    BinaryTreeNode<int>* insert(int data,BinaryTreeNode<int>* root){
        if(root==nullptr){
            BinaryTreeNode<int>* root_new=new BinaryTreeNode<int>(data);
            return root_new;
        }
        if(root->data>data){
           BinaryTreeNode<int>* from_left=insert(data,root->left);
           root->left=from_left;
        }
        else{
            BinaryTreeNode<int>* from_right=insert(data,root->right);
            root->right=from_right;
        }
        return root;
    }
    BinaryTreeNode<int>* deleted(int data,BinaryTreeNode<int>* root){
        if(root==nullptr){
            return nullptr;
        }
        if(root->data>data){
            root->left=deleted(data,root->left);
            return root;
        }
        if(root->data<data){
            root->right=deleted(data,root->right);
            return root;
        }
        if(root->data==data){
            if(root->right!=nullptr && root->left!=nullptr){
            BinaryTreeNode<int>* small=smallest_from_right(root->right);
            root->data=small->data;
            delete small;
            return root;
            }
            else if(root->left==nullptr){
               BinaryTreeNode<int>* temp=root->right;
               root->right=nullptr;
               delete root;
               return temp;
            }
            else if(root->right==nullptr){
                BinaryTreeNode<int>* temp=root->left;
                root->left=nullptr;
                delete root;
                return temp;
            }
            else{
                delete root;
                return nullptr;
            }
        }
    }
    void insertDuplicateNode(BinaryTreeNode<int>* root){
        
    }
};