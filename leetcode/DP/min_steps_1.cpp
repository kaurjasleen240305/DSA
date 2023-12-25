
//BRUTE FORCE 
int min_steps_1(int n){
    if(n==1){
        return 0;
    }
    if(n%2==0 && n%3==0){
        return (1+min(min_steps_1(n-1),min(min_steps_1(n/2),min_steps_1(n/3))));
    }
    else if(n%2==0 && n%3!=0){
        return (1+min(min_steps_1(n-1),min_steps_1(n/2)));
    }
    else if(n%2!=0 && n%3==0){
       return (1+min(min_steps_1(n-1),min_steps_1(n/3)));
    }
    else{
        return (1+min_steps_1(n-1));
    }
}

int min_steps_mem(int n,int* ans){
    if(n==1){
        return 0;
    }
    if(ans[n-1]!=-1){
        return ans[n-1];
    }
    if(n%2==0 && n%3==0){
        ans[n-1]=1+min(min_steps_1(n-1),min(min_steps_1(n/2),min_steps_1(n/3)));
        return (1+min(min_steps_1(n-1),min(min_steps_1(n/2),min_steps_1(n/3))));
    }
    else if(n%2==0 && n%3!=0){
        ans[n-1]=1+min(min_steps_1(n-1),min(min_steps_1(n/2),min_steps_1(n/3)));
        return (1+min(min_steps_1(n-1),min_steps_1(n/2)));
    }
    else if(n%2!=0 && n%3==0){
        ans[n-1]=1+min(min_steps_1(n-1),min(min_steps_1(n/2),min_steps_1(n/3)));
       return (1+min(min_steps_1(n-1),min_steps_1(n/3)));
    }
    else{
        ans[n-1]=1+min(min_steps_1(n-1),min(min_steps_1(n/2),min_steps_1(n/3)));
        return (1+min_steps_1(n-1));
    }
}

//MEMOIZATION
int min_steps_2(int n){
    int* ans=new int[n];
    for(int i=0;i<n;i++){
        ans[i]=-1;
    }
    return min_steps_mem(n,ans);
}

int main(){
    int n;
    cin>>n;
    // cout<<min_steps_2(n)<<endl;
    int ans=0;
    int position=1;
    while(position<n){
        position*=3;
        ans++;
    }
    if(position!=n){
    position=position/3;
    ans--;
    while(position<n){
        position*=2;
        ans++;
    }
    if(position!=n){
    position=position/2;
    ans--;
    while(position<n){
        position++;
        ans++;
    }
    }
    }
    cout<<ans<<endl;
}