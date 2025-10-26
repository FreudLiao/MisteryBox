#include <iostream>
#include <stack>
#include <string>

using namespace std;


bool isSymm (string s) {
    
    stack<char> myStack;
    
    for (char c : s){
        switch (c){
            case '(':
                myStack.push(')');
                break;
            case '[':
                myStack.push(']');
                break;
            case '{':
                myStack.push('}');
                break;
            default :
                if(myStack.empty() || myStack.top() != c){
                    return false;
                }
            myStack.pop();
        }
    }
    return myStack.empty(); // 檢查stack必須是空的否則都是InValid
}
int main() {
    string str1 = "{[()]}";
    string str2 = "{[)]}";
    string str3 = "()";
    
    cout << str1 << "is " << (isSymm(str1) ? "Valid" : "InValid") << endl;
    cout << str2 << "is " << (isSymm(str2) ? "Valid" : "InValid") << endl;
    cout << str3 << "is " << (isSymm(str3) ? "Valid" : "InValid") << endl;

    return 0 ;
}
