#include <iostream>
#include <vector>
#include <algorithm>

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

string find_num(int product) {
    string res;
    vector<bool> primes = seive(product); 
    if (primes[product]) return "-1";
    vector<int> nums;
    for (int i = 2; i < 10; i++) {
        while (primes[i] && product % i == 0) {
            nums.push_back(i);
            product /= i;
        }
    }
    if (product > 1) return "-1";
    int inx = nums.size()-2;
    int tmp = nums.back();
    while (inx >= 0) {
        if (tmp * nums[inx] < 10) tmp *= nums[inx];
        else {
            res.push_back('0' + tmp);
            tmp = nums[inx];
        }
        inx --;
    }
    res.push_back('0' + tmp);
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int n; cin >> n;
    cout << find_num(n);
}