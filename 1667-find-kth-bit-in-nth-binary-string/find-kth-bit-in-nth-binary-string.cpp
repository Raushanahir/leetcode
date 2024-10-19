class Solution {
public:
    char findKthBit(int n, int k) {
        
        if(n==1) return '0';

        string s="0";
        for(int i=1;i<n;i++){
            string ss=s;
            for(int i=0;i<ss.size();i++){
                if(ss[i]=='0') ss[i]='1';
                else ss[i]='0'; 
            }
            reverse(ss.begin(),ss.end());
            s = s + "1" + ss;
        }

        return s[k-1];
    }
};