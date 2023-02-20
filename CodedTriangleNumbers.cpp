#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#define ll long long

bool isTriangularWord(ll n){
	ll x = 1, y = 2;
	while(x<n) x += y++;
	return x==n;
}


ll stringToLL(std::string& s){
	ll sum = 0;
	for(ll i=0; i<s.size(); i++) sum += (int)(s[i] - '0') - 16;
	return sum + 60;
}


int main(){
    int ans = 0;
	std::string word;
	std::ifstream file("words.txt"); // Download "words.txt" from "https://projecteuler.net/project/resources/p042_words.txt"
	while(std::getline(file, word, ',')){
		if(isTriangularWord(stringToLL(word	))) ans++;
	}
	std::cout << ans << '\n';
	return 0;
}
