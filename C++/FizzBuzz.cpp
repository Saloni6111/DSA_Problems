#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> fizzBuzz(int n) {
    vector<string> result;

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            result.push_back("FizzBuzz");
        } else if (i % 3 == 0) {
            result.push_back("Fizz");
        } else if (i % 5 == 0) {
            result.push_back("Buzz");
        } else {
            result.push_back(to_string(i));
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<string> output = fizzBuzz(n);

    for (const string& s : output) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
