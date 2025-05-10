class Solution {
public:
    long long minSum(vector<int>& num1, vector<int>& num2) {

        int n = num1.size(), m = num2.size();
        long long zeros1 = 0, zeros2 = 0;

        long long sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum1 += num1[i];
            if (num1[i] == 0) {
                zeros1++;
            }
        }

        for (int j = 0; j < m; j++) {
            sum2 += num2[j];
            if (num2[j] == 0) {
                zeros2++;
            }
        }

        if (zeros1 == 0 || zeros2 ==0) {
            if (zeros1 != 0) {
                sum1 += zeros1;
                return sum2 >= sum1 ? sum2 : -1;
            } else if (zeros2 != 0) {
                sum2 += zeros2;
                return sum1 >= sum2 ? sum1 : -1;
            }
            return sum1==sum2?sum1: -1;
        } else {
            sum1 += zeros1;
            sum2 += zeros2;
        }

        return max(sum1, sum2);
    }
};