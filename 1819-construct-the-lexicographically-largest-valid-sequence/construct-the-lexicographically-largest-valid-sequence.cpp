class Solution {
public:
    vector<int> constructDistancedSequence(int n) {

        vector<int> ans(2 * n - 1, -1);
        vector<bool> used(n+1, false);

        solve(ans, used, 0,n);

        return ans;
    }

    bool solve(vector<int>& ans, vector<bool>& used, int ind,int n) {

        if (ans.size() == ind)
            return true;

        // agar already filled ho tab
        if (ans[ind] != -1)
            return solve(ans, used, ind + 1,n);

        for (int i = n; i >=1; i--) {

            if (used[i] == true)
                continue;

            // if i is not used 
            used[i] = true;
            ans[ind] = i;
            if (i == 1) {
                if (solve(ans, used, ind + 1,n))
                    return true;
            } 
            else {
                int j=i+ind;

                if(j<ans.size() and ans[j]==-1){
                    ans[j]=i;
                    if (solve(ans, used, ind + 1,n))
                        return true;
                    ans[j] = -1;
                }
            }
            // undo if false return 
            ans[ind] = -1;
            used[i] = false;
        }

        // when no any cases is run
        return false;
    }
};