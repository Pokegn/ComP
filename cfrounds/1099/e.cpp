#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 100000;
    vector<bool> can(N + 1, false);

    for (int a = 0; a * a <= N; ++a) {
        for (int b = 0; a * a + b * b <= N; ++b) {
            int val = a * a + b * b;
            if (val >= 1) {
                can[val] = true;
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= N; ++i) {
        if (can[i]) count++;
    }

    cout << count << endl;
    return 0;
}