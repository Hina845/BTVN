#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum_of_primes(int n) {
    int sum = 0;
    vector<bool> res(n, 1);
    for (int i = 2; i < n; i++) {
        if (res[i] == 1) {
            sum += i;
            for (int next_num = i*2; next_num <= n; next_num += i)
                res[next_num] = 0;         
        }
    }
    return sum;
}

int main() {
    int n; cin >> n;
    cout << sum_of_primes(n);
}
