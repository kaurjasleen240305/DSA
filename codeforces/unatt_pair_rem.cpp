#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int> ans;
    while(t--){
        int n;
        cin>>n;
        char s[n];
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        vector<int> v;
        for(auto i:mp){
            v.push_back(i.second);
        }
        int st=0,end=v.size()-1;
        sort(v.begin(), v.end(), [](int a, int b) {
        return a > b;  
    });
        if(v.size()<2){
            ans.push_back(n);
        }
        else{
            while(v[1]!=0){
                v[st]=v[st]-1;
                v[end]=v[end]-1;
                sort(v.begin(), v.end(), [](int a, int b) {
                   return a > b;  
                });
                while(v[end]==0){
                    end=end-1;
                }
            }
            ans.push_back(v[0]);
        }
    }
    for(auto i:ans){
        cout<<i<<endl;
    }
}