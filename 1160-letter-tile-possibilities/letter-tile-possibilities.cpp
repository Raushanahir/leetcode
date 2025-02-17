class Solution {
public:
    int n;
    int numTilePossibilities(string tiles) {

        n = tiles.size();

        unordered_set<string> st;

        No_of_substring(tiles, st, "", 0);

        unordered_set<string> ans;

        for (auto it : st) {
            sort(it.begin(), it.end());
            do {
                ans.insert(it);
            } while (next_permutation(begin(it), end(it)));
        }

        return ans.size() - 1;
    }

    void No_of_substring(string s, unordered_set<string>& st, string temp,
                         int ind) {

        if (ind == n) {
            st.insert(temp);
            return;
        }

        temp.push_back(s[ind]);
        No_of_substring(s, st, temp, ind + 1);
        temp.pop_back();
        No_of_substring(s, st, temp, ind + 1);
    }
};