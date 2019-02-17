#include <stdio.h>
#include <stdbool.h>

bool isValid(char* s) {
    //counts the length of a string
    int length = -1;
    while (s[++length] != '\0'){};
    
    char stack[length];
    int top = -1;
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
    return top == -1;
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
