class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size();
        for(int i=0;i<n;i++){
            stones[i]%=3;
        }

        vector<int> freq(3,0);
        for(int i=0;i<n;i++){
            freq[stones[i]]++;
        }

        return freq[0] & 1 ? abs(freq[1] - freq[2]) > 2 : min(freq[1], freq[2]) > 0;
    }
};