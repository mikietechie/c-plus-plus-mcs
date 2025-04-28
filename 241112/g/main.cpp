#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int sum;
    bool lazy;
    Node() : sum(0), lazy(false) {}
};

vector<Node> segTree;
vector<int> heights;

void build(int node, int start, int end)
{
    if (start == end)
    {
        segTree[node].sum = heights[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        segTree[node].sum = segTree[2 * node].sum + segTree[2 * node + 1].sum;
    }
}

void push(int node, int start, int end)
{
    if (segTree[node].lazy)
    {
        segTree[node].lazy = false;
        if (start != end)
        {
            segTree[2 * node].lazy = !segTree[2 * node].lazy;
            segTree[2 * node + 1].lazy = !segTree[2 * node + 1].lazy;
            swap(segTree[2 * node].sum, segTree[2 * node + 1].sum);
        }
    }
}

void reverseRange(int node, int start, int end, int l, int r)
{
    push(node, start, end);
    if (start > r || end < l)
        return;
    if (start >= l && end <= r)
    {
        segTree[node].lazy = !segTree[node].lazy;
        push(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    reverseRange(2 * node, start, mid, l, r);
    reverseRange(2 * node + 1, mid + 1, end, l, r);
    segTree[node].sum = segTree[2 * node].sum + segTree[2 * node + 1].sum;
}

int querySum(int node, int start, int end, int l, int r)
{
    push(node, start, end);
    if (start > r || end < l)
        return 0;
    if (start >= l && end <= r)
        return segTree[node].sum;
    int mid = (start + end) / 2;
    return querySum(2 * node, start, mid, l, r) + querySum(2 * node + 1, mid + 1, end, l, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    heights.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> heights[i];
    }

    segTree.resize(4 * n);
    build(1, 0, n - 1);

    for (int i = 0; i < m; ++i)
    {
        int q, l, r;
        cin >> q >> l >> r;
        --l;
        --r;
        if (q == 1)
        {
            reverseRange(1, 0, n - 1, l, r);
        }
        else
        {
            cout << querySum(1, 0, n - 1, l, r) << '\n';
        }
    }

    return 0;
}