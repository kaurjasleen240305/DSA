#include<bits/stdc++.h>
#include<stack>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            v.push_back({x,y});
        }
        int x_pos=0,x_neg=0,y_pos=0,y_neg=0;
        for(int i=0;i<n;i++){
            if(v[i].first>0){
                x_pos++;
            }
            if(v[i].first<0){
                x_neg++;
            }
        }
        for(int i=0;i<n;i++){
            if(v[i].second>0){
                y_pos++;
            }
            if(v[i].second<0){
               y_neg++;
            }
        }
        if(x_pos && x_neg && y_pos && y_neg){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }


    }
}