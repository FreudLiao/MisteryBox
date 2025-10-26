#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isSymm (string s)
{
    stack<char> myStack;
    
    for (char c : s)
    {
        if(c == '(' || c == '[' || c == '{')
        {
            myStack.push(c);
        }
        else if(c == ')' || c == ']' || c == '}')
        {
            
            if(myStack.empty()){
                return false;
            }
        
        char topStack = myStack.top();
        if (c == ')' && topStack == '(' ||
            c == ']' && topStack == '[' ||
            c == '}' && topStack == '{')
        {
            myStack.pop();
        }
        else {
        return false;
            } 
        }
    }
    return myStack.empty(); 
}
int main(){
    string str1 = "{[()]}";
    string str2 = "[{(]}]";
    string str3 = ")([{}]";
    
    cout << str1 << "is " << (isSymm(str1) ? "Valid" : "InValid") << endl;
    cout << str2 << "is " << (isSymm(str2) ? "Valid" : "InValid") << endl;
    cout << str3 << "is " << (isSymm(str3) ? "Valid" : "InValid") << endl;

    return 0;
}
