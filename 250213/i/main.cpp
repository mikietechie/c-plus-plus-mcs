#include <iostream>
#include <random>
#include <chrono>

int main() {
    int number_limit;
    int validation_flag = 0;
    std::cin >> number_limit;

    unsigned time_seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 random_engine(time_seed);
    std::uniform_int_distribution<int> distribution(1, 2 * number_limit);

    const int max_attempts = 100;
    for (int attempt = 0; attempt < max_attempts; attempt++) {
        int random_value = distribution(random_engine);
        std::cout << random_value << std::endl;
        
        char user_response;
        std::cin >> user_response;
        
        if (user_response == 'a') {
            validation_flag = 1;
            break;
        }
    }

    return 0;
}