#include <iostream>
#include <vector>

int main(){
	std::vector<unsigned int> sum(60,0);
	int hundred50DigitNumbers = 100;
    while(hundred50DigitNumbers--){
		std::string s; std::cin >> s;
		std::vector<unsigned int> v;

		for(auto i=s.rbegin(); i!=s.rend(); ++i) v.push_back(*i-'0');
		v.resize(sum.size(), 0);

		for(unsigned int i=0; i<v.size(); i++){
			sum[i] += v[i];
			if(sum[i]>=10){
				sum[i+1]++;
				sum[i] -= 10;
			}
		}
	}

	std::cout << "\nFirst 10 digits: ";
	auto i = sum.rbegin();
	while(*i==0) i++;
	int first10Digits = 10;
	while(first10Digits--) std::cout << *i++;
	std::cout << '\n';
	return 0;
}
