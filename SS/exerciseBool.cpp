#include <iostream>

using namespace std;

int main()
{
    int age;
    cout << "請輸入年齡：";
    cin  >> age;
    
    bool isAdult = (age >= 18); // 創造一個可以判斷的變數

    if (isAdult) 
    {
        cout <<"Access granted." << endl;
    } 
    else 
    {
        cout << "Access denied.";
    }
    return 0;
}
