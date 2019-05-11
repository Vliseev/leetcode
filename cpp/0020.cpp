class Solution {
public:
    bool isValid(string s) {
        auto n = s.size();
        if(n==0)
            return true;
        stack<char> st;
        for(int i=0;i<n;++i){
            if(s[i]=='{'||s[i]=='['||s[i]=='(')
                st.push(s[i]);
            else{
                if(st.empty())
                    return false;
                auto top = st.top();
                if(top=='('&&s[i]==')')
                    st.pop();
                else if(top=='{'&&s[i]=='}')
                    st.pop();
                else if(top=='['&&s[i]==']')
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};
