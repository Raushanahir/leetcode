class Solution {
public:
    int n;
    vector<string> letterCombinations(string digits) {
        
        n=digits.size();
        vector<string>v={"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(n==0) return {};

        vector<string>ans;

        fn(v,ans,digits,"",0);
    
        return ans;
    }

    void fn(vector<string>&v,vector<string>&ans, string digits, string temp, int ind){

            if(ind>=n){
                ans.push_back(temp);
                return;
            }
            int k=digits[ind]-'0';

            for(auto it:v[k]){
                fn(v,ans,digits,temp+it,ind+1);
            }
    }
};