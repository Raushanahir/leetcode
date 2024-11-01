class Solution {
public:
    string makeFancyString(string s) {
        
        string ans="";

        for(int i=0;i<s.size();){
            int k=0;
            string temp="";
            while(s[i]==s[i+1] and i<s.size()){
                i++;
                k++;
            }
            if(k>=1){
                ans+=s[i];
                ans+=s[i];
                i++;
            }
            else{
                ans+=s[i];
                i++;
            }

        }

        return ans;
    }
};
