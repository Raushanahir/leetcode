class Solution {
public:
    int bulbSwitch(int n) {
        if(n == 0) return 0;
        int ans = 0;
        for(int i = 1; i <=n; i++) {
            int val = ceil(sqrt(i) * 1.0);
            if(i == val * val) ans++;
        }
        return ans;
    }
};