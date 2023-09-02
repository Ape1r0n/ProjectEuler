#include <iostream>
#include <vector>
#include <cmath>

using std::floor, std::log10, std::vector;

bool is_prime(int n){
    if(n < 2) return false;
    for(int i = 2; i*i <= n; i++)
            if(n % i == 0) return false;
    return true;
}

vector<int> sieve(int n) {
    vector<bool> is_prime(n, true);
    is_prime[0] = false;
    is_prime[1] = false;
    is_prime[2] = true;
    for(int i = 3; i*i <= n; i += 2){
        int index = 2 * i;
        while(index < n){
            is_prime[index] = false;
            index += i;
        }
    }
    vector<int> primes;
    primes.push_back(2);
    for(int i = 3; i < n; i += 2){
        if(is_prime[i])
            primes.push_back(i);
	}
    return primes;
}

int bin_pow(int a, int n){
	int res = 1;
	while(n){
		if(n&1) res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

bool comb(int a, int b){
    int a_x = floor(log10(a)) + 1;
    int b_x = floor(log10(b)) + 1;
    if(is_prime(a * bin_pow(10, b_x) + b) && is_prime(b * bin_pow(10, a_x) + a))
        return true;
    return false;
}

int prime_pairs(){
    vector<int> primes = sieve(10000);
    int n = primes.size();
    for(int a = 0; a < n; a++){
        for(int b = a; b < n; b++){
            if(comb(primes[a], primes[b])){
                for(int c = b; c < n; c++){
                    if(comb(primes[a], primes[c]) && comb(primes[b], primes[c])){
                        for(int d = c; d < n; d++){
                            if(comb(primes[a], primes[d]) && comb(primes[b], primes[d]) && comb(primes[c], primes[d])){
                                for(int e = d; e < n; e++){
                                    if(comb(primes[a], primes[e]) && comb(primes[b], primes[e]) && comb(primes[c], primes[e]) && comb(primes[d], primes[e])){
                                        return primes[a] + primes[b] + primes[c] + primes[d] + primes[e];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main(){
	std::cout << prime_pairs() << '\n';
    return 0;
}

