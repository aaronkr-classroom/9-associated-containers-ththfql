// chp7ex8.cpp
#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include <vector>

using namespace std;

map<string, vector<int>> findUrlsInFile(const string& filename) {
    map<string, vector<int>> urlLines;
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Unable to open file." << endl;
        return urlLines;
    }

    string line;
    regex urlRegex(R"((https?://\S+)|\b(?:https?:\/\/)?(?:www\.)?[-a-zA-Z0-9@:%._\+~#=]{1,256}\.[a-zA-Z0-9()]{1,6}\b[-a-zA-Z0-9()@:%_\+.~#?&//=]*)");
    int lineNumber = 0;
    while (getline(file, line)) {
        ++lineNumber;
        smatch match;
        while (regex_search(line, match, urlRegex)) {
            string url = match[0];
            urlLines[url].push_back(lineNumber);
            line = match.suffix();
        }
    }

    file.close();
    return urlLines;
}

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    map<string, vector<int>> urlLines = findUrlsInFile(filename);

    // Ãâ·Â
    for (const auto& pair : urlLines) {
        cout << "URL: " << pair.first << " appears on line(s): ";
        for (int line : pair.second) {
            cout << line << " ";
        }
        cout << endl;
    }

    return 0;
}