#include <stdio.h>
#include <string.h>	//provide str algorithm
#include <stdlib.h>	//memory allocation

/*
	name:Count and Say
	notes:
		non-recursive algorithm
		how to use pointers correctly
		1. 指针变量 char* p; p = (char*)malloc(3 * sizeof(char)) 初始化的时候
		不能使用 p = "wq" ，因为这只是将指针指向常量字符串，在后续中不能进行修改
		必须进行单个字符赋值 p[0] = 'w'; p[1] = 'q'; p[2] = '\0'; 
		或者使用 string.h 库中的 memset(p, 0, 3 * sizeof(char)); 进行初始化
		只有这样才能使得指针 p 不会变为野指针，在后续的程序中可以进行修改
		还可以通过将最后一个字符赋值为 '\0' 来初始化 p[2] = '\0';
	references:
		1. 有关指针的心得之指针常见错误：
			https://blog.csdn.net/lsjseu/article/details/9004669
*/
char* countAndSay(int n) {
	if (n == 1) {
		return "1";
	}
	char *cur, *temp;
	cur = (char*)malloc(2);
	cur[0] = '1';
	cur[1] = '\0';
	while (--n) {
		int len = strlen(cur);
		temp = (char*)malloc(len * 3);
		memset(temp, 0, len * 3);
		int count = 1;
		int k = -1;
		for (int i = 1; i < len; ++i){
			if (cur[i] == cur[i - 1]) {
				++count;
			} else {
				temp[++k] = '0' + count;
				temp[++k] = cur[i - 1];
				count = 1;
			}
		}
		temp[++k] = '0' + count;
		temp[++k] = cur[len - 1];
		free(cur);
		cur = temp;
	}
	return cur;
}

/*
	notes:recursive algorithm
*/
char* countAndSayRecursive(int n) {
	char* res = (char*)malloc(2);
	char* temp;
	int len, count, k;
	if (n == 1) {
		res[0] = '1';
		res[1] = '\0';
	} else {
		temp = countAndSayRecursive(n - 1);
		len = strlen(temp);
		res = (char*)malloc(len * 2 + 1);
		//memset(res, 0, len * 2 + 1);
		res[len * 2] = '\0';
		k = -1;
		count = 1;
		int i;
		for (i = 1; temp[i] != '\0'; ++i) {
			if (temp[i] == temp[i - 1]) {
				++count;
			} else {
				res[++k] = '0' + count;
				res[++k] = temp[i - 1];
				count = 1;
			}
		}
		res[++k] = '0' + count;
		res[++k] = temp[len - 1];
		res[++k] = '\0';
	}
	return res;
}

/*test unit*/
int main(int argc, char const *argv[]){
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%s\n", countAndSayRecursive(n));
	}
	return 0;
}