class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
       for(int i=0;i<s.length();i++){
           if((s[i]=='(') || (s[i]=='{') || (s[i]=='[')){
               st.push(s[i]);
           }
           else if((s[i]==')') || (s[i]=='}') || (s[i]==']')){
               char d=st.top();
               if(d=='('){
                  if(s[i]!=')'){
                    return false;
                  }
               }
               else if(d=='{'){
                if(s[i]!='}'){
                    return false;
                  }
               }
               else if(d=='['){
                if(s[i]!=']'){
                    return false;
                  }
               }
           }
       }
       return true;

    }
};