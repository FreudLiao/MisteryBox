#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;

            // 計算 <= mid 的數字個數
            for (int i = 0; i < n; i++) {
                int j = n - 1;
                while (j >= 0 && matrix[i][j] > mid) {
                    j--;
                }
                count += (j + 1);
            }

            if (count < k) {
                low = mid + 1; // mid 太小，往右邊找
            } else {
                high = mid; // mid 可能是答案，往左逼近
            }
        }
        return low;
    }
};
