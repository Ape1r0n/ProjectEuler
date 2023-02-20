#include <iostream>

int main(){
    const long long mod = 10000000000LL;
    long long sum = 0;
    for(int i=1; i<=1000; i++){
        long long power = 1;
        for(int j=1; j<=i; j++) power = (power * i) % mod;
        sum = (sum + power) % mod;
    }
    std::cout << sum << '\n';
    return 0;
}
