#include <stdio.h>

/*
	name:Search Insert Position
	note:顺序查找
*/
int searchInsertOld(int* nums, int numsSize, int target) {
	int i = 0;
	while (i < numsSize) {
		if (target <= nums[i]) {
			if (i == 0) {
				return 0;
			}
			return i;
		} else {
			if (i == numsSize - 1){
				return numsSize;
			}
			++i;
		}
	}
	return 0;
}

/*
	功能：折半查找找出目标 target 位置
*/
int searchInsert(int* nums, int numsSize, int target) {
	int left = 0, right = numsSize - 1;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (target == nums[mid]) {
			return mid;
		} else if (target < nums[mid]) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return left;
}

/*test unit*/
int main(int argc, char const *argv[]){
	int *p;
	int a[] = {1, 3, 5, 6};
	p = a;
	printf("%d\n", searchInsert(p, 4, 5));
	printf("%d\n", searchInsert(p, 4, 2));
	printf("%d\n", searchInsert(p, 4, 7));
	printf("%d\n", searchInsert(p, 4, 0));
	return 0;
}