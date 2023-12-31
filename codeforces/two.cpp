#include<bits/stdc++.h>
#include <algorithm>
using namespace std;


int main(){
    long long int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> odd;
        vector<int> even;
        for(int i=0;i<n;i++){
            if(arr[i]%2==0){
                even.push_back(arr[i]);
            }
            else{
                odd.push_back(arr[i]);
            }
            int esum=0;
            int osum=0;
            for(auto j:even){
                esum+=j;
            }
            if(odd.size()==1 && even.size()!=0){
                osum+=(odd[0]-1);
            }
            else{
            for(int j=0;j<odd.size();j++){
                if((j+1)%3==0){
                    osum+=(odd[j]-1);
                }
                else{
                    osum+=odd[j];
                }
            }
            }
            cout<<(osum+esum)<<" ";
        }
        cout<<endl;
    }
}

