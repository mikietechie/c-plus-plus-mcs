#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, string> memo;

string findMinString(const string &p1, const string &p2, int i = 0, int j = 0) {
    string key = to_string(i) + "," + to_string(j);
    if (memo.count(key)) return memo[key];

    // Базовые случаи
    if (i == p1.size() && j == p2.size()) return "";
    if (i == p1.size()) {
        if (p2[j] == '*') return findMinString(p1, p2, i, j+1);
        return "NO";
    }
    if (j == p2.size()) {
        if (p1[i] == '*') return findMinString(p1, p2, i+1, j);
        return "NO";
    }

    // Обработка текущих символов
    char c1 = p1[i], c2 = p2[j];
    string result = "NO";

    if (c1 == '*' && c2 == '*') {
        // Оба шаблона имеют '*', можем пропустить в любом
        string opt1 = findMinString(p1, p2, i+1, j);
        string opt2 = findMinString(p1, p2, i, j+1);
        if (opt1 != "NO" && (result == "NO" || opt1.size() < result.size())) result = opt1;
        if (opt2 != "NO" && (result == "NO" || opt2.size() < result.size())) result = opt2;
    }
    else if (c1 == '*') {
        // Пропускаем символ в первом шаблоне или добавляем символ из второго
        string opt1 = findMinString(p1, p2, i+1, j);
        string opt2 = findMinString(p1, p2, i, j+1);
        if (opt2 != "NO") {
            char c = (c2 == '?') ? 'a' : c2;
            opt2 = c + opt2;
            if (opt1 != "NO" && (result == "NO" || opt1.size() < opt2.size())) result = opt1;
            else if (opt2 != "NO" && (result == "NO" || opt2.size() < result.size())) result = opt2;
        }
        else if (opt1 != "NO") {
            result = opt1;
        }
    }
    else if (c2 == '*') {
        // Аналогично предыдущему случаю
        string opt1 = findMinString(p1, p2, i, j+1);
        string opt2 = findMinString(p1, p2, i+1, j);
        if (opt2 != "NO") {
            char c = (c1 == '?') ? 'a' : c1;
            opt2 = c + opt2;
            if (opt1 != "NO" && (result == "NO" || opt1.size() < opt2.size())) result = opt1;
            else if (opt2 != "NO" && (result == "NO" || opt2.size() < result.size())) result = opt2;
        }
        else if (opt1 != "NO") {
            result = opt1;
        }
    }
    else {
        // Обычные символы или '?'
        char c;
        if (c1 == '?' && c2 == '?') c = 'a';
        else if (c1 == '?') c = c2;
        else if (c2 == '?') c = c1;
        else if (c1 == c2) c = c1;
        else return "NO";

        string rest = findMinString(p1, p2, i+1, j+1);
        if (rest != "NO") result = c + rest;
    }

    memo[key] = result;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    cin.ignore(); // Пропустить перевод строки после числа тестов

    while (T--) {
        memo.clear();
        string p1, p2;
        getline(cin, p1);
        getline(cin, p2);

        string result = findMinString(p1, p2);
        if (result == "NO") {
            cout << "NO\n";
        } else {
            cout << result << "\n";
        }
    }

    return 0;
}