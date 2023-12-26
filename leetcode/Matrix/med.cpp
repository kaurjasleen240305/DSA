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
                    cout<<"false"<<endl;
                    // cout<<i%3<<" "<<j%3<<" "<<board[i][j]<<endl;
                    return false;
                }
                }
            }
        }
        return true;
    }
int main(){
    vector<vector<char>> v;
    char x;
    for(int i=0;i<9;i++){
        vector<char> y;
        for(int j=0;j<9;j++){
            cin>>x;
            y.push_back(x);
        }
        v.push_back(y);
    }
    cout<<isValidSudoku(v)<<endl;
}