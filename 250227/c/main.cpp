#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <unordered_map>

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

int power_mod(int x, int n, int m) {
    int result = 1 % m;
    x %= m;
    while (n > 0) {
        if (n % 2 == 1)
            result = (result * x) % m;
        x = (x * x) % m;
        n /= 2;
    }
    return result;
}

int count_solutions(int N, int M) {
    vector<int> x_pow(M);
    for (int x = 1; x < M; ++x)
        x_pow[x] = power_mod(x, N, M);

    // Frequency count of x^N mod M
    vector<int> freq(M, 0);
    for (int x = 1; x < M; ++x)
        freq[x_pow[x]]++;

    // Count all pairs (including X > Y)
    vector<int> sum_counts = multiply(freq, freq);
    
    // Adjust for X <= Y: (total_pairs + diagonal) / 2
    int diagonal = 0;
    for (int x = 1; x < M; ++x) {
        int s = (x_pow[x] + x_pow[x]) % M;
        sum_counts[s]--;
        diagonal++;
    }
    for (int s = 0; s < sum_counts.size(); ++s)
        sum_counts[s] = sum_counts[s] / 2 + (s % M == (2 * x_pow[s/2]) % M ? 1 : 0);

    // Frequency count of z^N mod M
    vector<int> z_freq(M, 0);
    for (int z = 1; z < M; ++z)
        z_freq[x_pow[z]]++;

    // Count valid solutions
    int total = 0;
    for (int z = 1; z < M; ++z) {
        int zn = x_pow[z];
        if (zn < sum_counts.size())
            total += sum_counts[zn];
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    cout << count_solutions(N, M) << '\n';

    return 0;
}