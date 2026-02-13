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
#define endl '\n'

using namespace std;
ll MOD = 998244353;

vector<ll> fact;

ll fexp(ll a, ll b, ll m){
    a%=m;
    ll res = 1;
    while(b>0){
        if(b&1) res = res*a%m;
        a = a*a %m;
        b>>=1;
    }
    return res;
}

ll binom(ll a, ll b){ //a en b
    ll ret = 1;
    if(b == 0) return 1;
    for(ll k = 0; k<b; k++){
        ret*=(a-k); ret%=MOD;
    }

    ret*=fexp(fact[b], MOD-2, MOD);
    ret%=MOD;

    return ret;
}

void solve()
{
    ll n;
    cin >> n;

    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    vector<set<ll>> closest(n);
    for (ll i = 0; i < n; i++)
    {
        ll cl = INT_MAX;
        for (ll j = 0; j < n; j++)
        {
            if (i == j) {
                continue;
            }

            ll dist = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
            cl = min(cl, dist);
        }

        for (ll j = 0; j < n; j++)
        {
            if (i == j) {
                continue;
            }

            ll dist = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
            if (dist == cl) {
                closest[i].insert(j);
            }
        }
    }
    
    vector<ll> groupsSizes;
    vector<ll> isPartOfGroup(n);
    for (ll i = 0; i < n; i++)
    {
        if (isPartOfGroup[i]) {
            continue;
        }
        set<ll> help = closest[i];
        help.insert(i);
        bool valid = true;
        for (auto& neigh:closest[i])
        {
            help.erase(neigh);
            if (closest[neigh] != help) {
                valid = false;
                break;
            }
            help.insert(neigh);
        }

        if (valid) {
            groupsSizes.push_back(closest[i].size() + 1);
            for (auto& neigh : closest[i])
            {
                isPartOfGroup[neigh] = 1;
            }
        }
        else {
            groupsSizes.push_back(1);
        }
    }

    fact = vector<ll>(n + 2);
    fact[0] = 1;
    for (ll i = 1; i < n+2; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i]%=MOD;
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    dp[0][0] = 1;
    for (ll j = 0; j < groupsSizes.size(); j++) //iteraciones que son los grupos
    {
        for (ll k = 0; k <= n; k++) //iterar sobre cuantos colores usaria
        {
                if(k+1<=n){ dp[j + 1][k + 1] += dp[j][k];
                    dp[j+1][k+1]%=MOD;}
                if(groupsSizes[j] != 1 && k+groupsSizes[j] <= n){ dp[j + 1][k + groupsSizes[j]] += dp[j][k];
                     dp[j + 1][k + groupsSizes[j]]%=MOD;}
        }
    }

    // cout << groupsSizes.size() << endl;

    // for(ll j=0; j<groupsSizes.size(); j++){
    //     cout << "gpsize " << groupsSizes[j] << endl;
    // }
    // return;

    ll szz = groupsSizes.size();
    ll ans = 0;
    for (ll i = 0; i <= n; i++)
    {
        ans += (((fact[i] * dp[szz][i]) % MOD)*binom(n, i)) % MOD;
        ans %= MOD;
    }
    
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    ll t = 1;
    //cin >> t;
    for (ll j = 0; j < t; j++)
    {
        solve();
        cout << endl;
    }
    return 0;

}