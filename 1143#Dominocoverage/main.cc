#include <stdio.h>

long long matrix[30][2][2];

int main(int argc, char *argv[]) {
    int n = 0;
    int i = 0;
    int j = 1;
    long long r00 = 1, r01 = 0, r10 = 0, r11 = 1;

    scanf("%d", &n);

    matrix[1][0][0] = 0;
    matrix[1][0][1] = 1;
    matrix[1][1][0] = 1;
    matrix[1][1][1] = 1;

    while(n) {
        i = n % 2;
        n = n / 2;
        if(j != 1) {
            matrix[j][0][0] = (matrix[j - 1][0][0] * matrix[j - 1][0][0] + matrix[j - 1][0][1] * matrix[j - 1][1][0]) % 19999997;
            matrix[j][0][1] = (matrix[j - 1][0][0] * matrix[j - 1][0][1] + matrix[j - 1][0][1] * matrix[j - 1][1][1]) % 19999997;
            matrix[j][1][0] = (matrix[j - 1][1][0] * matrix[j - 1][0][0] + matrix[j - 1][1][1] * matrix[j - 1][1][0]) % 19999997;
            matrix[j][1][1] = (matrix[j - 1][1][0] * matrix[j - 1][0][1] + matrix[j - 1][1][1] * matrix[j - 1][1][1]) % 19999997;
        }
        if(i) {
            int _r00 = (r00 * matrix[j][0][0] + r01 * matrix[j][1][0]) % 19999997;
            int _r01 = (r00 * matrix[j][0][1] + r01 * matrix[j][1][1]) % 19999997;
            int _r10 = (r10 * matrix[j][0][0] + r11 * matrix[j][1][0]) % 19999997;
            int _r11 = (r10 * matrix[j][0][1] + r11 * matrix[j][1][1]) % 19999997;
            r00 = _r00; r01 = _r01; r10 = _r10; r11 = _r11;
        }
        j++;
    }
    printf("%lld\n", r11);
    return 0;
}
