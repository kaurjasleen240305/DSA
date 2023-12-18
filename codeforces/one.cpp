#include<bits/stdc++.h>
#include<stack>
using namespace std;

string simplifyPath(string path) {
        stack<char> st;
        int y=0;
        string ans="";
        for(int i=path.length()-1;i>=0;i--){
            if(path[i]=='/' && st.empty() && i!=0){
                continue;
            }
            if(path[i]=='.'){
               y++;
               if(y==2){
                // cout<<st.top()<<endl;
                  if(!(st.empty())){
                     while(st.top()!='/' || (!st.empty())){
                        st.pop();
                     }
                  }
                  y=0;
               }
               continue;
            }
            if(path[i]!='.'){
                if(path[i]=='/'){
                    if(!(st.empty())){
                    if(st.top()=='/'){
                        continue;
                    }
                    }
                }
                st.push(path[i]);
            }
        }
        while(!(st.empty())){
             ans+=st.top();
             st.pop();
      //       cout<<ans<<endl;
        }
        return ans;
    }
int main(){
    string s;
    cin>>s;
    cout<<simplifyPath(s)<<endl;
    
}