#include<vector>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int hIndex(vector<int>& citations) {
        int n=citations.size();
        sort(citations.begin(),citations.end());
        int x=-1;
        for(int i=n-1;i>=0;i--){
            if((n-i)>=citations[i]){
                return (citations[i]);
            }
        }
        return -1;
    }