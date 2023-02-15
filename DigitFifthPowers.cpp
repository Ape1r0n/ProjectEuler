#include <iostream>
#define ll long long

ll binpow(ll a, ll b) {
    ll ans = 1;
	while(b){
		if(b&1) ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}

ll sum_of_powers(ll n){
    ll sum = 0;
    ll m = n;
    while(m){
        ll digit = m % 10;
        sum += binpow(digit, 5);
        m /= 10;
    }
    return sum;
}

int main() {
    ll sum = 0;
    for(ll i=10; i<1000000; i++){
        if(sum_of_powers(i) == i) sum += i;

    }
	std::cout << sum << '\n';
    return 0;
}

