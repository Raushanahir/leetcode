class Solution {
public:
    int maximumSwap(int num) {
        vector<int>v;
        int dup=num;

        while(num){
            int k=num%10;
            num/=10;
            v.push_back(k);
        }

        vector<int>vv=v;
        sort(vv.begin(),vv.end());

        int t=v.size()-1;
        while(t>=0 && v[t]==vv[t] )t--;

        if(t<1) return dup; 

        int maxi=0;
        int ind1=-1, ind2=-1;

        for(int i=0; i<=t; i++){
            if(maxi<v[i]){
                maxi=v[i];
                ind1=i;
            }if(maxi >v[i]){
                ind2=i;
            }
        }

        if(ind1!=-1 && ind2!=-1){
            swap(v[ind1],v[ind2]);
        }
        
        for(int it=v.size() -1 ; it>=0; it--){
            num=(num*10) + v[it];
        }

        return num;
    }
};