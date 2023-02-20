#include <iostream>
#include <cmath>

int main(){
    int ans = 1;
    std::string s = "";
    for(int i=1; i<=1000000; i++) s += std::to_string(i);
    for(int i=0; i<=6; i++) ans *= (s[std::pow(10, i) - 1] - '0');
    std::cout << ans << '\n';
    return 0;
}

