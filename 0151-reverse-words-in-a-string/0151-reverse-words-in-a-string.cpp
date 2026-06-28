class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = n - 1;
        string result = "";
        int cnt = 0;
        while (i >= 0) {
            if (s[i] == ' ') {
                string temp = s.substr(i + 1, cnt);
                if (temp != "")
                    result += temp + " ";
                cnt = 0;
                i--;
            } else {
                cnt++;
                i--;
            }
        }
        string temp = s.substr(i + 1, cnt);
        if (temp != "")
            result += temp;
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }
};