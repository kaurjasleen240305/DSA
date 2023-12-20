#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int zeroes=0,ones=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                zeroes++;
            }
            else{
                ones++;
            }
        }
        if(zeroes==ones){
            cout<<0<<endl;
        }
        else if(zeroes==0 || ones==0){
            cout<<(s.length())<<endl;
        }
        else{
            vector<int> ofz;
            vector<int> ofo;
            string s_n=s;
            if(ones>zeroes){
                for(int i=0;i<s.length();i++){
                    if(s[i]=='0'){
                        ofz.push_back(i);
                        // cout<<i<<endl;
                    }
                    else{
                        ofo.push_back(i);
                    }
                }
                for(int i=0;i<(ofz.size());i++){
                    s_n[ofz[i]]='1';
                    s_n[ofo[i]]='0';
                }
                int ans=0;
                for(int i=(s_n.length()-1);i>=0;i--){
                    if(s_n[i]=='0'){
                        break;
                    }
                    // cout<<"hey"<<endl;
                    ans++;
                }
                cout<<ans<<endl;
            }
            else{
                for(int i=0;i<s.length();i++){
                    if(s[i]=='0'){
                        ofz.push_back(i);
                        // cout<<i<<endl;
                    }
                    else{
                        ofo.push_back(i);
                    }
                }
                for(int i=0;i<(ofo.size());i++){
                    s_n[ofz[i]]='1';
                    s_n[ofo[i]]='0';
                }
                int ans=0;
                for(int i=(s_n.length()-1);i>=0;i--){
                    if(s_n[i]=='1'){
                        break;
                    }
                    // cout<<"hey"<<endl;
                    ans++;
                }
                cout<<ans<<endl;
            }
        }
    }
}