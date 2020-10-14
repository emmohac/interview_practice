class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bool visited[nums.size() + 1];
        for (int i = 0; i < nums.size() + 1; ++i)
            visited[i] = false;
        
        for (const int i : nums)
            if (visited[i])
                return i;
            else
                visited[i] = true;
        return 0;
    }
};
