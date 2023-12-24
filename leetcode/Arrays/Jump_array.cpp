#include<vector>
#include<iostream>
using namespace std;

 bool canJump(vector<int>& nums) {
        int n=nums.size();
        int got=0;
        for(int i=0;i<n;i++){
            if(got<i){
                return false;
            }
            got=max(got,i+nums[i]);
        }
        return true;
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
    cout<<canJump(v)<<endl;
}