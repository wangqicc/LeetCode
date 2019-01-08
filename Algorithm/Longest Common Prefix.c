#include <stdio.h>//provide for printf();
#include <string.h>//provide for strlen()
#include <stdlib.h>//provide for malloc()

char* longestCommonPrefix(char** strs, int strsSize) {
    //if you don't have any strings, just return ""
    if (strsSize < 1) {
        return "";
    }
    //use result to record answer
    char* result;
    //use size to record the length of the first string, minSize to record the length of the minimum string
    int size, minSize;
    size = strlen(strs[0]);
    result = (char*)malloc(sizeof(char) * (size + 1));
    strcpy(result, strs[0]);
    //this is main code
    int i, j;
    for (i = 1; i < strsSize; ++i) {
        minSize = 0;
        for (j = 0; j < size; ++j) {
            if (result[j] != strs[i][j]) {
                result[j] = '\0';
                break;
            }
            ++minSize;
        }
        if (minSize == 0) {
            return "";
        }
        if (minSize < size) {
            size = minSize;
        }
    }

    return result;
}

//test unit
int main(int argc, char const *argv[]) {
    int strsSize = 2;
    char* a[] = {"aa", "a"};
    char** strs;
    strs = (char**)malloc(sizeof(char**));
    strs = a;

    char* result = longestCommonPrefix(strs, strsSize);
    for (int i = 0; i < strlen(result); ++i) {
        printf("%c\n", result[i]);
    }
	return 0;
}
