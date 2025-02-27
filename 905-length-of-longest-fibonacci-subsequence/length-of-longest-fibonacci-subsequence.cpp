class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        unordered_set<int>st;
        int n=arr.size();
        for(auto it:arr){
            st.insert(it);
        }
        int ans=2;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=arr[i];
                int b=arr[j];
                int k=a+b;
                int cnt=2;
                while(st.find(k)!=st.end()){
                    cnt+=1;
                    a=b;
                    b=k;
                    k=a+b;
                }
                ans=max(ans,cnt);
                if(ans>=(n-j)) break;
            }
                if(ans>=(n-i)) break;
        }
        if(ans==2) return 0;
        return ans;
    }
};