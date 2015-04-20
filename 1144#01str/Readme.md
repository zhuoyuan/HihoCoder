### Description
Give two numbers m and n, decide if it can be used to generate a string which can't contains substr "11" or "001" with exactly m '1' and n '0', if yes, ouput the minimum by dictionary order, if no, output "NO"

- input : 0 <= n,m <= 100000, 0 < m + n
- output: S or NO

For example:
input  3 1
output NO

input  3 3
output 010101

### My Solution
- First, without "11" and "001", we can assert the string must like this:
010101010000000 or 10101 or 010101, there must be only this three forms, so if n < m - 1, the anster is "NO"

- Senond, if it has a solution, the minium one is easy to get, just put one '0' at the fisrt postion of the string if you can.
