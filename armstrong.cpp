#include <iostream>

using namespace std;

bool isArmstrong(int number) {
    if (number < 0) return false; // Armstrong numbers are non-negative

    int original = number;
    int sum = 0;
    int digits = 0;

    // Count the number of digits
    while (number > 0) {
        digits++;
        number /= 10;
    }

    // Reset number to the original value
    number = original;

    // Calculate the sum of the digits raised to the power of the total digits
    while (number > 0) {
        int digit = number % 10;
        int power = 1;

        // Calculate digit^digits manually
        for (int i = 0; i < digits; i++) {
            power *= digit;
        }

        sum += power;
        number /= 10;
    }

    // Check if the sum is equal to the original number
    return sum == original;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isArmstrong(num)) {
        cout << "True (The number is an Armstrong number)" << endl;
    } else {
        cout << "False (The number is not an Armstrong number)" << endl;
    }

    return 0;
}

