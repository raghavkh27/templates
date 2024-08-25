#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 1;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            int e = 0;
            while(n % i == 0) {
                n /= i;
                e++;
            }
            res *= (e + 1);
        }
    }
    if(n > 1) {
        res *= 2; // n is a prime number greater than sqrt(n)
    }
    cout << res;
    return 0;
}
