class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> n;
        for(int i=0; i<nums.size(); i++) {
            n.push_back({nums[i], i});
        }
        sort(n.begin(), n.end());
        int i = 0;
        int j = nums.size()-1;
        while(i<j) {
            int val = n[i].first + n[j].first;
            if(val == target) {
                return {min(n[i].second, n[j].second), max(n[i].second, n[j].second)};
            }
            else if(val > target) {
                j--;
            }
            else {
                i++;
            }
        }
        return {};
    }
};
