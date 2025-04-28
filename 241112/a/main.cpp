#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Node {
    int x, y;
    int left = 0, right = 0, parent = 0;
    int id;
};

bool build_cartesian_tree(vector<Node>& nodes) {
    // Sort nodes by x to satisfy BST property
    sort(nodes.begin(), nodes.end(), [](const Node& a, const Node& b) {
        return a.x < b.x;
    });

    // Now build heap-like structure based on y values
    stack<Node*> st;
    for (auto& node : nodes) {
        Node* last = nullptr;
        while (!st.empty() && st.top()->y > node.y) {
            last = st.top();
            st.pop();
        }

        if (!st.empty()) {
            node.parent = st.top()->id;
            st.top()->right = node.id;
        }

        if (last) {
            node.left = last->id;
            last->parent = node.id;
        }

        st.push(&node);
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Node> nodes(n);

    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].x >> nodes[i].y;
        nodes[i].id = i + 1;
    }

    // Sort nodes by y to process in heap order
    sort(nodes.begin(), nodes.end(), [](const Node& a, const Node& b) {
        return a.y < b.y;
    });

    if (!build_cartesian_tree(nodes)) {
        cout << "NO\n";
        return 0;
    }

    // Sort back by id for output
    sort(nodes.begin(), nodes.end(), [](const Node& a, const Node& b) {
        return a.id < b.id;
    });

    cout << "YES\n";
    for (const auto& node : nodes) {
        cout << node.parent << " " << node.left << " " << node.right << "\n";
    }

    return 0;
}