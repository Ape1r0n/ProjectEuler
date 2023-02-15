#include <iostream>
#include <vector>

void multiply(std::vector<int>& num, int n){
	int carry = 0;
	for(int i = 0; i < num.size(); i++){
		int product = num[i] * n + carry;
		num[i] = product % 10;
		carry = product / 10;
	}
	while(carry){
		num.push_back(carry % 10);
		carry /= 10;
	}
}

int main(){
	int sum=0;
	std::vector<int> v;
	v.push_back(1);
	for(int i=2; i<=100; i++) multiply(v, i);
	for(int i=0; i<v.size(); i++) sum += v[i];
	std::cout << sum << '\n';
    for(auto itr = v.rbegin(); itr != v.rend(); ++itr){
		std::cout << *itr;
	}
	std::cout << '\n';
	return 0;
}
