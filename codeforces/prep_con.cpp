#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int ack=k;
        int a[n];
        int b[n];
        int c[n];
        k=k-1;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        c[0]=a[0];
        for(int i=1;i<n;i++){
            c[i]=c[i-1]+a[i];
        }
        int ans=a[0];
        // c[0]=a[0];
        int i=0;
        int maxi=-1;
        if(ack<=n){
            while(k>0){
            //   d[i].push_back(k*b[i]+c[i]);
              if(maxi<(k*b[i]+c[i])){
                cout<<c[i]<<" "<<(k*b[i])<<endl;
                maxi=k*b[i]+c[i];
              }
              k--;
              i++;
            }
            cout<<maxi<<endl;
            

        }
        else{
            
        }

    }
}