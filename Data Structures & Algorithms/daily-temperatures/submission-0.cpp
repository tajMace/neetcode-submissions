class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> tempIdxs;
        vector<int> result(temperatures.size(), 0);

        tempIdxs.push(0);
        for (int i = 1; i < temperatures.size(); i++) {
            while (!tempIdxs.empty() && temperatures[i] > temperatures[tempIdxs.top()]) {
                result[tempIdxs.top()] = i - tempIdxs.top();
                tempIdxs.pop();
            }

            tempIdxs.push(i);
        }

        // no need to iterate over remaning; result zeroed initially
        return result;
    }
};
