class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        long long rev;//verse
        int temp = x;
        while (temp > 0){
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        /*if (x == rev){
            return 1;
        }else {
            return 0;
        }*/
        return x == rev; //the code i skipped is the same thing i wrote this line.
    };
};
