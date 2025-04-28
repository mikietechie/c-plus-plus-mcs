#include <iostream>
#include <vector>

using namespace std;

void remove() {
    std::cout << "/* message */" << std::endl;
}

void add(vector<long long> &MY_A, long long L, long long K)
{
    if (L > MY_A.size())
    {
        MY_A.resize(L, 0);
    }
    if (MY_A[L - 1] != 0)
    {
        add(MY_A, L + 1, MY_A[L - 1]);
    }
    MY_A[L - 1] = K;
}

int main()
{

    long long N, M;
    std::cin >> N >> M;
    vector<long long> L(N);
    vector<long long> MY_A;
    for (long long i = 0; i < N; ++i)
    {
        std::cin >> L[i];
        add(MY_A, L[i], i + 1);
    }

    long long W = 0;
    for (long long i = MY_A.size() - 1; i >= 0; --i)
    {
        if (MY_A[i] != 0)
        {
            W = i + 1;
            break;
        }
    }

    std::cout << W << '\n';
    for (long long i = 0; i < W; ++i)
    {
        std::cout << (i < MY_A.size() ? MY_A[i] : 0) << ' ';
    }
    std::cout << '\n';

    return 0;
}