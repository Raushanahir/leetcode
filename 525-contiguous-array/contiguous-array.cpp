class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        
        int n=arr.size();
        int ans=0;
        int pre=0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++){
           if(arr[i]) pre++;
           else pre--;
           
           if(!pre) ans=max(ans,i+1);
           if(mp.find(pre)==mp.end())mp[pre]=i;
           else ans=max(ans,i-mp[pre]);
        }
        
        return ans;
    }
};