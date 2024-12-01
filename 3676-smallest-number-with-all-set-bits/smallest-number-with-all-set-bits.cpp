class Solution {
public:
    int smallestNumber(int n) {
        int cnt = 32 - __builtin_clz(n);
        return (1 << cnt) - 1;
    }
};