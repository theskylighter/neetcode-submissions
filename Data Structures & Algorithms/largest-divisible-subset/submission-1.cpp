class Solution {
    vector<vector<vector<int>>> memo;
    vector<vector<bool>> visited;
    
    vector<int> helper(int idx, int prev_idx, vector<int>& nums) {
        // Base case
        if (idx == nums.size()) return {};
        
        // Cache intercept (offset prev_idx by +1 to handle -1)
        if (visited[idx][prev_idx + 1]) {
            return memo[idx][prev_idx + 1];
        }
        
        // Choice A: Skip
        vector<int> skip = helper(idx + 1, prev_idx, nums);
        
        // Choice B: Take
        vector<int> take = {};
        if (prev_idx == -1 || nums[idx] % nums[prev_idx] == 0) {
            take = helper(idx + 1, idx, nums);
            take.push_back(nums[idx]); // Build the chain on the way up
        }
        
        visited[idx][prev_idx + 1] = true;
        
        // Return and cache the longer vector
        if (take.size() > skip.size()) {
            return memo[idx][prev_idx + 1] = take;
        } else {
            return memo[idx][prev_idx + 1] = skip;
        }
    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Initialize 2D grid for N x (N+1)
        memo.resize(n, vector<vector<int>>(n + 1));
        visited.resize(n, vector<bool>(n + 1, false));
        
        vector<int> ans = helper(0, -1, nums);
        
        // Vectors were built backwards, so reverse for the final answer
        reverse(ans.begin(), ans.end());
        return ans;
    }
};