//
// Created by 유영빈 on 2023/12/05.
//
#include <iostream>
#include <fstream>
#include "FileManager.h"

using namespace std;


FileManager::FileManager(ShapeManager &sma) : sm(sma) {

}

FileManager::~FileManager() {

}

void FileManager::saveFile(string s) {
    ofstream out{s + ".txt", ios::trunc};
    if (out) {
        fShapes = sm.getShape();
        for (int i = 0; i < sm.getNShape(); ++i) {
            if (fShapes[i] != nullptr)
                fShapes[i]->saveDraw(out);
        }
        out.close();
        cout << s << ".txt 파일이 저장되었습니다." << endl;
    } else {
        cout << "파일을 저장하지 못했습니다." << endl;
    }
}

void FileManager::readFile(string s) {
    ifstream input{s + ".txt"};
    if (input) {
        string line;
        while (getline(input, line)) {
            cout << line << endl;
        }
    } else {
        cout << "파일을 읽지 못했습니다." << endl;
    }
}