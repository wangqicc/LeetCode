#include <stdio.h>
#include <stdbool.h>
#define STACK_SIZE 100000

bool isValid(char* s) {
    char stack[STACK_SIZE];
    int top = -1;
    //counts the length of a string
    int length = -1;
    while (s[++length] != '\0'){};
    //this is the main code
    int i;
    for (i = 0; i < length; ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack[++top] = s[i];
            continue;
        }
        //use top > -1 to avoid overflows
        if (s[i] == ')') {
            if (top > -1 && stack[top] == '(') {
                --top;
                continue;
            } else {
                return false;
            }
        }
        if (s[i] == ']') {
            if (top > -1 && stack[top] == '[') {
                --top;
                continue;
            } else {
                return false;
            }
        }
        if (s[i] == '}') {
            if (top > -1 && stack[top] == '{') {
                --top;
                continue;
            } else {
                return false;
            }
        }
    }
    //check for overflow
    if (top != -1) {
        return false;
    }
    return true;
}

//test unit
int main(int argc, char const *argv[]) {
    printf("%d\n", isValid("]"));//return 0
    printf("%d\n", isValid("(])"));//return 0
    printf("%d\n", isValid("()"));//return 1
    printf("%d\n", isValid("()[]{}"));//return 1
    printf("%d\n", isValid("(]"));//return 0
	return 0;
}
