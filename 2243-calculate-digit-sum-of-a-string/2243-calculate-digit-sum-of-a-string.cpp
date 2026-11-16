class Solution {
public:
    void digit(string s, int n, int k, string& str){
        int sum = s[0]-'0';
        for(int i = 1; i < n; i++){
            if((i % k) == 0){
                cout << str << "digit fn" << endl;
                str += to_string(sum);
                sum = s[i]-'0';
            }else{
                sum += s[i]-'0';
            }
        }
        str += to_string(sum);
    } 
    string digitSum(string s, int k) {
        if(s.length() <= k){
            return s;
        }
        while(s.length() > k){
            string str = "";
            digit(s, s.length(),k, str);
            cout << str << endl;
            s = str;
        }
        return s;
    }
};