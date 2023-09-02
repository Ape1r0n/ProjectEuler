#include <iostream>

bool isPrime(int n){
    for(int i = 3; i*i<=n; i += 2)
        if(n % i == 0) return false;
    return true;
}

int main(){
    int n = 1, primes = 0, diagonals = 1;
    for(int sl = 3;; sl += 2){
        for(int i=0; i<4; i++){
            n += sl - 1;
            if(isPrime(n)) primes++;
        }
        diagonals += 4;
        if(primes * 10 < diagonals){
            std::cout << sl << '\n';
            break;
        }
    }
    return 0;
}

