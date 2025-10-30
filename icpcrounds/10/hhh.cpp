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
	vector<ll> t(n);
	for (int i = 0; i < n; i++) cin >> t[i];
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
		ll posp = (ll) floor(sqrtl(t[1]));
		if (posp * posp == t[1] || (posp+1)*(posp+1) == t[1]) {
			cout << t[1] << ' ' << posp << endl;

		}
		else {
			cout << t[1] * t[1] << ' ' << t[1] * t[1] << endl;
		}
        return;
	}

    //N = t[n-1] o t[n-1]*t[1]
    ll sq = (ll)floor(sqrtl((double) t[1])); //checar si es potencia de p
    if(sq*sq == t[1] || (sq+1)*(sq+1) == t[1]){
        cout << t[n-1] << ' ' << sq << endl;
        return;
    }
    ll p = t[1];
    bool ispot = true;
    for(int i=1; i<n; i++){
        ll temp = t[i];
        while(temp%p == 0) temp/=p;
        if(temp!=1) ispot = false;
    }

    //cout << 2;
    if(ispot == true){
        //return;
        for(int i=1; i<n; i++){
            if(t[i]!=t[i-1]*p){
                cout << t[n-1] << ' ' << t[i-1]*p << endl;
                return;
            }
        }
        cout << t[n-1]*p << ' ' << t[n-1]*p << endl;
        return;
    } //ahora si, hay dos primos que lo dividen

    if(n ==3){
        if(t[n-1]%t[n-2] == 0){ //t[n-1] es n
            cout << t[n-1] << ' ' << t[n-1]/t[n-2] << endl;
        }
        else{
            cout << t[n-1]*t[n-2] << ' ' << t[n-1]*t[n-2] << endl;
        }
        return;
    }

    //quiero saber si t[n-1] es n o n/t[1]
    bool flag = true;
    for(int i=0; i<n; i++){
        if(t[n-1]%t[i]!=0) flag = false; //false significa que quitamos a n
    }
    if(flag == false){
        cout << t[n-1]*t[1] << ' ' << t[n-1]*t[1] << endl;
        return;
    }
    //aqui ya se que es t[n-1]
    //1 2 3 4 6 8 12 24
    
    map<ll, ll> esta;
    for(int i=0; i<n; i++){
        esta[t[i]] = 1;
    }
    for(int i=0; i<n; i++){
        if(esta[t[n-1]/t[i]]!=1){
            cout << t[n-1] << ' ' << t[n-1]/t[i] << endl;
            return;
        }
    }
    //cout << "Xd";
    sq = (ll)floor(sqrtl((double) t[n-1]));
    if(sq*sq == t[n-1]){
        cout << t[n-1] << ' ' << sq << endl;
        return;
    }
    if((sq+1)*(sq+1) == t[n-1]){
        cout << t[n-1] << ' ' << sq+1 << endl;
        return;
    }
    while(true){
        t[n-1] = 0/0;
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
} //1 2 3 4 6 12