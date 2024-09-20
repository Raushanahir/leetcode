class Solution {
public:
    int findTheLongestSubstring(string s) {
        
        vector<int>vis(5,0);
        map<vector<int>,int>mp;
        mp[vis]=-1;
        int ans=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='a')vis[0]^=1;
            else if(s[i]=='e') vis[1]^=1;  
            else if(s[i]=='i') vis[2]^=1;  
            else if(s[i]=='o') vis[3]^=1;  
            else if(s[i]=='u') vis[4]^=1;  

            if(mp.find(vis)!=mp.end()){
                ans=max(ans,i-mp[vis]);
            }else mp[vis]=i;
        }
        return ans;
    }
};