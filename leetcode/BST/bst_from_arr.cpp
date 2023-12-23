#include<bits/stdc++.h>
#include "ll.h";
using namespace std;
#include "bt.h";
BinaryTreeNode<int>* helper(int* input,int st int end){
    if(st>end){
        return NULL;
    }
    int mid=st+end/2;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(input[mid]);
    root->left=helper(input,st,mid-1);
    root->right=helper(input,mid+1,end);
}