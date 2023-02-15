#include <iostream>
#include <vector>


//Apparently, I had no need for this, but დამენანა ამის წასლა
std::vector<std::vector<int>> generateMatrix(int n){
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int number = 1;
    while (number <= n * n) {
        for (int j = left; j <= right; j++) matrix[top][j] = number++;
        top++;

        for (int i = top; i <= bottom; i++) matrix[i][right] = number++;
        right--;
        
		for (int j = right; j >= left; j--) matrix[bottom][j] = number++;
        bottom--;

        for (int i = bottom; i >= top; i--) matrix[i][left] = number++;
        left++;
    }
    return matrix;
}

int main(){
	long long sum = 1;
	for (long long i = 3; i <= 1001; i += 2) sum += 4 * i * i - 6 * i + 6;
	std::cout << sum << '\n';
	return 0;
}
