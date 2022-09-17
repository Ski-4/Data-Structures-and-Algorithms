// Link to problem - https://www.interviewbit.com/problems/0-1-knapsack/


// Top Down Approach
vector<vector<int>> dp;

int findMaxValue(vector<int>& values, int i, int w, vector<int>& weights) {
    if(i==(int)values.size())
        return 0;
        
    if(dp[i][w]!=-1)
        return dp[i][w];
        
    int ans = 0;
    if(w-weights[i]>=0)
        ans = values[i]+findMaxValue(values,i+1,w-weights[i],weights);
    ans = max(ans,findMaxValue(values,i+1,w,weights));
    
    dp[i][w] = ans;
    
    return ans;
}

int Solution::solve(vector<int> &values, vector<int> &weights, int W) {
    int n = values.size();
    
    dp = vector<vector<int>>(n,vector<int>(W+1,-1));
    
    return findMaxValue(values,0,W,weights);
}

// Bottom Up Approach
int Solution::solve(vector<int> &values, vector<int> &weights, int W) {
    int n = values.size();
    
    vector<vector<int>> dp = vector<vector<int>>(n+1,vector<int>(W+1,0));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=W;j++) {
            dp[i][j] = dp[i-1][j];
            if(j-weights[i-1]>=0) {
                dp[i][j] = max(dp[i][j],dp[i-1][j-weights[i-1]]+values[i-1]);
            }
        }
    }
    
    return dp[n][W];
}