#include <iostream>
#include <set>
using namespace std;


int main()
{
    set<int> my_set{2,1,-3};
    auto it = my_set.begin();
    // --it; // Reverses the iterator
    return 0;
}

