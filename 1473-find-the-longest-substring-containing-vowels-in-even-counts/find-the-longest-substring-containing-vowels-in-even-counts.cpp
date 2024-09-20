class Solution {
public:
    int findTheLongestSubstring(string s) {
        
        vector<int>vis(5,0);
        map<vector<int>,int>mp;
        mp[vis]=-1;
        int ans=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){vis[0]+=1; vis[0]=vis[0]%2;}
            else if(s[i]=='e') {vis[1]+=1;  vis[1]=vis[1]%2;}
            else if(s[i]=='i') {vis[2]+=1;  vis[2]=vis[2]%2;}
            else if(s[i]=='o') {vis[3]+=1;  vis[3]=vis[3]%2;}
            else if(s[i]=='u') {vis[4]+=1;  vis[4]=vis[4]%2;}

            if(mp.find(vis)!=mp.end()){
                ans=max(ans,i-mp[vis]);
            }else mp[vis]=i;
        }
        return ans;
    }
};