class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        
        int i=0, j=0;
        int n=name.size() , m=typed.size();

        while(i<n and j<m){
            int cnt=0;
            if(name[i]!=typed[j]) return false;
            while(i<n and name[i]==typed[j]){
                i++;
                cnt++;
            }
            int cnt2=0;
            while(j<m and name[i-1]==typed[j] ){
                j++;
                cnt2++;
            }
            if(cnt2>=cnt)continue;
            else return false;
        }

        if(i==n and j==m ) return true;
        return false;
    }
};