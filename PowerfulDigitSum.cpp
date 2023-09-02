#include <algorithm>
#include <cstring>
#include <iostream>

int digitSum(char* str){
    int sum = 0;
    for(int i = 0; i < strlen(str); ++i) sum += str[i] - '0';
    return sum;
}

int main() {
    int maxDigitSum = 0;
    for(int a=1; a<100; a++){
        char result[201] = {'1', '\0'};
        for(int b=1; b<100; b++){
            char temp[201] = {'\0'};
            int carry = 0;
            for(int i=strlen(result)-1, j=0; i>=0; i--, j++){
                int product = (result[i] - '0') * a + carry;
                carry = product / 10;
                temp[j] = product % 10 + '0';
            }
            while(carry){
                temp[strlen(temp)] = carry % 10 + '0';
                carry /= 10;
            }
            std::reverse(temp, temp + strlen(temp));
            if(digitSum(temp) > maxDigitSum) maxDigitSum = digitSum(temp);
            std::strcpy(result, temp);
        }
    }
    std::cout << maxDigitSum << '\n';
    return 0;
}

