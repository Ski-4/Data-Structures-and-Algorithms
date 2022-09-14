// Link to problem - https://leetcode.com/problems/removing-minimum-number-of-magic-beans/


class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        
        sort(beans.begin(),beans.end());
        
        int n = beans.size();
        
        long long int ans = LLONG_MAX;
        
        long long int sum = 0;
        for(int i=0;i<n;i++)
            sum += beans[i];
        
        for(int i=0;i<n;i++) {
            long long int result = sum-(n-i)*(long long int)beans[i];
            ans = min(ans,result);
        }
        
        return ans;
    }
};