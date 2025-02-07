class Solution {
public:
    int maxDifference(string s) {
        
        unordered_map<char,int>mp;

        for(auto it:s){
            mp[it]++;
        }

        int odd=0 , even=INT_MAX;

        for(auto it:mp){
            if(it.second%2!=0){
                odd=max(it.second,odd);
            }else {
                even=min(it.second,even);
            }
        }

        return odd-even;
    }
};