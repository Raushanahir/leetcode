class Solution {
public:
    int longestValidParentheses(string s) {
        
        int cnt=0;
        int n=s.size();
        stack<pair<char,int>>st;

        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({s[i],i});
                cnt=max(i,cnt);
            }
            else if(s[i]=='(')st.push({s[i],i});
            else{
                if(st.top().first=='('){
                    st.pop();      
                    if(!st.empty())
                    cnt=max((i-st.top().second),cnt);
                }else {
                    st.push({s[i],i});
                }
            }
        }

        if(st.empty()) return n;
        return cnt;
    }
};