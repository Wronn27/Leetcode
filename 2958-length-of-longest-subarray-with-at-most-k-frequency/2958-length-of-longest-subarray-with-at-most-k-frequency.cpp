class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size(),max_len=0,l=0;
        unordered_map<int,int> mp;
        
        for(int r=0;r<n;r++){
            mp[nums[r]]++;

            while(mp[nums[r]]>k){
                mp[nums[l]]--;
                l++;
            }

            max_len=max(max_len,r-l+1);
        }
        return max_len;
    }
};