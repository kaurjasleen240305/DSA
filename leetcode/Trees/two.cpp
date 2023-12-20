//LEVEL WISE INPUT IN TREES
//USING QUEUES
#include<iostream>
#include<queue>
#include "treenode.h"
using namespace std;

TreeNode<int>* takeInputlLevel(){
    int rootdata;
    cout<<"Enter rootdata";
    cin>>rootdata;
    TreeNode<int>* root=new TreeNode<int>(rootdata);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter num off children of "<<front->data<<endl;
        int numchild;
        cin>>numchild;
        for(int i=0;i<numchild;i++){
            int childData;
            cout<<"enter the data for"<<i<<"th child of"<<front->data<<endl;
            cin>>childData;
            TreeNode<int>* child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;

}


void printTree(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i=0;i<(root->children.size());i++){
        cout<<root->children[i]->data<<" ";
    }
    cout<<endl;
    for(int i=0;i<(root->children.size());i++){
        printTree(root->children[i]);
    }
}

int main(){
    TreeNode<int>* root=takeInputlLevel();
    printTree(root);
}