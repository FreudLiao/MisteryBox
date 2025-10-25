#include <iostream>
#include <string>
using namespace std;

int main()
{
    string mess1 = "Cod ing!";
    string mess2 = "Hurray!";
    string combine = mess2 + mess1; //先加二再加一
    
    cout << mess1 << mess2 << endl; 
    cout << combine << endl; //輸出兩string結合
    cout << "length1:" << mess1.length() << endl; //計算第一個長度
    cout << "length2:" << mess2.size() << endl; //計算第二個長度
    
    mess1[3] = '$'; // 像陣列一樣更改第幾個字串的大小
    cout << mess1 << endl;
}
