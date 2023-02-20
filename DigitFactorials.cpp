#include <iostream>
using namespace std;

int factorial(int n) {
	if(n<=1) return 1;
	return n*factorial(n-1);
}

int main() {
    int ans = 0;
    for(int i=10; i<100000; i++){
        int n = i, digit_sum = 0;
        while(n){
            digit_sum += factorial(n%10);
			n/=10;
		}
        if(digit_sum==i) ans += i;
    }
	std::cout << ans << '\n';
    return 0;
}

