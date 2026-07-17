class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int ,int>> freq(2001, {0, 0});

        for (auto &num : nums) {
            int numIdx = num + 1000;
            freq[numIdx].first = num;
            freq[numIdx].second++;
        }

        // O(nlog(n)); could make this step faster... bucket sort.
        sort(freq.begin(), freq.end(), [](const auto &a, const auto &b) {
            return a.second > b.second;
        });

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freq[i].first);
        }


        return result;
    }
};
