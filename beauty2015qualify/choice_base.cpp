#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef unsigned long long uint64_t;

uint64_t getMCost(int x, int y, vector<pair<int, int> > &vb) {
    int res = 0x7fffffff;
    for(int i = 0; i < vb.size(); i++)
        res = min(res, (abs(x - vb[i].first) + abs(y - vb[i].second)));
    return res;
}

uint64_t getOCost(int A, int x, int y, int sum_x, int sum_y, int sum_x_x, int xum_y_y) {
    uint64_t res = 0;
    res += (sum_x_x + xum_y_y + A * (x * x + y * y) - 2 * (sum_x * x + sum_y * y));
    return res;
}

int main(int argc, char *argv[]) {
    int T = 0;
    int N, M, A, B;
    int i, j, k;

    uint64_t sum_ax, sum_ay;
    uint64_t sum_ax_ax, sum_ay_ay;

    cin >> T;
    for(k = 0; k < T; k++) {
        cin >> N >> M >> A >> B;

        vector<pair<int, int> > va;
        vector<pair<int, int> > vb;
        sum_ax = sum_ay = 0;
        sum_ax_ax = sum_ay_ay = 0;

        for(i = 0; i < A; i++) {
            int x, y;
            cin >> x >> y;
            va.push_back(make_pair(x, y));
            sum_ax += x;
            sum_ay += y;
            sum_ax_ax += x * x;
            sum_ay_ay += y * y;
        }
        for(i = 0; i < B; i++) {
            int x, y;
            cin >> x >> y;
            vb.push_back(make_pair(x, y));
        }

        int x0 = sum_ax / A;
        int y0 = sum_ay / A;
        
        uint64_t minCost = getMCost(x0, y0, vb) + getOCost(A, x0, y0, sum_ax, sum_ay, sum_ax_ax, sum_ay_ay);
        if(x0 < M) minCost = min(minCost, getMCost(x0 + 1, y0, vb) + getOCost(A, x0 + 1, y0, sum_ax, sum_ay, sum_ax_ax, sum_ay_ay));
        if(y0 < N) minCost = min(minCost, getMCost(x0, y0 + 1, vb) + getOCost(A, x0, y0 + 1, sum_ax, sum_ay, sum_ax_ax, sum_ay_ay));
        if(x0 < M && y0 < M) minCost = min(minCost, getMCost(x0 + 1, y0 + 1, vb) + getOCost(A, x0 + 1, y0 + 1, sum_ax, sum_ay, sum_ax_ax, sum_ay_ay));
            
        cout << "Case #" << k + 1 << ": " << minCost << endl;
    }
    
    return 0;
}
