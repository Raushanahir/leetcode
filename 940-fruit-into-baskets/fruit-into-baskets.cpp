class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int j = 0, i = 0;
        int ans = 0;
        int n = fruits.size();\
        unordered_map<int,int>mp;

        while (j < n) {
            mp[fruits[j]]++;
                ans=max(ans,j-i);
                while(mp.size()>2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0){
                        mp.erase(fruits[i]);
                    }
                    i++;
                }
            j++;
        }
        ans = max(ans, j - i);

        return ans;
    }
};