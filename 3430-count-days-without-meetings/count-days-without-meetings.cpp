class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());
        int n = meetings.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty() || st.top() < meetings[i][0]) {
                st.push(meetings[i][0]);
                st.push(meetings[i][1]);
            } else {
                int top = st.top();
                st.pop();
                top = max(top, meetings[i][1]);
                st.push(top);
            }
        }
        int prev = days + 1;
        int ans = 0;
        while (!st.empty()) {
            ans += (prev - st.top() - 1);
            st.pop();
            prev = st.top();
            st.pop();
        }
        if (prev != 1) {
            ans += prev - 1;
        }
        return ans;
    }
};