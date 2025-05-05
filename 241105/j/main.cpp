#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct Node
{
    int min_val;
    int max_val;
};

class SegmentTree
{
private:
    vector<Node> tree;
    int size;

    Node combine(const Node &a, const Node &b)
    {
        return {min(a.min_val, b.min_val), max(a.max_val, b.max_val)};
    }

    void build(const vector<int> &arr, int node, int left, int right)
    {
        if (left == right)
        {
            tree[node] = {arr[left], arr[left]};
        }
        else
        {
            int mid = (left + right) / 2;
            build(arr, 2 * node + 1, left, mid);
            build(arr, 2 * node + 2, mid + 1, right);
            tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void update(int node, int left, int right, int pos, int value)
    {
        if (left == right)
        {
            tree[node] = {value, value};
        }
        else
        {
            int mid = (left + right) / 2;
            if (pos <= mid)
            {
                update(2 * node + 1, left, mid, pos, value);
            }
            else
            {
                update(2 * node + 2, mid + 1, right, pos, value);
            }
            tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    Node query(int node, int left, int right, int ql, int qr)
    {
        if (qr < left || ql > right)
        {
            return {INT_MAX, INT_MIN};
        }
        if (ql <= left && right <= qr)
        {
            return tree[node];
        }
        int mid = (left + right) / 2;
        Node left_node = query(2 * node + 1, left, mid, ql, qr);
        Node right_node = query(2 * node + 2, mid + 1, right, ql, qr);
        return combine(left_node, right_node);
    }

public:
    SegmentTree(const vector<int> &arr)
    {
        size = arr.size();
        tree.resize(4 * size);
        build(arr, 0, 0, size - 1);
    }

    void update(int pos, int value)
    {
        update(0, 0, size - 1, pos, value);
    }

    int get_diff(int l, int r)
    {
        Node res = query(0, 0, size - 1, l, r);
        return res.max_val - res.min_val;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 100000;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        a[i] = (i * i) % 12345 + (i * i * i) % 23456;
    }

    SegmentTree st(a);

    int k;
    cin >> k;
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        if (x > 0)
        {
            cout << st.get_diff(x, y) << '\n';
        }
        else
        {
            st.update(abs(x), y);
        }
    }

    return 0;
}