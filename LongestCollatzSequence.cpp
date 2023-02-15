#include <iostream>

int main(){
		long long count=0,ans=27;
		for(long long i=27; i<1000000; i++){
			long long temp=0, n=i;
			while(n != 1){
				if(n%2) n = 3*n + 1;
				else n /= 2;
				temp++;
			}
			if(temp>count){
				count=temp;
				ans = i;
			}
			std::cout << i << " -> " << temp << '\n';
		}
		std::cout << ans << '\n'; 
        return 0;
}
