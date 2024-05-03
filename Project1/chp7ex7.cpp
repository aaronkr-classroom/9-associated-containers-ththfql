//chp7ex7.cpp
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// 각 단어와 해당 단어가 나타나는 행 번호의 맵을 생성
map<string, vector<int>> xref(istream& in) {
    string line;
    map<string, vector<int>> ret;

    int line_number = 0;
    while (getline(in, line)) {
        ++line_number;

        // 행이 비어있는 경우 건너뛴다
        if (line.empty()) continue;

        // 한 행만 있는 경우
        if (line.find_first_of("\n") == string::npos) {
            string word;
            for (char ch : line) {
                if (isalnum(ch)) {
                    word += ch;
                }
                else if (!word.empty()) {
                    ret[word].push_back(line_number);
                    word.clear();
                }
            }
            if (!word.empty()) {
                ret[word].push_back(line_number);
            }
        }
        // 여러 행이 있는 경우
        else {
            string lines = line;
            string word;
            for (char ch : lines) {
                if (isalnum(ch)) {
                    word += ch;
                }
                else if (!word.empty()) {
                    ret[word].push_back(line_number);
                    word.clear();
                }
            }
            if (!word.empty()) {
                ret[word].push_back(line_number);
            }
        }
    }
    return ret;
}

int main() {
    map<string, vector<int>> result = xref(cin);

    // 출력
    for (const auto& pair : result) {
        cout << pair.first << " occurs on line(s): ";
        for (int line : pair.second) {
            cout << line << " ";
        }
        cout << endl;
    }

    return 0;
}