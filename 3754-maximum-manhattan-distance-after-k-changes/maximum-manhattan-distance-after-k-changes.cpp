class Solution {
public:
    int maxDistance(string s, int k) {
        int p = k;
        int max_dis=0, dis = 0;
        // north east
        for(auto it:s){
            if(k>0 and (it=='S' || it == 'W')){
                dis++;
                k--;
            }
            else if(k==0 and (it=='S' || it == 'W')){
                dis--;
            }
            else dis++;
            max_dis = max(max_dis, dis);
        }

        // north west
        dis = 0, k = p;
        for(auto it:s){
            if(k>0 and (it=='S' || it == 'E')){
                dis++;
                k--;
            }
            else if(k==0 and (it=='S' || it == 'E')){
                dis--;
            }
            else dis++;
            max_dis = max(max_dis, dis);
        }


        // sorth east
        dis = 0, k = p;;
        for(auto it:s){
            if(k>0 and (it=='N' || it == 'W')){
                dis++;
                k--;
            }
            else if(k==0 and (it=='N' || it == 'W')){
                dis--;
            }
            else dis++;
            max_dis = max(max_dis, dis);
        }

        // south west
        dis = 0, k = p;
        for(auto it:s){
            if(k>0 and (it=='N' || it == 'E')){
                dis++;
                k--;
            }
            else if(k==0 and (it=='N' || it == 'E')){
                dis--;
            }
            else dis++;
            max_dis = max(max_dis, dis);
        }
        return max_dis;
    }
};