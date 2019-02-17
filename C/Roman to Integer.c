#include <stdio.h>
//#include <stdbool.h>
//Roman to Integer
int romanToInt(char* s) {
    int result = 0;

    int count = 0;
    while (s[count++] != '\0'){};
    --count;

    for (int i = 0; i < count; ++i) {
        switch (s[i]) {
            case 'I':
                if (s[i + 1] == 'V') {
                    ++i;
                    result += 4;
                } else if (s[i + 1] == 'X') {
                    ++i;
                    result += 9;
                } else {
                    result += 1;
                }
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                if (s[i + 1] == 'L') {
                    ++i;
                    result += 40;
                } else if (s[i + 1] == 'C') {
                    ++i;
                    result += 90;
                } else {
                    result += 10;
                }
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
                if (s[i + 1] == 'D') {
                    ++i;
                    result += 400;
                } else if (s[i + 1] == 'M') {
                    ++i;
                    result += 900;
                } else {
                    result += 100;
                }
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
            default :
                break;
        }
    }
    return result;
}
//test unit
int main(int argc, char const *argv[]) {
	/*int x;
    while (scanf("%d", &x) != EOF) {
        printf("%d\n", isPalindrome(x));
    }*/
    printf("%d\n", romanToInt("III"));
    printf("%d\n", romanToInt("IV"));
    printf("%d\n", romanToInt("IX"));
    printf("%d\n", romanToInt("LVIII"));
    printf("%d\n", romanToInt("MCMXCIV"));
	return 0;
}
