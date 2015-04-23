### Description

The circus clown Sunny has a magic box. When the circus is performing, Sunny puts some balls into the box one by one. The balls are in three colors: red(R), yellow(Y) and blue(B). Let Cr, Cy, Cb denote the numbers of red, yellow, blue balls in the box. Whenever the differences among Cr, Cy, Cb happen to be x, y, z, all balls in the box vanish. Given x, y, z and the sequence in which Sunny put the balls, you are to find what is the maximum number of balls in the box ever.

For example, let's assume x=1, y=2, z=3 and the sequence is RRYBRBRYBRY. After Sunny puts the first 7 balls, RRYBRBR, into the box, Cr, Cy, Cb are 4, 1, 2 respectively. The differences are exactly 1, 2, 3. (|Cr-Cy|=3, |Cy-Cb|=1, |Cb-Cr|=2) Then all the 7 balls vanish. Finally there are 4 balls in the box, after Sunny puts the remaining balls. So the box contains 7 balls at most, after Sunny puts the first 7 balls and before they vanish.

### Input
Line 1: x y z
Line 2: the sequence consisting of only three characters 'R', 'Y' and 'B'.
For 30% data, the length of the sequence is no more than 200.
For 100% data, the length of the sequence is no more than 20,000, 0 <= x, y, z <= 20.

###Output
The maximum number of balls in the box ever.
