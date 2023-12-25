#include<iostream>
#include<cmath>
using namespace std;

int lcs_DP(string s,string t){
    int m=s.size();
    int n=t.size();
    int **ans=new int*[m+1];
    for(int i=0;i<=m;i++){
        ans[i]=new int[n+1];
    }
    for(int i=0;i<=n;i++){
        ans[0][i]=0;
    }
    for(int i=0;i<=m;i++){
        ans[i][0]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m-i]==t[n-j]){
                ans[i][j]=1+ans[i-1][j-1];
                return (1+ans[i-1][j-1]);
            }
            else{
                ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
            }
        }
    }
    return ans[m][n];
}

int lcs(string s,string t){
//base case
if(s.size()==0 || t.size()==0){
    return 0;
}

//Rec calls
  if(s[0]==t[0]){
    return 1+lcs(s.substr(1),t.substr(1));
  }
    int a=lcs(s.substr(1),t);
    int b=lcs(s,t.substr(1));
    int c=lcs(s.substr(1),t.substr(1));
    return max(a,max(b,c));
}
int main(){


}
    
