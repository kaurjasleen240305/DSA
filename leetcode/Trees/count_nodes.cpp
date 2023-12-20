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

int numNodes(TreeNode<int>* root){
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+=numNodes(root->children[i]);
    }
    return ans;
}

int sumofNodes(TreeNode<int>* root){
    if(root->children.size()==0){
        return root->data;
    }
    int ans=root->data;
    for(int i=0;i<root->children.size();i++){
        ans+=sumofNodes(root->children[i]);
    }
    return ans;
}

TreeNode<int>* maxNode(TreeNode<int>* root){
    TreeNode<int>* max=root;
    for(int i=0;i<root->children.size();i++){
        if((max->data)<(maxNode(root->children[i])->data)){
            max=maxNode(root->children[i]);
        }
    }
    return max;
}

int height_of_tree(TreeNode<int>* root){
    int maxi=0;
    for(int i=0;i<root->children.size();i++){
        if(height_of_tree(root->children[i])>maxi){
            maxi=height_of_tree(root->children[i]);
        }
    }
    return (maxi+1);
}

//DEPTH OF A NODE IS HOW FAR IT IS FROM THE NODE
//PRINT NODES AT LEVEL K
void printAtLevelK(TreeNode<int>* root,int k){
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    for(int i=0;i<root->children.size();i++){
        printAtLevelK(root->children[i],k-1);
    }
}
//COUNT LEAF NODES
int LeafNodes(TreeNode<int>* root){
    if(root->children.size()==0){
        return 1;
    }
    int ans=0;
    for(int i=0;i<root->children.size();i++){
        ans+=LeafNodes(root->children[i]);
    }
    return ans;
}
int main(){
    TreeNode<int>* root1=takeInputlLevel();
    cout<<numNodes(root1)<<endl;
    cout<<sumofNodes(root1)<<endl;
    cout<<maxNode(root1)->data<<endl;
    cout<<height_of_tree(root1)<<endl;
    printTree(root1);
}