#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <numeric>
#define int64_t long long
using namespace std;

void solve();

int main(){
    solve();
    return 0;
}

pair<int64_t, int64_t> dist(int64_t a, int64_t x, int64_t y){
    int64_t n = (a*x-y)*(a*x-y);
    int64_t d = (a*a+1);
    const int64_t g = (n == 0 ? d: gcd(n, d));
    n /= g;
    d /= g;
    return {n, d};
}

void solve(){
    int n; cin >> n;
    int64_t a, b; cin >> a >> b;
    vector<pair<int64_t,pair<int64_t,int64_t>>> p(n);

    for(auto &[x, V]: p)
        cin >> x >> V.first >> V.second;

    map<pair<int64_t, int64_t>, map<pair<int64_t, int64_t>, int64_t>> freq;
    for(const auto &[x, V]: p){
        const auto &[Vx, Vy] = V;
        freq[dist(a, Vx, Vy)][V]++;
    }

    int64_t ans = 0;
    for(const auto &[d, points]: freq){
        int64_t N = 0;
        for(const auto &[V, freq]: points)
            N += freq, ans -= freq*freq-freq;
        ans += N*N-N;
    }

    cout << ans << endl;

}