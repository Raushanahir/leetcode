class Solution {
public:
    int val = 1;
    void f(unordered_set<string> &us, vector<string> &ans, string s, int ind) {
        if(ind == s.length()) {
            int l = ans.size();
            val = max(val, l);
            return;
            
        }
        string s1 = "";
        for(int i = ind; i < s.size(); i++) {
            s1.push_back(s[i]);
            if(!us.count(s1)) {
                ans.push_back(s1);
                us.insert(s1);
                f(us, ans, s, i + 1);
                us.erase(s1);
                ans.pop_back();
            }
        }
    }
    int maxUniqueSplit(string s) {
        vector<string>ans;
        unordered_set<string> us;
        f(us, ans, s, 0);
        return val;
        
    }
};