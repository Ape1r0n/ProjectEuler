#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

std::vector<int> primes = {2};
std::set<std::string> searched;

std::string createPlaceholder(std::string s, int index){
    s[index] = '*';
    return s;
}

void genWildcardStrings(std::string s, int index, std::vector<std::string>& wildcards){
    if(index > 0 && searched.find(s) == searched.end()){
        wildcards.push_back(s);
        searched.insert(s);
    }
    for(int x=index; x<s.length(); x++) genWildcardStrings(createPlaceholder(s, x), x+1, wildcards);
}

bool isPrime(int n){
	for(int i=2; i*i<=n; i++)
		if(n%i==0) return false;
	return true;
}

int countPrimes(std::string wildcard){
    int count = 0;
    for(int i=0; i<=9; i++){
        std::string num = wildcard;
        std::replace(num.begin(), num.end(), '*', char(i+'0'));
        if(num[0] == '0') continue;
        int n = std::stoi(num);
        if(isPrime(n)) ++count;
    }
    return count;
}

int main() {
    for(int x=3; x<1000000; x++){
        bool found = false;
        for(int i=0; i<primes.size(); i++){
            if(x%primes[i] == 0){
                found = true;
                break;
            }
            if(primes[i] * primes[i] > x) break;
        }
        if(!found) primes.push_back(x);
    }
    
    for(int x=0; x<primes.size(); x++){
        std::vector<std::string> wildcards;
        std::string prime_str = std::to_string(primes[x]);
        genWildcardStrings(prime_str, 0, wildcards);
        for(int y = 1; y < wildcards.size(); ++y){
            int count = countPrimes(wildcards[y]);
            if(count >= 8){
                std::cout << primes[x] << '\n';
                return 0;
            }
        }
    }
    return 0;
}

