#include <iostream>  //according to leetcode Q9.
#include <vector>
using namespace std;
//boolean fuc. can't write in main fuc.
//using two vector to exchage every int to opposite site.
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        vector<int> a;
        int temp = x;   //create a variable in stead of using true value.
        while (temp > 0){
            a.push_back(temp % 10);
            temp /= 10;
        }
        vector<int> b;
        for(int i = a.size() - 1; i >= 0; i --){
            b.push_back(a[i]);
        }
        if(a == b){
            return 1;
        }else {
            return 0;
        }
    }

int main()
{
    int x;
    cin >> x;
    if(isPalindrome(x)){
        cout << "Is palindrome.";
    }else {
        cout << "Is not palindrome.";
    }
    return 0;
}
