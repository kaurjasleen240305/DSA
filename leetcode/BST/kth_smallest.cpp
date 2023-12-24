class Solution {
public:
    void dfs(TreeNode* root,int k,vector<int>& v){
       if(root==NULL || v.size()>=k){
           return;
       }
       if(root->left==NULL && root->right==NULL){
           v.push_back(root->val);
       }
       else{
          dfs(root->left,k,v);
          if(v.size()<k){
           v.push_back(root->val);
          }
          dfs(root->right,k,v);
       }
    }
    int kthSmallest(TreeNode* root, int k) {
       vector<int> v;
       dfs(root,k,v);
       return v.back();
    }
};