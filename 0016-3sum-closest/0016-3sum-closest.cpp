class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sumClosest = nums[0] + nums[1] + nums[2];
        for (int first = 0; first < n - 2; first++) {
            int second = first + 1;
            int third = n - 1;
            while (second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                if (abs(sumClosest - target) > abs(sum - target)) {
                    sumClosest = sum;
                }
                if (sum < target) {
                    second++;
                } else {
                    third--;
                }
            }
        }
        return sumClosest;
    }
};