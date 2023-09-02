#include <cmath>
#include <iostream>
#include <vector>

int arr[20000000];

long double log800800(long double a){
	return log2(a) / log2(800800);
}

long double logOfNum(long double p, long double q){
	return q*log800800(p) + p*log800800(q);
}

int main(){
	for(int i=2; i<20000000; i++){
		if(arr[i] == 1) continue;
		for(int k=2*i; k<20000000; k+=i) arr[k] = 1;
	}
	std::vector<int> v;
	for(int i=2; i<20000000; i++)
		if(arr[i] == 0) v.push_back(i);
	
	int q = v.size() - 1, ans = 0;
	for(int p=0; p<=q; p++){
		while(logOfNum(v[p], v[q]) > 800800) q--;
		if(p<q) ans += q - p;
	}
	std::cout << ans << '\n';
	return 0;
}
