#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstdint>

using namespace std; 

int64_t calc(int64_t MIN, int64_t MINSIDE, int64_t MAXR, int64_t MAX){
	int64_t lower_bound = MINSIDE-MIN;
	int64_t upper_bound = MAX-MAXR;
	if(lower_bound <= upper_bound) return MAX-MINSIDE;
	else return MAX-MIN;
}

int64_t solve(const vector<int64_t> &a){
	const int64_t n = a.size();

	map<int64_t, vector<int64_t>> indx;
	for(int64_t i = 0; i < n; i++)
		indx[a[i]].push_back(i);

	int64_t p1 = indx.begin() -> second.front();
	int64_t p2 = indx.begin() -> second.back();

	multiset<int64_t> left;
	multiset<int64_t> right;
	int64_t MIN = indx.begin() -> first;
	int64_t MAXR = MIN;
	int64_t MAX = indx.rbegin() -> first;

	for(int64_t i = 0; 	 i < p1; i++)
		left.insert(a[i]);
	for(int64_t i = p1; i <= p2; i++)
		MAXR = max(MAXR, a[i]);
	for(int64_t i = n-1; i > p2; i--)
		right.insert(a[i]);

	int64_t ans = MAX-MIN;
	for(const auto &[val, idx]: indx){
		int64_t np1 = idx.front();
		int64_t np2 = idx.back();

		while(np1 < p1)
			MAXR = max(MAXR, a[p1-1]), left.erase(left.find(a[--p1]));

		while(p2 < np2)
			MAXR = max(MAXR, a[p2+1]), right.erase(right.find(a[++p2]));

		int64_t MINSIDE = min(left.empty() ? 1e10 : *left.begin(), right.empty() ? 1e10 : *right.begin());
		ans = min(ans, calc(MIN, MINSIDE, MAXR, MAX));

		clog << p1 << ' ' << p2 << ' ' << MIN << ' ' << MINSIDE << ' ' << MAXR << ' ' << MAX << ' ' << ans << endl;
	}
	return ans;


}

int main(){

	int64_t tt; cin >> tt;
	while(tt--){
		int64_t n; cin >> n;
		vector<int64_t> a(n);
		for(int64_t &it: a) cin >> it;
		vector<int64_t> an;
		for(int64_t &it: a) an.push_back(-it);

		cout << min(solve(a), solve(an)) << endl;
	}

	return 0;
}