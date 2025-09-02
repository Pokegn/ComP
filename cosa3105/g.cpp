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


void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n), prefixMax(n), suffixMin(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

	prefixMax[0] = v[0];
    for (ll i = 1; i < n; i++)
    {
		prefixMax[i] = max(prefixMax[i - 1], v[i]);
    }

	suffixMin[n - 1] = v[n - 1];
	for (ll i = n - 2; i >= 0; i--)
	{
		suffixMin[i] = min(suffixMin[i + 1], v[i]);
	}

    ll ans = 0;
    for (ll i = 1; i < n-1; i++)
    {
		if (prefixMax[i] == v[i] && suffixMin[i] == v[i]) {
			ans++;
		}
    }
    cout << ans;
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