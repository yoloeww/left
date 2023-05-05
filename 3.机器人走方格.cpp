#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, k, p;
long long remained = pow(10, 9) + 7;
int process(int n, int cur, int rest, int p) {
    if (rest == 0)
        return cur == p ? 1 : 0;
    if (cur == 1) {
        return process(n, 2, rest - 1, p) % remained;
    }
    if (cur == n) {
        return process(n, n - 1, rest - 1, p) % remained;
    }
    return process(n, cur + 1, rest - 1, p) % remained + process(n, cur - 1, rest - 1, p) % remained;
}
int main() {
    cin >> n >> m >> k >> p;
    if (n < 2 || k < 1 || m < 1 || p < 1 || p > n) {
        cout << 0 << endl;
        return 0;
    }

    cout << process(n, m, k, p);
    return 0;
}