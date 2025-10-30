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
//#define endl '\n'
#define pb push_back
#define fi first
#define se second
ll MOD = 998244353;

void solve() {
    ll n; cin >> n;
	vector<ll> t(n - 1);
	for (int i = 0; i < n - 1; i++) cin >> t[i];
	sort(t.begin(), t.end());
	if (n == 1 && t[0]==1) {
		cout << "*" << '\n';
		return;
	}
	if (n == 1) {
		cout << t[0] << ' ' << 1 << endl;
		return;
	}

	if (t[0] != 1) {
		cout << t[n - 1] << ' ' << 1 << endl;
		return;
	}

	if (n == 2) {
		ll posp = (ll) floor(sqrt(t[1]));
		if (posp * posp == t[1]) {
			cout << t[1] << ' ' << posp << endl;
		}
		else {
			cout << posp * posp << ' ' << posp * posp << endl;
		}
	}

    //N = t[n-1] o t[n-1]*t[1]
    ll sq = (ll)floor(sqrt((double) t[1])); //checar si es potencia de p
    if(sq*sq == t[1]){
        cout << t[n-1] << ' ' << sq << endl;
        return;
    }
    ll p = t[1];
    bool ispot = true;
    for(int i=1; i<n; i++){
        ll temp = t[i];
        while(temp%p == 0) temp/=p;
        if(temp!=0) ispot = false;
    }

    if(ispot == true){
        for(int i=1; i<n; i++){
            if(t[i]!=t[i-1]*p){
                cout << t[n-1] << ' ' << t[i] << endl;
                return;
            }
        }
        cout << t[n-1]*p << ' ' << t[n-1]*p << endl;
    } //ahora si, hay dos primos que lo dividen

    //quiero saber si t[n-1] es n o n/t[1]
    if(t[n-1] <= 1e18/t[1]+1){
        ll maxpot = 1;
        while()
    }
    //aqui ya se que es t[n-1]
    
    if(t[n-1] < t[1]*t[n-2]){

    }
    else{

    }


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t = 1;
	//cin >> t;


	while (t--) {
		solve();
	}
}