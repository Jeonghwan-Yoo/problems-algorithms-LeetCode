class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = (int)nums.size();
        unordered_map<int, int> um;
        um.emplace(nums[0], 0);
        
        for (int i = 1; i < len; i++) {
            int leftValue = target - nums[i];
            if (um.count(leftValue) > 0) {
                return vector<int>{ i, um[leftValue] };
            }
            um.emplace(nums[i], i);
        }
        return vector<int>{ -1, -1 };
    }
};