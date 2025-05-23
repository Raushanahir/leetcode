class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        
        int n=digits.size();
        vector<int>ans;
        set<int>st;

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i==k || j==k) continue;
                    int dig=100*digits[i]+10*digits[j]+digits[k];
                    if(dig%2==0 and dig/100!=0){
                        ans.push_back(dig);
                    }
                    dig=100*digits[j]+10*digits[i]+digits[k];
                    if(dig%2==0 and dig/100!=0){
                        ans.push_back(dig);
                    }
                }
            }
        }

        sort(ans.begin(),ans.end());
        vector<int>res;

        for(auto it:ans){
            if(res.empty() || res.back()!=it){
                res.push_back(it);
            }
        }

        return res;
    }
};