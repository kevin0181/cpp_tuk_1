#include<iostream>

using namespace std;

void change(char &);

int main() {
    char str[]{"The quick brown fox jumps over the lazy dog"};

    for (int i = 0; i < strlen(str); ++i)
        change(str[i]);

    cout << str << '\n';
}

void change(char &str) {
    if(str == ' '){
        str = '-';
    }else{
        str = toupper(str);
    }
}