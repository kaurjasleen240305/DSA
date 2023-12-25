#include<vector>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int index=-1;
        int n=gas.size();
        int ans=0;
        int i=0;
        while(i!=index ){
            if(gas[i]>cost[i] && i<(n-1)){
                if(ans==0){
                    index=i;
                }
                cout<<gas[i]<<" "<<cost[i]<<endl;
                gas[i+1]+=(gas[i]-cost[i]);
                gas[i]=cost[i];
                cout<<gas[i]<<" "<<gas[i+1]<<endl;
                ans++;
                i++;
            }
            if(gas[i]>cost[i] && i==(n-1)){
                if(ans==0){
                    index=i;
                }
                cout<<gas[i]<<" "<<cost[i]<<endl;
                gas[0]+=(gas[i]-cost[i]);
                gas[i]=cost[i];
                cout<<gas[i]<<" "<<gas[0]<<endl;
                ans++;
                i=0;
            }
            if(index!=-1 && gas[i]<cost[i]){
                break;
            }
        }
        bool x=true;
        cout<<"HI"<<endl;
        for(int i=0;i<n;i++){
            cout<<gas[i]<<" "<<cost[i]<<endl;
            if(gas[i]<cost[i]){
                x=false;
                break;
            }
        }
        if(x){
            return index;
        }
        else{
            return -1;
        }
    }

string reverseWords(string s) {
       vector<string> y;
       string x="";
       int n=s.length();
       string ans="";
       for(int i=0;i<n;i++){
           if(s[i]!=' '){
               x+=s[i];
           }
           if(s[i]==' '){
               if(x!=""){
                   y.push_back(x);
                   x="";
               }
           }
           if(i==n-1 && s[i]!=' '){
               if(x!=""){
               y.push_back(x);
               }
           }
       }
       for(int i=y.size()-1;i>=0;i--){
           if(i==0){
             ans+=y[i];
           }
           else{
               ans+=(y[i]+' ');
           }
       }
       return ans;
    }

int main(){
    int n;
    cin>>n;
    vector<int> gas;
    vector<int> cost;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        gas.push_back(x);
    }
    for(int i=0;i<n;i++){
        cin>>x;
        cost.push_back(x);
    }
    cout<<canCompleteCircuit(gas,cost)<<endl;
}