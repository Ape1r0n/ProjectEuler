#include <iostream>
#include <vector>

#define ull unsigned long long

std::vector<ull> primes;

bool isLess(ull a, ull b, ull c, ull d) {
	return a * d < c * b;
}

ull phi(ull x) {
	ull result  = x;
	ull reduced = x;
	for (ull p : primes) {
		if (p*p > reduced)
			break;

		if (reduced % p != 0)
		continue;

		do {
			reduced /= p;
		} while (reduced % p == 0);

		result -= result / p;
	}

	if (reduced > 1)
		result -= result / reduced;

	return result;
}


int main() {
	ull numerator   = 15499, denominator = 94744, current = 1;
	for (ull i = 2; ; i++) {
		bool isPrime = true;
		
		for (ull p : primes) {
			if (p*p > i)
				break;

			if (i % p == 0) {
				isPrime = false;
				break;
			}
		}

		if (!isPrime)
			continue;

		primes.push_back(i);

		current *= i;
		if (isLess(phi(current), current - 1, numerator, denominator))
			break;
	}

	current /= primes.back();

	for (ull i = 1; ; i++) {
		ull next = current * i;
		
		if (isLess(phi(next), next - 1, numerator, denominator)) {
			std::cout << next << std::endl;
			break;
		}
	}

	return 0;
}
