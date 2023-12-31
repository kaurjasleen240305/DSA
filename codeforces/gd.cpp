#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    long long int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int pro=1;
        for(int i=0;i<n;i++){
            pro*=arr[i];
        }
        if(2023%pro==0){
            int x=2023/pro;
            cout<<"YES"<<endl;
            cout<<x<<" ";
            for(int i=1;i<=(k-1);i++){
                cout<<1<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
 
    }
}
 