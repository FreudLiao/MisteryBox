#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;


int main() {
    int n;
    cin  >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    //reverse
    int b[n];
    for(int i = n-1; i >= 0; i--){
        b[i]=arr[n-i-1];
    }
    for(int i = 0; i < n; i++){
        cout << b[i] << " ";
    }
    return 0;
}
