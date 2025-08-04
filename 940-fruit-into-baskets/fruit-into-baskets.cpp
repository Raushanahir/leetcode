class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int a = 0, b = -1;
        int j = 1, i = 0;
        int ans = 0;
        int n = fruits.size();
        while (j < n and fruits[j] == fruits[j - 1]) {
            a = j;
            j++;
        }
        b = j;

        while (j < n) {
            if (fruits[j] != fruits[a] and fruits[j] != fruits[b]) {
                ans = max(ans, j - i);
                if (a < b) {
                    while (i <= a) {
                        i++;
                    }
                    a = j;
                } else {
                    while (i <= b) {
                        i++;
                    }
                    b = j;
                }
            } else {
                if (fruits[j] == fruits[a])
                    a = j;
                else
                    b = j;
            }
            j++;
        }
        ans = max(ans, j - i);

        return ans;
    }
};