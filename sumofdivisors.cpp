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
           int sum = 0; 
           int power =1;
        do{
            sum+=power;
            power*=i;
        }while(e-->0);
        res*=sum;
        }
    }
    if(n > 1) {
        res *= (1+n); // n is a prime number greater than sqrt(n)
    }
    cout << res;
    return 0;
}
