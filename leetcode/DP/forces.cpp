#include<bits/stdc++.h>
using namespace std;

void brute_map(string s,int& ans,map<string,bool>& mp){
    if(s.length()==0){
        return;
    }
   if(mp[s]==false){
     cout<<s<<endl;
     ans++;
     mp[s]=true;
   }
   string x="",y=s[0]+"";
   for(int i=1;i<s.length();i++){
    x+=s[i];
   }
   for(int i=2;i<s.length();i++){
    y+=s[i];
   }
   brute_map(x,ans,mp);
   brute_map(y,ans,mp);
}

void brute(string s,int& ans){
    map<string,bool> mp;
    brute_map(s,ans,mp);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int ans=0;
        brute(s,ans);
        cout<<ans<<endl;
    }
}