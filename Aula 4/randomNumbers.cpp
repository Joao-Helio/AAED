#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Initialize the random seed
    srand(time(NULL));

    // cout << "RAND_MAX = " << RAND_MAX << endl;
    // cout << "Minimum value = " << 0 << endl;

    // Generate 100000 random numbers
    const int MIN_VALUE = 0;
    const int MAX_VALUE = 100000;
    const int RANGE = MAX_VALUE - MIN_VALUE + 1;
    for (int i = 0; i < 100000; i++) {
        int num = (rand() % RANGE) + MIN_VALUE;
        //cout << num << " ";
    }

    return 0;
}
