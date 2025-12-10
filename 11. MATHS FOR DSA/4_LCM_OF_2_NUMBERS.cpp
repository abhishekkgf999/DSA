/*
#LCM OF TWO NUMBERS

he least common multiple (LCM) of two numbers is the smallest positive integer that is divisible by both numbers. 
The LCM can be found using the formula:  |a * b| / GCD(a, b);

*/

#include <iostream>
using namespace std;
// Function to calculate the GCD (Greatest Common Divisor) using Euclid's algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the LCM (Least Common Multiple)
int lcm(int a, int b) {
    // Ensure that both numbers are non-zero before calculating LCM
    if (a == 0 || b == 0) {
        cout << "Error: Both numbers must be non-zero for LCM calculation." << endl;
        return 0; 
    }

    // Calculate LCM using the formula: LCM(a, b) = |a * b| / GCD(a, b)
    return (abs(a) / gcd(a, b)) * abs(b);
}

int main() {
    // Example usage
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Calculate and display the LCM
    int result = lcm(num1, num2);
    
    if (result != 0) {
        cout << "LCM of " << num1 << " and " << num2 << " is: " << result << endl;
    } else {
        cout << "Error occurred during LCM calculation." << endl;
    }

    return 0;
}
