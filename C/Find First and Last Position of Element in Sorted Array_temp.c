#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
	name: Find First and Last Position of Element in Sorted Array
	Return an array of size *returnSize.
	Note: The returned array must be malloced, assume caller calls free().
*/
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	*returnSize = 2;
	int* res = (int*)malloc(sizeof(int) * 2);
	memset(res, -1, 8);

	int low = 0, high = numsSize - 1;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		printf("%d : %d : %d\n", low, mid, high);
		if (nums[mid] == target) {
			int start = mid, end = mid;
			while (start >= 0) {
				if (nums[start] == nums[mid]) {
					--start;
				}
			}
			while (end < numsSize) {
				if (nums[end] == nums[mid]) {
					++end;
				}
			}
			res[0] = start + 1;
			res[1] = end - 1;
			return res;
		} else if (nums[mid] < target) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
    return res;
}

void printArr(int* nums, int numsSize) {
	int i;
	for (i = 0; i < numsSize - 1; ++i) {
		printf("%d --> ", nums[i]);
	}
	printf("%d\n", nums[i]);
}

/*test unit*/
int main(int argc, char const *argv[]){
	int nums1[] = {5, 7, 7, 8, 8, 10};
	int nums[] = {1};
	int numsSize = 1;
	int target = 1;
	int returnSize;
	printArr(nums, numsSize);
	int* p = searchRange(nums, numsSize, target, &returnSize);
	printArr(p, returnSize);
	return 0;
}
/*
	notes: reset with nums = {1}, target = 1;
*/