class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        vector<int> nums;
        int start1 = 0;
        int start2 = 0;
        while (start1 < len1 && start2 < len2) {
            if (nums1[start1] < nums2[start2]) {
                nums.emplace_back(nums1[start1]);
                start1++;
            } else {
                nums.emplace_back(nums2[start2]);
                start2++;
            }
        }
        while (start1 < len1) {
            nums.emplace_back(nums1[start1]);
            start1++;
        }
        while (start2 < len2) {
            nums.emplace_back(nums2[start2]);
            start2++;
        }
        
        int len = nums.size();
        int lenHalf = len / 2;
        double ret = 1e7;
        if (len % 2 == 1) {
            ret = nums[lenHalf];
        } else {
            ret = ((double)nums[lenHalf] + nums[lenHalf - 1]) / 2;
        }
        return ret;
    }
};