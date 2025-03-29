class Solution {
public:
    int mod = 1e9 + 7;
    long long binExp(long long a, long long b) {
        if (b == 0) return 1;
        long long res = binExp(a, b / 2);
        res = (res * res) % mod;
        if (b % 2) res = (res * a) % mod;
        return res;
    }
    int maximumScore(vector<int>& arr, int k) {
        int n = arr.size();
        vector<long long> prime(n);
        for (int i = 0; i < n; i++) {
            int num = arr[i];
            for (int j = 2; j <= sqrt(num); j++) {
                if (num % j == 0) {
                    prime[i]++;
                    while (num % j == 0)
                        num /= j;
                }
            }
            if (num >= 2)
                prime[i]++;
        }
        vector<long long> next(n, n), prev(n, -1);
        stack<long long> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() &&
                   prime[st.top()] < prime[i]) {
                int idx = st.top();
                st.pop();
                next[idx] = i;
            }
            if (!st.empty())
                prev[i] = st.top();
            st.push(i);
        }
        vector<long long> subCount(n);
        for (int i = 0; i < n; i++) subCount[i] = (next[i] - i) * (i - prev[i]);
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < n; i++) pq.push({arr[i], i});
        long long ans = 1;
        while(k > 0) {
            long long val = pq.top().first;
            long long ind = pq.top().second;
            pq.pop();
            long long operation = min((long long)k, subCount[ind]);
            ans = ans * binExp(val, operation) % mod;
            k -= operation;
        }
        return (int)ans%mod;
    }
};