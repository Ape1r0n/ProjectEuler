#include <cmath>
#include <iostream>

#define ll long long

ll Pi(int i){
    return ((i*(3*i-1)) >> 1);
}

bool isPentagonal(ll n){
    ll x = 1, y = 2;
    while(x<n){
        x = ((y*(3*y-1)) >> 1);
        y++;
    }
    return x == n;
}

int main(){
	ll D = INT64_MAX;
    for(ll j=1; j<=10000; j++){
        ll Pj = Pi(j);
        for(ll k=j+1; k<10000;k++){
            ll Pk = Pi(k);
            if(Pk - Pj >= D) break;
            if(isPentagonal(Pj + Pk) && isPentagonal(Pk - Pj)){
                ll diff = Pk - Pj;
                if(diff<D) D = diff;
            }
        }
    }
    std::cout << D << '\n';
    return 0;
}

