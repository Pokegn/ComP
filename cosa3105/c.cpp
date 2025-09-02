#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define MOD (int(1e9+7))

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<int64_t> a(n), sorted_a(n);
		for(int i = 0;i < n; i++){
			cin >> a[i];
			sorted_a[i] = a[i];
		}
		sort(sorted_a.begin(), sorted_a.end());
		for(int64_t &ai: a){
			// ai + x = MOD
			// ai = MOD - x
			// quiero encontrar el mayor number menor o igual a MOD-x
			// cuidar ue no sea el mismo number
			int x = MOD - ai - 1;

			auto it = upper_bound(sorted_a.begin(), sorted_a.end(), x);
			if(it == sorted_a.begin()){
				it = sorted_a.end();
				it--;
				if(*it == ai){
					it--;
				}
				cout << (ai + *it) % MOD << ' ';
				continue;
			}

			it--;
			if(*it == ai){
				if(it == sorted_a.begin()){
					it = sorted_a.end();
					it--;
				} else {
					it--;
				}
			}

			cout << (ai + *it) % MOD << ' ';



			// cout << (ai + *it)%MOD << ' ';


		}
		cout << '\n';

		
	}

	return 0;
}
