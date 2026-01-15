#include <iostream>
using namespace std;
    //using divide to check the begging equal the end or not. 
    bool isPalindrome(int x){
        if (x < 0 || x % 10 == 0){
            return 0;// negative or hundred. 
        }
        int temp = x, rev = 0;
        while(temp > rev){
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        return temp == rev || temp == rev / 10;
}

int main(){
    int x;
    cin >> x;
    if(isPalindrome(x)){
        cout << "Is palindrome.";
    }else {
        cout << "Is not palindrome.";
    }
    return 0;
}
