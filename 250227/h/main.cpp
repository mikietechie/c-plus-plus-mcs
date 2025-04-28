// #include <bits/stdc++.h>
// #include <iostream>
// #include <sstream>
// #include <algorithm>
// #include <vector>
// #include <cmath>
// #include <iomanip>
// #include <string>
// #include <queue>
// #include <deque>
// #include <bitset>
// #include <cassert>
// #include <istream>
// #include <numeric>
// #include <random>
// #include <complex>

// #pragma GCC optimize ("unroll-loops")

// using namespace std;

// int main()
// {
//     long long a, b, c, d, e, f, n, m;
//     ios_base::sync_with_stdio(false);
//     std::cin.tie(0);
//     cout.tie(0);
//     std::cin >> n >> a >> b >> c >> d >> e >> f >> m;
//     std::cout.precision(6);
//     std::cout << std::fixed;
//     for (long long i = 0; i < m; i++)
//     {
//         long long q;
//         std::cin >> q;
//         long long x1 = (a + b * q) ^ (c * q);
//         long long x2 = (a + b * ((n - q) % n)) ^ (c * ((n - q) % n));
//         long long x3 = (d + e * q) ^ (f * q);
//         long long x4 = (d + e * ((n - q) % n)) ^ (f * ((n - q) % n));
//         double y1 = (x1 + x2) / 2000.0l;
//         double y2 = (x3 - x4) / 2000.0l;
//         double y3 = (x3 + x4) / 2000.0l;
//         double y4 = -(x1 - x2) / 2000.0l;
//         std::cout << y1 << " " << y2 << " " << y3 << " " << y4 << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <iomanip>

using ll = long long;

using goodfloat = double;

int main() {
    // Initialize variables with meaningful names
    ll sequence_length, coeff_a, coeff_b, coeff_c;
    ll coeff_d, coeff_e, coeff_f, query_count;
    
    // Optimize I/O operations
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    // Read input parameters
    std::cin >> sequence_length >> coeff_a >> coeff_b >> coeff_c;
    std::cin >> coeff_d >> coeff_e >> coeff_f >> query_count;
    
    // Configure output formatting
    std::cout << std::fixed << std::setprecision(6);
    
    // Process each query
    for (ll query = 0; query < query_count; ++query) {
        ll input_value;
        std::cin >> input_value;
        
        // Calculate intermediate values
        ll term1 = (coeff_a + coeff_b * input_value) ^ (coeff_c * input_value);
        ll term2 = (coeff_a + coeff_b * ((sequence_length - input_value) % sequence_length)) 
                        ^ (coeff_c * ((sequence_length - input_value) % sequence_length));
        ll term3 = (coeff_d + coeff_e * input_value) ^ (coeff_f * input_value);
        ll term4 = (coeff_d + coeff_e * ((sequence_length - input_value) % sequence_length)) 
                        ^ (coeff_f * ((sequence_length - input_value) % sequence_length));
        
        // Compute final results
        goodfloat result1 = (term1 + term2) / 2000.0;
        goodfloat result2 = (term3 - term4) / 2000.0;
        goodfloat result3 = (term3 + term4) / 2000.0;
        goodfloat result4 = -(term1 - term2) / 2000.0;
        
        // Output the results
        std::cout << result1 << " " << result2 << " " 
                  << result3 << " " << result4 << "\n";
    }
    
    return 0;
}
