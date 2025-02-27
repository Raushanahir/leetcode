class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        unordered_set<int>st;
        // int p,q,r,s,i,j,u,v;
        int n=arr.size();
        for(auto it:arr){
            st.insert(it);
        }
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int ans=2;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=arr[i];
                int b=arr[j];
                int k=a+b;
                int cnt=2;
                // if(dp[i][j]==1)
                // {
                //     continue;
                // }
                while(st.find(k)!=st.end()){
                    // u=mp[a];
                    // v=mp[b];
                    // dp[u][v]=1;
                    cnt+=1;
                    a=b;
                    b=k;
                    k=a+b;
                }
                ans=max(ans,cnt);
                if(ans>=(n-j)) break;
            }
                if(ans>=(n-i)) break;
        }
        if(ans==2) return 0;
        return ans;
    }
};