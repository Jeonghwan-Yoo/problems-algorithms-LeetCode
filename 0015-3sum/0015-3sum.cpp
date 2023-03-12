class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        vector<vector<int>> ret;
        int first = 0;
        while (first < n - 2) {
            int second = first + 1;
            int third = n - 1;
            while (second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                if (sum == 0) {
                    ret.emplace_back(vector<int>{ nums[first], nums[second], nums[third] });
                    while (second + 1 < third && nums[second] == nums[second + 1]) {
                        second++;    
                    }
                    while (second < third - 1 && nums[third] == nums[third - 1]) {
                        third--;    
                    }
                    second++;
                    third--;
                }
                else if (sum < 0) {
                    second++;
                } else {
                    third--;
                }
            }
            while (first + 1 < n - 2 && nums[first] == nums[first + 1]) {
                first++;
            }
            first++;
        }
        
        return ret;
    }
};