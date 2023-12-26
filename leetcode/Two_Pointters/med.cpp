#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
        vector<int> given=height;
        sort(height.begin(),height.end());
        int x=height[height.size()-1];
        int y;
        for(int i=height.size()-2;i>=0;i--){
            if(i==0){
                y=height[0];
            }
            if(height[i]!=x){
                y=height[i];
                break;
            }
        }
        int x_st=-1,x_en=-1,y_st=-1,y_en=-1;
        for(int i=0;i<given.size();i++){
            if(given[i]==x){
                x_st=i;
                break;
            }
        }
        for(int i=0;i<given.size();i++){
            if(given[i]==y){
                y_st=i;
                break;
            }
        }
        for(int i=given.size()-1;i>=0;i--){
            if(given[i]==x){
                x_en=i;
                break;
            }
        }
        for(int i=given.size()-1;i>=0;i--){
            if(given[i]==y){
                y_en=i;
                break;
            }
        }
        // cout<<x_st<<" "<<x_en<<" "<<y_st<<" "<<y_en<<endl;
        int len=max(abs(x_st-y_st),max(abs(x_st-y_en),max(abs(x_en-y_st),abs(x_en-y_en))));
        // cout<<len<<endl;
        return len*(y);

    }

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<maxArea(v)<<endl;
}