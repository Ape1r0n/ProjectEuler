#include <iostream>

int d(int n){
	int sum = 1;
	for(int i=2; i<=n/2; i++){
		if(n%i==0) sum += i;
	}
	return sum;
}

int main(){
	int sum=0;
	for(int i=2; i<10000; i++){
		int a = d(i);
		int b = d(a);
		if(i==b && i!=a) sum += i;
	}
	std::cout << sum << '\n';
    return 0;
}
