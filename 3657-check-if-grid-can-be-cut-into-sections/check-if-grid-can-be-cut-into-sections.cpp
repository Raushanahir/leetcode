class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rec) {

        vector<pair<int,int>>x,y;
        for(auto it:rec){
            x.push_back({it[0],it[2]});
            y.push_back({it[1],it[3]});
        }

        sort(begin(x),end(x));
        sort(begin(y),end(y));

        return fn(x) || fn(y);
    }

    bool fn(vector<pair<int,int>>&v){

        stack<int>st;

        for(auto it:v){
            if(st.empty() || st.top()<=it.first){
                st.push(it.first);
                st.push(it.second);
            }else{
                int k=st.top();
                st.pop();
                st.pop();
                st.push(it.first);
                st.push(max(it.second,k));
            }
        }

        return st.size()>4?1:0;
    }
};