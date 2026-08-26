class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result;
        int temp1 = 1;
        for(int i=0; i<size; ++i){
            temp1 *= nums[i];
        }
        for(int i=0; i<size; ++i){
            if(nums[i] != 0){
                result.push_back(temp1/nums[i]);
            }
            else{
                int temp2 = 1;
                for(int j=0; j<size; ++j){
                    if(j != i){
                        temp2 *= nums[j];
                    }
                }
                result.push_back(temp2);
            }
        }

        return result;
    }
};
