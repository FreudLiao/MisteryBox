#include <iostream>
#include <stdexcept>
using namespace std;

class CppArray {
private:
    float* array;
    int size;

public:
    // (a) constructor
    CppArray(int size = 5, float initvalue = 0.0f) {
        this->size = size;
        array = new float[size];
        for (int i = 0; i < size; i++)
            array[i] = initvalue;
    }

    // (b) copy constructor
    CppArray(const CppArray& cp2) {
        size = cp2.size;
        array = new float[size];
        for (int i = 0; i < size; i++)
            array[i] = cp2.array[i];
    }

    // (d) destructor
    ~CppArray() {
        delete[] array;
    }

    // (f) getSize
    int getSize() const { return size; }

    // (e) operator[]
    float& operator[](int index) {
        if (index < 0 || index >= size)
            throw out_of_range("out of range error");
        return array[index];
    }

    // (c) deep assignment operator
    CppArray& operator=(const CppArray& cp2) {
        if (this == &cp2) return *this;
        delete[] array;
        size = cp2.size;
        array = new float[size];
        for (int i = 0; i < size; i++)
            array[i] = cp2.array[i];
        return *this;
    }

    // (g) friend functions
    friend ostream& operator<<(ostream& out, const CppArray& arr) {
        out << "{";
        for (int i = 0; i < arr.size; i++) {
            out << arr.array[i];
            if (i != arr.size - 1)
                out << ", ";
        }
        out << "}";
        return out;
    }

    friend istream& operator>>(istream& in, CppArray& arr) {
        for (int i = 0; i < arr.size; i++) {
            in >> arr.array[i];
        }
        return in;
    }
};

int main() {
    CppArray arr1;
    CppArray arr2(3, 1.5f);

    cout << "arr1: " << arr1 << endl;
    cout << "arr2: " << arr2 << endl;

    arr1[0] = 10;
    arr1[1] = 20;

    cout << "after change arr1: " << arr1 << endl;
    CppArray arr3 = arr1; // copy constructor
    cout << "arr3(copy of arr1): " << arr3 << endl;

    // 指定運算子
    arr3 = arr2;
    cout << "after assign, arr3 = " << arr3 << endl;

    // 測試例外
    try {
        cout << arr1[10] << endl; // 超出範圍
    } catch (out_of_range& e) {
        cout << "例外發生：" << e.what() << endl;
    }
    CppArray arr4(3);
    cin >> arr4;
    cout << arr4.getSize();
    

    return 0;
}
