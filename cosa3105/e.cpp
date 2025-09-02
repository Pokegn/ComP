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

ll MOD = 1e9 + 7;

ll fexp(ll x, ll y) {
	ll res = 1;
	while (y > 0) {
		if (y & 1) {
			res = (res * x) % MOD;
		}
		x = (x * x) % MOD;
		y >>= 1;
	}
	return res;
}

ll inv(ll x) {
	return fexp(x, MOD - 2);
}

void solve() {
	ll n, x;
	cin >> n >> x;

	vector<vector<ll>> v(n, vector<ll>(6));
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < 6; j++)
		{
			cin >> v[i][j];
		}
	}

	map<ll, ll> prev;
	prev[1] = 1;

	ll n2 = 0;
	if (n > 7)
	{
		n2 = n - 7;
		n = 7;
	}
	for (ll i = 0; i < n; i++)
	{
		map<ll, ll> newmp;
		for (ll j = 0; j < 6; j++)
		{
			for (auto& p : prev)
			{
				newmp[(p.first * v[i][j]) % MOD] += p.second;
			}
		}

		prev = newmp;
	}

	if (n2 == 0) {
		cout << prev[x];
		return;
	}

	map<ll, ll> firstPart = prev;
	prev.clear();
	prev[1] = 1;

	for (ll i = n; i < n+n2; i++)
	{
		map<ll, ll> newmp;
		for (ll j = 0; j < 6; j++)
		{
			for (auto& p : prev)
			{
				newmp[(p.first * v[i][j]) % MOD] += p.second;
			}
		}

		prev = newmp;
	}

	map<ll, ll> secondPart = prev;

	ll ans = 0;
	for (auto& p : secondPart) {
		ll search = (x * inv(p.first)) % MOD;
		if (firstPart.find(search) != firstPart.end()) {
			ans = ans + (p.second * firstPart[search]);
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