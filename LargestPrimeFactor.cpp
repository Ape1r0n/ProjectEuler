#include <iostream>

int main(){
	unsigned long long n;
	n = 600851475143;
	for(unsigned long long i = 2;	i*i<=n; i++){
		while(n%i==0 && n!=i) n/=i;
	}
	std::cout << n << '\n';
    return 0;
}
