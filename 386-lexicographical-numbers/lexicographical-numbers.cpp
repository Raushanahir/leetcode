class Solution {
public:
//  by recursion
    vector<int> lexicalOrder(int n) {
        
        vector<int>ans;
        for(int i=1;i<=9;i++){
            solve(i,n,ans);
        }

        return ans;
    }

    void solve(int i, int n, vector<int>&ans){

        if(i>n) return ;
        ans.push_back(i);

        for(int j=0;j<=9;j++){
            int k=i*10+j;
            solve(k,n,ans);
        }
    }
};