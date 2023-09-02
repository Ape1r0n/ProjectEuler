#include <algorithm>
#include <iostream>
#include <map>
#include <string>

bool containSameDigits(std::string a, std::string b){
	std::map<char, int> mp;
	std::sort(a.begin(),a.end());
	std::sort(b.begin(), b.end());
	for(int i=0; i<a.size(); i++) mp[a[i]]++;
	for(int i=0; i<b.size(); i++) mp[b[i]]--;
	return a == b;
}


int main(){
	int count = 1;
	for(int x=125874; x<100000000; x++){
		int x2 = 2*x, x3 = 3*x, x4 = 4*x, x5 = 5*x, x6 = 6*x;
		if(containSameDigits(std::to_string(x), std::to_string(x2))) count++;
		if(containSameDigits(std::to_string(x), std::to_string(x3))) count++;
		if(containSameDigits(std::to_string(x), std::to_string(x4))) count++;
		if(containSameDigits(std::to_string(x), std::to_string(x5))) count++;
		if(containSameDigits(std::to_string(x), std::to_string(x6))) count++;
		if(count == 6){
			std::cout << x << '\n';
			return 0;
		}
		count = 1;
	}
	return 0;
}
