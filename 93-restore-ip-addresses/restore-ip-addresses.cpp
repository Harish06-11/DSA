class Solution {
public:
    vector<string> result;

    void backtrack(string &s, int index, int parts, string current) {
        // If we've formed 4 parts
        if (parts == 4) {
            // All digits must be used
            if (index == s.size()) {
                current.pop_back(); // remove last '.'
                result.push_back(current);
            }
            return;
        }

        
        for (int len = 1; len <= 3; len++) {
            if (index + len > s.size())
                break;

            string part = s.substr(index, len);

 
            if (part.size() > 1 && part[0] == '0')
                continue;

         
            if (stoi(part) > 255)
                continue;

            backtrack(s, index + len, parts + 1, current + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        result.clear();

        
        if (s.length() < 4 || s.length() > 12)
            return result;

        backtrack(s, 0, 0, "");

        return result;
    }
};
