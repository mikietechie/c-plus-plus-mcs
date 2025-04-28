#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>

using namespace std;
using complex_t = complex<double>;

const double PI = acos(-1);

void fft(vector<complex_t>& a, bool invert) {
    int n = a.size();
    if (n <= 1) return;

    vector<complex_t> a0(n/2), a1(n/2);
    for (int i = 0, j = 0; i < n; i += 2, ++j) {
        a0[j] = a[i];
        a1[j] = a[i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double angle = 2 * PI / n * (invert ? -1 : 1);
    complex_t w(1), wn(cos(angle), sin(angle));

    for (int i = 0; i < n/2; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i+n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i+n/2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<complex_t> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < max(a.size(), b.size())) n <<= 1;
    n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; ++i)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; ++i)
        result[i] = round(fa[i].real());
    return result;
}

int count_duels(const string& alley) {
    int n = alley.size();
    vector<int> trees(n);
    for (int i = 0; i < n; ++i)
        trees[i] = (alley[i] == '1') ? 1 : 0;

    // Create reversed array
    vector<int> rev_trees = trees;
    reverse(rev_trees.begin(), rev_trees.end());

    // Multiply using FFT
    vector<int> product = multiply(trees, rev_trees);

    // Count valid configurations
    int count = 0;
    for (int d = 1; d < n; ++d) {
        if (product[n-1 + d] >= 1 && trees[d] == 1) {
            count += product[n-1 + d];
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string alley;
    cin >> alley;

    cout << count_duels(alley) << '\n';

    return 0;
}