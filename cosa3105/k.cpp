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


ll dpf(map<vector<ll>, ll>& dp, vector<ll>& v, ll n) {
	
	if (dp.find(v) != dp.end()) {
		return dp[v];
	}

	if (n == 1 || n == 0) {
		return 1;
	}

	ll x = 0;
	for (ll i = 0; i < 26; i++) {
		if (v[i] >= 2) {
			vector<ll> temp = v;
			temp[i] -= 2;
			x += dpf(dp, temp, n - 2);
		}
	}

	return dp[v] = x;
}



void solve() {
	string s;
	ll n;
	cin >> n;
	cin >> s;

	map<vector<ll>, ll> dp;
	vector<ll> v(26, 0);
	dp[v] = 1;
	for (ll i = 0; i < n; i++) {
		v[s[i] - 'a']++;
	}
	ll ans = dpf(dp, v, n);


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