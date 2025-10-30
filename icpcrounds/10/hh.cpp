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

vector<ll> primes;
vector<bool> is_prime(1e6+10, true);
ll lim = 1000000;
int divv[1000001] = { 0 };

ll square(ll t) {
	ll posp = (ll)floor(sqrt(t));
	if (posp * posp == t) return posp;
	return -1;
}

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

	if (n == 3) {
		ll xd = square(t[1]);
		if (square(t[1]) != -1) {
			if (t[2] % t[1] == 0 && (t[2]/t[1]) % t[1] == 0) {
				if (t[2] == t[1] * t[1]) {
					cout << t[1] * t[1] * t[1] << ' ' << t[1] * t[1] * t[1] << endl;
					return;
				}
				else {
					cout << t[2] << ' ' << t[1] * t[1] << endl;
					return;
				}
			}
			if ((t[2] % t[1] == 0)) {
				cout << t[2] << ' ' << t[2] / t[1] << endl;
			}
			cout << t[2] * t[1] << ' ' << t[2] * t[1] << endl;
		}
		else {
			cout << t[n-1] << ' ' << square(t[1]) << endl;
		}
	}

	vector<ll> misp;
	for (int i = 1; i < n; i++) {
		if(t[i] <= 1000000)
		if (is_prime[t[i]]) misp.push_back(t[i]);
	}

	for (int i = 1; i < n; i++) {
		if (t[i] <= 1000000000000 && square(t[i])!=-1) {
			ll pp = square(t[i]);
			if (is_prime[pp] = true) misp.push_back(pp);
		}
	}

	if (misp.size() == 0) {
		ll xd = t[1];
		if (square(t[1]) != -1) {
			misp.push_back(square(t[1]));
		}
		else misp.push_back(t[1]);
	}

	for (int i = 1; i < n; i++) {
		bool encontre = false;
		if (encontre == true) continue;
		bool flag = false;
		for (auto x : misp) {
			if (t[i] % x == 0) {
				flag = true;
			}
		}
		if (flag == false) {
			ll xd = square(t[i]);
			if (xd != -1) {
				misp.push_back(xd);
			}
			else misp.push_back(t[i]);
            encontre = true;
		}
	}

    for (int i = 1; i < n; i++) {
		bool encontre = false;
		if (encontre == true) continue;
		bool flag = false;
		for (auto x : misp) {
			if (t[i] % x == 0) {
				flag = true;
			}
		}
		if (flag == false) {
			ll xd = square(t[i]);
			if (xd != -1) {
				misp.push_back(xd);
			}
			else misp.push_back(t[i]);
            encontre = true;
		}
	}

    for (int i = 1; i < n; i++) {
		bool encontre = false;
		if (encontre == true) continue;
		bool flag = false;
		for (auto x : misp) {
			if (t[i] % x == 0) {
				flag = true;
			}
		}
		if (flag == false) {
			ll xd = square(t[i]);
			if (xd != -1) {
				misp.push_back(xd);
			}
			else misp.push_back(t[i]);
            encontre = true;
		}
	} //o ya encontramos a todos los primos o ese es el que falta

    ll casi = t[n-1];
    for(auto x: misp){
        while(casi%x == 0) casi/=x;
    }

    if(casi !=1){
        ll xd = square(casi);
        if (xd != -1) {
            misp.push_back(xd);
        }
        else misp.push_back(casi);
    } //ahora si ya estan todos los primos

    casi = t[n-1];
    vector<ll> divisores(1, 1);

    

	


	//ll p = t[1];
	//ll casi = t[n - 1];

	//ll maxp = p;
	//ll pot = 1;
	//while (casi % maxp == 0 && (ll)casi/maxp>=p ){
	//	maxp *= p;
	//	pot++;
	//}
	//if (casi % maxp!=0) {
	//	maxp /= p;
	//	pot--;
	//}

	//if (pot == n) { //si mi madre esta es potencia de 2

	//}

	//for (auto x : primes) {
	//	
	//}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t = 1;

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= lim; i++) {
    if (is_prime[i] && (long long)i * i <= lim) {
        for (int j = i * i; j <= lim; j += i)
            is_prime[j] = false;
    }
}
	//cin >> t;
	// for (ll i = 2; i <= lim; i++)
	// {
	// 	if (divv[i] == 0) {
	// 		primes.push_back(i);
	// 		is_prime[i] = true;
	// 	}
	// 	for (ll j = i; j <= lim; j++) {
	// 		divv[j] = i;
	// 	}
	// }


	while (t--) {
		solve();
	}
}