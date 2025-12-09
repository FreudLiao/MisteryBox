#include <iostream>

using namespace std;

struct node {
    int coef;
    int exp;
    node* next;

    node(int c, int e) : coef(c), exp(e), next(nullptr) {} //立刻分配
};

class poly {
private:
    node* head; //防止弄丟第一個位置在哪

public:
    poly() {
        head = new node(0, -1);  //虛擬首節點
        head->next = head;
    }

    ~poly() {
        node* curr = head->next;
        while (curr != head) {
            node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete head;
    }

    void addNode(int coef, int exp) {
        if (coef == 0) return;
        node* prev = head;
        node* curr = head->next;

        while (curr != head && curr->exp > exp) {
            prev = curr;
            curr = curr->next;
        }

        if (curr != head && curr->exp == exp) {
            curr->coef += coef;
            if (curr->coef == 0) {
                prev->next = curr->next;
                delete curr;
            }
        }
        else {
            node* newNode = new node(coef, exp);
            newNode->next = curr;
            prev->next = newNode;
        }
    }

    static poly PolyMul(poly& A, poly& B) {
        poly C;
        
        node* ptrA = A.head->next;
        
        while (ptrA != A.head) {
            
            node* ptrB = B.head->next;
            
            while (ptrB != B.head) {
                int newCoef = ptrA->coef * ptrB->coef;
                int newExp = ptrA->exp + ptrB->exp;
                
                C.addNode(newCoef, newExp);
                
                ptrB = ptrB->next;
            }
            ptrA = ptrA->next;
        }
        return C;
    }

    void print() {
        node* curr = head->next;
        if (curr == head) {
            cout << "0" << endl;
            return;
        }

        bool isFirst = true;
        while (curr != head) {
            if (curr->coef > 0 && !isFirst) {
                cout << "+";
            }
            
            if (curr->exp == 0) {
                cout << curr->coef;
            } else {
                cout << curr->coef;
            }

            if (curr->exp != 0) {
                cout << "x";
                if (curr->exp != 1) {
                    cout << "^" << curr->exp;
                }
            }

            isFirst = false;
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    poly poly1, poly2;
    int m, n;
    float coef;
    int exp;

    cout << "請輸入第一多項式的node數 m : ";
    cin >> m;
    cout << "請輸入" << m << "次 coef, exp:" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> coef >> exp;
        poly1.addNode(coef, exp);
    }

    cout << "請輸入第二個多項式的node數 n : ";
    cin >> n;
    cout << "請輸入" << n << "次 coef, exp:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> coef >> exp;
        poly2.addNode(coef, exp);
    }

    poly result = poly::PolyMul(poly1, poly2);

    cout << "輸出結果: ";
    result.print();

    return 0;
}
