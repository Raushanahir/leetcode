class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto it : arr) {
            if(!mp[it]) {
                mp[it]++;
                mp[2 * it]++;
            }
            else {
                if((it % 2 == 0) && mp[it/2]) {
                    mp[it]++;
                    mp[2 * it]++;
                }
            }
            if(it == 0) {
                if(mp[it] >= 4) return true;
            }
            else {
                if(mp[it] == 2 || mp[2 * it] == 2) return true;
            }
        }
        return false;
    }
};