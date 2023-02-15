#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> nextPermutation(std::vector<int>& nums){
    int n = nums.size();
    int i = n - 2;
    while(i >= 0 && nums[i] >= nums[i + 1]) i--;
    if(i >= 0){
        int j = n - 1;
        while (nums[j] <= nums[i]) j--;
		std::swap(nums[i], nums[j]);
    }
	std::reverse(nums.begin() + i+1, nums.end());
    return nums;
}

void printArray(std::vector<int> nums){
    for(int i=0; i<nums.size(); i++) std::cout << nums[i] << " ";
	std::cout << '\n';
}

int main(){
	std::vector<int> arr = {0,1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < 1000000; i++) {
        nextPermutation(arr);
		std::cout << i << ": ";
        printArray(arr);
    }
    return 0;
}
