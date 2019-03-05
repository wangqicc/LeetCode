#include <stdio.h>

/*
	功能：从一个数组中删除 val ，返回删除后的数组长度
*/
int removeElementOld(int* nums, int numsSize, int val) {
	int count = 0;
	if (numsSize < 1) {
		return 0;
	}
	for (int i = 0; i < numsSize; ++i) {
		if (nums[i] != val) {
			nums[count++] = nums[i];
		}
	}
    return count;
}

/*
	note：由于删除的数的数目远少于数组中元素数目，
		可以从数组中与 val 值相同的元素开始考虑
*/
int removeElement(int* nums, int numsSize, int val) {
	for (int i = 0; i < numsSize; ++i) {
		if (nums[i] == val) {
			nums[i] = nums[(numsSize--) - 1];
			--i;
		}
	}
    return numsSize;
}

/*test unit*/
int main(int argc, char const *argv[]){
	int* p;

	int nums1[] = {3, 2, 2, 3};
	p = nums1;
	printf("%d\n", removeElement(p, 3, 3));
	int nums2[] = {0, 1, 2, 2, 3, 0, 4, 2};
	p = nums2;
	printf("%d\n", removeElement(p, 10, 2));
	return 0;
}