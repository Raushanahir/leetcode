class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        map<int,int>mp;
        int n=arr.size();
        int i=0;
        for(auto it:arr){
            mp[it]=i;
            i++;
        }

        int ans=1;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=arr[i];
                int b=arr[j];
                int k=a+b;
                int cnt=2;
                while(1){
                    if(mp.find(k)==mp.end()) break;
                    cnt+=1;
                    a=b;
                    b=k;
                    k=a+b;
                }
                ans=max(ans,cnt);
            }
        }
        if(ans==2) return 0;
        return ans;
    }
};