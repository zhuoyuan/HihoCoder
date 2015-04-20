#include <iostream>
#include <cstring>

using namespace std;

int matrix[31][8][8];

void MatrixMul(int i, bool what);

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    if(n % 2) { cout << 0 << endl; return 0; }
    if(n < 2) { cout << 1 << endl; return 0; }
    /* init */
    memset(matrix, 0, sizeof(matrix));

    int i = 1;
    while(n) {
        MatrixMul(i, false);
        if(n % 2) MatrixMul(i, true);
        n /= 2;
        i++;
    }
    cout << matrix[0][7][7] << endl;
    return 0;
}

void MatrixMul(int index, bool what) {
    if(index == 1) {
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(i == j)
                    matrix[0][i][i] = 1;
                else
                    matrix[0][i][j] = 0;

                matrix[1][i][j] = 0;
            }
        }
        matrix[1][0][7] = matrix[1][1][6] = matrix[1][2][5] = matrix[1][3][4] = 1;
        matrix[1][3][7] = matrix[1][4][3] = matrix[1][5][2] = matrix[1][6][1] = 1;
        matrix[1][6][7] = matrix[1][7][0] = matrix[1][7][3] = matrix[1][7][6] = 1;
    }
    else {
        int i, j, k;
        if(what) { i = 0; j = 0; k = index; }
        else     { i = index; j = k = index - 1; }

        int media[8][8];
        memset(media, 0, sizeof(media));
        for(int r = 0; r < 8; r++) {
            for(int s = 0; s < 8; s++) {
                for(int t = 0; t < 8; t++)
                    media[r][s] += ((matrix[j][r][t] * matrix[k][t][s]) % 12357);
                media[r][s] %= 12357;
            }
        }
        memcpy(matrix[i], media, sizeof(media));
    }
}
