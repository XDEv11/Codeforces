//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

#include <cmath>

using namespace std;

using ll = long long;
const ll PM{998244353};
ll MC(ll a) { return (a % PM + PM) % PM; }
ll MA(ll a, ll b) { return (a + b) % PM; }
ll MS(ll a, ll b) { return (a - b + PM) % PM; }
ll MM(ll a, ll b) { return (a * b) % PM; }
ll MP(ll a, ll b) {
    ll res{1};
    do {
        if (b & 1) res = MM(res, a);
    } while (a = MM(a, a), b >>= 1);
    return res;
}
ll MI(ll a) { return MP(a, PM - 2); }
ll MD(ll a, ll b) { return MM(a, MI(b)); }

static void solve() {
	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	vector<ll> mn(n + 1), mx(n + 1), dpmn(n + 1), dpmx(n + 1);
	mn[0] = 0, mx[0] = 0, dpmn[0] = 1, dpmx[0] = 1;
	for (int i{0}; i < n; ++i) {
		auto& x{v[i]};

		mn[i + 1] = mn[i] + x;
		mx[i + 1] = max(abs(mx[i] + x), abs(mn[i + 1]));

		ll t{dpmn[i]};
		if (mn[i + 1] >= 0) t = MM(t, 2);
		dpmn[i + 1] = t;

		t = 0;
		if (mx[i + 1] == abs(mx[i] + x)) {
			t = dpmx[i];
			if (mx[i] + x >= 0) t = MM(t, 2);
		}
		if (mn[i] != mx[i]) {
			if (mx[i + 1] == abs(mn[i + 1])) t = MA(t, dpmn[i]);
		}
		dpmx[i + 1] = t;
	}

	cout << dpmx[n] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
