#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string a="";
        string b="";
        int y=-1;
        if(s.length()==2){
            if(int(s[0])<int(s[1])){
                cout<<s[0]<<" "<<s[1]<<endl;
                continue;
            }
            else{
                cout<<-1<<endl;
                continue;
            }
        }
        for(int i=0;i<s.length()-1;i++){
            if(s[i+1]!='0'){
               y=i;
               break;
            }
        }
        if(y==-1){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<=y;i++){
                a+=s[i];
            }
            for(int j=y+1;j<s.length();j++){
                b+=s[j];
            }
            if(a.length()>b.length()){
                cout<<-1<<endl;
            }
            else if(a.length()<b.length()){
                cout<<a<<" "<<b<<endl;
            }
            else{
                int agb=-1,bga=-1;
                // cout<<"HI";
                for(int i=0;i<a.length();i++){
                    if(a[i]!=b[i]){
                        if(int(a[i])>int(b[i])){
                            agb=1;
                            break;
                        }
                        else if(int(a[i])<int(b[i])){
                          bga=1;
                          break;
                        }
                    }
                }
                if(agb==1){
                    cout<<-1<<endl;
                }
                else if(bga==1){
                    cout<<a<<" "<<b<<endl;
                }
                else{
                    cout<<-1<<endl;
                }
            }
        }
    }
}