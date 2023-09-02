#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#define ll long long
#define ull unsigned long long
#define print(x) std::cout << x << '\n'

using std::cin, std::cout, std::string, std::vector;

template<typename T>
void printVector(vector<T>& v) {
    if (v.size() == 1) cout << v[0];
    for (int i = 0; i < v.size()-1; i++) cout << v[i] << ", ";
    if (v.size() > 1) cout << v[v.size()-1];
    cout << '\n';
}

ull gcd(ull a, ull b) {
	return b ? gcd(b, a%b) : a;
}

int main(int argc, char** argv) {
    ull maxLength = 5*1000*1000;
	vector<ull> v(maxLength, 0);

	for (ull m = 2; m < std::sqrt(maxLength); m++) {
		for (ull n = 1; n < m; n++) {
			if((m+n) % 2 != 1) continue;
			if(gcd(m,n) != 1) continue;
			ull a = m*m - n*n, b = 2*m*n, c = m*m + n*n, sum = (2 * (m * (n+m))), k = 1;
			while (k*sum <= maxLength) v[sum*(k++)]++;
		}
	}

	vector<ull> res;
	for (ull i = 0; i < v.size(); i++)
		if(v[i] == 1)
			res.push_back(i);

	auto pos = std::upper_bound(res.begin(), res.end(), 1500001);
	auto ans = std::distance(res.begin(), pos);
	print(ans);
	return 0;
}
