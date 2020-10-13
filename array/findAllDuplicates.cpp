class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // Time complexity: O(N) - N is length of nums
        // Space complexity: O(N)
        vector<int> ret;
        // if size is 1, there is nothing to return
        if (nums.size() == 1)
            return ret;
        for (int i = 0, len = nums.size(); i < len; ++i) {
            // making sure that the element at index i is positive
            int v = abs(nums[i]);
            // if it is negative, meaning that it has been seen before, add to ret
            if (nums[v-1] < 0)
                ret.push_back(v);
            // if it is not negative, make it negative to mark it is just seen now
            else
                nums[v-1] *= -1;
        }
        return ret;
    }
};