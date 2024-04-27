#include <iostream>
#include <vector>

using namespace std;

int numof0s(int n){
    int num5=0;
    for(int i=1;i<=n;i++){
        int tmp=i;
        while(tmp % 5==0){
            num5++;
            tmp /= 5;
        }
    }
    return num5;
}

int main() {
    int n; cin >> n;
    cout << numof0s(n);
}