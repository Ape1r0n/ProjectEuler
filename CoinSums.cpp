#include <iostream>

int main(){
    int p1=1, p2=2, p5=5, p10=10, p20=20, p50=50, p100=100;
    long long ans=1, counter=1; // 1 for just 2 pounds
    for(int i1=0; i1<=200; i1++){
        for(int i2=0; i2<=100; i2++){
            for(int i3=0; i3<=40; i3++){
                for(int i4=0; i4<=20; i4++){
                    for(int i5=0; i5<=10; i5++){
                        for(int i6=0; i6<=4; i6++){
                            for(int i7=0; i7<=2; i7++){
                                int count = i1 + p2*i2 + p5*i3 + p10*i4 + p20*i5 + p50*i6 + p100*i7;
                                if(count == 200){
									ans++; 
                                    std::cout << "-------------\n";
                                    std::cout << counter++ << ":\n" << count << " | " << i1 << ' '  << i2 << ' ' << i3 << ' ' << i4 << ' '  << i5 << ' ' << i6 << ' ' << i7 << ' ' << '\n';}
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << "The answer is " << ans << '\n';
    return 0;
}

