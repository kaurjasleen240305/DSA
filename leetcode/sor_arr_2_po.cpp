#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int st=0;
        int end=numbers.size()-1;
        while(st<=end){
            if(numbers[st]+numbers[end]>target){
                end--;
            }
            else if(numbers[st]+numbers[end]<target){
                st++;
            }
            else{
                ans.push_back(st+1);
                ans.push_back(end+1);
                break;
            }
        }
        return ans;
    }

int main(){
    int n;
    cin>>n;
    int t;
    cin>>t;
    vector<int> send;
    vector<int>recieve;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        send.push_back(x);
    }
    recieve=twoSum(send,t);
    for(auto i:recieve){
        cout<<i<<" ";
    }
    cout<<endl;
}
