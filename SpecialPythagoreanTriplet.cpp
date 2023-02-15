#include <iostream>
#include <cmath>

int main(){
	for(int i=20; i<500; i++){
		for(int j=i+1; j<i+500; j++){
			int k = std::sqrt(i*i + j*j);
			if(i+j+k==1000 && i*i + j*j == k*k) std::cout << i << '*' << j << '*' << k << '=' << i*j*k << '\n';
		}
	}
    return 0;
}
