#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int row=-1;
        int st=0;
        int end=m-1;
        int got=-1;
        while(st<end){
          if(matrix[st][n-1]==target){
             return true;
          }
          else if(matrix[end][n-1]==target){
              return true;
          }
          int mid=st+end/2;
          if(matrix[mid][n-1]==target){
              return true;
          }
          else if(matrix[mid][n-1]>target){
                end=mid-1;
          }
          else{
              st=st+1;
          }
        }
        if(got==-1){
            got=st;
        }
        st=0;
        // cout<<got<<endl;
        end=n-1;
        while(st<end){
            if(matrix[got][st]==target){
              return true;
          }
          else if(matrix[got][end]==target){
              return true;
          }
          int mid=st+end/2;
          if(matrix[got][mid]==target){
              return true;
          }
          else if(matrix[got][mid]>target){
                end=mid-1;
          }
          else{
              st=st+1;
          }
        }
        return false;
    }

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a;
    int x;
    for(int i=0;i<n;i++){
        vector<int> y;
        for(int i=0;i<m;i++){
            cin>>x;
            y.push_back(x);
        }
        a.push_back(y);
    }
    cout<<searchMatrix(a,3);
}