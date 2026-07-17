class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total_product = 1;
        int numZeroes = 0;
        for (auto &num : nums) {
            if (num == 0) {
                numZeroes++;
                continue;
            }

            total_product *= num;
        }

        vector<int> result;
        for (auto &num : nums) {
            if ((numZeroes == 1 && num != 0) || numZeroes > 1) {
                result.push_back(0);
                continue;
            } else if (numZeroes == 1 && num == 0) {
                result.push_back(total_product);
            } else {
                result.push_back(total_product / num);
            }
        }

        return result;
    }
};
