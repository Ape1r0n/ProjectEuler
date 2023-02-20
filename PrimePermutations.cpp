#include <algorithm>
#include <iostream>
#include <vector>

bool isPrime(int n){
    for(int i=2; i*i<=n; i++)
        if(n%i==0) return false;
    return true;
}

bool arePermutations(int a, int b, int c){
    std::vector<int> digitsA, digitsB, digitsC;
    while(a){
        digitsA.push_back(a % 10);
        a /= 10;
    }

    while(b){
        digitsB.push_back(b % 10);
        b /= 10;
    }

    while(c){
        digitsC.push_back(c % 10);
        c /= 10;
    }

    std::sort(digitsA.begin(), digitsA.end());
    std::sort(digitsB.begin(), digitsB.end());
    std::sort(digitsC.begin(), digitsC.end());
    return digitsA == digitsB && digitsB == digitsC;
}

int main(){
    for(int i=1000; i<=3339; i++){
        if(isPrime(i) && isPrime(i + 3330) && isPrime(i + 6660) && arePermutations(i, i + 3330, i + 6660) && i != 1487){
            std::cout << i << (i + 3330) << (i + 6660) << '\n';
			break;
        }
    }
    return 0;
}

