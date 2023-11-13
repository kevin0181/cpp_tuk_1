#include <iostream>

using namespace std;

class User {
private:
    int level;
    string name;
    int size;
public:
    User() {
        cout << "생성자 생성" << endl;
    }

    User(const char *a) : size{static_cast<int>(strlen(a))} {
        cout << size;
    }

    ~User() {
        cout << "소멸자 소멸" << endl;
    }
};

int main() {
    User u{"영빈"};
}
