class Solution {
public:
    vector<int> applyOperations(vector<int>& arr) {
        
        
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1]){
                arr[i]=arr[i]*2;
                arr[i+1]=0;
            }
        }

        vector<int>ans(n,0);

        int i=0;
        for(auto it:arr){
            if(it!=0){
                ans[i]=it;
                i++;
            }
        }

        return ans;

    }
};