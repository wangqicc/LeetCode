#include <stdio.h>

/*
	name: Fibonacci Number
	notes:
		1. 使用额外的空间，可使得在常数时间内输出
*/
int fibOld(int N) {
    int nums[31];
    nums[0] = 0;
    nums[1] = 1;
    int i;
    for (i = 2; i < 31; ++i) {
    	nums[i] = nums[i - 1] + nums[i - 2];
    }
    return nums[N];
}

/*
	notes:
		1. 减少空间使用，每次输出必须进行一遍运算
*/
int fib(int N) {
	if (N < 2) {
		return N;
	}
	int One = 0, Two = 1, Three, i;
	for (i = 2; i <= N; ++i) {
		Three = One + Two;
		One = Two;
		Two = Three;
	}
	return Three;
}

/*test unit*/
int main(int argc, char const *argv[]){
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", fib(n));
	}
	return 0;
}