class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++) {
            um[nums[i]] = i;
        }
        
        vector<vector<int>> ret;
        for (int first = 0; first < n; first++) {
            for (int second = first + 1; second < n; second++) {
                int thirdValue = -(nums[first] + nums[second]);
                if (um.count(thirdValue) > 0 && um[thirdValue] > second) {
                    ret.emplace_back(vector<int>{ nums[first], nums[second], thirdValue });
                }
                second = um[nums[second]];
            }
            first = um[nums[first]];
        }
        
        return ret;
    }
};