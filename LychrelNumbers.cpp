#include <iostream>
#include <string>

#define ull unsigned long long

ull reversed(ull n){
	ull r = 0;
	while(n){
		r = r*10 + n%10;
		n /= 10;
	}
	return r;
}

bool isPalindrome(ull n){
	return n == reversed(n);
}

bool isLychrel(ull n){
	
	std::string s = "";
	for(ull i=0; i<50; i++){
		n += reversed(n);
		if(isPalindrome(n)) return true;
	}
	return false;
}


int main(){
	int ans = 0;
	for(int i=10; i<10000; i++)
		if(!isLychrel(i)) ans++;
	std::cout << ans << '\n';
	return 0;
}
