class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         std::unordered_map<long, int> cache;
        cache[0] = 1;
        int count = 0;
        long sum = 0;

        for (int num : nums) {
            sum += num;
            long diff = sum - k;
            if (cache.find(diff) != cache.end()) {
                count += cache[diff];
            }
            cache[sum]++;
        }

        return count;
    }
};