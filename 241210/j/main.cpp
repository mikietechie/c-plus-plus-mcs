#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string order;
    cin >> order;
    getline()

    // Проверяем, является ли порядок "ijk" (стандартный алгоритм Флойда-Уоршелла)
    if (order == "k i j") {
        cout << "0 0" << endl;
        return 0;
    }

    // Для других порядков находим контрпример
    // Минимальный контрпример - граф с 3 вершинами и 2 рёбрами 1->2 и 2->3
    // При неправильном порядке циклов путь 1->3 может не обнаружиться
    cout << "3 2" << endl;
    cout << "1 2" << endl;
    cout << "2 3" << endl;

    return 0;
}