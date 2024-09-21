class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        vector<string>ans;

        for(int i=1;i<=n;i++){
            string s=to_string(i);
            ans.push_back(s);
        }

        sort(ans.begin(),ans.end(),cmp);
        vector<int>res;

        for(auto it:ans){
            res.push_back(stoi(it));
        }
        return res;
    }

    static bool cmp(string a, string b){
        int i=0;
        int k=min(a.size(),b.size());
        while(i<k){
            if(a[i]==b[i]){
                i++;
                continue;
            }
            return a<b;
        }
        return a<b;
    }
};