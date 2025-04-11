class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        
        int ans=0;

        for(int i=low; i<=high;i++){
            string s=to_string(i);
            int n=s.size();
            int k=i;
            if(n%2!=0){
                i=pow(10,n);
            }else{
                int a=0 , b=0;
                int j=n;
                while(j>n/2){
                    a+=(k%10);
                    k=k/10;
                    j--;
                }
                while(j>0){
                    b+=k%10;
                    k/=10;
                    j--;
                }
                if(a==b)ans++;
            }
        }

        return ans;
    }
};