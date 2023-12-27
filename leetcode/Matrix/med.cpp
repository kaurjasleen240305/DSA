#include<bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
        map<pair<int,int>,map<char,bool>> mp;
        int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!='.'){
                if(mp[{i/3,j/3}][board[i][j]]==false){
                    // cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                    mp[{i/3,j/3}][board[i][j]]=true;
                }
                else{
                    // cout<<"false"<<endl;
                    // cout<<i%3<<" "<<j%3<<" "<<board[i][j]<<endl;
                    return false;
                }
                }
            }
        }
        return true;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        map<pair<int,int>,bool> mp;
        vector<int> ans;
        int i=0;
        int j=0;
        while(i<n && j<n){
            ans.push_back(matrix[i][j]);
            mp[{i,j}]=true;
            // cout<<matrix[i][j]<<endl;
            if(j+1<n && mp[{i,j+1}]==false){
                j=j+1;
            }
            else if(i+1<m && mp[{i+1,j}]==false){
                i=i+1;
            }
            else if(j-1>=0 && mp[{i,j-1}]==false){
                j=j-1;
            }
            else if(i-1>=0 && mp[{i-1,j}]==false){
                i=i-1;
            }
            else{
                break;
            }
        }
        return ans;
    }
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v;
    int x;
    for(int i=0;i<n;i++){
        vector<int> y;
        for(int j=0;j<m;j++){
            cin>>x;
            y.push_back(x);
        }
        v.push_back(y);
    }
    for(auto i:spiralOrder(v)){
        cout<<i<<" ";
    }
    cout<<endl;
    
}