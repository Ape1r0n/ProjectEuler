#include <iostream>
#define ll long long

ll gcd(ll a, ll b){
	return b ? gcd(b, a%b) : a;
}

int main(){
	ll lcm = 1;
	for(int i=1; i<21; i++){
		lcm = (i*lcm)/gcd(i,lcm);
	}
	std::cout << lcm << '\n';
    return 0;
}
