class Solution {
public:
    int mod=1e9+7;
    typedef long long ll;
    int maximumXorProduct(long long a, long long b, int n) {
        
        ll axor=0;
        ll bxor=0;

        for(int i=49;i>=n;i--){
            if (a & (1ll << i)) axor |= (1ll << i);
            if (b & (1ll << i)) bxor |= (1ll << i);
        }

        for(int i=n-1;i>=0;i--){
            bool ith_bit_a=a&(1ll<<i);
            bool ith_bit_b=b&(1ll<<i);

            if(ith_bit_a==ith_bit_b){
                axor^=(1ll<<i);
                bxor^=(1ll<<i);
                continue;
            }

            if(axor>bxor){
                bxor=bxor^(1ll<<i);
            }
            else {
                axor=axor^(1ll<<i);
            }
        }

        axor%=mod;
        bxor%=mod;

        return (axor*bxor)%mod;
    }
};