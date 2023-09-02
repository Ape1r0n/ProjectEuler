#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define ll long long
#define ull unsigned long long
#define print(x) std::cout << x << '\n'

using std::cin, std::cout, std::string, std::vector;

bool aux(ll n) {
	for (ll i = 2; i < 21; i++) 
		if (n % i) return false;
	return true;
}

int main(int argc, char** argv) {
	for (ll i = 2520; i <= 9223372036854775807; i++) {
		if (aux(i)) {
			print(i);
			return 0;
		}
	}
    return 0;
}
