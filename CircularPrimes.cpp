#include <iostream>
#include <algorithm>

bool isPrime(int n){
	for(int i=2; i*i<=n; i++){
		if(n%i==0) return false;
	}
	return true;
}

bool isCircularPrime(int n){
    std::string s = std::to_string(n);
    for(int i=0; i<s.length(); i++){
        std::rotate(s.begin(), s.begin()+1, s.end());
        if(!isPrime(std::stoi(s))) return false;
    }
    return true;
}

int main(){
	int ans=13;
	for(int i=100; i<1000000; i++){
		if(isCircularPrime(i)) ans++;
	}
	std::cout << ans << '\n';
    return 0;
}
