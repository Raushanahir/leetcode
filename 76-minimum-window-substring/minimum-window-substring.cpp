class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int>mp;
        int n=s.size();
        if(t.size()>n) return "";

        for(auto it:t){
            mp[it]++;
        }

        int i=0 , j=0;
        int flag=0;
        int ans=INT_MAX, ind=0;

        while(j<n){
            flag=0;
            mp[s[j]]--;
            for(auto it:mp){
                if(it.second>0){
                    flag=1;
                    break;
                }
            }
            while(flag==0){
                if(flag==0 and ans>=j-i+1){
                    ans=min(j-i+1,ans);
                    ind=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    flag=1;
                }
                i++;
            }
            j++;
        }

        if(ans==INT_MAX) return "";

        return s.substr(ind,ans);
    }
};