#include <bits/stdc++.h>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s;

        for (int i = 0; i < nums.size(); i++) {
            if (s.contains(nums[i])) {
                return true;
            }
        
            s.insert(nums[i]);
        }

        return false;
    }
};