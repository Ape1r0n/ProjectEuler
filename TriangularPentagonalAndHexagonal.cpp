#include <iostream>
#include <cmath>

#define ll long long

ll triangular(ll n){
    return ((n*(n+1))>>1);
}

ll pentagonal(ll n){
    return ((n*(3*n-1))>>1);
}

ll hexagonal(ll n){
    return n*(2*n-1);
}

int main() {
    ll i = 286; // The next triangle number after T285
    ll j = 166; // The next pentagonal number after P165
    ll k = 144; // The next hexagonal number after H143

    ll T, P, H;

    while(true){
        T = triangular(i);
        P = pentagonal(j);
        H = hexagonal(k);


        if (T == P && P == H) {
			std::cout << T << '\n';
            return 0;;
        }

        if(T<=P && T<=H) i++;
        else if(P<=T && P<=H) j++;
        else k++;
    }

    return 0;
}

