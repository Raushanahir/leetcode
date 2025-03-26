class Solution {
public:
    int minMoves2(vector<int>& g) {

       sort(begin(g),end(g));

        int n=g.size();
        int median=g[n/2];

        int ope=0;

        for(int i=0;i<n;i++){
            int diff=abs(g[i]-median);
            ope+=diff;
        }

        return ope;
    }
};