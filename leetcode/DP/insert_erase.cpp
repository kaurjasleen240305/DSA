#include<bits/stdc++.h>
using namespace std;

int brute_map(string s,int ans,map<string,bool>& mp){
    if(s.length()==1){
        // cout<<s<<endl;
        if(mp[s]==false){
         ans++;
         mp[s]=true;
      }
        return ans;
    }
   if(mp[s]==false){
     ans++;
     mp[s]=true;
   }
   else{
      return ans;
   }
   string x,y;
   for(int i=0;i<s.length();i++){
    if(i==0){
        continue;
        }
    x+=s[i];
   }
   for(int i=0;i<s.length();i++){
       if(i==1){
        continue;
       }
    y+=s[i];
   }
   ans=brute_map(x,ans,mp);
   ans=brute_map(y,ans,mp);
   return ans;
}

int brute(string s,int ans){
    map<string,bool> mp;
    return(brute_map(s,ans,mp));
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        char x;
        for(int i=0;i<n;i++){
           cin>>x;
           s+=x;
        }
        int arr[26];
        for(int i=0;i<26;i++){
            arr[i]=0;
        }
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(arr[int(s[i]-97)]==0){
                ans+=(s.length()-i);
            }
            arr[int(s[i]-97)]++;
        }
        cout<<ans<<endl;
    }
}