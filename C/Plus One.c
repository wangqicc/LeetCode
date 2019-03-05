#include <stdio.h>
#include <stdlib.h>

void printArr(int* nums, int numsSize) {
	int i;
	for (i = 0; i < numsSize - 1; ++i) {
		printf("%d --> ", nums[i]);
	}
	printf("%d\n", nums[i]);
}

/*
	name: Plus One
	notes:
		1. 从后往前处理进制问题，在范围足够大的情况下不能转化为数字来进行处理
*/
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    if (digits == NULL || digitsSize < 1) {
    	*returnSize = 0;
    	return NULL;
    }
    int* res = (int*)malloc(sizeof(int) * digitsSize);
    res[digitsSize - 1] = digits[digitsSize - 1] + 1;
    int i;
    for (i = digitsSize - 2; i >= 0; --i) {
    	if (res[i + 1] == 10) {
    		res[i + 1] = 0;
    		res[i] = digits[i] + 1;
    	} else {
    		res[i] = digits[i];
    	}
    }
    *returnSize = digitsSize;
    if (res[0] == 10) {
    	res[0] = 1;
    	res = (int*)realloc(res, sizeof(int) * (digitsSize + 1));
    	res[digitsSize] = 0;
    	*returnSize = digitsSize + 1;
    }
    return res;
}


/*test unit*/
int main(int argc, char const *argv[]){
	int digits1[] = {9, 9, 9, 9};
	int digits2[] = {5, 2, 0, 9};
	int returnSize;
	printf("before:\n");
	printArr(digits2, 4);
	int* p = plusOne(digits2, 4, &returnSize);
	printf("after:\n");
	printArr(p, returnSize);
	return 0;
}