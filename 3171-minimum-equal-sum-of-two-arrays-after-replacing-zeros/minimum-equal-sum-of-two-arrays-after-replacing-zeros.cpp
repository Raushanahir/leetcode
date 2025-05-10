class Solution {
public:
    long long minSum(vector<int>& num1, vector<int>& num2) {

        int n = num1.size(), m = num2.size();
        sort(num1.rbegin(), num1.rend());
        sort(num2.rbegin(), num2.rend());
        long long zeros1 = -1, zeros2 = -1;

        long long sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum1 += num1[i];
            if (num1[i] == 0) {
                zeros1 = n - i;
                break;
            }
        }

        for (int j = 0; j < m; j++) {
            sum2 += num2[j];
            if (num2[j] == 0) {
                zeros2 = m - j;
                break;
            }
        }

        if (zeros1 == -1 || zeros2 == -1) {
            if (zeros1 != -1) {
                sum1 += zeros1;
                return sum2 >= sum1 ? sum2 : -1;
            } else if (zeros2 != -1) {
                sum2 += zeros2;
                return sum1 >= sum2 ? sum1 : -1;
            }
            if (sum1 == sum2) {
                return sum1;
            } else
                return -1;
        } else {
            sum1 += zeros1;
            sum2 += zeros2;
        }

        return max(sum1, sum2);
    }
};