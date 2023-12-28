#include<bits.stdc++.h>
using namespace std;
int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        int max=INT_MIN;
        int min=INT_MAX;
        map<int,int> ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(nums[i]>max){
                max=nums[i];
            }
            if(nums[i]<min){
                min=nums[i];
            }
        }
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]-1]>0){
                ans[nums[i]]=nums[i]-1;
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(ans[nums[i]]==0){
                int size=1;
                for(int i=nums[i]+1;i<max;i++){
                     if(ans[i]==i-1){
                         size++;
                     }
                     else{
                         break;
                     }
                }
                if(size>ans){
                    ans=size;
                }
            }
        }
        return ans;
    }