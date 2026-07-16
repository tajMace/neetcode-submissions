class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> seen;         // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int compliment = target - nums[i];

            if (seen.count(compliment)) {
                return {seen[compliment], i};
            }

            seen[nums[i]] = i;
        }

        return {};
    }
};
