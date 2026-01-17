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
ll MOD = 998244353;

ll solve2(vector<pair<ll, ll>> v, ll n) {
	vector<pair<ll, ll>> original = v;
	sort(v.begin(), v.end());

	set<pair<ll, ll>> outside;
	for (ll i = 1; i < n; i++){
		outside.insert(v[i]);
	}

	ll l = v[0].second, r = v[0].second;
	ll ans = v.back().first - v[0].first;
	ll maxInside = v[0].first;
	ll index = 0;
	while (outside.size()) {
		while (index+1 < n && v[index + 1].first <= maxInside) {
			index++;

			while (v[index].second < l) {
				l--;
				outside.erase(original[l]);
				maxInside = max(maxInside, original[l].first);
			}

			while (v[index].second > r) {
				r++;
				outside.erase(original[r]);
				maxInside = max(maxInside, original[r].first);
			}
		}

		if (outside.empty()) {
			break;
		}

		ll sz1 = abs(outside.rbegin()->first - outside.begin()->first);
		ll sz2 = maxInside - v[0].first;
		ll tans = max(sz1, sz2);
		ans = min(ans, tans);

		maxInside = max(maxInside, v[index + 1].first);
	}

	return ans;
}

ll solve3(vector<pair<ll, ll>> v, ll n) {
	vector<pair<ll, ll>> original = v;
	sort(v.rbegin(), v.rend());

	set<pair<ll, ll>> outside;
	for (ll i = 1; i < n; i++) {
		outside.insert(v[i]);
	}

	ll l = v[0].second, r = v[0].second;
	ll ans = v[0].first - v.back().first;
	ll minInside = v[0].first;
	ll index = 0;
	while (outside.size()) {
		while (index + 1 < n && v[index + 1].first >= minInside) {
			index++;

			while (v[index].second < l) {
				l--;
				outside.erase(original[l]);
				minInside = min(minInside, original[l].first);
			}

			while (v[index].second > r) {
				r++;
				outside.erase(original[r]);
				minInside = min(minInside, original[r].first);
			}
		}

		if (outside.empty()) {
			break;
		}

		ll sz1 = abs(outside.rbegin()->first - outside.begin()->first);
		ll sz2 = v[0].first - minInside;
		ll tans = max(sz1, sz2);
		ans = min(ans, tans);

		minInside = min(minInside, v[index + 1].first);
	}

	return ans;



}

void solve() {
	ll n;
	cin >> n;
	vector<pair<ll, ll>> v(n);

	for (ll i = 0; i < n; i++)
	{
		cin >> v[i].first;
		v[i].second = i;
	}

	ll ans = min(solve3(v,n), solve2(v, n));

	cout << ans << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t = 1;
	cin >> t;

	while (t--) {
		solve();
	}
}