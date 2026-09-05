class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int best = min(heights[i], heights[j])*(j-i);
        while(i<j){
            if(heights[i] < heights[j]){
                ++i;
                best = max(best, min(heights[i], heights[j])*(j-                           i));
            }
            else{
                --j;
                best = max(best, min(heights[i], heights[j])*(j-                           i));
            }
        }

        return best;
    }
};
