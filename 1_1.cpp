#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<bool> seive(int n) {
    vector<bool> res(n, 1);
    res[0] = 0; res[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (res[i] == 1) {
            for (int next_num = i*2; next_num <= n; next_num += i)
                res[next_num] = 0;         
        }
    }
    return res;
} 

int main() {
    int a, b; cin >> a >> b;
    vector<bool> primes = seive(min(a, b));
    int res = -1;
    for (int i = 2; i < primes.size(); i++) if (primes[i] && a % i == 0 && b % i == 0) {
        res = i;
    }
    cout << res;
}