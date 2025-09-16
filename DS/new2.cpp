#include <iostream>
using namespace std;

int main() {
    int x;
    
    // 輸入學生人數
    cout << "請輸入學生人數: ";
    cin >> x;
    cin.ignore(); // 清除輸入緩衝區
    
    // 先讀取所有姓名來找出最長長度
    char** tempNames = new char*[x];
    int maxLength = 0;
    
    cout << "\n請輸入" << x << "個學生的英文全名:\n";
    for (int i = 0; i < x; i++) {
        char buffer[1000];
        cout << "學生" << i + 1 << ": ";
        cin.getline(buffer, 1000);
        
        // 計算姓名長度
        int length = 0;
        while (buffer[length] != '\0') {
            length++;
        }
        
        // 更新最大長度
        if (length > maxLength) {
            maxLength = length;
        }
        
        // 暫時儲存姓名
        tempNames[i] = new char[length + 1];
        int j = 0;
        while (buffer[j] != '\0') {
            tempNames[i][j] = buffer[j];
            j++;
        }
        tempNames[i][j] = '\0';
    }
    
    // 根據 x 和 y 動態宣告二維字元陣列
    int y = maxLength;
    char** names = new char*[x];
    for (int i = 0; i < x; i++) {
        names[i] = new char[y + 1];
    }
    
    // 將所有姓名存入動態二維陣列
    for (int i = 0; i < x; i++) {
        int j = 0;
        while (tempNames[i][j] != '\0') {
            names[i][j] = tempNames[i][j];
            j++;
        }
        names[i][j] = '\0';
        
        // 釋放暫時記憶體
        delete[] tempNames[i];
    }
    delete[] tempNames;
    
    // 輸出時使用姓名之間的空白鍵對齊顯示
    cout << "\n對齊顯示的學生名單:\n";
    for (int i = 0; i < x; i++) {
        cout << names[i];
        
        // 計算需要補多少空白
        int currentLength = 0;
        while (names[i][currentLength] != '\0') {
            currentLength++;
        }
        
        int spacesNeeded = y - currentLength;
        for (int j = 0; j < spacesNeeded; j++) {
            cout << " ";
        }
        
        // 在姓名之間加上空格分隔（最後一個不加）
        if (i < x - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    // 釋放動態記憶體
    for (int i = 0; i < x; i++) {
        delete[] names[i];
    }
    delete[] names;
    
    return 0;
}
