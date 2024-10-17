class Solution {
public:
    long long minimumSteps(string s) {
        
        int i=0  , j=s.size()-1;
        long long ans=0;

        while(i<j){
            while(s[i]=='0' and j>i) i++;
            
            while(s[j]=='1' and j>i) j--;

            swap(s[i],s[j]);
            ans+=(j-i);
        }
        return ans;
    }
};