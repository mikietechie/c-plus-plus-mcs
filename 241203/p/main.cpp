#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Структура для хранения позиции и направления
struct State
{
    int x, y;
    int dir; // 0-5, начиная с направления вправо и по часовой стрелке
    bool operator==(const State &other) const
    {
        return x == other.x && y == other.y && dir == other.dir;
    }
};

// Хеш-функция для State
namespace std
{
    template <>
    struct hash<State>
    {
        size_t operator()(const State &s) const
        {
            return hash<int>()(s.x) ^ hash<int>()(s.y) ^ hash<int>()(s.dir);
        }
    };
}

// Направления в шестиугольной сетке (шесть возможных направлений)
const int dx[] = {1, 0, -1, -1, 0, 1};
const int dy[] = {0, 1, 1, 0, -1, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string commands;
    cin >> n >> commands;

    // Моделируем движение вертолета
    State heli{0, 0, 0}; // Начинаем в (0,0), смотрим вправо
    unordered_map<int, unordered_map<int, bool>> walls;

    for (char cmd : commands)
    {
        switch (cmd)
        {
        case 'E':
            heli.x += dx[heli.dir];
            heli.y += dy[heli.dir];
            break;
        case 'L':
            heli.dir = (heli.dir + 5) % 6; // Поворот налево (60°)
            break;
        case 'R':
            heli.dir = (heli.dir + 1) % 6; // Поворот направо (60°)
            break;
        case 'M':
            walls[heli.x][heli.y] = true;
            break;
        }
    }

    State target = heli;  // Конечная позиция вертолета
    State start{0, 0, 0}; // Начальная позиция вездехода

    // BFS для поиска кратчайшего пути
    queue<State> q;
    unordered_map<State, pair<State, char>> parent;
    q.push(start);
    parent[start] = {start, '\0'};

    bool found = false;
    while (!q.empty() && !found)
    {
        State current = q.front();
        q.pop();

        // Проверяем, достигли ли цели
        if (current.x == target.x && current.y == target.y)
        {
            found = true;
            break;
        }

        // Генерируем возможные действия
        // 1. Поворот налево
        State left = current;
        left.dir = (left.dir + 5) % 6;
        if (parent.find(left) == parent.end())
        {
            parent[left] = {current, 'L'};
            q.push(left);
        }

        // 2. Поворот направо
        State right = current;
        right.dir = (right.dir + 1) % 6;
        if (parent.find(right) == parent.end())
        {
            parent[right] = {current, 'R'};
            q.push(right);
        }

        // 3. Движение вперед
        State forward = current;
        forward.x += dx[forward.dir];
        forward.y += dy[forward.dir];
        if (!walls[forward.x][forward.y] && parent.find(forward) == parent.end())
        {
            parent[forward] = {current, 'E'};
            q.push(forward);
        }
    }

    // Восстанавливаем путь
    vector<char> path;
    State current = target;
    while (!(current == start))
    {
        auto [prev, cmd] = parent[current];
        path.push_back(cmd);
        current = prev;
    }
    reverse(path.begin(), path.end());

    // Выводим результат
    cout << path.size() << '\n';
    for (char cmd : path)
    {
        cout << cmd;
    }
    cout << '\n';

    return 0;
}