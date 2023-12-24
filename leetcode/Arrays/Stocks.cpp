#include<bits/stdc++.h>

int maxProfit(vector<int>& prices) {
        int ans=0;
        int buyed=-1;
        prices.push_back(-1);
        for(int i=0;i<prices.size();i++){
            if(buyed!=-1){
                if(prices[i]>prices[i-1]){
                    continue;
                }
                else{
                    ans+=prices[i-1]-buyed;
                    buyed=-1;
                }
            }
            if(prices[i+1]-prices[i]>0){
               buyed=prices[i];
            }
        }
        return ans;
    }