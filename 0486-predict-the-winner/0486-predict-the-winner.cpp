class Solution {
public:
    int dp[21][21];
    int helper(int l,int r,vector<int>& nums)
    {
        if(l==r){
            return dp[l][r]=nums[l];
        }
        if(dp[l][r]!=-1) return dp[l][r];
        
        return dp[l][r]=max(nums[l]-helper(l+1,r,nums)
                            ,nums[r]-helper(l,r-1,nums));
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return true;
        memset(dp,-1,sizeof(dp));

        int ans=helper(0,n-1,nums);
        return ans>=0 ? true : false;
    }
};