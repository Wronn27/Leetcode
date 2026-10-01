class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        vector<int> ans,keys;
        while(!freq.empty()){
            for(auto i:freq){
                if(i.second==0) continue;
                ans.push_back(i.first);
                freq[i.first]--;
            }
            erase_if(freq,[](const auto& temp){
                return temp.second==0;
            });
        }
        return ans;
    }
};