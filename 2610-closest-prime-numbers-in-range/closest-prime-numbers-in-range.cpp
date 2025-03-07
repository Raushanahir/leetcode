class Solution {
public:
    vector<int> closestPrimes(int left, int right) {

        vector<int> prime(right + 1, 0);

        for (int i = 2; i <= right / 2; i++) {
            if (prime[i] == 0) {
                int j = 2;
                while (i * j <= right) {
                    prime[i * j] = 2;
                    j++;
                }
            }
        }

        vector<int> ans(2, -1);
        int a = 0, b = 0;
        for (int i = left; i <= right; i++) {
            // cout << prime[i];
            if(i==1) continue;
            if (prime[i] == 0) {
                if (a == 0) {
                    a = i;
                } else if (b == 0) {
                    b = i;
                } else {
                    if (ans[0] == -1) {
                        ans[0] = a;
                        ans[1] = b;
                    } else if (abs(ans[0] - ans[1]) > abs(a - b)) {
                        ans[0] = a;
                        ans[1] = b;
                    }
                    a = b;
                    b = i;
                }
            }
        }
        if (abs(ans[0] - ans[1]) > abs(a - b)) {
            ans[0] = a;
            ans[1] = b;
        }
        if (ans[1]==-1 and a!=0 and b!=0) {
            ans[0] = a;
            ans[1] = b;
        }

        return ans;
    }
};