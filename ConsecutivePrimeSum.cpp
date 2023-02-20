#include <iostream>
#include <vector>

bool isPrime(int n){
	for(int i=2; i*i<=n; i++)
		if(n%i==0) return false;
	return true;
}

int main(){
	int a[1000001] = {0};
	std::vector<int> v;
	for(int x=2; x<1000001; x++){
		if(a[x]) continue;
		v.push_back(x);
		for(int y=2*x; y<1000001; y+=x) a[y] = 1;
	}
	int max_sum = 0, max_count = 0;
    for(int i=0; i<v.size(); i++){
        int sum = 0, count = 0;
        for(int j=i; j<v.size(); j++){
            sum += v[j];
            count++;
            if(sum >= 1000000) break;
            if(isPrime(sum) && count > max_count){
                max_sum = sum;
                max_count = count;
            }
        }
    }
    std::cout << max_sum << '\n';
	return 0;
}
