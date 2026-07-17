class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();

        // get prefix vector -> sum of all before i
        vector<int> prefix(size);
        prefix[0] = 1;
        for (int i = 1; i < size; i++) {
            prefix[i] = nums[i - 1] * prefix[i - 1];
        }

        // get suffix vector -> sum of all after i
        vector<int> suffix(size);
        suffix[size - 1] = 1;
        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = nums[i + 1] * suffix[i + 1];
        }

        // get result array
        vector<int> result;
        for (int i = 0; i < size; i++) {
            result.push_back(prefix[i] * suffix[i]);
        }


        return result;
    }
};
