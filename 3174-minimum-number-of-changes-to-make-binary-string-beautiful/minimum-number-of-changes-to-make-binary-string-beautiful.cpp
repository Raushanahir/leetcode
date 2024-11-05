class Solution {
public:
    int minChanges(string s) {
        
        int zero=0;
        int one=0;
        int cnt_cng=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='0') zero++;
            else one++;

            if(i%2!=0){
                if(one==1 || zero==1)
                    cnt_cng++;

                zero=0;
                one=0;
            }
        }

        return cnt_cng;
    }
};