#include <iostream>
#include <vector>

bool isCurious(int numerator, int denominator) {
    int n1 = numerator / 10;
    int n2 = numerator % 10;
    int d1 = denominator / 10;
    int d2 = denominator % 10;
    if(n2==0 && d2==0) return false;
    if(n1==d1 && (n2*denominator)==(d2*numerator)) return true;
    if(n1==d2 && (n2*denominator)==(d1*numerator)) return true;
    if(n2==d1 && (n1*denominator)==(d2*numerator)) return true;
    if(n2==d2 && (n1*denominator)==(d1*numerator)) return true;
    return false;
}

int main() {
    std::vector<std::pair<int, int>> curiousFractions;
    for(int i = 10; i<99; i++){
        for(int k=i+1; k< 100; k++){
            if(isCurious(i,k)) curiousFractions.push_back(std::make_pair(i,k));
        }
    }

    int productNumerator = 1, ans = 1;
    for(auto fraction : curiousFractions){
        productNumerator *= fraction.first;
        ans *= fraction.second;
    }

    for(int i=2; i<=ans; i++){
        while(productNumerator%i==0 && ans%i==0){
            productNumerator /= i;
            ans /= i;
        }
    }

    std::cout << ans << '\n';
    return 0;	
}

