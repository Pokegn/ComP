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

void solve() {
	string s;
	ll n;
	cin >> n;

	vector<ll> v(n);
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		cin >> v[i];
		ll temp = (ans + 1) * v[i];
		temp %= MOD;
		ans = (ans + temp) % MOD;
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