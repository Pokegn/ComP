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
    ll t; cin >> t;
    vector<ll> a, b;
    vector<vector<ll>> aa(t), bb(t);
    for(int i=0; i<t; i++){
        ll x; cin >> x;
        for(int j=0; j<x; j++){
            ll xd; cin >> xd;
            a.push_back(xd);
            aa[i].push_back(xd);
        }
    }

    for(int i=0; i<t; i++){
        ll x; cin >> x;
        for(int j=0; j<x; j++){
            ll xd; cin >> xd;
            b.push_back(xd);
            bb[i].push_back(xd);
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a.size()!=b.size()){
        cout << "N" << endl;
        return;
    }
    for(int i=0; i<a.size(); i++){
        if(a[i]!=b[i]){
            cout << "N" << endl;
            return;
        }
    }

    if(t>2){
        cout << "S" << endl;
        return;
    }

    if(t ==2 ){
        ll actual = aa[0].size();
        ll obj = bb[0].size();
        ll actual2 = aa[1].size();
        while(actual <obj){
            aa[0].push_back(aa[1][actual2-1]);
            aa[1][actual2-1] = -1;
            actual2--;
            actual++;
        }
        while(actual>obj){
            aa[1].push_back(aa[0][actual-1]);
            aa[0][actual2-1] = -1;
            actual2++;
            actual--;
        }

        for(int i=0; i<obj; i++){
            if(aa[0][i] != bb[0][i]){
                cout << "N" << endl;
                return;
            }
        }
        for(int i=0; i<actual+actual2-obj; i++){
            if(aa[1][i] != bb[1][i]){
                cout << "N" << endl;
                return;
            }
        }

        cout << "S" << endl;
        return;

    }

    if(t==1){
        for(int i=0; i<aa[0].size(); i++){
            if(aa[0][i]!=bb[0][i]){
                cout << "N" << endl;
                return;
            }
        }
        cout <<"S" <<endl;
        return;
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