class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int l = 0, r = rows*cols - 1;
        int m;
        //each cell is represented as i*rowsize + j
        while(l<=r){
            m = l + (r-l)/2;
            int curcol = m%cols;
            int currow = (m-curcol)/cols;
            if(matrix[currow][curcol]==target) return true;
            else if(matrix[currow][curcol]<target) l= m+1;
            else r = m-1;
        }

        return false;
    }
};
