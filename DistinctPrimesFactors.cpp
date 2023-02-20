#include <iostream>
#include <vector>


int main(){
	int i, consecutives = 0;
	for(i=647; i<1000000; i++){
		int n = i, k=2, count = 0;
		while(n != 1){
			if(n%k==0) count++;
			while(n%k==0) n /= k;
			k++;
		}

		if(count == 4) consecutives++;
		else consecutives = 0;

		if(consecutives == 4){
			std::cout << i-3 << '\n';
			return 0;
		}
	}
    return 0;
}
