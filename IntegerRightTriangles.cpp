#include <iostream>
#include <vector>
#include <cmath>

int main(){
	int ans = 0, max = 0, c, p;
	std::vector<std::pair<int,int>> vp(1001);
	for(int i=0; i<=1000; i++) vp[i] = std::make_pair(i, 0);
	for(int a=1;a<999;a++){
		for(int b=a+1; b<1000; b++){
			c = std::sqrt(a*a+b*b);
			p = a+b+c;
			if((a*a + b*b == c*c) && (p<=1000)) vp[p].second++;
		}
	}
	for(auto& e : vp){
		if(e.second > max){
			max = e.second;
			ans = e.first;
		}
	}
	std::cout << ans << '\n';
    return 0;
}
