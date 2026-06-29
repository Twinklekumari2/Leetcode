class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanValues{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int ans = romanValues[s.back()];
        for(int i = 0; i < s.length()-1; i++){
            int sign = romanValues[s[i]] < romanValues[s[i+1]] ? -1 : 1;
            ans += sign*romanValues[s[i]];
        }
        return ans;
    }
};