class Solution {
public:
    int findMin(vector<int>& nums) {
        // Time complexity: O(logN) - where N is number of element in nums
        // Space complexity: O(1)
        
        int len = nums.size();
        // if the array only has one element, that is the smallest element
        if (len == 1)
            return nums[0];
        
        int left = 0,
            right = len - 1;
        
        // if the array is already sorted, return the first element because it is minimum
        if (nums[left] < nums[right])
            return nums[left];
        
        
        while (left <= right) {
            // a safe way to avoid overflow
            int mid = left + (right - left) / 2;
            // nums[mid] is always less than nums[mid + 1] because the array is sorted
            // if nums[mid] is now less than nums[mid - 1], nums[mid] is the minimum
            if (mid > 0 && nums[mid] < nums[mid - 1])
                return nums[mid];
            // if nums[mid] >= nums[left] and greater than nums[right]
            // the [left, mid] is sorted, so starting searching on the right
            else if (nums[mid] >= nums[left] && nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};
