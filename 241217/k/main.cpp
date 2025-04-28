#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int _main()
{
    ll num;
    std::cin >> num;
    vector<ll> nums(num);

    for (ll &_num : nums)
    {
        std::cin >> _num;
    }

    vector<ll> ans_vector(num, 0);

    for (ll outer_index = 0; outer_index < num; outer_index++)
    {
        for (ll inner_index = nums[outer_index] - 1; inner_index >= 0; inner_index--)
        {
            if (ans_vector[outer_index + inner_index] > 0)
                break;
            ans_vector[outer_index + inner_index] = inner_index + 1;
        }
    }

    for (const ll &_num : ans_vector)
    {
        std::cout << _num << " ";
    }

    std::cout << "\n";
    return 0;
}

int main(int argc, char const *argv[])
{
    _main();
    return 0;
}
