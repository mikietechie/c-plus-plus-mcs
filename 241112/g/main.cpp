#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

mt19937 rnd(42);

struct Node {
    int val, prior;
    long long sum;
    int size;
    bool rev;
    Node *l, *r;
    
    Node(int v) : val(v), prior(rnd()), sum(v), size(1), rev(false), l(nullptr), r(nullptr) {}
};

int get_size(Node* t) {
    return t ? t->size : 0;
}

long long get_sum(Node* t) {
    return t ? t->sum : 0;
}

void update(Node* t) {
    if (t) {
        t->size = 1 + get_size(t->l) + get_size(t->r);
        t->sum = t->val + get_sum(t->l) + get_sum(t->r);
    }
}

void push(Node* t) {
    if (t && t->rev) {
        t->rev = false;
        swap(t->l, t->r);
        if (t->l) t->l->rev ^= true;
        if (t->r) t->r->rev ^= true;
    }
}

void split(Node* t, int key, Node*& l, Node*& r, int add = 0) {
    if (!t) {
        l = r = nullptr;
        return;
    }
    push(t);
    int cur_key = add + get_size(t->l);
    if (key <= cur_key) {
        split(t->l, key, l, t->l, add);
        r = t;
    } else {
        split(t->r, key, t->r, r, add + 1 + get_size(t->l));
        l = t;
    }
    update(t);
}

Node* merge(Node* l, Node* r) {
    push(l);
    push(r);
    if (!l || !r) return l ? l : r;
    if (l->prior > r->prior) {
        l->r = merge(l->r, r);
        update(l);
        return l;
    } else {
        r->l = merge(l, r->l);
        update(r);
        return r;
    }
}

void reverse(Node*& t, int l, int r) {
    Node *t1, *t2, *t3;
    split(t, l-1, t1, t2);
    split(t2, r-l+1, t2, t3);
    t2->rev ^= true;
    t = merge(t1, merge(t2, t3));
}

long long query_sum(Node*& t, int l, int r) {
    Node *t1, *t2, *t3;
    split(t, l-1, t1, t2);
    split(t2, r-l+1, t2, t3);
    long long res = t2->sum;
    t = merge(t1, merge(t2, t3));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        root = merge(root, new Node(x));
    }
    
    while (m--) {
        int q, l, r;
        cin >> q >> l >> r;
        if (q == 0) {
            cout << query_sum(root, l, r) << '\n';
        } else {
            reverse(root, l, r);
        }
    }
    
    return 0;
}