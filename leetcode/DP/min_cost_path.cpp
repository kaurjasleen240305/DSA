#include<bits/stdc++.h>
using namespace std;


//DP
int minCostPathdp(vector<vector<int>>& v,int n,int m){
    int **ans=new int*[m];
    for(int i=0;i<m;i++){
        ans[i]=new int[n];
    }
    ans[m-1][n-1]=v[m-1][n-1];
    for(int i=n-2;i>=0;i--){
        ans[m-1][i]=ans[m-1][i+1]+v[m-1][i];
    }
    for(int i=m-2;i>=0;i--){
        ans[i][n-1]=ans[i+1][n-1]+v[i][n-1];
    }
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            ans[i][j]=v[i][j]+min(ans[i][j+1],ans[i+1][j],ans[i+1][j+1]);
        }
    }
    return ans[0][0];
}

//BRUTE FORCE

int minCostPath(vector<vector<int>>& v,pair<int,int> st,pair<int,int> end,int n,int m){
    if((st.first>(n-1))|| (st.second>(m-1))){
        return INT_MAX;
    }
    if(st.first==end.first && st.second==end.second){
        return v[st.first][st.second];
    }
    int ans=v[st.first][st.second]+min(minCostPath(v,{st.first+1,st.second},end,n,m),min(minCostPath(v,{st.first,st.second+1},end,n,m),minCostPath(v,{st.first+1,st.second+1},end,n,m)));
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> t;
    int x;
    for(int i=0;i<n;i++){
        vector<int> y;
        for(int i=0;i<m;i++){
            cin>>x;
            y.push_back(x);
        }
        t.push_back(y);
    }
    cout<<minCostPathdp(t,m,n);
}