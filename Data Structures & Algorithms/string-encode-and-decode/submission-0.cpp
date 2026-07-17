class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";

        for (auto &str : strs) {
            encoded_string += to_string(str.length()) + ':' + str;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> result;
 
        int idx = 0;

        while (idx < s.length()) {
            string buff;
            string lenString;
            while (s[idx] != ':') {
                lenString += s[idx++];
            }

            int len = stoi(lenString);
            idx++;

            for (int i = 0; i < len; i++) {
                buff += s[idx++];
            }
            result.emplace_back(buff);
        }

        return result;
    }
};
