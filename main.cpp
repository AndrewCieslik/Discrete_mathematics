#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string getFactors(unsigned int number);
bool isPrime(int n);
int getPrimaryNumbers(unsigned int number);

int main() {
    cout << getFactors(72) << endl;
    cout << getFactors(5) << endl;
    cout << getFactors(100) << endl;
    int number = 72;
    cout << "Number of prime numbers: " << number << " is: " << getPrimaryNumbers(number) << endl;

    return 0;
}

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

string getFactors(unsigned int number) {
    string factors = "";
    int divisor = 2;
    while (number > 1) {
        if (isPrime(divisor)) {
            int count = 0;
            while (number % divisor == 0) {
                count++;
                number /= divisor;
            }
            factors += to_string(divisor);
            if (count > 1) {
                factors += "^" + to_string(count);
            }
            factors += "*";
        }
        divisor++;
    }
    if (factors.size() > 0) {
        factors.pop_back();
    }
    return factors;
}

int getPrimaryNumbers(unsigned int number) {
    int count = 0;
    for (int i = 2; i <= number; i++) {
        if (isPrime(i)) {
            count++;
        }
    }
    return count;
}
