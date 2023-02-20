#include <iostream>
#include <algorithm>

bool isPalindromeBase10(int n){
	int N = n, rn = 0;
	while(N){
		rn = 10*rn + N%10;
		N /= 10;
	}
	return rn == n;
}

bool isPalindromeBase2(int n){
	int N = n, rn = 0;
	while(N){
		rn = (rn << 1) | (N&1);
		N >>= 1;
	}
	return rn == n;
}

int main(){
	int ans = 0;
	for(int i=0; i<1000000; i++){
		if(isPalindromeBase10(i) && isPalindromeBase2(i)) ans += i;
	}
	std::cout << ans << '\n';
    return 0;
}
