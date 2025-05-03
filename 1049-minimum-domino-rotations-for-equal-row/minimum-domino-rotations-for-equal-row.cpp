class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        unordered_map<int,int>mp1,mp2;
        int n=tops.size();

        vector<int>v1={1,2}, v2={2,1};
        if(v1==tops and v2==bottoms) return 1;

        for(auto i=0;i<n;i++){
            mp1[tops[i]]++;
            mp2[bottoms[i]]++;
        }
        cout << mp2.size() ;
        if(mp1.size()==1 || mp2.size()==1 ) return 0;

        int a=0,b=0;
        for(auto it:mp1){
            if(it.second>=a){
                b=it.first;
                a=it.second;
            }
        }
        int c=0,d=0;
        for(auto it:mp2){
            if(it.second>=c){
                d=it.first;
                c=it.second;
            }
        }

        int cnt1=0,cnt2=0;

        if(a>c){
            for(int i=0;i<n;i++){
                if(tops[i]!=b){
                    swap(tops[i],bottoms[i]);
                    cnt1++;
                }
            }
        }else {
            for(int i=0;i<n;i++){
                if(bottoms[i]!=d){
                    swap(tops[i],bottoms[i]);
                    cnt2++;
                }
            }
        }

        bool flag=true;
        for(int i=1;i<n;i++){
            if(tops[i]!=tops[i-1]){
                flag=false;
                break;
            }
        }
        cout << cnt1 <<endl;
        if(flag==true) return cnt1;
        flag=true;

        for(int i=1;i<n;i++){
            if(bottoms[i]!=bottoms[i-1]){
                flag=false;
                break;
            }
        }

        if(flag==false) return -1;
        return cnt2;

    }
};