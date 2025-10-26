#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isSymm (string s)
{
    stack<char> myStack;
    /*
    用迴圈去讀取每一個輸入的值
    若不是([{，則跳到else if 一個一個比對，不用寫迴圈
    */
    for (char c : s)
    {
        //這邊的迴圈用的是複製Ｓ的內容（一次複製一個字串）
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
    
    //這邊用到的寫法是讓他比對上面自訂函式庫，若為Ｔ則左Ｆ為右
    cout << str1 << "is " << (isSymm(str1) ? "Valid" : "InValid") << endl;
    cout << str2 << "is " << (isSymm(str2) ? "Valid" : "InValid") << endl;
    cout << str3 << "is " << (isSymm(str3) ? "Valid" : "InValid") << endl;

    return 0;
}
