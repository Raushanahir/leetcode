class Solution {
public:
    bool checkPowersOfThree(int n) {
        
        unordered_set<int>st;

        while(n>0){
            int k=1;
            int i=1;
            while(n>=k){
                k=k*3;
                i++;
            }
            k=k/3;
            n=n-k;
            // cout << k << " " << n << endl;
            if(st.find(i)!=st.end()) return false;
            st.insert(i);
        }

        return true;
    }
};