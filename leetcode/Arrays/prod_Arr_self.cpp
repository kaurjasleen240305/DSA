#include<vector>
#include<iostream>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int prod_front[n];
        int prod_back[n];
        prod_front[0]=nums[0];
        prod_back[n-1]=nums[n-1];
        for(int i=1;i<nums.size();i++){
            prod_front[i]=prod_front[i-1]*nums[i];
        }
        for(int i=n-2;i>=0;i--){
            prod_back[i]=prod_back[i+1]*nums[i];
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                ans.push_back(prod_back[i+1]);
                continue;
            }
            if(i==nums.size()-1){
                ans.push_back(prod_front[i-1]);
                continue;
            }
            ans.push_back(prod_front[i-1]*prod_back[i+1]);
        }
        return ans;
    }