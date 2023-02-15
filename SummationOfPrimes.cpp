#include <iostream>

bool isPrime(int n){
	for(int i=2; i*i<=n; i++){
		if(n%i==0) return false;
	}
	return true;
}

int main(){
	long long sum = 0, n = 2000000;
	for(int i=2; i<n; i++){
		if(isPrime(i)) sum += i;
	}
	std::cout << sum << '\n';
    return 0;
}
