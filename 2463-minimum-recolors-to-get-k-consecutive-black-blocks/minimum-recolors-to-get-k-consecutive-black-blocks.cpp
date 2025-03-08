class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int ans=blocks.size();
        int w=0;
        int i=0, j=0;

        while(j<blocks.size()){
            if(blocks[j]=='W') w++;
            if(j-i==k){
                if(blocks[i]=='W')w--;
                i++;
            }
            if(j-i+1==k){
                ans=min(w,ans);
            }
            j++;
        }

        return ans;
    }
};