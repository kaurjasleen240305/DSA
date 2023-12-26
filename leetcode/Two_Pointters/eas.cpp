#include<bits/stdc++.h>
using namespace std;

//1
bool isPalindrome(string s) {
        string actual="";
        for(int i=0;i<s.length();i++){
            int x=int(s[i]);
            if((x>=65 && x<=90) || (x>=97 && x<=122) || (x>=49 && x<=57)){
                actual+=s[i];
            }
        }
        for(int i=0;i<actual.length();i++){
            int x=int(actual[i]);
            if((x>=65 && x<=90)){
                actual[i]=char(x+32);
            }
        }
        if(actual==""){
            return true;
        }
        int n=actual.length();
        bool ans=true;
        for(int i=0;i<=((actual.length()/2)-1);i++){
            if(actual[i]==actual[n-i-1]){
                continue;
            }
            else{
                ans=false;
                break;
            }
        }
        return ans;
    }

//2
bool isSubsequence(string s, string t) {
        if(s.length()==0){
            return true;
        }
        if(t.length()==0){
            return false;
        }
        if(s[0]==t[0]){
            return isSubsequence(s.substr(1),t.substr(1));
        }
        return isSubsequence(s,t.substr(1));
    }

int main(){
    string s;
    getline(cin,s);
    cout<<isPalindrome(s)<<endl;
}