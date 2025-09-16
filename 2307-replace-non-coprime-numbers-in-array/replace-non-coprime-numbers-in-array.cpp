class Solution {
    int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
            ans.push_back(x);
            // keep merging as long as last two are non-coprime
            while (ans.size() > 1) {
                int a = ans[ans.size()-2];
                int b = ans[ans.size()-1];
                int g = gcd(a, b);
                if (g > 1) {
                    ans.pop_back();
                    ans.pop_back();
                    ans.push_back(lcm(a, b));
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};