#include <iostream>

int main(){
    int count = 0;
    for(int n=1; n<=100; n++){
        for(int r=0; r<=n; r++){
            double nCr = 1.0;
            for(int i=1; i<=r; i++) nCr *= (double)(n - i + 1) / (double)i;
            if(nCr > 1000000) count++;
        }
    }
    std::cout << count << '\n';
    return 0;
}

