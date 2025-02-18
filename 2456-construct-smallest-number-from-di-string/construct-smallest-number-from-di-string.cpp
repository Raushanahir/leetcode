class Solution {
public:
    string smallestNumber(string pat) {
        
        int n=pat.size();
        vector<bool>vis(n+2,false);

        string ans="";
        int i=0;
        while(i<n){
            if(pat[i]=='I'){
                for(int j=1;j<n+2;j++){
                    if(vis[j]==false and pat[i]=='I'){
                        ans+=to_string(j);
                        i++; 
                        vis[j]=true;
                    }
                    if(pat[i]=='D') break;
                }
            }
            int cnt_d=0;
            while(i<n && pat[i]=='D'){
                cnt_d++;
                i++;
            }
            int cnt=cnt_d;
            int j=1;
            for(j=1;j<n+2;j++){
                if(vis[j]==false) cnt_d--;
                if(cnt_d==-1) break;
            }
            for(int k=j;k>=1;k--){
                if(vis[k]==false){
                    ans+=to_string(k);
                    cnt--;
                    vis[k]=true;
                }
                if(cnt==0) break;
            }
        }

        for(int i=1;i<n+2;i++){
            if(vis[i]==false){
                ans+=to_string(i);
                vis[i]=true;
            }
        }

        return ans;
    }
};