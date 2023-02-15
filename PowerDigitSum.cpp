#include <iostream>
#include <string>
#include <algorithm>

int main(){
	std::string	num = "2";
	for(int i=1; i<1000; i++){
		std::string s  = "";
		int carry = 0;
		for(unsigned long long j=num.size()-1; j>=0; j--){
			unsigned long long digit = carry + 2*(num[j]-'0');
			carry = digit/10;
			s = char(digit%10+'0') + s;
		}
		if(carry) s = char(carry+'0') + s;
		num = s;
	}
	unsigned long long sum=0;
	for(unsigned long long i=0; i<num.size();i++) sum += num[i] - '0';
	std::cout << sum << '\n';
    return 0;
}
