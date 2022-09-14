// Link to problem - https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        unordered_map<int,int> mp;
        mp[0] = -1;
        
        int ans = INT_MAX;
        
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum+=nums[i];
        }
        
        int target = sum-x;
        sum = 0;
        
        if(target==0)
            return n;
        
        for(int i=0;i<n;i++) {
            sum+=nums[i];
            if(mp.count(sum-target)) {
                ans = min(ans,n-(i-mp[sum-target]));
            }
            mp[sum] = i;
        }
        
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};