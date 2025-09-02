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
    ll n, m;
    cin >> n >> m;
    vector<string> mat(n);

    ll reqOnes = n + n + m + m - 4;
    ll goodOnes = 0;
    ll totalOnes = 0;
    for (ll i = 0; i < n; i++)
    {
        string s;
        cin >> s;
		mat[i] = s;
		for (ll j = 0; j < m; j++)
		{
			if (s[j] == '1')
			{
				totalOnes++;
				if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
				{
					goodOnes++;
				}
			}
		}
    }

	
	if (totalOnes < reqOnes)
	{
		cout << -1;
		return;
	}


    cout << reqOnes - goodOnes;
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