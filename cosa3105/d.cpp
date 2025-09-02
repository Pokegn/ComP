#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>


using namespace std;

int main(){
	// fast input/output
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		int q; cin >> q;
		string s; cin >> s;

		vector<vector<int>> prefix(n, vector<int>(26, 0));
		for(int i = 0; i < n; i++){
			prefix[i][s[i] - 'a']++;
			if(i > 0){
				for(int j = 0; j < 26; j++){
					prefix[i][j] += prefix[i - 1][j];
				}
			}
		}

		while(q--){
			int l, r; cin >> l >> r;
			// l and r could be out of range for prefix array
			l--; r--;
			char c; cin >> c;
			// basically we have a string that is repeated infinite time
			// from k = s+s+s+...
			// we are aksed, for string k, get how many times c is repeated inside k[l..r];
			int64_t r_rep = r / n;
			int64_t r_count = prefix[n - 1][c - 'a'] * r_rep;
			int64_t r_rem = r % n;
			r_count += prefix[r_rem][c - 'a'];

			int64_t l_rep = l / n;
			int64_t l_count = prefix[n - 1][c - 'a'] * l_rep;
			int64_t l_rem = l % n;
			l_count += prefix[l_rem][c - 'a'];

			int64_t ans = r_count - l_count + (s[l%n] == c ? 1 : 0);
			cout << ans << '\n';
		}

	}
}
