#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums) {
        vector<int> new_nums;
        int prev=-1;
        int count=1;
        for(int i=0;i<(nums.size());i++){
            if(i>0){
                prev=nums[i-1];
            }
            if(nums[i]==prev && (count<2)){
                count++;
                new_nums.push_back(nums[i]);
            }
            else if(nums[i]!=prev){
                new_nums.push_back(nums[i]);
                count=1;
            }
        }
        nums=new_nums;
        return new_nums.size();
    }
int main(){
    int n;
    cin>>n;
    vector<int> nums;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    int k=removeDuplicates(nums);
    cout<<k<<endl;
    for(auto i:nums){
        cout<<i<<" ";
    }
    cout<<endl;
}