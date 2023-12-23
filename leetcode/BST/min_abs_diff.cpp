#include<bits/stdc++.h>
using namespace std;

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