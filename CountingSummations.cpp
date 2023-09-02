#include <iostream>
#include <vector>


int main(int argc, char** argv) {
	std::vector<unsigned long long> v, dp(101, 0); 
	for (unsigned long long i = 1; i < 100; i++) v.push_back(i);
    dp[0] = 1;

	for (unsigned long long e : v) {
		for (unsigned long long i = e; i <= 100; i++)  
			dp[i] += dp[i - e];
	}

	std::cout << dp[dp.size()-1] << '\n';		
	return 0;
}
