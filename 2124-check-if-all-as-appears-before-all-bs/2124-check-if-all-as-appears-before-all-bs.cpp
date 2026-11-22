class Solution {
public:
    bool checkString(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i <= j){
            if(s[i] == 'a'){
                i++;
            }else if(s[j] == 'b'){
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
};