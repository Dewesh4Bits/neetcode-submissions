int util(int left, int right, vector<vector<int>> &dp, vector<int>& nums, int &n){
    if(left > right || left < 0 || right>=n)
        return 0; 
    
    if(dp[left][right] != -1)
        return dp[left][right]; 

    int maxVal = 0; 
    int leftVal = (left==0) ? 1 : nums[left-1]; 
    int rightVal = (right==n-1) ? 1 : nums[right+1]; 
    for(int i=left; i<=right; i++){
        int tempMax = util(left, i-1, dp, nums, n) + util(i+1, right, dp, nums, n) + leftVal*rightVal*nums[i]; 
        if(tempMax > maxVal)
            maxVal = tempMax; 
    }
    return dp[left][right] = maxVal; 
}

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size(); 
        /*
        vector<int> numsModified(n+2, 1); 
        for(int i=0; i<n; i++){
            numsModified[i+1] = nums[i]; 
        }
        */

        vector<vector<int>> dp(n+2, vector<int>(n+2, -1)); 
        return util(0, n-1, dp, nums, n);
    }
};
