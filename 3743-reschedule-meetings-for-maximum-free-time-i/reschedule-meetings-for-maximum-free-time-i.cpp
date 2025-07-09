class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        if(eventTime == n) return 0;
        
        int ans=0;
        int ins_time=0;
        vector<int>free;
        for(int i=0;i<n;i++){
                free.push_back(startTime[i]-ins_time);
                ins_time=endTime[i];
        }
        free.push_back(eventTime-ins_time);

        int i=0,j=0;
        int maxi=0;
        while(j<free.size()){
            while(j<free.size() and (j-i)<=k){
                ans+=free[j];
                j++;
            }
            maxi=max(ans,maxi);
            ans-=free[i];
            i++;
        }

        return maxi;
    }
};