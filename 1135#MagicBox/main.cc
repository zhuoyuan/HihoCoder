#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *arv[]) {
    int rby[26];
    int x, y, z;
    string s;

    cin >> x >> y >> z;
    cin >> s;

    int sumxyz = x + y + z;
    int xorxyz = x ^ y ^ z;
    int mulxyz = x * y * z;
    int maxleft = 0;

    rby[17] = rby[1] = rby[24] = 0;
    for(int i = 0; i < s.size(); i++) {
        rby[s[i] - 'A']++;
        maxleft = max(maxleft, rby[17] + rby[1] + rby[24]);
        int xx = abs(rby[17] - rby[24]);
        int yy = abs(rby[24] - rby[ 1]);
        int zz = abs(rby[ 1] - rby[17]);
        if(xorxyz == xx ^ yy ^ zz && sumxyz == xx + yy + zz && mulxyz == xx * yy * zz)
            rby[17] = rby[1] = rby[24] = 0;
    }

    cout << maxleft << endl;
    return 0;
}
