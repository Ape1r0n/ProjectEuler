#include <cmath>
#include <iostream>
#include <vector>

bool isPrime(int n){
    for(int i=2; i*i<=n; i++)
        if(n%i==0) return false;
    return true;
}

int main(){
	std::vector<int> primes;
    for(int i=2; i<10000; i++)
        if(isPrime(i)) primes.push_back(i);
        
    for(int i=9; i<10000; i+=2){
        if(i&1 && !isPrime(i)){
            bool flag = false;
            for(int j=0; j<primes.size(); j++){
                int k = (i - primes[j]) / 2;
                if(k <= 0) break;
                if(sqrt(k) == floor(sqrt(k))){
                    flag = true;
                    break;
                }
            }
            if(!flag){
				std::cout << i << '\n';
                return 0;
            }
        }
    }
    return 0;
}
