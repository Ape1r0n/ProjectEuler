#include <iostream>
#include <vector>
#include <algorithm>

unsigned int reciprocalCycle(unsigned int n){
	std::vector<unsigned int> v(n,0);
	unsigned int pos = 1, dividend = 1;
	for(;;){
		unsigned int r = dividend%n;
		if(r==0) return 0;
		if(v[r] != 0) return pos-v[r];
		v[r] = pos;
		pos++;
		dividend = r*10;
	}
}

int main(){
	std::vector<unsigned int> v = {0};
	unsigned int longestCycle = 0, temp = 0;
	for(unsigned int d=7; d<1000; d++){
		auto length = reciprocalCycle(d);
		if(longestCycle<length){
			longestCycle = length;
			temp = d;
		}
		v.push_back(temp);
	}
	std::cout << *std::max_element(v.begin(),v.end()) << '\n';
    return 0;
}
