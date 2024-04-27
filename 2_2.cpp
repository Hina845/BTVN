#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int> nums, int tmp) {
    for (int i = 0; i < nums.size(); i++) {
        if (tmp == nums[i]) return false;
    }
    return true;
}

int main() {
    int n, m; cin >> n >> m;
    int count = 0;
    vector<int> nums;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++) {
            int t; cin >> t;
            arr[i][j] = t;
        }
    }
    for (int i = 0; i < n-1; i ++) {
        for (int j = 0; j < m-1; j++) {
            int tmp = arr[i][j]*1000 + arr[i+1][j]*100 + arr[i][j+1]*10 + arr[i+1][j+1];
            if (check(nums, tmp) == true) {
                nums.push_back(tmp);
                count ++;
            }
        }
    }
    cout << count;
}