//using stack to check parentheses.
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack <int> a;
        for (int i = 0 ;i < n; i ++){
            char x = s[i];
            if(x == '(' || x == '[' || x == '{'){
                a.push(x);
            }else{
                if(a.empty()){
                    return false; //前面如果都是空的那就回傳false
                }
                char b = a.top();
                if((x == ')' && a.top() == '(')
                 ||(x == ']' && a.top() == '[')
                 ||(x == '}' && a.top() == '{')){
                 a.pop();
                 }else{
                    return false;
                 }
            }
        }
        return a.empty(); // 防止一個符號出現ex. '('
    }
};
