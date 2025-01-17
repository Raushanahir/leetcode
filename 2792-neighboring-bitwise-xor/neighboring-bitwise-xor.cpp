class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        

        int n=derived.size();
        int ans=derived[n-1];
        for(int i=n-2;i>=0;i--){
            ans=ans^derived[i];
        }

        if(derived[n-1]==derived[n-1]^ans) return true;
        return false;
    }
};