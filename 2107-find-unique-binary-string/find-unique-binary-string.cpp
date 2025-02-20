class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n=nums.size();
        unordered_set<string>st;

        for(auto it:nums){
            st.insert(it);
        }

        string ans=solve(st,"",0,n);

        return ans;
    }

    string solve(unordered_set<string>&st , string s, int ind,int n){

        if(ind==n){
            if(st.find(s)==st.end()){
                return s;
            }else return "";
        }

        s.push_back('0');
        string ans=solve(st,s,ind+1,n);
        if(!ans.empty()) return ans;
        s.pop_back();
        s.push_back('1');
        ans=solve(st,s,ind+1,n);
        if(!ans.empty()) return ans;
        s.pop_back();

        return "";
    }
};