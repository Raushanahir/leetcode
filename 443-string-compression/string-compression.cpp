class Solution {
public:
    int compress(vector<char>& chars) {

        int n=chars.size();

        int i=0,j=1;
        int cnt=0;
        if(n==1) return 1;

        while(j<n){
            cnt=0;
            while(j<n and chars[j]==chars[j-1]){
                cnt++;
                j++;
            }
            chars[i]=chars[j-1];
            i++;
            if(cnt==0){j++; continue;}
            cnt++;
            string s=to_string(cnt);

            for(auto it:s){
                chars[i]=it;
                i++;
            }
            j++;
        }
        if(j==n) chars[i]=chars[j-1];
        if(j==n+1) i=i-1;

       return i+1;
    }
};