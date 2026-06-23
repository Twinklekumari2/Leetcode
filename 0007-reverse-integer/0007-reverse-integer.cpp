class Solution {
public:
    int reverse(int x) {
       int rem;
       signed int num = 0;
       if(x > 0){
       while(x > 0) {
            rem = x % 10;
            if(num > INT_MAX/10 || (num == INT_MAX/10 && rem > 7)){
                return 0;
            }
            num = rem + 10*num;
          x = x/10;
       }
       }
       else{
          while(x < 0) {
            rem = x % 10;
            if(num < INT_MIN/10 || (num == INT_MIN/10 && rem < -8)){
                return 0;
            }
            num = rem + 10*num;
            x = x/10;
       }
       }
       return num;
    }
};