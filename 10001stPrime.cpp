#include <iostream>

bool isPrime(long long n){
	for(long long i=2; i*i<=n; i++){
		if(!(n%i)) return false;
	}
	return true;
}

long long nthPrime(int n){
		long long count = 0, i=1;
		while(count != n){
			i++;
			if(isPrime(i)) count++;
		}
		return i;
}


int main(){
	int n; std::cin >> n;
	std::cout << nthPrime(n) << '\n';
    return 0;
}
