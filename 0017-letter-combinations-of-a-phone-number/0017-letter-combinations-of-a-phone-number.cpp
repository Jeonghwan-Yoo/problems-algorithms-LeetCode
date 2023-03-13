class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (digits.size() == 0) {
            return combinations;
        }
        
        unordered_map<char, string> dial({
            { '2', "abc" },
            { '3', "def" },
            { '4', "ghi" },
            { '5', "jkl" },
            { '6', "mno" },
            { '7', "pqrs" },
            { '8', "tuv" },
            { '9', "wxyz" }
        });
        
        function<void(string, int, string)> getLetterCombinations = [&](const string digits, int idx, string combination) {
            if (idx >= digits.size()) {
                combinations.emplace_back(combination);
                return;
            }
            
            string letters = dial[digits[idx]];
            int len = letters.size();
            for (int i = 0; i < len; i++) {
                getLetterCombinations(digits, idx + 1, combination + letters[i]);
            }
        };
        getLetterCombinations(digits, 0, "");
        
        return combinations;
    }
    
};