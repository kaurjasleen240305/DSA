#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        long long int arr[n];
        long long int ones[n];
        for(long long int i=0;i<n;i++){
            cin>>arr[i];
        }
        long long int one=0;
        long long int one_init=0;
        long long int j=-1,k=-1;
        long long int ans=0;
        for(long long int i=0;i<n;i++){
            if(!(arr[i]) && !(one_init)){
                one_init=1;
                j=i;
            }
            if(arr[i]==1){
                one++;
            }
            if(arr[i]==0){
                ans+=one;
            }
        }
        // cout<<ans<<endl;
        for(long long int i=n-1;i>=0;i--){
            if(arr[i]==1){
                k=i;
                break;
            }
        }
        long long int one_2=0,ans_2=0;
        long long int one_3=0,ans_3=0;
        if(j==-1){
            cout<<(n-1)<<endl;
            continue;
        }
        else{
            arr[j]=1;
            for(long long int i=0;i<n;i++){
                if(arr[i]==1){
                one_2++;
            }
              if(arr[i]==0){
              ans_2+=one_2;
              }
            }
            if(ans<ans_2){
                ans=ans_2;
            }
            arr[j]=0;
        }
        if(k==-1){
            cout<<(n-1)<<endl;
            continue;
        }
        else{
            arr[k]=0;
            for(long long int i=0;i<n;i++){
                if(arr[i]==1){
                one_3++;
            }
            if(arr[i]==0){
              ans_3+=one_3;
            }
            }
            if(ans<ans_3){
                ans=ans_3;
            }
        }

        cout<<ans<<endl;


    }
}