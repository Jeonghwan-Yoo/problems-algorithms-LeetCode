class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        vector<int> nums;
        for (int i = 0; i < len1; i++) {
            nums.emplace_back(nums1[i]);
        }
        for (int i = 0; i < len2; i++) {
            nums.emplace_back(nums2[i]);
        }
        sort(nums.begin(), nums.end());
        
        int len = nums.size();
        int lenHalf = len / 2;
        double ret = 1e7;
        if (len % 2 == 1) {
            ret = nums[lenHalf];
        } else {
            ret = (nums[lenHalf] + nums[lenHalf - 1]) / 2.0;
        }
        return ret;
    }
};