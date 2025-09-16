 #include <iostream>
using namespace std;

int main() {
    int n, m;
    
    // 輸入學生人數和姓名長度
    cout << "請輸入學生人數: ";
    cin >> n;
    cout << "請輸入姓名最大長度: ";
    cin >> m;
    cin.ignore(); // 清除輸入緩衝區
    
    // 使用malloc建立二維動態陣列
    char** names = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        names[i] = (char*)malloc((m + 1) * sizeof(char));
    }
    
    // 輸入學生姓名
    cout << "\n請輸入" << n << "個學生姓名:\n";
    for (int i = 0; i < n; i++) {
        cout << "學生" << i + 1 << ": ";
        
        // 直接讀取到動態陣列中
        cin.getline(names[i], m + 1);
        
        // 如果輸入超過長度，清除緩衝區
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    
    // Bubble sort 根據最後一個字元的ASCII碼
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // 取得字串長度
            int len1 = 0, len2 = 0;
            while (names[j][len1] != '\0') len1++;
            while (names[j + 1][len2] != '\0') len2++;
            
            // 取得最後一個字元
            char last_char1 = names[j][len1 - 1];
            char last_char2 = names[j + 1][len2 - 1];
            
            if (last_char1 > last_char2) {
                // 交換指標
                char* temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }
    
    // 印出排序後的結果
    cout << "\n排序後的學生名單:\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ": " << names[i] << endl;
    }
    
    // 釋放動態記憶體
    for (int i = 0; i < n; i++) {
        free(names[i]);
    }
    free(names);
    
    return 0;
}
