class Solution {
public:
    long long solve(string& str, string& input, int limit) {

        if (str.length() < input.length()) {
            return 0;
        }

        long long count = 0;
        string tailstr = str.substr(str.length() - input.length());
        int remainL = str.length() - input.length();

        for (int i = 0; i < remainL; i++) {
            int digit = str[i] - '0';

            if (digit <= limit) {
                count += digit * pow(limit + 1, remainL - i - 1);
            } else {
                count += pow(limit + 1, remainL - i);
                return count;
            }
        }
        if (tailstr >= input) {
            return count + 1;
        }
        return count;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s) {

        string startstr = to_string(start - 1);
        string finishstr = to_string(finish);

        return solve(finishstr, s, limit) - solve(startstr, s, limit);
    }
};