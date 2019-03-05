# LeetCode
> There is my accpted JAVA and C solution

| Index |                            Title                             |                           Solution                           | Difficulty | days |
| :---: | :----------------------------------------------------------: | :----------------------------------------------------------: | :--------: | :--: |
|   1   |      [Two Sum](https://leetcode.com/problems/two-sum/)       | [Java](https://github.com/wangqicc/LeetCode/blob/master/Java/Two%20Sum.java) |    Easy    |  \   |
|   2   | [Reverse Integer](https://leetcode.com/problems/reverse-integer/) | [Java](https://github.com/wangqicc/LeetCode/blob/master/Java/Reverse%20Integer.java) |    Easy    |  \   |
|   3   | [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | [Java](https://github.com/wangqicc/LeetCode/blob/master/Java/Palindrome%20Number.java) |    Easy    |  \   |
|   4   | [Roman to Integer](https://leetcode.com/problems/roman-to-integer/) | [Java](https://github.com/wangqicc/LeetCode/blob/master/Java/Roman%20to%20Integer.java)/[C](https://github.com/wangqicc/LeetCode/blob/master/C/Roman%20to%20Integer.c) |    Easy    | 2/17 |
|   5   | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) | [Java](https://github.com/wangqicc/LeetCode/blob/master/Java/Valid%20Parentheses.java)/[C](https://github.com/wangqicc/LeetCode/blob/master/C/Valid%20Parentheses.c) |    Easy    | 2/17 |
|   6   | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) | [C](https://github.com/wangqicc/LeetCode/blob/master/C/Longest%20Common%20Prefix.c) |    Easy    | 2/17 |
|   7   | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) |                            [C]()                             |    Easy    | 2/26 |
|   8   | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) |                            [C]()                             |    Easy    | 2/26 |
|   9   | [Remove Element](https://leetcode.com/problems/remove-element/) |                            [C]()                             |    Easy    | 2/26 |
|  10   | [Search Insert Position](https://leetcode.com/problems/search-insert-position/) |                            [C]()                             |    Easy    | 2/27 |
|  11   | [Count and Say](https://leetcode.com/problems/count-and-say/) |                            [C]()                             |    Easy    | 2/28 |
|  12   | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) |                            [C]()                             |    Easy    | 3/1  |
|  13   | [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) |                            [C]()                             |   Medium   | 3/1  |
|  14   |                                                              |                                                              |            |      |
|       |                                                              |                                                              |            |      |
|       |                                                              |                                                              |            |      |
|       |                                                              |                                                              |            |      |
|       |                                                              |                                                              |            |      |
|       |                                                              |                                                              |            |      |

***

**notes:**

1. String in java is immutable. StringBuilder is mutable, that is it can be modified in memory.
2. 最长公共子序列

> 使用 `dp[i][j]` 来表示序列X的i位和序列Y的j位之前的最长公共子序列的长度。那么如果`X[i] == Y[j]`，`dp[i][j] = dp[i + 1][j + 1] + 1`；否则`dp[i][j] = max{d[[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}`。

3. **website:** http://www.calvinneo.com
4. 