class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k>nums.size()) return {};
        if(nums.size() == 1) return {nums[0]};

        vector<int> res;
        deque<int> mdec;

        int r;
        for(r=0; r<nums.size(); ++r){
            if(mdec.empty()){
                mdec.push_back(r);
                goto L;
            }
            if(nums[r] < nums[mdec.back()]) mdec.push_back(r);
            else{
                while(!mdec.empty() && nums[r]>=nums[mdec.back()]){
                    mdec.pop_back();
                }  
                mdec.push_back(r);
            }
            L: if(r-k+1>=0){
                res.push_back(nums[mdec.front()]);
                if(mdec.front() == r-k+1) mdec.pop_front();
            } 
        } 
        return res;
    }
};
