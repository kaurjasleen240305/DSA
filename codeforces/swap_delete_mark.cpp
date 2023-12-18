#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string ac=s;
        vector<int> zeroes;
        vector<int> ones;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                zeroes.push_back(i);
            }
            else{
                ones.push_back(i);
            }
        }
        if(ones.size()==zeroes.size()){
            cout<<0<<endl;
            continue;
        }
        else if(ones.size()==0 || (zeroes.size()==0)){
            cout<<s.length()<<endl;
        }
        else{
            if(ones.size()>zeroes.size()){
                vector<int> deleted;
                // cout<<"Hey"<<endl;
                for(int i=0;i<zeroes.size();i++){
                    s[ones[i]]='0';
                    s[zeroes[i]]='1';
                }
                for(int i=0;i<ac.length();i++){
                    if(s[i]==ac[i]){
                        deleted.push_back(i);
                        ans++;
                    }
                }
                for(int i=deleted.size()-1;i>=0;i--){
                    int j=deleted[i];
                    int n=s.length();
                   while((j+1<n)&&(ac[j]==ac[j+1])){
                        ans++;
                        j++;
                   }
                   if(j==(ac.length())){
                    continue;
                   }
                   else{
                    if(ac[i]='0'){
                        ac[i]='1';
                    }
                    else{
                        ac[i]='0';
                    }
                   }
                }
                cout<<ans<<endl;
            
            }
            else{
                for(int i=0;i<ones.size();i++){
                    s[zeroes[i]]='0';
                    s[ones[i]]='1';
                }
                for(int i=0;i<ac.length();i++){
                    if(s[i]!=ac[i]){
                        ans++;
                    }
                }
                cout<<ans<<endl;
            }
        }
    }
}