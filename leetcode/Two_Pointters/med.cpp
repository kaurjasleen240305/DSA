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

vector<vector<int>> threeSum(vector<int> arr){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        int st=i+1;
        int end=arr.size()-1;
        int need=0-arr[i];
        while(st<end){
            if(arr[st]+arr[end]>need){
                end=end-1;
            }
            else if(arr[st]+arr[end]<need){
                st=st+1;
            }
            else{
                vector<int> x;
                x.push_back(arr[i]);
                x.push_back(arr[st]);
                x.push_back(arr[end]);
                ans.push_back(x);
                break;
            }
        }
    }
    return ans ;
}

int minSubArrayLen(int target, vector<int>& nums) {
       int ans=INT_MAX;
       int left_ptr=0;
       int right_ptr=0;
       int sum_arr[nums.size()];
       sum_arr[0]=nums[0];
       for(int i=1;i<nums.size();i++){
           sum_arr[i]=sum_arr[i-1]+nums[i];
       }
       while(left_ptr<=right_ptr && right_ptr<nums.size() && left_ptr<=nums.size()){
          int sum;
          if(left_ptr==0 || right_ptr==0){
              sum=sum_arr[right_ptr];
          }
          else{
              sum=sum_arr[right_ptr]-sum_arr[left_ptr-1];
          }
          if(sum>=target){
              ans=min(ans,right_ptr-left_ptr+1);
              left_ptr++;
          }
          else{
              right_ptr++;
          }
       }
       if(ans==INT_MAX){
           return 0;
       }
       else{
           return ans;
       }
    }

int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int lp=0,rp=0;
        map<char,bool> mp;
        int ans=INT_MIN;
        while(lp<=rp && lp<n && rp<n){
            if(mp[s[rp]]==false){
               ans=max(ans,rp-lp+1);
               mp[s[rp]]=true;
               rp++;
            }
            else{
                ans=max(ans,rp-lp+1);
                mp[s[lp]]=false;
                lp++;
            }
        }
        return ans-1;
    }

int main(){
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    cout<<minSubArrayLen(12,a)<<endl;
}