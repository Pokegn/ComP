#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair < ll, ll > pll;

#define f first
#define s second
#define mp make_pair

const int N = 200500;

ll dp[N];
bool u[N];
int n, j, sz;
pll p[N], q[N], line[N];

double cross(ll k1, ll l1, ll k2, ll l2) {
	return ((l2 - l1 + 0.0) / (k1 - k2 + 0.0));
}

void add(ll k, ll l) {
	while (sz > 1) {
		if (cross(line[sz - 1].f, line[sz - 1].s, line[sz].f, line[sz].s) < cross(line[sz].f, line[sz].s, k, l))
			break;
		sz--;
	}
	line[++sz] = mp(k, l);
	j = min(j, sz);
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%I64d %I64d", &p[i].f, &p[i].s);

	sort(p + 1, p + 1 + n);

	for (int i = 1; i <= n; i++) {
		while (sz && q[sz].f <= p[i].f && q[sz].s <= p[i].s)
			sz--;
		q[++sz] = p[i];
	}

	sort(q + 1, q + 1 + sz);

	n = sz;
	sz = 0;
	j = 1;

	add(q[1].s, dp[0]);

	for (int i = 1; i <= n; i++) {
		while (j < sz && cross(line[j].f, line[j].s, line[j + 1].f, line[j + 1].s) < q[i].f)
			j++;
		dp[i] = line[j].f * q[i].f + line[j].s;
		add(q[i + 1].s, dp[i]);
	}

	printf("%I64d", dp[n]);

	return 0;
}