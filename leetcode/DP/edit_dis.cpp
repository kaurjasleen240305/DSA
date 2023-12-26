#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE 
int min_edit_steps(string s,string t){
    if(s.length()==0 || t.length()==0){
        max(s.length(),t.length());
    }
    if(s[0]==t[0]){
        return (min_edit_steps(s.substr(1),t.substr(1)));
    }
    return 1+min(min_edit_steps(s,t.substr(1)),min(min_edit_steps(s.substr(1),t.substr(1)),min_edit_steps(s.substr(1),t)));
}

//DP
int min_edit_2(string s,string t){
    int m=s.length();
    int n=t.length();
    int ans[m+1][n+1];
    for(int j=0;j<=n;j++){
        ans[0][j]=j;
    }
    for(int i=0;i<=m;i++){
        ans[i][0]=i;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m-i]==t[n-j]){
                ans[i][j]=ans[i-1][j-1];
            }
            else{
                ans[i][j]=1+min(ans[i-1][j-1],min(ans[i-1][j],ans[i][j-1]));
            }
        }
    }
    return ans[m][n];
}

int main(){
   string s,t;
   cin>>s>>t;
   cout<<min_edit_2(s,t)<<endl;
}