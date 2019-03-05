#include <stdio.h>

/*
	name: Container With Most Water
	notes:
		1. Brute Force (暴力解法)
		2. time complexity: O(n^2)
		3. space complexity: O(l) Constant extra space is used(常量的额外空间被使用)
*/
int maxAreaBF(int* height, int heightSize) {
    int i, j;
    int max = 0;
    int area;
    for (i = 0; i < heightSize; ++i) {
    	for (j = i + 1; j < heightSize; ++j) {
    		area = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
    		if (area > max) {
    			max = area;
    		}
    	}
    }
    return max;
}

/*
	notes:
		1. Two pointer approach
		2. time complexity: O(n) Single pass(单程/一次遍历)
		3. space complexity: O(l)
*/
int maxAreaTwoP(int* height, int heightSize) {
    int max = 0;
    int i = 0, j = heightSize - 1;
    int area;
    while (i < j) {
    	area = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
    	if (area > max) {
    		max = area;
    	}
    	if (height[i] < height[j]) {
    		++i;
    	} else {
    		--j;
    	}
    }
    return max;
}

/*test unit*/
int main(int argc, char const *argv[]){
	int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	int* p = height;
	printf("%d\n", maxAreaTwoP(p, 9));
	return 0;
}