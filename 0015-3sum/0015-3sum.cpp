class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        vector<vector<int>> ret;
        for (int first = 0; first < n - 2; first++) {
            for (int second = first + 1; second < n - 1; second++) {
                int thirdValue = -(nums[first] + nums[second]);
                if (binary_search(nums.begin() + second + 1, nums.end(), thirdValue)) {
                    ret.emplace_back(vector<int>{ nums[first], nums[second], thirdValue });
                }
                while (second + 1 < n && nums[second] == nums[second + 1]) {
                    second++;
                }
            }
            while (first + 1 < n && nums[first] == nums[first + 1]) {
                first++;
            }
        }
        
        return ret;
    }
};