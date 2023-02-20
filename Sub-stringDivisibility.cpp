#include <algorithm>
#include <iostream>
#include <string>

bool isSubStringDivisible(std::string& s){
    if(std::stoi(s.substr(1, 3)) % 2 != 0) return false;
    if(std::stoi(s.substr(2, 3)) % 3 != 0) return false;
    if(std::stoi(s.substr(3, 3)) % 5 != 0) return false;
    if(std::stoi(s.substr(4, 3)) % 7 != 0) return false;
    if(std::stoi(s.substr(5, 3)) % 11 != 0) return false;
    if(std::stoi(s.substr(6, 3)) % 13 != 0) return false;
    if(std::stoi(s.substr(7, 3)) % 17 != 0) return false;
    return true;
}

long long pandigitalSubStringDivisibleSum(){
    long long ans = 0;
    std::string digits = "0123456789";
    do{
        if(isSubStringDivisible(digits)) ans += std::stoll(digits);
    }while(std::next_permutation(digits.begin(), digits.end()));
    return ans;
}

int main(){
	long long ans = 0;
	std::string digits = "0123456789";
	do{
        if(isSubStringDivisible(digits)) ans += std::stoll(digits);
    }while(std::next_permutation(digits.begin(), digits.end()));
    std::cout << ans << '\n';
    return 0;
}

