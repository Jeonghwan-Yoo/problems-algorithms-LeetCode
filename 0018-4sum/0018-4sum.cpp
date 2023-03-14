class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ret;
        int n = nums.size();
        for (int first = 0; first < n - 3; first++) {
            for (int second = first + 1; second < n - 2; second++) {
                for (int third = second + 1; third < n - 1; third++) {
                    for (int fourth = third + 1; fourth < n; fourth++) {
                        if ((long long)nums[first] + nums[second] + nums[third] + nums[fourth] == target) {
                            ret.emplace_back(vector<int>{ nums[first], nums[second], nums[third], nums[fourth] });
                            while (fourth + 1 < n && nums[fourth] == nums[fourth + 1]) {
                                fourth++;
                            }
                        }
                        while (third + 1 < n && nums[third] == nums[third + 1]) {
                            third++;
                        }
                    }
                    while (second + 1 < n && nums[second] == nums[second + 1]) {
                        second++;
                    }
                }
                while (first + 1 < n && nums[first] == nums[first + 1]) {
                    first++;
                }
            }
        }
        return ret;
    }
};