#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

typedef long long int myint;
typedef vector<long long int> v;
#define f(i,n) for(long long int i=0;i<n;i++)
#define pb push_back
typedef long long int myint;
typedef vector<long long int> v;
#define f(i,n) for(long long int i=0;i<n;i++)
#define pb push_back
int main(){
    int t;
    cin>>t;
    while(t--){
        myint n,k;
        cin>>n>>k;
        myint a[n];
        myint b[n];
        myint sum_a[n];
        myint ans=0;
        myint maxi_b[n];
        f(i,n){
            cin>>a[i];
        }
        f(i,n){
            cin>>b[i];
        }
        sum_a[0]=a[0];
        for(int i=1;i<n;i++){
            sum_a[i]=sum_a[i-1]+a[i];
        }
        maxi_b[0]=b[0];
        for(int i=1;i<n;i++){
           maxi_b[i]=max(maxi_b[i-1],b[i]);
        }
        if(k>n){
            myint ans=sum_a[n-1]+(k-n)*maxi_b[n-1];
            for(int i=n-1;i>0;i--){
                int maybe=sum_a[i-1]+(k-i)*maxi_b[i-1];
                if(maybe>ans){
                    ans=maybe;
                }
            }
            cout<<ans<<endl;
        }
        else{
            myint ans=0;
            for(int i=k-1;i>=0;i--){
                myint maybe=sum_a[i]+(k-1-i)*maxi_b[i];
                if(maybe>ans){
                    ans=maybe;
                }
            }
            cout<<ans<<endl;
        }

    }
}
