#include <iostream>
#include <string>

using namespace std;
unsigned int c[1001][1001];

int main(int argc, char *argv[]) {
    int T;
    int i, j, k, l;
    string s;

    cin >> T;
    for(int r = 0; r < T; r++) {
        cin >> s;
        int len = s.size();

        for(l = 1; l <= len; l++) {
            for(i = 0; i < len - l + 1; i++) {
                j = i + l - 1;
                if(1 == l)
                    c[i][j] = 1;
                else {
                    if(s[i] == s[j])
                        c[i][j] = c[i + 1][j] + c[i][j - 1] + 1;
                    else
                        c[i][j] = c[i + 1][j] + c[i][j - 1] - c[i + 1][j - 1]; /* c[i][j] may be negative number*/
                    c[i][j] %= 100007;
                }
            }
        }
        cout << "Case #" << r + 1 << ": " << (c[0][len - 1] % 1000007 + 100007) % 100007 << endl;
    }
}
