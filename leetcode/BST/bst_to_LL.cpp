#include<bits/stdc++.h>
using namespace std;
#include "bt.h"
#include "ll.h"

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

pair<Node<int>*,Node<int>*> bst_to_ll(BinaryTreeNode<int>* root_bt){
    if(root_bt==nullptr){
        return {nullptr,nullptr};
    }
    Node<int>* root=new Node<int>(root_bt->data);
    pair<Node<int>*,Node<int>*> came_left=bst_to_ll(root_bt->left);
    pair<Node<int>*,Node<int>*> came_right=bst_to_ll(root_bt->right);
    if(came_left.first==nullptr && came_left.second==nullptr){
        if(came_right.first==nullptr && came_right.second==nullptr){
             return {root,root};
        }
        root->next=came_right.first;
        return {root,came_right.second};
    }
    came_left.second->next=root;
    Node<int>* left=came_left.first;
    if(came_right.first==nullptr && came_right.second==nullptr){
         return {left,root};
    }
    else{
        root->next=came_right.first;
        return {left,came_right.second};
    }
}

int main(){
   BinaryTreeNode<int>* root=takeInputLevel();
   pair<Node<int>*,Node<int>*> ll=bst_to_ll(root);
   Node<int>* head=ll.first;
   while(head!=nullptr){
    cout<<head->data<<" -> ";
    head=head->next;
   }
}