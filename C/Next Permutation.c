#include <stdio.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
	name: flip the integer array(翻转整型数组)
*/
void reverse(int* nums, int start, int end) {
	if (start >= end) {
		return ;
	}
	while (start < end) {
		swap(&nums[start], &nums[end]);
		++start;
		--end;
	}
}

/*
	name: Next Permutation
	notes:
		1. 6 --> 3 --> 4 --> 9 --> 8 --> 7 --> 1
			首先从后往前找到 nums[i] > nusm[i - 1] 的位置
			如果 i 为 0 的话，则说明序列已经是递减的，转置即可
			如果 i 不为 0 ，则从 nums[numsSize - 1] 找到 nums[i] 
			找到一个比 nums[i - 1] 大的，执行交换的操作
			然后对从 i 开始 numsSize - 1 结束的序列执行转置的操作即可
		2. 在这个例子中 i 位置为 9 ，从后往前找到 7 > 4 ，交换后可得
			6 --> 3 --> 7 --> 9 --> 8 --> 4 --> 1
			再将包含 9 之后的位置元素进行转置即得
			6 --> 3 --> 7 --> 1 --> 4 --> 8 --> 9
*/
void nextPermutation(int* nums, int numsSize) {
	//take care of boundary
	if (nums == NULL || numsSize < 2) {
		return ;
	}
    int i, j, temp;
    for (i = numsSize - 1; i > 0; --i) {
    	if (nums[i] > nums[i - 1]) {
    		break;
    	}
    }
    if (i == 0) {
    	reverse(nums, 0, numsSize - 1);
    } else {
    	int k;
    	for (k = numsSize - 1; k >= i; --k) {
    		if (nums[i - 1] < nums[k]) {
    			swap(&nums[i - 1], &nums[k]);
    			break;
    		}
    	}
    	reverse(nums, i, numsSize - 1);
    }
}

/*
	name: 输出序列
*/
void printArr(int* nums, int numsSize) {
	int i;
	for (i = 0; i < numsSize - 1; ++i) {
		printf("%d --> ", nums[i]);
	}
	printf("%d\n", nums[i]);
}

/*test unit*/
int main(int argc, char const *argv[]){
	int nums1[] = {1, 2, 3};
	int nums2[] = {3, 2, 1};
	int nums3[] = {1, 1, 5};
	int nums4[] = {1, 5, 4, 3, 2};
	int nums5[] = {1, 2, 3, 4, 5};
	int nums6[] = {5, 4, 3, 2, 1};
	int nums7[] = {6, 3, 4, 9, 8, 7, 1};
	int numsSize = 7;
	printf("before: ");
	printArr(nums7, numsSize);
	nextPermutation(nums7, numsSize);
	printf("after: ");
	printArr(nums7, numsSize);
	return 0;
}
/*
	reference: https://leetcode.com/problems/next-permutation/discuss/13865/Sharing-my-clean-and-easy-understand-java-code-with-explanation
*/