class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Time complexity: O(logN) - N is length of nums
        // Space complexity: O(1)
        int len = nums.size();
        if (len == 0)
            return -1;
        
        int left = 0,
            right = len - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // if the target is found, return the index
            if (nums[mid] == target)
                return mid;
            // if the mid element is greater than or equal the far left element
            else if (nums[mid] >= nums[left]) {
                // if the target is less than mid element and greater than or equal to the far left element
                // the target is in the range of [left, mid - 1] so make right to be mid - 1
                if (target < nums[mid] && target >= nums[left])
                    right = mid - 1;
                // othercases, i.e. target greater than mid element
                else
                    left = mid + 1;
            // if the mid element is less than or equal the far left element
            } else {
                // if the target is greater than the mid element and less than or equal the far right element
                // the target is in the range of [mid+1, right] so make left to be mid + 1
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                // othercases, i.e. target less than mid element
                else
                    right = mid - 1;
            }
        }
        // return -1 if not found
        return -1;
    }
};
