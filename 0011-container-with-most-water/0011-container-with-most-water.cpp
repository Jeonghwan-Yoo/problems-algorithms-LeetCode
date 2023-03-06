class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        int maxVal = 0;
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int val = (right - left) * min(height[left], height[right]);
            if (maxVal < val) {
                maxVal = val;
            }
            
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxVal;
    }
};