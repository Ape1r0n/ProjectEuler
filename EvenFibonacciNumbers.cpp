#include <iostream>

int fib(int n){
	if(n==1) return 1;
	if(n==2) return 2;
	return fib(n-1) + fib(n-2);
}

int main(){
	long long ans = 0;
	for(int i=1; i<33; i++){
		if(fib(i)%2==0) ans += fib(i);
	}
	std::cout << ans << '\n';
    return 0;
}
