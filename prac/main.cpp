#include <iostream>

using namespace std;

class Prac {
private:
    int a;
public :
    void setA(int b) {
        a = b;
    }

    int getA() {
        return a;
    }

};

int main() {
    Prac prac;
    prac.setA(5);
    cout << prac.getA();

}
