class Solution {
public:
    long long coloredCells(int n) {
        
        long long ans=0;
        long long color=1;
        if(n==1) return 1;

        while(n>1){
            n--;
            ans+=(color*2);
            color+=2;
        }
        ans+=color;

        return ans;
    }
};