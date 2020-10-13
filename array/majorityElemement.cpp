class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Time complexity: O(N) - N is length of nums
        // Space complexity: O(N)

        // count how many time each element occurs
        unordered_map<int,int> map;
        for (const int i : nums)
            map[i] += 1;
        
        int threshold = floor(nums.size() / 3);
        vector<int> ret;
        // for each element in map, if its occurence is greater than threshold
        // add it to ret array
        for (const auto &kv : map)
            if (kv.second > threshold)
                ret.push_back(kv.first);
        return ret;
    }
};