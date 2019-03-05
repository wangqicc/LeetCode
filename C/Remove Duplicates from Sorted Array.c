#include <stdio.h>

/*
	功能：删除数组中重复的元素并返回删除后的数组长度(原)
*/
int removeDuplicatesOld(int* nums, int numsSize) {
	int count = 0, reduce;
	if (numsSize > 0) {
		count = 1;
		reduce = nums[0];
	}
	int i;
	for (i = 1; i < numsSize; ++i) {
		if (reduce != nums[i]) {
			reduce = nums[i];
			nums[count++] = reduce;
		}
	}
    return count;
}

/*
	功能：删除数组中重复的元素并返回删除后的数组长度
*/
int removeDuplicates(int* nums, int numsSize) {
	int count = 0;
	if (numsSize < 1) {
		return count;
	}
	++count;
	for (int i = 1; i < numsSize; ++i) {
		if (nums[i] != nums[i - 1]) {
			nums[count++] = nums[i];
		}
	}
    return count;
}


/*test unit*/
int main(int argc, char const *argv[]){
	int* p;

	int nums1[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	p = nums1;
	printf("%d\n", removeDuplicates(p, 3));
	int nums2[] = {1, 1, 2};
	p = nums2;
	printf("%d\n", removeDuplicates(p, 10));
	int nums3[] = {};
	p = nums3;
	printf("%d\n", removeDuplicates(p, 0));
	return 0;
}