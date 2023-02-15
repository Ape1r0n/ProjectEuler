#include <iostream>
#include <vector>

bool isAbundant(int n){
	int divisorSum = 1;
	for(int i=2; i*i<=n; i++){
		if(n%i==0){
			divisorSum += i;
			if(i != n/i) divisorSum += n/i;
		}
	}
	return divisorSum>n;
}


int main(){
	std::vector<int> abundantNumbers;
	int count=0;

	for(int i=12; i<28124; i++){
		if(isAbundant(i)) abundantNumbers.push_back(i);
	}

	bool arr[28123] = {false};
	for(int i=0; i<abundantNumbers.size(); i++){
		for(int k=i; k<abundantNumbers.size(); k++){
			if(abundantNumbers[i] + abundantNumbers[k] <= 28123) arr[abundantNumbers[i]+abundantNumbers[k]] = true;
			else break;
		}
	}

	for(int i=0; i<28124; i++){
		if(!arr[i]) count += i;
	}

	std::cout << count << '\n';
    return 0;
}
