#include<bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
        char crr[1001];
        int arr[7];
        arr[0]=1;
        arr[1]=5;
        arr[2]=10;
        arr[3]=50;
        arr[4]=100;
        arr[5]=500;
        arr[6]=1000;
        crr[1]='I';
        crr[5]='V';
        crr[10]='X';
        crr[50]='L';
        crr[100]='C';
        crr[500]='D';
        crr[1000]='M';
        string ans="";
        int index=6;
        while(num!=0){
            if(num-arr[index]>=0){
                ans+=crr[arr[index]];
                num=num-arr[index];
            }
            else{
                index--;
            }
        }
        return ans;
    }
int main(){
    int n;
    cin>>n;
    cout<<intToRoman(n)<<endl;
}