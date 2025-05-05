#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    vector<int> tails;       // Хранит последние элементы подпоследовательностей
    vector<int> indices;     // Индексы последних элементов
    vector<int> prev(n, -1); // Массив предшественников

    for (int i = 0; i < n; ++i) {
        // Ищем первый элемент в tails, который <= sequence[i]
        auto it = upper_bound(tails.begin(), tails.end(), sequence[i], greater<int>());
        
        if (it == tails.end()) {
            // Добавляем новый элемент в конец
            if (!indices.empty()) {
                prev[i] = indices.back();
            }
            tails.push_back(sequence[i]);
            indices.push_back(i);
        } else {
            // Заменяем найденный элемент
            int pos = it - tails.begin();
            if (pos > 0) {
                prev[i] = indices[pos - 1];
            }
            *it = sequence[i];
            indices[pos] = i;
        }
    }

    // Восстанавливаем последовательность
    vector<int> result;
    int current = indices.back();
    while (current != -1) {
        result.push_back(current + 1); // +1 для 1-based индексации
        current = prev[current];
    }
    reverse(result.begin(), result.end());

    // Выводим результат
    cout << result.size() << '\n';
    for (int idx : result) {
        cout << idx << '\n';
    }

    return 0;
}