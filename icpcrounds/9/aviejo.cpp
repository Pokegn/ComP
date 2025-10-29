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
 
pair<ll, ll> menor(ll a, ll b, ll c, ll d) {
	if (b < 0) {
		a *= -1; b *= -1;
	}
	if (d < 0) {
		c *= -1;
		d *= -1;
	}
	if (a * d < b * c) {
		return { a,b };
	}
	return { c,d };
 
}
 
ll dist(ll x1, ll y1, ll z1, ll x2, ll y2, ll z2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
}
 
pair<ll,ll> distrecta(ll A, ll B, ll C, ll x1, ll y1, ll z1, ll x2, ll y2, ll z2) {
	ll a, aden;
	a = (A-x2)*(x1-x2)+(B-y2)*(y1-y2)+(C-z2)*(z1-z2);
	aden = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
	
	if(aden == 0){
	    return {dist(A,B,C,x1,y1,z1),1};
	}
 
	ll orilla1 = dist(A, B, C, x1, y1, z1);
	ll orilla2 = dist(A, B, C, x2, y2, z2);
 
	if (a >= 0 && a <= aden) {
		ll distancia = dist(A * aden, B * aden, C * aden, a * x1 + (aden - a) * x2, a * y1 + (aden - a) * y2, a * z1 + (aden - a) * z2);
		ll den = aden * aden;
 
		return{ distancia, den };
	}
 
	else{
		return { min(orilla1, orilla2), 1 };
	}
}
 
void solve() {
	ll x1, x2, y1, y2, z1, z2, p1, p2, q1, q2, r1, r2;
	cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> p1 >> q1 >> r1 >> p2 >> q2 >> r2;
	ll k1, k2, k3, l1, l2, l3;
	k1 = 2 * ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
	k2 = -2 * ((p1 - p2) * (x1 - x2) + (q1 - q2) * (y1 - y2) + (r1 - r2) * (z1 - z2));
	k3 = -2 * ((x1 - x2) * (x2 - p2) + (y1 - y2) * (y2 - q2) + (z1 - z2) * (z2 - r2));
 
	swap(x1, p1);
	swap(x2, p2);
	swap(y1, q1);
	swap(y2, q2);
	swap(z1, r1);
	swap(z2, r2);
 
	l2 = 2 * ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
	l1 = -2 * ((p1 - p2) * (x1 - x2) + (q1 - q2) * (y1 - y2) + (r1 - r2) * (z1 - z2));
	l3 = -2 * ((x1 - x2) * (x2 - p2) + (y1 - y2) * (y2 - q2) + (z1 - z2) * (z2 - r2));
 
	swap(x1, p1);
	swap(x2, p2);
	swap(y1, q1);
	swap(y2, q2);
	swap(z1, r1);
	swap(z2, r2);
 
	//cout << k1 << ' ' << k2 << ' ' << k3 << ' ' << l1 << ' ' << l2 << ' ' << l3 << '\n';
 
	ll bn, bd, an, ad; //numerador y denominador
	bn = k1 * l3 - k3 * l1;
	bd = k1 * l2 - k2 * l1;
	an = k2 * l3 - k3 * l2;
	ad = k2 * l1 - k1 * l2;
	ll na = an, da = ad, nb = bn, db = bd;
 
	//cout << an << ' ' << ad << ' ' << bn << ' ' << bd << '\n';
    
	if (ad != 0 && bd != 0) {
       // cout << "xd";
	    //cout << na << ' ' << da << ' ' << nb << ' ' << db << '\n';
		ll ga = __gcd(na, da);
		ll gb = __gcd(nb, db);
		na /= ga;
		da /= ga;
		nb /= gb;
		db /= gb;
		if (da < 0) {
			na *= -1;
			da *= -1;
		}
		if (db < 0) {
			nb *= -1;
			db *= -1;
		}
		ll xdd = da * db;
		na *= db;
		nb *= da;
		da = xdd;
		db = xdd;
	    //cout << na << ' ' << da << ' ' << nb << ' ' << db << '\n';
 
 
		if (na >= 0 && na <= da && nb >= 0 && nb <= db) { //mi denominador es da^2 o xdd^2
			vector<ll> ansnum(3, 0);
			ansnum[0] += x1 * na + x2 * (da - na);
			ansnum[0] -= p1 * nb + p2 * (db - nb);
			//cout << x1*na+x2*(da-na) << ' ' << p1 * nb + p2 * (db - nb) << ' ';
			ansnum[0] *= ansnum[0];
 
			ansnum[1] += y1 * na + y2 * (da - na);
			ansnum[1] -= q1 * nb + q2 * (db - nb);
		//	cout <<y1 * na + y2 * (da - na)<< ' ' << q1 * nb + q2 * (db - nb) << ' ';
			ansnum[1] *= ansnum[1];
 
			ansnum[2] += z1 * na + z2 * (da - na);
			ansnum[2] -= r1 * nb + r2 * (db - nb);
			//cout << z1 * na + z2 * (da - na) << ' ' << r1 * nb + r2 * (db - nb) << ' ';
			ansnum[2] *= ansnum[2];
 
            //cout << ansnum[0] << ' ' << ansnum[1] << ' ' << ansnum[2] << '\n';
			ll ansb = ansnum[0] + ansnum[1] + ansnum[2];
			ll di = __gcd(ansb, (da * da));
			//cout << ansb << ' ' << da*da << ' ' << di << '\n';
			xdd = da*da;
			ansb /= di; xdd /= di;
			if(xdd == 0){
			    xdd = 1;
			}
			if(xdd < 0){
			    xdd*=-1;
			    ansb*=-1;
			}
			
			cout << ansb << ' ' << xdd << '\n';
			return;
		}
	}
		vector<ll> dn(4);
		vector<ll> dd(4);
		pair<ll, ll> par;
		par = distrecta(x1, y1, z1, p1, q1, r1, p2, q2, r2);
		dn[0] = par.first;
		dd[0] = par.second;
		par = distrecta(x2, y2, z2, p1, q1, r1, p2, q2, r2);
		dn[1] = par.first;
		dd[1] = par.second;
		par = distrecta(p1, q1, r1, x1,y1, z1, x2, y2, z2);
		dn[2] = par.first;
		dd[2] = par.second;
		par = distrecta(p2, q2, r2, x1, y1, z1, x2, y2, z2);
		dn[3] = par.first;
		dd[3] = par.second;
        for(int i=0; i<4; i++){
            //cout << dn[i] << ' ' << dd[i] << '\n';
        }
		par = menor(dn[0], dd[0], dn[1], dd[1]);
		par = menor(par.first, par.second, dn[2], dd[2]);
		par = menor(par.first, par.second, dn[3], dd[3]);
		
		ll g = __gcd(par.first, par.second);
		par.first/=g; par.second/=g;
		
		if(par.second == 0) par.second = 1;
		if(par.second<0){
		    par.first*=-1;
		    par.second*=-1;
		}
        
       // cout << "xd";
		cout << par.first << ' ' << par.second << '\n';
		
		return;
		
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