#pragma GCC optimize("O3")
//#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>
#include <utility>
#include<iterator>
#include <iomanip>
#include <bitset>
#include <queue>
#include <array>
#include<numeric>
#include <stack>
#include <functional>

#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <chrono>

using namespace std;

//#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl '\n'
#define pb push_back
#define fi first
#define se second


ll dpf(vector<ll>& dp, vector<ll>&next, ll i) {
    if (dp[i] != -1)
        return dp[i];

    dp[i] = dpf(dp, next, i + 1) + 1;
    if (next[i] != -1)
        dp[i] = min(dp[i], dpf(dp, next, next[i]) + 1);

    return dp[i];
}

void solve() {
    ll n, m;
    cin >> n;
    vector<ll> v(n);

    vector<ll> next(n, -1);
    vector<ll> colorLastSeen(200001, -1);


    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        if (colorLastSeen[v[i]] != -1) {
            next[colorLastSeen[v[i]]] = i;
        }
        colorLastSeen[v[i]] = i;
    }

    vector<ll> dp(n, -1);
    dp[n - 1] = 0;

    cout << dpf(dp, next, 0);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
        cout << endl;
    }

    return 0;
}