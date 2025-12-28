#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a; // 一般數字 %d
    long b; // 較長的數字（８位數以上）%ld
    char c; // 字元字母 %c
    float d; // 有小數點的數字 %f
    double e; //很多小數點，較長的數字 %lf
    cin >> a >> b >> c >> d >> e;
    printf("%d\n%ld\n%c\n%f\n%lf", a, b, c, d, e);
    return 0;
    
}
