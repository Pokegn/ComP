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
	string s; cin >> s;
    ll n = s.length();
    ll ind = n-1;
    while(ind>=0){
        if(ind%2 == (n-1)%2){
            if(s[ind]!='o') break;
        }
        else{
            if(s[ind]!='i') break;
        }
        ind--; //primera letra no ultimate
    }	
    if(ind == -1){
        cout << "ULTIMATE" << '\n';
        return;
    }
    ll scorea = 0;
    ll scorei = 0;
    vector<ll> sa(n, 0);
    vector<ll> si(n, 0);
    for(int i=0; i<n; i++){
        if(s[i] == 'a'){
            scorea++;
        }
        if(s[i] == 'i'){
            scorei++;
        }
        if(s[i] == 'e'){
            scorea--;
        }
        if(s[i] == 'o'){
            scorei--;
        }
        if(scorei<0 || scorea < 0){
            cout << "INVALID" << '\n';
            return;
        }
        sa[i] = scorea; //del 0 al i abiertas - cerradas
        si[i] = scorei;
    }
    if(scorei!=0 || scorea!=0){
        cout << "INVALID" << '\n';
        return;
    }

    stack<ll> izq;
    vector<ll> pareja(n);

    for(int i=0; i<n; i++){
        if(s[i] == 'a' || s[i] == 'i'){
            izq.push(i);
        }
        else{
            auto j = izq.top();
            izq.pop();
            pareja[i] = j;
            pareja[j] = i;
        }
    }

    ll i = ind;
    while(i>=0){
        if(i == 0){
            s[i] = 'i';
            break;
        }
        if(s[i] == 'a' && sa[i-1] > 0){
            s[i] == 'e';
            sa[i]-=2;
            break;
        }
        if(s[i] == 'a'){
            
        }
        if(s[i] == 'a'){
            ll l = i;
            ll r = pareja[i];
            s[l] = 'i';
            s[r] = 'o';
            for(int j = l+1; j<r; j++){
                if(j-l < r-j) s[i] = 'a';
                else s[i] = 'e';
            }
            l = pareja[i]+1;
            r = n;
            for(int j = l+1; j<r; j++){
                if(j-l < r-j) s[i] = 'a';
                else s[i] = 'e';
            }
            cout << s << '\n';
            return;
        }
        i--;
    }

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