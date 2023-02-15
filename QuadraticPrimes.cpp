#include <iostream>

bool isPrime(int n){
	if(n<=1) return false;
	for(int i=2; i*i<=n; i++){
		if(n%i==0) return false;
	}
	return true;
}

int main(){
	int product=0, maxPrime = 2;;
	for(int a= -1000; a<1001; a++){
		for(int b= -1000; b<1001; b++){
			int n=0;
			while(isPrime(n*n + a*n + b)) n++;
			if(n > maxPrime){
				product = a*b;
				maxPrime = n;
			}
		}
	}
	std::cout << product << '\n';
    return 0;
}
