class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];  // Sort in ascending order by v[i][1]
    });
        int cnt=1;
        int n=points.size();
        int end=points[0][1];

        for(int i=1;i<n;i++){
            if(points[i][0]>end){
                cnt++;
                end=points[i][1];
            }
        }

        return cnt;

    }
};