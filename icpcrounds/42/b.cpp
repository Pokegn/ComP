#include <iostream>
#include <bitset>
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
#include <tuple>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <list>
//#include <bits/stdc++.h>
#define ll long long
#define pb push_back
//#define endl '\n'

using namespace std;

ll queries;

ll zbetween(ll x, ll y) {
    queries++;
    cout << "? " << x << " " << y << endl;
    cin >> x;
    return x;
    
}
void solve()
{
    queries = 0;
    ll n;
    cin >> n;

    vector<ll> par(n);
    par[1] = 0;

    vector<ll> level, nl;
    ll lvl = 2;
    for (; lvl < n; lvl++)
    {

        if (lvl == n-1 || !zbetween(1, lvl)) {
            par[lvl] = 1;
            nl.push_back(lvl);
            lvl++;
            break;
        }
        else {
            par[lvl] = 0;
            level.push_back(lvl);
        }
    }

    while (lvl < n) {
        for (ll i = 0; i < level.size(); i++)
        {
            if ((i == level.size()-1 && nl.empty()) || !zbetween(lvl, level[i])) {
                par[lvl] = level[i];
                nl.push_back(lvl);
                lvl++;
            }
        }
        swap(level, nl);
        nl.clear();
    }

    cout << "! ";
    for (ll i = 1; i < n; i++)
    {
        cout << par[i] << " ";
    }
}

int main()
{
    //ios::sync_with_stdio(false); cin.tie(0);
    ll t = 1;
    cin >> t;
    for (ll j = 0; j < t; j++)
    {
        solve();
        cout << endl;
    }
    return 0;

}