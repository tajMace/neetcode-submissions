class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        unordered_set<int> s;

        // turn into a hashmap for o(1) lookup
        for (auto &num : nums) {
            s.insert(num);
        }

        int longest = 0;
        for (auto &num : nums) {
            if (s.count(num - 1) != 0) {
                continue;
            }

            int attempt = 0;
            for (int i = num; s.count(i); i++) {
                attempt++;
            }
            longest = (longest > attempt) ? longest : attempt;
        }

        return longest;
    }
};
