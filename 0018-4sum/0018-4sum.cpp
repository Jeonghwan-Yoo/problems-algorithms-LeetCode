class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ret;
        int n = nums.size();
        for (int first = 0; first < n - 3; first++) {
            for (int second = first + 1; second < n - 2; second++) {
                int third = second + 1;
                int fourth = n - 1;
                while (third < fourth) {
                    long long sum = (long long)nums[first] + nums[second] + nums[third] + nums[fourth];
                    if (sum == target) {
                        ret.emplace_back(vector<int>{ nums[first], nums[second], nums[third], nums[fourth] });
                        while (third + 1 < fourth && nums[third] == nums[third + 1]) {
                            third++;
                        }
                        third++;
                        while (third < fourth - 1 && nums[fourth] == nums[fourth - 1]) {
                            fourth--;
                        }
                        fourth--;
                    } else if (sum < target) {
                        third++;
                    } else {
                        fourth--;
                    }
                }
                while (second + 1 < n - 2 && nums[second] == nums[second + 1]) {
                    second++;
                }
            }
            while (first + 1 < n - 3 && nums[first] == nums[first + 1]) {
                first++;
            }
        }
        
        return ret;
    }
};