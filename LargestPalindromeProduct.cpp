#include <algorithm>
#include <iostream>
#include <vector>

bool isPalindrome(int n){
	int temp = 0, k=n;
	while(k){
		temp = temp*10 + k%10;
		k /= 10;
	}
	return n==temp;
}

int main(){
	std::vector<int> v;
	for(int i=999; i>99; i--){
		for(int j=999; j>99; j--){
			if(isPalindrome(i*j)) v.push_back(i*j);
		}
	}
	v.shrink_to_fit();
	std::cout << *std::max_element(v.begin(),v.end()) << '\n';
    return 0;
}
