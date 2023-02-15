#include <iostream>
#include <vector>

#define ull unsigned long long
typedef std::vector<unsigned long long> FIBB;

FIBB add(const FIBB& a, const FIBB& b){
	FIBB result = b;
	ull carry = 0;

	for(ull i=0; i<result.size(); i++){
		if(i<a.size()) result[i] += a[i];
		result[i] += carry;
		
		if(result[i]>=10){
			carry = 1;
			result[i] -= 10;
		}else carry = 0;
	}

	if(carry) result.push_back(carry);
	return result;
}



int main(){
	FIBB cache = {0,1};
	cache.reserve(5000);
		
	FIBB a = {1}, b = {1};
	ull fIndex = 2;

	while(cache.size()<=5000){
		fIndex++;
		auto next = add(a,b);
		a = std::move(b);
		b = std::move(next);

		auto smth = b.size();
		auto largestKnown = cache.size()-1;

		if(largestKnown<smth) cache.push_back(fIndex);
	}

	std::cout << cache[1000] << '\n';

	return 0;
}
