#include<iostream>
#include "bt.h"
using namespace std;
#include<queue>
pair<int,int> heightDiameter(BinaryTreeNode<int>* root){
    if(root==nullptr){      //first->height second->diameter
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> leftAns=heightDiameter(root->left);
    pair<int,int> rightAns=heightDiameter(root->right);
    int d=max(leftAns.first+rightAns.first,max(leftAns.second,rightAns.second));
    int h=max(leftAns.first,rightAns.first)+1;
    return {h,d};
    
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
   //MAXIMUM DISTANCE BETWEEN ANY TWO NODEs;
   BinaryTreeNode<int>* root=takeInputLevel();
   cout<<"Height"<<heightDiameter(root).first<<endl;
   cout<<"Diameter"<<heightDiameter(root).second<<endl;

}