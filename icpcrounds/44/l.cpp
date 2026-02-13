#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define rep(i, a, b) for(int i = a; i < (b); i++)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

ld PI = acos(-1);

ld dist(ld l, ld x, ld y, ld d){
	//cout << "caso " << l << ' ' << x << ' ' << y << ' ' << d << ' ';
	ld ret = sin(d);

	ld dist = sqrt((x-l)*(x-l)+y*y);
	ret*=dist;

	ld angi = asin(y/dist);
    if(angi<0){
        ll xd = 0;
        for(int i=0; i<1e10; i++) xd++;
    }

	if(x<l){
		ret/= sin(angi-d);
		//cout << ret << endl;
		return ret;
	}
	else{
		ret/= sin(angi+d);
		//cout << ret << endl;
		return ret;
	}
}

void solve(){
    vector<int> pot2(1<<22, -1);
    int potdemierda = 1;
    for(int i=0; i<22; i++){
        pot2[potdemierda] = i;
        potdemierda*=2;
    }

    // cout << pot2[0] << ' ' << pot2[1] << ' ' << pot2[2] << ' ' << pot2[256] << endl;
    // return;
    
	int n; cin >> n;
	ld l,r; cin >> l >> r;
	vector<pair<ld, ld>> pts(n);
	vector<ld> deg(n);

	for(int i=0; i<n; i++){
		cin >> pts[i].first >> pts[i].second >> deg[i];
        deg[i] = (PI*deg[i])/180.0;
	}
	vector<ld> dp(1<<n, -1);
	int sz = 1<<n;
	dp[0] = 0;
	for(int i=1; i<sz; i++){
		for(int j=1; j<sz; j*=2){
			if((i&j) == 0) continue;
			int last = i^j; //bitmask sin j
			int add = pot2[j]; //indice del que voy a agregar
            ld x = pts[add].first;
            ld y = pts[add].second;
            ld li = l+dp[last];
            ld a = r-li;
            ld b = sqrt((li-x)*(li-x)+y*y);
            ld c = sqrt((r-x)*(r-x)+y*y);
            ld alfa = acos((b*b+c*c-a*a)/(2*b*c));
            if(alfa <= deg[add]){
                cout << fixed << setprecision(10) << r-l << endl;
                return;
            }
            ld thisangle = min(deg[add], alfa);

			dp[i] = max(dp[i], dp[last] + dist(li, x, y, thisangle));
		}
	}
	//cout << dp[sz-1] << endl;
	cout << fixed << setprecision(10) << min(dp[sz-1], r-l) << endl;
	return;
}

int main() {
	int tt = 1;
	// cin >> tt;
	while(tt--)
		solve();
	return 0;
}