#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int T;
    cin >> T;
    while(T--) {
        int i, n;
        cin >> i >> n;
        while((i % 4 == 0 || i % 4 == 1) && n) {
            i = i % 4 + i / 4;
            n--;
        }
        cout << n << endl;
    }
    return 0;
}
