class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size(),i=1,sum=nums[0];
        while(i<n && nums[i]==nums[i-1]+1){
            sum+=nums[i];
            i++;
        }
        set<int> st(nums.begin(),nums.end());
        for(i=sum;i<10000;i++){
            if(!st.count(i))
            return i;
        }
        return -1;
    }
};