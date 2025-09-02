#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main(){

	// optimize input and ouput 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	


	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<int64_t> a(n);
		for(int64_t &ai: a)
			cin >> ai;

		int64_t ans = 0;
		for(int64_t i = 1; 1e6 >= i; i<<=1){
			int64_t streak = 0;
			// cout << "checking for bit :" << i << endl;
			// cout << (1ll<<i) << endl;
			for(int64_t &ai: a){
				// cout << (ai & (1ll<<i)) << endl;
				if(ai & i) streak++;
				else {
					int64_t combinations = (streak)*(streak+1)/2;
					ans += combinations * i;
					streak = 0;
				}
			}
			int64_t combinations = (streak)*(streak+1)/2;
			ans += combinations * i;;
			streak = 0;
			// cout << ans << endl;
		}


		cout << ans << '\n';
	}

	



	return 0;
}
