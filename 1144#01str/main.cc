#include <stdio.h>

char a[200004];

void gen01Str(int n, int m) {
    if(n < m - 1) { printf("NO\n"); return; }
    int i, j;
    for(int i = 1; i < 2 * m; i++)
        a[i] = (i % 2 ? '1' : '0');

    j = n - m + 1 + (n == m - 1 ? 0 : 1);
    for(i = 1; i < j - 1; i++)
        a[2 * m - 1 + i] = '0';
    a[2 * m - 1 + i] = '\0';

    if(j) { a[0] = '0'; printf("%s\n", a); }
    else  {printf("%s\n", a + 1);}
}

int main(int argc, char *argv[]) {
    int n, m;
    scanf("%d %d", &n, &m);
    gen01Str(n, m);
    return 0;
}
