class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        stack<char>st , st1;
        int n=s.size(), m=part.size();
        int k=m-1;

        for(int i=0;i<n;i++){
            st.push(s[i]);
            k=m-1;
            if(st.top()==part[k]){
                while(k>=0 and !st.empty() and st.top()==part[k]){
                    k--;
                    st1.push(st.top());
                    st.pop();
                }

                if(k==-1){
                    while(!st1.empty()) st1.pop();
                }else{
                    while(!st1.empty()){
                        st.push(st1.top());
                        st1.pop();
                    }
                }
            }
        }

        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }

        return ans;
    }
};