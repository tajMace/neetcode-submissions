vector<int> getLetterFrequencyArray(string str);
vector<vector<string>> indexToArray(auto strs, auto seen);

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<int>> seen;

        for (int i = 0; i < strs.size(); i++) {
            auto freq = getLetterFrequencyArray(strs[i]);
            vector<int>& v = seen[freq];
            v.push_back(i);
        }

        return indexToArray(strs, seen);
    }
};

vector<int> getLetterFrequencyArray(string str) {
    vector<int> v(26);
    for (auto &letter : str) {
        v[letter - 'a']++;
    }

    return v;
}

vector<vector<string>> indexToArray(auto strs, auto seen) {
    vector<vector<string>> result;

    for (auto &[vec, idxs] : seen) {
        vector<string> same;
        for (auto &strIdx : idxs) {
            same.push_back(strs[strIdx]);
        }
        result.push_back(same);
    }

    return result;
}