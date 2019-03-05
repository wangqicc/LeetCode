#include <stdio.h>
#include <stdlib.h>	//memory

/*
	name: Merge Sorted Array
	notes:
		1. 采用插入排序的方法进行操作
		2. 整型指针使用方式和字符型差不多，针对初始化来说
*/
void mergeOld(int* nums1, int m, int* nums2, int n) {
    int i = 0, j = 0;
    int k;
    while (i < m + j && j < n) {
    	if (nums1[i] > nums2[j]) {
    		k = m + j;
    		while (k > i) {
    			nums1[k] = nums1[k - 1];
    			--k;
    		}
    		nums1[i] = nums2[j];
    		++j;
    	}
    	++i;
    }
    while (j < n) {
    	nums1[i] = nums2[j];
    	++i;
    	++j;
    }
}

/*
	notes:
		1. 逆向思维，对 nums1 从后往前进行归并算法
*/
void merge(int* nums1, int m, int* nums2, int n) {
	int k = m + n;
	int i = m - 1, j = n - 1;
	while (i >= 0 && j >= 0) {
		if (nums1[i] > nums2[j]) {
			nums1[--k] = nums1[i--];
		} else {
			nums1[--k] = nums2[j--];
		}
	}
	while (j >= 0) {
		nums1[--k] = nums2[j--];
	}
}

void print(int *cur, int n) {
	int i;
	printf("%d", cur[0]);
	for (i = 1; i < n; ++i) {
		printf("-->%d", cur[i]);
	}
	printf("\n");
}

/*test unit*/
int main(int argc, char const *argv[]){
	int nums1[] = {2, 9, 0, 0, 0, 0};
	int nums2[] = {1, 2, 3, 5};
	int *p1, *p2;
	p1 = nums1;
	p2 = nums2;
	mergeOld(p1, 2, p2, 4);
	print(nums1, 6);
	return 0;
}