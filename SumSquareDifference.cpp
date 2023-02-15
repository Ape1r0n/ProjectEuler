#include <iostream>

int main(){
	long long ans = 5;
	for(int i=3; i<101; i++) ans += i*i;
	std::cout << (100*(100+1)/2)*(100*(100+1)/2) - ans << '\n';
    return 0;
}
