#include <iostream>


bool isPrime(int n){
	if(n<=1) return false;
	for(int i=2; i*i<=n; i++){
		if(n%i==0) return false;
	}
	return true;
}

bool truncatableRight(int n){
	int N = n;
	while(N){
		if(!isPrime(N)) return false;
		N /= 10;
	}
	return true;
}

bool truncatableLeft(int n){
	int i, N = n;
	for(i=1; i<1000000; i*=10){
		if(N<=i) break;
	}
	i /= 10;

	while(N){
		if(!isPrime(N)) return false;
		N = N - (N-N%i);  
		i /= 10;
	}
	return true;
}


int main(){
	int ans = 0;
	for(int i=11; i<1000000; i++){
		if(truncatableLeft(i) && truncatableRight(i)){
			ans += i;
			std::cout << i << '\n';
		}
	}
	std::cout << "Answer: " << ans << '\n';
	return 0;
}
