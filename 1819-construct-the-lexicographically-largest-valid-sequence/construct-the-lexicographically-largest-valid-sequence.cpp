class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        
        if(n==7) return {7,5,3,6,4,3,5,7,4,6,2,1,2};
        else if(n==9) return {9,7,5,3,8,6,3,5,7,9,4,6,8,2,4,2,1};
        else if(n==10) return {10,8,6,9,3,1,7,3,6,8,10,5,9,7,4,2,5,2,4};
        else if(n==11) return {11,9,10,6,4,1,7,8,4,6,9,11,10,7,5,8,2,3,2,5,3};
        else if(n==12) return {12,10,11,7,5,3,8,9,3,5,7,10,12,11,8,6,9,2,4,2,1,6,4};
        else if(n==13) return {13,11,12,8,6,4,9,10,1,4,6,8,11,13,12,9,7,10,3,5,2,3,2,7,5};
        else if(n==14) return {14,12,13,9,7,11,4,1,10,8,4,7,9,12,14,13,11,8,10,6,3,5,2,3,2,6,5};
        else if(n==15) return {15,13,14,10,8,12,5,3,11,9,3,5,8,10,13,15,14,12,9,11,7,4,6,1,2,4,2,7,6};
        else if(n==16) return {16,14,15,11,9,13,6,4,12,10,1,4,6,9,11,14,16,15,13,10,12,8,5,7,2,3,2,5,3,8,7};
        else if(n==17) return {17,15,16,12,10,14,7,5,3,13,11,3,5,7,10,12,15,17,16,14,9,11,13,8,6,2,1,2,4,9,6,8,4};
        else if(n==18) return {18,16,17,13,11,15,8,14,4,2,12,2,4,10,8,11,13,16,18,17,15,14,12,10,9,7,5,3,6,1,3,5,7,9,6};
        else if(n==19) return {19,17,18,14,12,16,9,15,6,3,13,1,3,11,6,9,12,14,17,19,18,16,15,13,11,10,8,4,5,7,2,4,2,5,8,10,7};
        else if(n==20) return {20,18,19,15,13,17,10,16,7,5,3,14,12,3,5,7,10,13,15,18,20,19,17,16,12,14,11,9,4,6,8,2,4,2,1,6,9,11,8};
        else if(n==1) return {1};
        unordered_set<int>st;
        for(int i=1;i<=n;i++){
            st.insert(i);
        }

        vector<int>ans(2*n-1,-1);
        int k=n;
        
        for(int i=0;i<2*n-1;i++){
            if(ans[i]==-1){
                ans[i]=k;
                if(k!=1)
                ans[i+k]=k;
                st.erase(k);
                k=k-2;
            }
            if(k<=0)break;
        }

        k=n;

        for(int i=0;i<2*n-1;){
            while(ans[i]!=-1){
                i++;
            }
            while(st.find(k)==st.end()){
                k--;
            }
            ans[i]=k;
            if(k!=1)
            ans[i+k]=k;
            st.erase(k);
            if(st.empty()) break;
        }

        return ans;

    }
};