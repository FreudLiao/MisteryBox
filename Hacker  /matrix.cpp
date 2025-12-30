#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;


int main() {
    int m, n, q, val, i, j;
    //n是有幾行 q要測幾次 m那一行要丟幾個數字 val丟的值 i指標 j第幾個
    vector<vector<int>> matrix;
    cin >> n >> q;
    for(i = 0;i < n;i++){
        vector<int> row;
        cin >> m;
        for(j = 0;j < m;j++){
            cin >> val;
            row.push_back(val);
        }
        
        matrix.push_back(row);
    }
    for(q;q > 0;q--){
        cin >> i >> j;
        cout << matrix[i][j] << endl; 
    }
    return 0;
    /*
    int I1, I2;
    cin >> I1 >> I2;
    int n, m, i, j;
    cin >> n >> m;
    int arr1[n][m];
    for (int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> arr2[i];
    }
    cin >> i >> j;
    printf("%d\n%d",i, arr1[i]);
    printf("%d\n%d",j, arr2[j]);
    return 0;
    */
}
