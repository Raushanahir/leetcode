class Solution {
public:
    typedef pair<int,char>p;
    string longestDiverseString(int a, int b, int c) {
        
        string ans="";
        priority_queue<p,vector<p>>pq;

        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});

        while(!pq.empty()){
            int curval=pq.top().first;
            char curchar=pq.top().second;
            pq.pop();

            if(ans.size()>=2 and ans[ans.size()-1]==curchar and ans[ans.size()-2]==curchar){
                // checking the last two character of string of ans if same then this condision will be used
                if(pq.empty()) break;

                int nextval=pq.top().first;
                char nextchar=pq.top().second;
                pq.pop();

                nextval--;
                ans+=nextchar;

                if(nextval>0) 
                    pq.push({nextval , nextchar});
            }
            else{
                ans+=curchar;
                curval--;
            }

            if(curval>0){
                pq.push({curval,curchar});
            }
        }
        return ans;
    }
};