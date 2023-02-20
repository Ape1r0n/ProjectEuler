#include <iostream>
#include <algorithm>
#include <string>

bool isPrime(int n){
    for(int i=2; i*i<=n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

std::string shorten(std::string& s){
	std::string res = "";
	for(int i=0; i<s.size()-1; i++) res += s[i];
	return res;
}

int main() {
    std::string s = "987654321", a = s;
	std::sort(a.begin(), a.end());
	int ans = 0, iteration = 1;
    do{
        int n = std::stoi(s);
        if(isPrime(n) && n > ans) ans = n;
		if(s == a){
			s = shorten(s);
			a = shorten(a);
		}
		std::prev_permutation(s.begin(), s.end());
    }while(ans == 0);
    std::cout << ans << '\n';
    return 0;
}
