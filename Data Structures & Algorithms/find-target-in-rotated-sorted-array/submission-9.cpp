class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r=nums.size()-1;
        int m;

        while(l<=r){
            m = l+ (r-l)/2;
            if(nums[m]==target) return m;
            else if(target < nums[m]){
                if(nums[l]<nums[r]) r= m-1;
                else if(nums[m]>nums[r]){
                    if(target<nums[l]) l= m+1;
                    else r= m-1;
                }
                else{
                    if(target<nums[l]) r= m-1;
                    else l= m+1;
                }
            }
            else{
                if(nums[l]<nums[r]) l= m+1;
                else if(nums[m]>nums[r]) l = m+1;
                else{
                    if (target<nums[l]) l= m+1;
                    else r= m-1;
                }
            }
        }

        return -1;
    }
};
