#include <iostream>
#include <string>
#include <algorithm>

bool isPandigital(std::string s){
    if(s.length() != 9) return false;
	std::sort(s.begin(), s.end());
    return s == "123456789";
}

int main() {
    int ans=0;
    for(int i=10000; i>=9;i--){
        std::string s = std::to_string(i) + std::to_string(i * 2);
        if(isPandigital(s)) ans = std::max(ans, std::stoi(s));
    }
    std::cout << ans << '\n';
    return 0;
}

