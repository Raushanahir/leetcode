class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {

        n=n*n;
        int ans=maxWeight/w;
        if(ans<=n) return ans;
        return n;   
    }
};