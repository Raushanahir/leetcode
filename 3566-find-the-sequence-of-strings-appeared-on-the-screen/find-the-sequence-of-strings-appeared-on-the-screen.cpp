class Solution {
public:
    vector<string> stringSequence(string target) {

        vector<string>ans;
        string s="";

        for(auto it:target){
            for(char i='a';i<=it;i++){
                ans.push_back(s+i);
            }
            s=ans.back();
        }   
        return ans;
    }
};