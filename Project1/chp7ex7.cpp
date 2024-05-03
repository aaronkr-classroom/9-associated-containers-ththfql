//chp7ex7.cpp
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// �� �ܾ�� �ش� �ܾ ��Ÿ���� �� ��ȣ�� ���� ����
map<string, vector<int>> xref(istream& in) {
    string line;
    map<string, vector<int>> ret;

    int line_number = 0;
    while (getline(in, line)) {
        ++line_number;

        // ���� ����ִ� ��� �ǳʶڴ�
        if (line.empty()) continue;

        // �� �ุ �ִ� ���
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
        // ���� ���� �ִ� ���
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

    // ���
    for (const auto& pair : result) {
        cout << pair.first << " occurs on line(s): ";
        for (int line : pair.second) {
            cout << line << " ";
        }
        cout << endl;
    }

    return 0;
}